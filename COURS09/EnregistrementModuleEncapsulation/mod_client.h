//
// Created by Anis Boubaker on 2025-11-13.
//

#ifndef MOD_CLIENT__H
#define MOD_CLIENT__H

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
    t_adresse* adresse;
} t_client;


//Prototypes
void afficher_client(const t_client* un_client);
void saisir_client(t_client* un_client);



#endif //MOD_CLIENT_H
