#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double x, y;
    int cadran;

    printf("Abscisse (x): ");
    scanf("%lf", &x);
    printf("Ordonnee (y): ");
    scanf("%lf", &y);

    if(x==0 || y==0){
        printf("Vous etes sur l'axe.\n");
        cadran = 0;
    }
    else if(x > 0)
    {
        if(y>0){
            cadran = 1;
        } else  {
            cadran = 2;
        }
    } else {
        if(y>0){
            cadran = 4;
        }else  {
            cadran = 3;
        }
    }

    if(cadran){
        printf("Vous etes situe-e sur le cadran num. %d\n", cadran);
    }



    return EXIT_SUCCESS;
}
