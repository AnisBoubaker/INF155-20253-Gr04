#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nb_lignes;
    int compteur;

    printf("Combien de lignes: ");
    scanf("%d", &nb_lignes);

    //Note: Bonds de 3: for(int i=0; i < nb_lignes ; i+=3)
    for(int i=0; i < nb_lignes ; i++)
    {
        printf("#####\n");
    }


//    compteur = 0;
//    while( compteur < nb_lignes )
//    {
//        printf("#####\n");
//        compteur++;
//    }

    return EXIT_SUCCESS;
}
