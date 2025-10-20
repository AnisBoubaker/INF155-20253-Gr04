#include <stdio.h>
#include <limits.h>
#include "stat2d.h"



int main() {

    int tab2d[4][TAILLE_MAX_COLS] = { {5, 10, 12}, {3,8}, {7, 6, 5}, {12} };

    int tab2d_nul[10][20] = {0}; // Alternative à { {0} };

    for(int ligne=0; ligne < 4 ; ligne++)
    {
        for(int colonne = 0; colonne < 5; colonne++)
        {
            printf("%d ", tab2d[ligne][colonne]);
        }
        printf("\n");
    }

//    int somme = 0;
//    for(int i=0; i<4; i++)
//    {
//        for(int j=0; j<5; j++)
//        {
//            somme += tab2d[i][j];
//        }
//    }
//    printf("La somme des elements: %d\n", somme);

    printf("La somme des elements: %d\n", somme_tab2d(tab2d, 4, 5));

    return 0;
}



