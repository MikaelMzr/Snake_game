#include "serpent.h"
#include <stdlib.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

Case prochaine_case(Serpent serpent) {

    /* permet de faire avancer le serpent de case en case */ 

    /* Variables */ 

    Case retour;

    retour.x = serpent->coord.x;
    retour.y = serpent->coord.y;

    /* choix de la direction */ 

	switch (serpent->sens) {
		case NORD : retour.y--; break;
		case SUD : retour.y++; break;
		case EST : retour.x++; break;
		case OUEST : retour.x--; break;
        default : break;
	}
    return retour;
}

int ajout_morceau(Serpent *serpent, Case nouvelle) {

    /* permet d'ajouter un morceau au corps du serpent */

    /* Variables */

    Serpent temp_s;

    temp_s = *serpent;
    if (!(*serpent = (Serpent)malloc(sizeof(Morceau))))
        return 0;
    (*serpent)->sens = temp_s->sens; /* choix de la direction */ 
    (*serpent)->coord.x = nouvelle.x;
    (*serpent)->coord.y = nouvelle.y;
    (*serpent)->corps = temp_s;
    return 1;
}
