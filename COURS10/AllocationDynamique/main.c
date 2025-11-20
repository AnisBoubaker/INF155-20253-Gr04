#include <stdio.h>
#include <stdlib.h>

int main() {

    int* entier_dynamique = NULL;


    entier_dynamique = (int*)malloc(sizeof(int));
    *entier_dynamique = 200;
    printf("Le contenu de l'entier dynamique: %d\n", *entier_dynamique);

    free(entier_dynamique);

    entier_dynamique = (int*)malloc(sizeof(int));
    *entier_dynamique = 500;
    printf("Le contenu de l'entier dynamique: %d\n", *entier_dynamique);

    return 0;
}
