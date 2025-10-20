#ifndef STAT2D__H
#define STAT2D__H

#include <limits.h>

#define TAILLE_MAX_COLS 5

int somme_tab2d( int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_cols);
double moyenne_tab2d(int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_cols);
int min_tab_nnul(int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_colonnes);

#endif