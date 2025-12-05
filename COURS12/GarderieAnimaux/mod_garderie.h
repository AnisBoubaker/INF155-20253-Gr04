//
// Created by Anis Boubaker on 2025-11-27.
//

#ifndef GARDERIEANIMAUX_MOD_GARDERIE_H
#define GARDERIEANIMAUX_MOD_GARDERIE_H

#include "mod_animal.h"

#define TAILLE_INCREMENT 10

typedef struct garderie{
    t_animal** animaux; //Tableau 1D de références (pointeurs) vers des t_animal
    int nb_animaux; //taille effective du tableau animaux
    int taille_max; //Taille maximale actuelle du tableau d'animaux
} t_garderie;


t_garderie* init_garderie(void);

void afficher_garderie(t_garderie* g);

int garderie_ajouter_animal(t_garderie* g, const t_animal* a);

t_animal* garderie_retirer_animal(t_garderie* g, int indice);



t_animal* garderie_retirer_animal_ref(t_garderie* g, const t_animal* a);


#endif //GARDERIEANIMAUX_MOD_GARDERIE_H
