#include <stdio.h>
#include <stdlib.h>

//Déclaration des prototypes
void min_max_de_3(int a, int b, int c, int* adr_min, int* adr_max);

int main() {

    int min, max;

    min_max_de_3(50, -12, 38, &min, &max);

    printf("Min=%d, Max = %d\n", min, max);

    return EXIT_SUCCESS;
}

void min_max_de_3(int a, int b, int c, int* adr_min, int* adr_max)
{
    int min;
    int max;

    min = a;
    min = b<min?b:min;
    min = c<min?c:min;

    max = a;
    max = b>max ? b : max;
    max = c>max ? c : max;

    *adr_min = min;
    *adr_max = max;

}