//
// Created by Anis Boubaker on 2025-11-27.
//

#include "mod_personne.h"

t_personne* init_personne(const char* nom, const char* prenom, const char* telephone)
{
    t_personne* p;

    p = (t_personne*)malloc(sizeof(t_personne));
    if(p == NULL)
    {
        return NULL;
    }
    p->nom = (char*)malloc(sizeof(char)*(strlen(nom)+1));
    if(p->nom==NULL)
    {
        free(p);
        return NULL;
    }
    strcpy(p->nom, nom);

    p->prenom = (char*)malloc(sizeof(char)*(strlen(prenom)+1));
    if(p->prenom == NULL)
    {
        free(p->nom);
        free(p);
        return NULL;
    }
    strcpy(p->prenom, prenom);

    strcpy(p->telephone, telephone);

    return p;
}

void free_personne(t_personne* p)
{
    free(p->nom);
    free(p->prenom);
    free(p);
}

void afficher_personne(const t_personne* p)
{
    printf("%s %s (Tel: %s)",
           p->prenom, p->nom, p->telephone);
}