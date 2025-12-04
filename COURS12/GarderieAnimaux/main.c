#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mod_personne.h"
#include "mod_animal.h"


int main() {

    t_personne* romy;
    t_personne* jon;

    t_animal* a1;
    t_animal* a2;
    t_animal* a3;

    romy = init_personne("Boulanger", "Romy", "514-786-4523");
    jon = init_personne("Snow", "Jon", "514-898-5623");

    a1 = init_animal("Choupi", "Chien", "Golden", 2021,1,20,romy);
    a2 = init_animal("Ghost", "Loup", "Direwolf", 1978,10,21, jon);
    a3 = init_animal("Toutou", "Chat", "Persan", 2023, 6,10, romy);

    afficher_animal(a1);
    afficher_animal(a2);
    afficher_animal(a3);

    return 0;
}
