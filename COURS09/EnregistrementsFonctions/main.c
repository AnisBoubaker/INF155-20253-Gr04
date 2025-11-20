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

//Prototypes
void afficher_client(const t_client* un_client);
void saisir_client(t_client* un_client);


int main() {

    t_client c1;


    //c1.adresse.numero = 10500;

    saisir_client(&c1);

    //Affichage du client saisi:
    afficher_client(&c1);

    return 0;
}


void afficher_client(const t_client* un_client)
{
    printf("\n\nInformations du client numero %d:\n", un_client->num);
    printf("Nom et prénom: %s %s\n", un_client->nom, un_client->prenom);
    printf("Adresse: %d %s %s %s", un_client->adresse.numero, un_client->adresse.rue,
           un_client->adresse.ville,un_client->adresse.cpostal);
}

void saisir_client(t_client* un_client)
{
    printf("Saisir les informations du client:\n");
    printf("Num: ");
    scanf("%d", &(*un_client).num);
    getchar(); //Pour éliminer le retour à la ligne que scanf a laissé trainer dans la mémoire du clavier

    printf("Nom: ");
    fgets((*un_client).nom, MAX_CHAR, stdin );
    (*un_client).nom[ strlen((*un_client).nom)-1  ] = '\0';
    printf("Prenom: ");
    fgets(un_client->prenom, MAX_CHAR, stdin );
    un_client->prenom[ strlen(un_client->prenom)-1  ] = '\0';
    printf("Adresse:\n");
    printf("Num: ");
    scanf("%d", &un_client->adresse.numero  );
    getchar();
    printf("Rue: ");
    fgets(un_client->adresse.rue, MAX_CHAR, stdin);
    un_client->adresse.rue[ strlen( un_client->adresse.rue ) -1  ] = '\0';
    printf("Ville: ");
    fgets(un_client->adresse.ville, MAX_CHAR, stdin);
    un_client->adresse.ville[ strlen( un_client->adresse.ville ) -1  ] = '\0';
    printf("Code postal: ");
    fgets(un_client->adresse.cpostal, MAX_CHAR, stdin);
    un_client->adresse.cpostal[ strlen( un_client->adresse.cpostal ) -1  ] = '\0';
}