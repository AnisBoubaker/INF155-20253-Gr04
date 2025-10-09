#include <stdio.h>
#include <stdlib.h>

#define POND_TP1 0.15
#define POND_TP2 0.15
#define POND_QUIZ 0.15
#define POND_INTRA 0.15
#define POND_FINAL 0.4


double calculer_moyenne(double tp1, double tp2, double quiz, double intra, double final)
{
    const double pond_tp1= 0.15;

    double moyenne = 0;
    moyenne += tp1 * POND_TP1; //Le précompilateur va le remplacer par moyenne += tp1 * 0.15;
    moyenne += tp2 * POND_TP2;
    moyenne += quiz * POND_QUIZ;
    moyenne += intra * POND_INTRA;
    moyenne += final * POND_FINAL;

    return moyenne;
}


int main(void) {

    printf("La moyenne est: %lf\n", calculer_moyenne(70.5, 80, 74, 72, 65));
    printf("La moyenne est: %lf\n", calculer_moyenne(80, 80, 80, 80, 80));


    return EXIT_SUCCESS;
}
