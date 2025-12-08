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

//Sauvegarde un animal dans le fichier dont on reçoit la référence
//Ça veut dire que le fichier est déjà ouvert, si on a la référence
int animal_sauvegarder(t_animal* a, FILE* fichier)
{
    if(a==NULL || fichier==NULL) return 0;

    fprintf(fichier, "%s\n%s\n%s\n%d %d %d\n",
            a->nom,
            a->espece,
            a->race,
            a->date_naiss.jour,
            a->date_naiss.mois,
            a->date_naiss.annee);
    //Si la sauvegarde de la personne ne fonctionne pas
    //on retourne faux
    if(! personne_sauvegarder(a->proprietaire, fichier))
    {
        return 0;
    }

    return 1;
}

t_animal* animal_charger(FILE* fichier){
    char buffer_nom[1000];
    char buffer_espece[100];
    char buffer_race[100];
    int jour, mois, annee;
    t_personne* proprietaire = NULL;

    if(fichier==NULL) return NULL;

    fgets(buffer_nom, 1000, fichier);
    buffer_nom[strlen(buffer_nom)-1] = '\0';
    fgets(buffer_espece, 100, fichier);
    buffer_espece[strlen(buffer_espece)-1] = '\0';
    fgets(buffer_race, 20, fichier);
    buffer_race[strlen(buffer_race)-1] = '\0';

    //Notez l'espace à la fin pour "consommer" le retour à la
    //ligne après l'année.
    fscanf(fichier, "%d %d %d ", &jour, &mois, &annee);

    proprietaire = personne_charger(fichier);

    if(proprietaire==NULL){
        return NULL;
    }

    return init_animal(buffer_nom, buffer_espece, buffer_race,
                       jour, mois, annee,
                       proprietaire);
}