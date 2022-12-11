#include "graphique.h"
#include <ncurses.h>
#include <assert.h>

/*Mezouar Mikael 
 * Peinzi Ferdyl
 * Groupe 6*/


void affiche_carre(int origine_y, int origine_x, int cote) {

    /* Affiche les carrés qui composeront la zone où se deplacera le serpent */ 

   
    /* Variables */ 

    int i;
    int j;

    for (i = 0 ; i < cote ; i++) {
        for (j = 0 ; j < cote ; j++) {
            if (j == 0 || j == cote - 1)
                mvaddch(origine_y + i, origine_x + j,
                        (i == 0 || i == cote - 1) ? '+' : '|');
            else
                mvaddch(origine_y + i, origine_x + j,
                        (i == 0 || i == cote - 1) ? '-' : ' ');
        }
    }
}

void afficher_quadrillage(Monde mon) {

    /* Affiche la totalité du quadriallge en fonction des dimensions du monde passées en arguments */ 

    /* Variables */ 

    int i;
    int j;

    for (i = 0 ; i < mon.nb_ligne ; i++) {
        for (j = 0 ; j < mon.nb_colonne ; j++)
            affiche_carre((COTE - 1) * i, (COTE - 1) * j, COTE);
    }
}

void afficher_pomme(Pomme pom) {

    /* Affiche les pommes sur le quadrillage */ 

    /* Variables */ 
    int centre;

    centre = COTE / 2;
    attron(COLOR_PAIR(1)); /* Initialisation de la couleur de la pomme */ 
    mvaddch(pom.pos.y * (COTE - 1) + centre,
            pom.pos.x * (COTE - 1) + centre, 'o');
    attroff(COLOR_PAIR(1)); 
}

void afficher_serpent(Serpent ser) {


    /* Affiche le corps du serpent sur le quadrillage, une case représente un partie du corps du serpent */ 

    /* Variables */ 
    int centre;

    centre = COTE / 2;
    attron(COLOR_PAIR(TETE)); /* On differencie la couleur de la tete et du corps du serpent */ 
    mvaddch(ser->coord.y * (COTE - 1) + centre,
            ser->coord.x * (COTE - 1) + centre, 'o');
    ser = ser->corps;
    attroff(COLOR_PAIR(TETE));
    attron(COLOR_PAIR(MORCEAU)); /* On differencie la couleur de la tete et du corps du serpent */ 
    while (ser) {
        mvaddch(ser->coord.y * (COTE - 1) + centre,
                ser->coord.x * (COTE - 1) + centre, 'o');
        ser = ser->corps;
    }
    attroff(COLOR_PAIR(MORCEAU));
}

void afficher_monde(Monde mon) {

    /* Affiche l'etat du monde au cours du jeu et le score, soit le nombre de pommes mangées */ 
    EnsembleP temp;

    afficher_quadrillage(mon);
    for (temp = mon.pomme_presente ; temp; temp = temp->suivant)
        afficher_pomme(temp->pomme);
    afficher_serpent(mon.serpent);
    mvprintw((COTE - 1) * mon.nb_ligne + 1, COLS / 2 - 10,
             "Le nombre de pomme mangee est : %2d", mon.nb_pomme_mangee);
}
