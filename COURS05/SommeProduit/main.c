#include <stdio.h>
#include <stdlib.h>

void somme_produit(int n, int* adr_somme, int* adr_produit);

int main() {

    int somme, produit;

    somme_produit(5, &somme, &produit);
    printf("La somme jusqu'a 5: %d, le produit: %d", somme, produit);

    return EXIT_SUCCESS;
}


void somme_produit(int n, int* adr_somme, int* adr_produit)
{
    *adr_somme = 0;
    *adr_produit = 1;

    for(int i=1; i<=n; i++)
    {
        *adr_somme += i;
        *adr_produit *= i;
    }

//    int somme = 0, produit = 1;
//
//    for(int i=1; i<=n ; i++)
//    {
//        somme += i;
//        produit*= i;
//    }
//
//    *adr_somme = somme;
//    *adr_produit = produit;
}