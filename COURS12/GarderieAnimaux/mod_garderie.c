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
    if(g==NULL) return;
    for(int i=0; i<g->nb_animaux; i++)
    {
        free_personne(g->animaux[i]->proprietaire);
        //Met le propriétaire des tous les animaux subséquents qui ont
        //le même propriétaire à NULL
        for(int j=i+1; j<g->nb_animaux; j++)
        {
            if(g->animaux[j]->proprietaire == g->animaux[i]->proprietaire)
            {
                g->animaux[j]->proprietaire = NULL;
            }
        }
        free_animal(g->animaux[i]);
    }
    free(g->animaux);
    free(g);
}

void afficher_garderie(t_garderie* g)
{
    if(g==NULL) return;
    for(int i=0; i < g->nb_animaux; i++)
    {
        afficher_animal(g->animaux[i]);
    }
}

int garderie_ajouter_animal(t_garderie* g, const t_animal* a)
{
    if(g==NULL || a==NULL) return 0;
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
    if(g==NULL || indice<0 || indice>=g->nb_animaux)
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
    if(g==NULL || a==NULL) return -1;
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
    if(g==NULL || a==NULL) return NULL;
    position = garderie_chercher_animal(g, a);
    if(position == -1)
    {
        return NULL;
    }

    return garderie_retirer_animal(g, position);
}

int garderie_sauvegarder(const t_garderie* g, const char* nom_fichier)
{
    FILE* fichier = NULL;

    if(g==NULL) return 0;

    //Ouverture du fichier
    fichier=fopen(nom_fichier, "w");
    if(fichier==NULL) return 0;

    fprintf(fichier, "%d\n", g->nb_animaux);
    //Écriture des données dans le fichier
    for(int i=0; i<g->nb_animaux; i++){
        //Si la sauvegarde de l'animal ne fonctionne pas, on ferme le ficher
        //et on arrête en retournant faux
        if(! animal_sauvegarder(g->animaux[i], fichier) ){
            fclose(fichier);
            return 0;
        }
    }

    fclose(fichier);
    return 1;
}

t_garderie* garderie_charger(const char* nom_fichier){
    FILE* fichier;
    int nb_animaux;
    t_garderie* g = NULL;

    fichier = fopen(nom_fichier, "r");
    if(fichier==NULL) return NULL;

    g = init_garderie();

    fscanf(fichier, "%d ", &nb_animaux);
    for(int i=0; i<nb_animaux; i++)
    {
        t_animal* a = animal_charger(fichier);
        if(a == NULL)
        {
            free_garderie(g);
            fclose(fichier);
            return NULL;
        }
        if(! garderie_ajouter_animal(g, a) ){
            free_garderie(g);
            fclose(fichier);
            return NULL;
        }
    }

    fclose(fichier);
    return g;
}
