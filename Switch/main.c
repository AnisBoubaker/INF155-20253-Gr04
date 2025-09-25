#include <stdio.h>

int main() {
    char choix;

    printf("Choisir A, B ou C: ");
    scanf("%c", &choix);

    switch(choix)
    {
        case 'a':
        case 'A':
            printf("Vous avez choisi A, bon choix!\n");
            break;
        case 'b':
        case 'B':
            printf("Vous avez choisi B, pas mal!\n");
            break;
        case 'c':
        case 'C':
            printf("Vous avez choisi C, c'est bien!\n");
            break;
        default:
            printf("Vous deviez choisir A, B ou C!\n");
    }



    return 0;
}
