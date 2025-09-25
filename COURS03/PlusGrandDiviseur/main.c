#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n, div;

    printf("Saisir un nombre (n): ");
    scanf("%d", &n);
    do {
        printf("Saisir un diviseur (div): ");
        scanf("%d", &div);
    } while( div ==0 );

    while (n % div != 0)
    {
        n--;
    }

    printf("Le resultat est: %d\n", n);

    return EXIT_SUCCESS;
}
