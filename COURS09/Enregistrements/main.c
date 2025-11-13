#include <stdio.h>
#include <string.h>


#define MAX_CHAR 100
typedef struct etudiant
{
    char nom[MAX_CHAR];
    char prenom[MAX_CHAR];
    char cperm[MAX_CHAR];
    double tp1;
    double tp2;
    double intra;
    double final;
} t_etudiant;

typedef struct etudiant t_etudiant;

//Création de l'alias intp qui représente unsigned int
typedef unsigned int intp;


int main() {
    t_etudiant etudiant1;
    struct etudiant etudiant2;

    struct etudiant classe[100];

    intp val1;


    classe[5].tp1 = 80;

    etudiant1.tp1 = 85;
    etudiant1.tp2 = 90;
    etudiant1.intra = 78;
    etudiant1.final = 85;

    //etudiant1.nom = "Jacques"; PAS PERMIS!!!
    strcpy(etudiant1.nom, "Jacques");
    strcpy(etudiant1.prenom, "Marie");
    strcpy(etudiant1.cperm, "JACM67564534");

    printf("Informations de l'étudiant-e:\n");
    printf("Nom et prenom: %s %s\n", etudiant1.nom, etudiant1.prenom);
    printf("Code permanent: %s\n", etudiant1.cperm);
    printf("Notes: (TP1)%.2lf, (TP2)%.2lf, (Intra)%.2lf, (Final)%.2lf\n",
           etudiant1.tp1,etudiant1.tp2, etudiant1.intra, etudiant1.final);


    return 0;
}
