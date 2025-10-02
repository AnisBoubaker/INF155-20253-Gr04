#include <stdio.h>
#include <stdlib.h>


double calculer_moyenne(double tp1, double tp2, double quiz, double intra, double final)
{
    double moyenne = 0;
    moyenne += tp1 * 0.15;
    moyenne += tp2 * 0.15;
    moyenne += quiz * 0.15;
    moyenne += intra * 0.15;
    moyenne += final * 0.4;

    return moyenne;
}


int main(void) {

    printf("La moyenne est: %lf\n", calculer_moyenne(70.5, 80, 74, 72, 65));
    printf("La moyenne est: %lf\n", calculer_moyenne(80, 80, 80, 80, 80));


    return EXIT_SUCCESS;
}
