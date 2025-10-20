#include <stdio.h>
#include <stdlib.h>

//Déclaration des prototypes
int v_abs(int x);
int min_de_3(int a, int b, int c);

int main() {

    printf("Le min: %d\n", min_de_3(32,2,18));
    printf("Le min: %d\n", min_de_3(30,-40,50));

    return EXIT_SUCCESS;
}

int v_abs(int x){
    return x<0 ? -x : x;
}

int min_de_3(int a, int b, int c)
{
    int min;

    //On passe a,b,c à leurs valeurs absolues.
    //On peut aussi utiliser la fonction abs
    a = a<0?-a:a;
    b = b<0?-b:b;
    c = v_abs(c);

    min = a;
    min = b<min?b:min;
    min = c<min?c:min;
//    if(b < min){
//        min = b;
//    }
//    if(c < min){
//        min = c;
//    }
    return min;
}