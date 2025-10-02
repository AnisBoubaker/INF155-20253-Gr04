#include <stdio.h>


int factorielle(int n)
{
    int fact = 1;
    int i;
    for(i=1; i<=n; i++)
    {
        fact *= i;
    }

    return fact;
}




int main() {

    int n=10;
    int k=3;

    int fact_n;
    int fact_k;
    int fact_n_k;
    int combinaisons;

    //combinaisons = factorielle(n) / (factorielle(k) * factorielle(n-k));
    fact_n = factorielle(n);
    fact_k = factorielle(k);
    fact_n_k = factorielle(n - k);
    combinaisons = fact_n / (fact_k * fact_n_k);
    printf("Le nombre de combinaisons de %d parmi %d est: %d\n", k, n, combinaisons);


//    for(int i=1; i<n; i++)
//    {
//        fact_n *= i;
//    }
//
//    for(int i=1; i<k; i++)
//    {
//        fact_k *= i;
//    }
//
//    for(int i=1; i<n-k; i++)
//    {
//        fact_n_k *= i;
//    }
//    combinaisons = fact_n / (fact_k * fact_n_k);
//    printf("Le nombre de combinaisons de %d parmi %d est: %d\n", k, n, combinaisons);


    return 0;
}
