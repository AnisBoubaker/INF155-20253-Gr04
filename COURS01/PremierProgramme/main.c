/*
    Programme qui calcule le salaire d'un ou une employé-e.
    Auteur: Anis Boubaker
    Date: 2025-09-04
 */

#include <stdlib.h> //contient la constante EXIT_SUCCESS
#include <stdio.h>  //contient les fonctions printf et scanf

int main(void)
{
    //Déclaration de variables
    double taux_horaire;
    double nb_heures;
    double salaire;

    printf("Saisir le nombre d'heures: ");
    scanf("%lf", &nb_heures);

    printf("Saisie le taux horaire: ");
    scanf("%lf", &taux_horaire);

    salaire = nb_heures * taux_horaire;

    printf("Le salaire est de: %lf\n", salaire);

    return EXIT_SUCCESS;
}