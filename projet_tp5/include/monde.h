#ifndef __MONDE__
#define __MONDE__
#include "pomme.h"
#include "serpent.h"
#define MORCEAU 5
#define TETE 6


/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

typedef struct {
    int nb_ligne;
    int nb_colonne;
    Serpent serpent;
    EnsembleP pomme_presente; /*ensemble des pommes présentes*/
    int taille_serpent;
    int nb_pomme_mangee;
} Monde;

int ajouter_pomme_monde(Monde *mon);
Serpent init_serpent(Monde mon);
int deplacer_serpent(Monde *mon);
int mort_serpent(Monde mon);
int manger_pomme_serpent(Monde *mon);

#endif
