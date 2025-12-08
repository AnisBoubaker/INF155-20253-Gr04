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
    if(p==NULL) return;

    free(p->nom);
    free(p->prenom);
    free(p);
}

void afficher_personne(const t_personne* p)
{
    printf("%s %s (Tel: %s)",
           p->prenom, p->nom, p->telephone);
}

int personne_sauvegarder(const t_personne* p, FILE* fichier)
{
    if(p==NULL || fichier==NULL) return 0;

    fprintf(fichier, "%s\n%s\n%s\n",
            p->nom,
            p->prenom,
            p->telephone);

    return 1;
}

//Retourne NULL en cas d'erreur de chargement ou de création
//de la personne.
t_personne* personne_charger(FILE* fichier){
    char buffer_nom[1000];
    char buffer_prenom[1000];
    char buffer_tel[20];

    if(fichier==NULL) return 0;

    fgets(buffer_nom, 1000, fichier);
    buffer_nom[strlen(buffer_nom)-1] = '\0';
    fgets(buffer_prenom, 1000, fichier);
    buffer_prenom[strlen(buffer_prenom)-1] = '\0';
    fgets(buffer_tel, 20, fichier);
    buffer_tel[strlen(buffer_tel)-1] = '\0';

    return init_personne(buffer_nom, buffer_prenom, buffer_tel);
}