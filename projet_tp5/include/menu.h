#ifndef __MENU__
#define __MENU__
#define MENU 3
#define CONTENU 25
#define SELECT 8
#define UNSELECT 7
#include "monde.h"

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/


typedef struct {
    int duree_tour;
    int taille_serpent;
    int nb_colonne;
    int nb_ligne;
    int nb_pommes;
} Option;

Monde init_monde(Option opt);
Option init_option(void);
void jeu(void);

#endif
