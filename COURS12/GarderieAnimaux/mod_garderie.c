//
// Created by Anis Boubaker on 2025-11-27.
//

#include "mod_garderie.h"

//Déclaration des fonctions privées
static int garderie_chercher_animal(const t_garderie* g, const t_animal* a);


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

int garderie_ajouter_animal(t_garderie* g, const t_animal* a)
{
    if(g->nb_animaux == g->taille_max){ //Tableau plein => Agrandir
        t_animal** adresse_tmp;
        adresse_tmp = realloc(g->animaux, sizeof(t_animal*)*(g->taille_max+TAILLE_INCREMENT));
        if(adresse_tmp == NULL)
        {
            return 0;
        }
        g->animaux = adresse_tmp;
        g->taille_max += TAILLE_INCREMENT;
    }

    g->animaux[ g->nb_animaux ] = a;
    g->nb_animaux ++;
    return 1;
}

t_animal* garderie_retirer_animal(t_garderie* g, int indice)
{
    t_animal* animal_retire;
    if(indice<0 || indice>=g->nb_animaux)
    {
        return NULL;
    }
    animal_retire = g->animaux[indice];

    for(int i=indice; i<g->nb_animaux - 1; i++)
    {
        g->animaux[i] = g->animaux[i+1];
    }
    g->nb_animaux --;
    return animal_retire;
}

static int garderie_chercher_animal(const t_garderie* g, const t_animal* a){
    for(int i=0; i<g->nb_animaux; i++)
    {
        if(g->animaux[i] == a){
            return i;
        }
    }
    return -1;
}

t_animal* garderie_retirer_animal_ref(t_garderie* g, const t_animal* a){
    int position;

    position = garderie_chercher_animal(g, a);
    if(position == -1)
    {
        return NULL;
    }

    return garderie_retirer_animal(g, position);
}


