//
// Created by Anis Boubaker on 2025-11-27.
//

#include "mod_garderie.h"

t_garderie* init_garderie(void)
{
    t_garderie* g;

    g = (t_garderie*)malloc(sizeof(t_garderie));
    if(g == NULL)
    {
        return NULL;
    }

    g->animaux = (t_animal**)malloc(sizeof(t_animal*)*TAILLE_INCREMENT);
    if(g->animaux == NULL)
    {
        free(g);
        return NULL;
    }

    g->nb_animaux = 0;
    g->taille_max = TAILLE_INCREMENT;

    return g;
}

//Libérer l'espace d'une garderie, incluant l'espace occupé par
//tous les animaux qu'elle contient
void free_garderie(t_garderie* g)
{
    for(int i=0; i<g->nb_animaux; i++)
    {
        free_animal(g->animaux[i]);
    }
    free(g->animaux);
    free(g);
}

void afficher_garderie(t_garderie* g)
{
    for(int i=0; i < g->nb_animaux; i++)
    {
        afficher_animal(g->animaux[i]);
    }
}