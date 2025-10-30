#include <stdio.h>

int main() {

    int tab[10] = {10, 20, 30 , 40, 50};

    //tab est un pointeur
    printf("La valeur pointée par tab: %d\n", *tab);

    *tab = 70;

    printf("La valeur à tab[0]: %d\n", tab[0]);

    //Utiliser le pointeur tab pour accéder à la 2e case du tableau (tab[1])
    printf("L'adresse de tab: %p\n", tab);
    printf("L'adresse de tab+1: %p\n", tab+1);

    printf("La valeur pointée par tab+1: %d\n", *(tab+1));
    printf("La valeur pointée par tab+2: %d\n", *(tab+2));

    return 0;
}
