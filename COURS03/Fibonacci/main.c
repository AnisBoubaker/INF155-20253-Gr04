#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int terme_voulu;
    int fib_n, fib_n_1, fib_n_2;
    do {
        printf("Terme voulu: ");
        scanf("%d", &terme_voulu);
    } while(terme_voulu <0);

    fib_n_2 = 1;
    fib_n_1 = 1;
    fib_n=1;
    for(int i=2; i<=terme_voulu; i++)
    {
        fib_n = fib_n_2 + fib_n_1;
        //Préparation de la prochaine itération
        fib_n_2 = fib_n_1;
        fib_n_1 = fib_n;
    }

    printf("La valeur du terme %d est %d.\n", terme_voulu, fib_n);

    return EXIT_SUCCESS;
}
