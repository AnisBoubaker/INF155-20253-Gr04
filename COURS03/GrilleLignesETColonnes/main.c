#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nb_lignes, nb_colonnes;

    printf("Nombre de lignes: ");
    scanf("%d", &nb_lignes);
    printf("Nombre de colonnes: ");
    scanf("%d", &nb_colonnes);


    for(int j=0; j<nb_lignes; j++)
    {
        //Afficher UNE ligne
        for (int i = 0; i < nb_colonnes; i++)
        {
            if((i+j) % 2)
            {
                printf(".");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
