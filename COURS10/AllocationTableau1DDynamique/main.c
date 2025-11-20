#include <stdio.h>
#include <stdlib.h>

int main() {
    int* tab = NULL;
    int taille;

    printf("Saisir la taille du tableau: ");
    scanf("%d", &taille);

    tab = (int*)malloc( taille * sizeof(int));
    if(tab == NULL)
    {
        printf("Desole, memoire epuisee...\n");
        exit(1000);
    }

//    *(tab+0) = 25;
//    *(tab+1) = 50;
//    *(tab+2) = 75;
    tab[0] = 25;
    tab[1] = 50;
    tab[2] = 75;

    for(int i=0; i<3; i++)
    {
        printf("%d  ", tab[i]);
    }
    printf("\n");


    printf("Saisir la nouvelle taille du tableau: ");
    scanf("%d", &taille);

    int* ptr_tmp;
    ptr_tmp = realloc(tab, taille);
    if(ptr_tmp == NULL)
    {
        printf("Modification de la taille du tableau a échoué.\n");
    } else {
        tab = ptr_tmp;
    }

    printf("Contenu du tableau après réallocation: \n");
    for(int i=0; i<3; i++)
    {
        printf("%d  ", tab[i]);
    }
    printf("\n");

    return 0;
}
