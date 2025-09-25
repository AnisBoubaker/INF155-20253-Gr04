#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nb_lignes;

    printf("Combien de lignes: ");
    scanf("%d", &nb_lignes);

    while( nb_lignes > 0 )
    {
        printf("#####\n");
        nb_lignes--;
    }

    return EXIT_SUCCESS;
}
