#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int max;
    int somme;
    int compteur;

    //Valider la saisie et re-demander si la valeur est incorrecte
    do{
        printf("Terme maximal (Positif >=0): ");
        scanf("%d", &max);
    } while( max < 0 );


//    max = -1;
//    while( max < 0 )
//    {
//        printf("Terme maximal (Positif >=0): ");
//        scanf("%d", &max);
//    }

    somme = 0;
    compteur = 1;
    while( compteur <= max )
    {
        somme = somme + compteur;
        compteur++;
    }

//    somme = 1;
//    compteur = 1;
//    while( compteur <= max )
//    {
//        somme = somme * compteur;
//        compteur++;
//    }

    printf("La somme des termes de 1 à %d est: %d\n", max, somme);

    return EXIT_SUCCESS;
}
