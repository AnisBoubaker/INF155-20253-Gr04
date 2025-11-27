#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mod_personne.h"

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
    t_personne* proprietaire;
} t_animal;

int main() {

    t_personne* p1;

    p1 = init_personne("Boulanger", "Romy", "514-786-4523");

    afficher_personne(p1);

    free_personne(p1);

    return 0;
}
