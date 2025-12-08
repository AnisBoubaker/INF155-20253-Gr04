#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mod_personne.h"
#include "mod_animal.h"
#include "mod_garderie.h"


int main() {

    t_personne* romy;
    t_personne* jon;

    t_animal* a1;
    t_animal* a2;
    t_animal* a3;

    t_garderie* ma_garderie;

    romy = init_personne("Boulanger", "Romy", "514-786-4523");
    jon = init_personne("Snow", "Jon", "514-898-5623");

    a1 = init_animal("Choupi", "Chien", "Golden", 2021,1,20,romy);
    a2 = init_animal("Ghost", "Loup", "Direwolf", 1978,10,21, jon);
    a3 = init_animal("Toutou", "Chat", "Persan", 2023, 6,10, romy);

    ma_garderie = init_garderie();

    garderie_ajouter_animal(ma_garderie, a1);
    garderie_ajouter_animal(ma_garderie, a2);
    garderie_ajouter_animal(ma_garderie, a3);

    afficher_garderie(ma_garderie);

//    printf("\n******************\n APRES SUPPRESSION \n******************\n");
//
//    garderie_retirer_animal(ma_garderie, ma_garderie->nb_animaux-1);
//
//    afficher_garderie(ma_garderie);

    t_animal* a4 = init_animal("Toutou", "Chat", "Persan", 2023, 6,10, romy);

//    int position;
//
//
//
//    position = garderie_chercher_animal(ma_garderie, a4);
//    printf("L'animal se trouve a la position: %d\n", position);

    printf("\n******************\n APRES SUPPRESSION \n******************\n");

    garderie_retirer_animal_ref(ma_garderie, a4);
    afficher_garderie(ma_garderie);

    //Sauvegarde
    if( garderie_sauvegarder(ma_garderie, "../ma_garderie.txt") ){
        printf("Sauvegarde réussie.\n");
    } else {
        printf("Erreur lors de la sauvegarde de la garderie.\n");
    }

    //Chargement et affichage de la garderie
    t_garderie* garderie_chargee = NULL;

    garderie_chargee = garderie_charger("../ma_garderie.txt");
    if(garderie_chargee==NULL){
        printf("Erreur de chargement de la garderie.\n");
        exit(1);
    }

    printf("======== AFFICHAGE DE LA GARDERIE CHARGEE ==========\n");
    afficher_garderie(garderie_chargee);

    free_garderie(ma_garderie);
    free_garderie(garderie_chargee);

    return 0;
}
