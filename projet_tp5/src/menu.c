#include "menu.h"
#include "monde.h"
#include "serpent.h"
#include "graphique.h"
#include "case.h"
#include <string.h>
#include <ncurses.h>
#include <unistd.h>
#include <assert.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

Monde init_monde(Option opt) {

    /* Remplit la structure monde, on y entre les dimensons du monde et tout ce qu'il y a autour pour initaliser le jeu */ 

    /* Variables */ 

    Monde retour;
    int i;

    /* Remplissage de la structure Monde */ 

    retour.pomme_presente = NULL;
    retour.nb_ligne = opt.nb_ligne;
    retour.nb_colonne = opt.nb_colonne;
    retour.taille_serpent = opt.taille_serpent;
    retour.serpent = init_serpent(retour);
    

    /* Initialisation des pommes sur le quadriallage */ 
    
    for (i = 0 ; i < opt.nb_pommes ; i++) {
        while (!ajouter_pomme_monde(&retour));
    }
    retour.nb_pomme_mangee = 0;
	return retour;
}



Option init_option(void){

    /* Remplit la structure option pour initialiser le jeu avant son lancement */ 

    /* Initialisation de variables */ 

    Option retour;

    /* Initialisaion de la structure */ 

    retour.duree_tour=150000;
    retour.taille_serpent=4;
    retour.nb_colonne=30;
    retour.nb_ligne=15;
    retour.nb_pommes=5;
    return retour;
}



void jeu(void){

    /* Regroupe l'ensemble des fonctions et permet de lancer le jeu */ 

    /* Initialisation */ 
    Option a=init_option();
    int touche;
    Monde partie = init_monde(a);
    clear();
    noecho();

    /* Lancement du jeu */ 
    
    afficher_monde(partie);
    refresh();
    getch();
    cbreak();
    nodelay(stdscr, TRUE);
    while(1){
        if (mort_serpent(partie)) {
            clear();
            mvprintw(LINES / 2, COLS / 2 - 4, "Vous avez PERDU !");
            refresh();
            cbreak();
            nodelay(stdscr, FALSE);
            getch();
            break;
        }
        if (!deplacer_serpent(&partie)) {
            if (manger_pomme_serpent(&partie)==0)
                while (!ajouter_pomme_monde(&partie));
        }
        afficher_monde(partie);
        refresh();
        touche = getch();
        switch (touche) {
            case 'q' : partie.serpent->sens = OUEST; break;
            case 'd' : partie.serpent->sens = EST; break;
            case 's' : partie.serpent->sens = SUD; break;
            case 'z' : partie.serpent->sens = NORD; break;
            case ' ' : while (getch() != ' '); break;
            default : break;
        }
        usleep(a.duree_tour);
    }
}
