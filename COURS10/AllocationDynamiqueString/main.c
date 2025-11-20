#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Pour avoir un espace de la taille nécessaire sans gaspillage:
 * 1. Realloc après que la saisie ait été effectuée
 * 2. Utiliser un buffer temporaire pour effectuer la saisie, puis allouer à la taille exacte.
 */

int main() {
    char* nom = NULL;
    char* prenom = NULL;
    char* buffer = NULL;

    buffer = (char*)malloc(250*sizeof(char));

//    nom = (char*)malloc(100*sizeof(char));
//    prenom = (char*)malloc(100*sizeof(char));
//    if(nom == NULL || prenom==NULL)
//    {
//        printf("Pas assez de memoire.\n");
//        exit(100);
//    }

    printf("Saisir votre prénom: ");
    fgets(buffer, 100, stdin);
    buffer[ strlen(buffer)-1 ] = '\0';
    //Allocation du prenom à la taille exacte
    prenom = (char*)malloc( (strlen(buffer)+1)*sizeof(char) );
    strcpy(prenom, buffer);

    printf("Saisir votre nom: ");
    fgets(buffer, 100, stdin);
    buffer[ strlen(buffer)-1 ] = '\0';
    //Allocation du nom à la taille exacte
    nom = (char*)malloc( (strlen(buffer)+1)*sizeof(char) );
    strcpy(nom, buffer);

    free(buffer);

    printf("Vous vous appelez: %s %s\n", prenom, nom);
    return 0;
}
