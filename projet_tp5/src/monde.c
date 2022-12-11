#include "monde.h"
#include "graphique.h"
#include "case.h"
#include <stdlib.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

int case_libre(Monde mon, Case pos) {

    /* Initialisation */

    EnsembleP temp;
    Serpent temp_s;

    /*condition de sortie du tableau*/
	if (pos.x >= mon.nb_colonne || pos.x < 0)
		return 0;
	if (pos.y >= mon.nb_ligne || pos.y < 0)
		return 0;

    /*condition qui teste si la case n'est pas deja prise*/    
    for (temp = mon.pomme_presente ; temp ; temp = temp->suivant)
        if (compare_case(pos, temp->pomme.pos))
            return 0;
    for (temp_s = mon.serpent ; temp_s ; temp_s = temp_s->corps) {
        if (compare_case(pos, temp_s->coord))
            return 0;
    }
	return 1;
}





/*Nous avons changer le type renvoyer par la fonction de la consigne*/
int ajouter_pomme_monde(Monde *mon) {

    /* Permet d'ajouter des pommes sur la fenetre */ 

    /* Variables */ 

    Pomme nouvelle;
    EnsembleP temp;

    nouvelle = pomme_gen_alea(mon->nb_ligne, mon->nb_colonne);
    if (!case_libre(*mon, nouvelle.pos))
        return 0;
    if (!(temp = (EnsembleP)malloc(sizeof(Pommes))))
        exit(EXIT_FAILURE);
    temp->pomme.pos.x = nouvelle.pos.x;
    temp->pomme.pos.y = nouvelle.pos.y;
    temp->suivant = mon->pomme_presente;
    mon->pomme_presente = temp;
    return 1;
}

Serpent init_serpent(Monde mon) {

    /* Initialise le serpent au depart du jeu */ 

    /* Variables */ 

    Serpent retour;
    Serpent temp;
    int i;

    temp = NULL;
    for (i = 0 ; i < mon.taille_serpent ; i++) {
        if (!(retour = (Serpent)malloc(sizeof(Morceau))))
            exit(EXIT_FAILURE);
        retour->coord.x = mon.nb_colonne / 2 + i - mon.taille_serpent - 1;
        retour->coord.y = mon.nb_ligne / 2;
        retour->sens = EST;
        retour->corps = temp;
        temp = retour;
    }
    return retour;
}

int deplacer_serpent(Monde *mon) {

    /* Permet de deplacer le serpent sur la fenetre */ 

    /* Variables */ 

    Serpent temp_s;
    Case nouvelle;
    Case temp_c;

    nouvelle = prochaine_case(mon->serpent);
    if (!case_libre(*mon, nouvelle))
        return 0;
    for (temp_s = mon->serpent ; mon->serpent ; mon->serpent = mon->serpent->corps) {
        temp_c = mon->serpent->coord;
        mon->serpent->coord = nouvelle;
        nouvelle = temp_c;
    }
    mon->serpent = temp_s;
    return 1;
}

int mort_serpent(Monde mon) {

    

    /* Variables */ 

    Serpent temp_s;
    Case nouvelle;

    nouvelle = prochaine_case(mon.serpent);
	if (nouvelle.x >= mon.nb_colonne || nouvelle.x < 0)
		return 1;
	if (nouvelle.y >= mon.nb_ligne || nouvelle.y < 0)
		return 1;
    for (temp_s = mon.serpent->corps ; temp_s ; temp_s = temp_s->corps) {
        if (compare_case(nouvelle, prochaine_case(temp_s)))
            return 1;
    }
	return 0;
}

int manger_pomme_serpent(Monde *mon) {
    Case nouvelle;
    EnsembleP temp;
    EnsembleP mangee;

    nouvelle = prochaine_case(mon->serpent);
    if (compare_case(nouvelle, mon->pomme_presente->pomme.pos)) {
        
        mon->nb_pomme_mangee++;
        if (!ajout_morceau(&(mon->serpent), nouvelle)) {
            exit(EXIT_FAILURE); 
        }
        
        mangee = mon->pomme_presente;
        mon->pomme_presente = mangee->suivant;
        free(mangee);
        return 1;
    }
    for (temp = mon->pomme_presente ; mon->pomme_presente 
         && mon->pomme_presente->suivant ;
         mon->pomme_presente = mon->pomme_presente->suivant) {
        if (compare_case(nouvelle, mon->pomme_presente->suivant->pomme.pos)) {
            mon->nb_pomme_mangee++;
            if (!ajout_morceau(&(mon->serpent), nouvelle)) {
                exit(EXIT_FAILURE);
                        
            }
            
            mangee = mon->pomme_presente->suivant;
            mon->pomme_presente->suivant = mangee->suivant;
            free(mangee);
            mon->pomme_presente = temp;
            return 1;
        }
    }
    return 0;
}
