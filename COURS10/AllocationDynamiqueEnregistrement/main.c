#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 100
typedef struct etudiant{
    char nom[MAX_CHAR];
    char prenom[MAX_CHAR];
    char cperm[MAX_CHAR];
    double note_finale;
} t_etudiant;

int main() {
    t_etudiant et1;
    t_etudiant* et2 = NULL;

    et1.note_finale = 85;

    et2 = (t_etudiant*)malloc(sizeof(t_etudiant ));
    strcpy(et2->nom , "Valjean");
    strcpy(et2->prenom, "Jean");
    strcpy(et2->cperm, "VALJ56564534");
    et2->note_finale = 90;

    printf("L'etudiant %s %s (%s) a obtenu la note de : %.2lf\n",
           et2->prenom,
           et2->nom,
           et2->cperm,
           et2->note_finale);

    return 0;
}
