#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int annee_naissance, age;

    printf("Annee de naissance: ");
    scanf("%d", &annee_naissance);

    age = 2025 - annee_naissance;

    if( age >= 18)
    {
        if(age > 80)
        {
            printf("Vous ête vieux/vieille.\n");
        }
        else
        {
            printf("Vous ête majeur-e.\n");
        }
    }
    else
    {
        printf("Vous ête mineur-e.\n");
    }

    // MEILLEURE SOLUTION
//    if(age >= 80)
//    {
//        printf("Vous ête vieux/vieille.\n");
//    }
//    else if( age >= 18)
//    {
//        printf("Vous ête majeur-e.\n");
//    }
//    else
//    {
//        printf("Vous ête mineur-e.\n");
//    }

    // PREMIERE SOLUTION QUI MARCHE MAIS PAS IDEALE
//    if(age >= 80)
//    {
//        printf("Vous ête vieux/vieille.\n");
//    }
//    if( age >= 18 && age<80)
//    {
//        printf("Vous ête majeur-e.\n");
//    }
//    if( age < 18 )
//    {
//        printf("Vous ête mineur-e.\n");
//    }

//    if(age >= 18)
//    {
//        printf("Vous êtes majeur-e.\n");
//    }
//    else
//    {
//        printf("Vous êtes mineur-e.\n");
//    }

    return EXIT_SUCCESS;
}
