#include <stdio.h>

int main() {

    int un_entier = 10;
    double un_reel = 20.5;

    printf("L'adresse de un_entier est: %p\n", &un_entier);
    printf("L'adresse de un_reel est: %p\n", &un_reel);

    int* ptr_un_entier;

    ptr_un_entier = &un_entier;
    printf("Valeur: %p\n", ptr_un_entier);

    printf("Le contenu de un_entier: %d\n", un_entier);

    *ptr_un_entier = 50;

    printf("Le contenu de un_entier: %d\n", un_entier);

    int** une_var_bizarre;

    une_var_bizarre = &ptr_un_entier;
    **une_var_bizarre = 1000;

    return 0;
}
