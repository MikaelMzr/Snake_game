#ifndef __SERPENT__
#define __SERPENT__
#include "direction.h"
#include "case.h"

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/


typedef struct morceau {
    Direction sens;  /*direction */
    Case coord;      /*donnée de la liste (coordonnée) */
    struct morceau *corps; /*liste chainée */
} Morceau, *Serpent;

Case prochaine_case(Serpent serpent);
int ajout_morceau(Serpent *serpent, Case nouvelle);
#endif
