#include <stdio.h>
#include <stdlib.h>

/* DECLARATIONS DES PROTOTYPES */
/*
 * Affiche le menu et s'assure que la saisie de l'usager est valide
 * ENTREES: Aucune
 * SORTIE (entier): Le choix dans le menu fait l'usager
 */
int menu(void);


int main(void) {
    int choix_menu;

    switch( menu() )
    {
        case 1:
            printf("Création d'un nouveau client....");
            break;
        case 2:
            printf("Modification d'un client....");
            break;
        case 3:
            printf("Création d'une facture.....");
            break;
        case 9: return 0;
    }

    return EXIT_SUCCESS;
}



int menu(void)
{
    int choix;
    printf("Choisissez une option: \n");
    printf("1. Nouveau client\n");
    printf("2. Modifier un client existant\n");
    printf("3. Nouvelle facture\n");
    printf("9. Quitter\n");

    do{
        printf("Choix > ");
        scanf("%d", &choix);
    } while( choix<1 || (choix>3 && choix!=9) );

    return choix;
}