//
// Created by Anis Boubaker on 2025-11-27.
//

#ifndef GARDERIEANIMAUX_MOD_PERSONNE_H
#define GARDERIEANIMAUX_MOD_PERSONNE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct personne{
    char* nom;
    char* prenom;
    char telephone[20];
} t_personne;

//Constructeur d'une personne
t_personne* init_personne(const char* nom, const char* prenom, const char* telephone);

//Destructeur d'une personne
void free_personne(t_personne* p);

void afficher_personne(const t_personne* p);

int personne_sauvegarder(const t_personne* p, FILE* fichier);
t_personne* personne_charger(FILE* fichier);

#endif //GARDERIEANIMAUX_MOD_PERSONNE_H
