#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personne{
    char* nom;
    char* prenom;
    char telephone[20];
} t_personne;

typedef struct date{
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct animal{
    char* nom;
    char espece[100];
    char race[100];
    t_date date_naiss;
    t_personne proprietaire;
} t_animal;

int main() {

    t_personne p1;
    t_animal* a1 = NULL;

    p1.nom = (char*)malloc(sizeof(char)*(strlen("Boulanger")+1));
    strcpy(p1.nom,  "Boulanger");
    p1.prenom = (char*)malloc(sizeof(char)*(strlen("Romy")+1));
    strcpy(p1.prenom, "Romy");
    strcpy(p1.telephone, "514-786-7867");
    //printf("%s %s (Tel: %s)\n", p1.prenom, p1.nom, p1.telephone);

    a1 = (t_animal*)malloc(sizeof(t_animal));

    a1->nom = (char*)malloc(sizeof(char)*(strlen("Choupi")+1));
    strcpy(a1->nom, "Choupi");
    strcpy(a1->espece, "Chien");
    strcpy(a1->race, "Golden");

    a1->date_naiss.annee = 2021;
    a1->date_naiss.mois = 1;
    a1->date_naiss.jour = 20;

    a1->proprietaire = p1;

    printf("Nom: %s, Espece: %s, Race: %s\n",
           a1->nom, a1->espece, a1->race);
    printf("Date de naissance: %d-%d-%d\n",
           a1->date_naiss.jour, a1->date_naiss.mois, a1->date_naiss.annee);
    printf("Propietaire: %s %s (Tel: %s)\n",
           a1->proprietaire.prenom, a1->proprietaire.nom, a1->proprietaire.telephone);

    return 0;
}
