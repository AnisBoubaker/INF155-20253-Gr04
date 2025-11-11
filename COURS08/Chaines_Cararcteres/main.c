#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int main() {
    char ma_chaine[] = "Bonjour tout le monde!";
    char prenom[TAILLE_MAX];

    printf("Ma chaine contient: %s\n", ma_chaine);

    printf("Saisir le prenom: ");
    //scanf("%s", prenom); //Marche pas car s'arrete aux espaces!
    fgets(prenom, TAILLE_MAX, stdin);
    prenom[ strlen(prenom)-1 ] = '\0';


    printf("Votre prenom : %s\n", prenom);

    return 0;
}
