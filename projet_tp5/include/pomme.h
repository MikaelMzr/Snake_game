#ifndef __POMME__
#define __POMME__
#include "case.h"

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

typedef struct {
    Case pos;
} Pomme;

typedef struct pommes {
    Pomme pomme;
    struct pommes *suivant;
} Pommes, *EnsembleP;

Pomme pomme_gen_alea(int n, int m);


#endif 
