//
// Created by Anis Boubaker on 2025-11-13.
//

#include "mod_client.h"

void afficher_client(const t_client* un_client)
{
    printf("\n\nInformations du client numero %d:\n", un_client->num);
    printf("Nom et prénom: %s %s\n", un_client->nom, un_client->prenom);
    printf("Adresse: %d %s %s %s", un_client->adresse->numero, un_client->adresse->rue,
           un_client->adresse->ville,un_client->adresse->cpostal);
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
    scanf("%d", &un_client->adresse->numero  );
    getchar();
    printf("Rue: ");
    fgets(un_client->adresse->rue, MAX_CHAR, stdin);
    un_client->adresse->rue[ strlen( un_client->adresse->rue ) -1  ] = '\0';
    printf("Ville: ");
    fgets(un_client->adresse->ville, MAX_CHAR, stdin);
    un_client->adresse->ville[ strlen( un_client->adresse->ville ) -1  ] = '\0';
    printf("Code postal: ");
    fgets(un_client->adresse->cpostal, MAX_CHAR, stdin);
    un_client->adresse->cpostal[ strlen( un_client->adresse->cpostal ) -1  ] = '\0';
}