#include "pomme.h"
#include <stdlib.h>
#include <time.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

Pomme pomme_gen_alea(int n, int m) {

	/* permet de generer deux nombres aleatoires qui representent les coordonnees d'une pomme */ 

	/* Variables */ 
    int abs;
    int ord;
    Pomme new;

    abs = rand() % n;
    ord = rand() % m;
    new.pos.x = abs;
    new.pos.y = ord;
    return new;

}



