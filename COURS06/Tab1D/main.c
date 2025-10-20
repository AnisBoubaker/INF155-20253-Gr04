#include <stdio.h>

#define NB_MAX_ETUDIANTS 10


int main() {

    double notes[NB_MAX_ETUDIANTS] = {30, 35, 19, 28};

    int un_tableau[30]; //Le tableau contiendra des valeurs indéfinies
    int un_tableau2[10] = { 0 }; // Contiendra des 0 dans toutes les cases

    printf("La note à l'indice 3: %lf\n", notes[3]);

    notes[5] = 10.5;

    for(int i=0; i < NB_MAX_ETUDIANTS; i++)
    {
        printf("%lf, ", notes[i]);
    }



    return 0;
}
