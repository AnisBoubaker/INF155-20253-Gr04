#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char caractere1 = 'A'+10;
    char caractere2 = 'z' - '0';

    printf("Le caractere1 contient: %c\n", caractere1);
    printf("Le caractere2 contient: %c\n", caractere2);


    int var1;
    char var2;

    var1 = 58;
    var2 = var1;

    printf("Var2 contient: %d\n", var2);


    return EXIT_SUCCESS;
}
