
#include "stat2d.h"


double moyenne_tab2d(int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_cols)
{
    return (double)somme_tab2d(tab, nb_lignes, nb_cols) / (nb_lignes*nb_cols);
}

int somme_tab2d( int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_cols)
{
    int somme = 0;
    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_cols; j++)
        {
            somme+= tab[i][j];
        }
    }
    return somme;
}

int min_tab_nnul(int tab[][TAILLE_MAX_COLS], int nb_lignes, int nb_colonnes)
{
    //int min = tab[0][0];
    int min = INT_MAX;
    int min_a_change = 0;

    for(int i=0; i<nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            //Pourquoi il est nécessaire de mettre <= et non <
            if (min <= tab[i][j] && tab[i][j] != 0) {
                min = tab[i][j];
                min_a_change = 1;
            }
        }
    }

    if(min_a_change){
        return min;
    } else {
        return 0;
    }
}




