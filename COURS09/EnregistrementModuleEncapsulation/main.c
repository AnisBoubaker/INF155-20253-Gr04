/*
 * # Exercice 1
 * Écrire un programme qui déclare un enregistrement client comportant le numéro du client,
 * son nom et prénom, son adresse (numéro, rue, ville et code postal). Votre programme doit
 * demander la saisie des informations d'un client puis afficher les informations.
 *
 * Les chaines de caractères n'excèderont pas 100 caractères.
 */

#include <stdio.h>
#include <string.h>

#include "mod_client.h"

int main() {

    t_client c1;
    t_adresse adresse_c1;

    c1.adresse = & adresse_c1;

    //Changer le numero de la rue de c1 pour 10000
    c1.adresse->numero = 1000;
    //(*c1.adresse).numero = 10000;

    //c1.adresse.numero = 10500;

    saisir_client(&c1);

    //Affichage du client saisi:
    afficher_client(&c1);

    return 0;
}


