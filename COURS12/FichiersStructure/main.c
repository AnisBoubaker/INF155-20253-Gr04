#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct date{
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct personne{
    char nom[100];
    char prenom[100];
    t_date naiss;
} t_personne;


int main() {
    t_personne jean;
    FILE* personne;

    strcpy(jean.nom, "Valjean");
    strcpy(jean.prenom, "Jean");
    jean.naiss.jour = 10;
    jean.naiss.mois = 3;
    jean.naiss.annee = 1745;

    personne = fopen("../personne.txt", "w");
    if(personne == NULL)
    {
        printf("Erreur d'ouverture.");
        exit(1);
    }

    fprintf(personne, "%s\n%s\n%d %d %d\n",
            jean.nom, jean.prenom,
            jean.naiss.jour, jean.naiss.mois, jean.naiss.annee);

    fclose(personne);

    t_personne copie_jean;

    personne = fopen("../personne.txt", "r");
    if(personne == NULL)
    {
        printf("Erreur d'ouverture.");
        exit(1);
    }

    fgets(copie_jean.nom, 100, personne);
    copie_jean.nom[ strlen(copie_jean.nom) -1  ] = '\0';
    fgets(copie_jean.prenom, 100, personne);
    copie_jean.prenom[ strlen(copie_jean.prenom) -1  ] = '\0';
    fscanf(personne, "%d %d %d", &copie_jean.naiss.jour,
           &copie_jean.naiss.mois, &copie_jean.naiss.annee);

    printf("Nom: %s, Prenom: %s, Date de naissance: %d-%d-%d\n",
           copie_jean.nom, copie_jean.prenom,
           copie_jean.naiss.jour, copie_jean.naiss.mois, copie_jean.naiss.annee);

    return 0;
}
