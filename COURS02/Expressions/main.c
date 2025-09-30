#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a;
    int b;
    double resultat;

    a = 10;
    b = 3;

    //resultat = (double)a / b;
    resultat = a*1.0 / b;

    printf("Resultat = %lf\n", resultat);

    int resultat_modulo;
    resultat_modulo = a % b;
    printf("Resultat du modulo = %d\n", resultat_modulo);

    int x;
    int y;

    x = 11;
    y = ++x / 3;
    printf("Valeur de y: %d\n", y);
    printf("Valeur de x: %d\n", x);



    return EXIT_SUCCESS;
}
