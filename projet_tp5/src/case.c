#include "case.h"

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/

int compare_case(Case i, Case j) {

	/* compare les coordonnées de deux cases */ 
	/* Renvoie True si les cases sont égales, False sinon */ 
    return (i.x == j.x && i.y == j.y);
}
