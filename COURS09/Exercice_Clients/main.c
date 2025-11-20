/*
 * # Exercice 1
 * Écrire un programme qui déclare un enregistrement client comportant le numéro du client,
 * son nom et prénom, son adresse (numéro, rue, ville et code postal). Votre programme doit
 * demander la saisie des informations d'un client puis afficher les informations.
 *
 * Les chaines de caractères n'excèderont pas 100 caractères.
 */

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100
typedef struct adresse
{
    int numero;
    char rue[MAX_CHAR];
    char ville[MAX_CHAR];
    char cpostal[MAX_CHAR];
} t_adresse;

typedef struct client
{
    int num;
    char nom[MAX_CHAR];
    char prenom[MAX_CHAR];
    t_adresse adresse;
} t_client;


int main() {

    t_client c1;

    //c1.adresse.numero = 10500;
    printf("Saisir les informations du client:\n");
    printf("Num: ");
    scanf("%d", &c1.num);
    getchar(); //Pour éliminer le retour à la ligne que scanf a laissé trainer dans la mémoire du clavier

    printf("Nom: ");
    fgets(c1.nom, MAX_CHAR, stdin );
    c1.nom[ strlen(c1.nom)-1  ] = '\0';
    printf("Prenom: ");
    fgets(c1.prenom, MAX_CHAR, stdin );
    c1.prenom[ strlen(c1.prenom)-1  ] = '\0';
    printf("Adresse:\n");
    printf("Num: ");
    scanf("%d", &c1.adresse.numero  );
    getchar();
    printf("Rue: ");
    fgets(c1.adresse.rue, MAX_CHAR, stdin);
    c1.adresse.rue[ strlen( c1.adresse.rue ) -1  ] = '\0';
    printf("Ville: ");
    fgets(c1.adresse.ville, MAX_CHAR, stdin);
    c1.adresse.ville[ strlen( c1.adresse.ville ) -1  ] = '\0';
    printf("Code postal: ");
    fgets(c1.adresse.cpostal, MAX_CHAR, stdin);
    c1.adresse.cpostal[ strlen( c1.adresse.cpostal ) -1  ] = '\0';


    //Affichage du client saisi:
    printf("\n\nInformations du client numero %d:\n", c1.num);
    printf("Nom et prénom: %s %s\n", c1.nom, c1.prenom);
    printf("Adresse: %d %s %s %s", c1.adresse.numero, c1.adresse.rue, c1.adresse.ville,
           c1.adresse.cpostal);


    return 0;
}
