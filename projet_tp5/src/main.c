#include "pomme.h"
#include "menu.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/


int main(void) {

    /* Initialisation de la fenetre */ 
    initscr();

    /* Initialisation de la couleur */ 
    start_color();
    curs_set(0);
    init_pair( 1, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_GREEN, COLOR_BLACK);
    init_pair(UNSELECT, COLOR_WHITE, COLOR_BLACK);
    init_pair(SELECT, COLOR_BLACK, COLOR_WHITE);

    /* Initalisation de rand(), pour generer des nombres aleatoires */ 
    srand(time(NULL));

    /* Lancement du jeu */ 
    jeu();
    endwin();
    return (0);
}
