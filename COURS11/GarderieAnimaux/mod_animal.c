//
// Created by Anis Boubaker on 2025-11-27.
//

#include "mod_animal.h"

t_animal* init_animal( const char* nom,
                       const char* espece,
                       const char* race,
                       int annee_naiss, int mois_naiss, int jour_naiss,
                       const t_personne* proprietaire)
{
    t_animal* a;

    a = (t_animal*)malloc(sizeof(t_animal));
    if(a == NULL)
    {
        return NULL;
    }

    a->nom = (char*)malloc(sizeof(char)*(strlen(nom)+1));
    if(a->nom==NULL)
    {
        free(a);
        return NULL;
    }
    strcpy(a->nom, nom);
    strcpy(a->espece, espece);
    strcpy(a->race, race);
    a->date_naiss.jour = jour_naiss;
    a->date_naiss.mois = mois_naiss;
    a->date_naiss.annee = annee_naiss;

    a->proprietaire = proprietaire;


    return a;
}

void free_animal(t_animal* a)
{
    free(a->nom);
    free(a);
}

void afficher_animal(const t_animal* a)
{
    printf("Nom: %s, Espece: %s, Race: %s\n",
           a->nom, a->espece, a->race);
    printf("Date de naissance: %d-%d-%d\n",
           a->date_naiss.jour, a->date_naiss.mois, a->date_naiss.annee);
    printf("Proprietaire: ");
    afficher_personne(a->proprietaire);
    printf("\n-----------------------------------\n");
}
