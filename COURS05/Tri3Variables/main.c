#include <stdio.h>

void trier_variables(int* var1, int* var2, int* var3);
void swap(int* var1, int* var2);

int main() {
    int a = 12;
    int b = 5;
    int c = 7;

    trier_variables(&a, &b, &c);

    printf("a= %d, b=%d, c=%d\n", a,b,c);

    return 0;
}

void swap(int* var1, int* var2){
    int tmp;
    tmp = *var1;
    *var1 = *var2;
    *var2 = tmp;
}
void trier_variables(int* var1, int* var2, int* var3)
{
    int tmp;
    for(int i=0; i<2; i++){
        if(*var1 > *var2)
        { //Intervertir le contenu de ce qui se trouve à *var1 et *var2
            swap(var1, var2);
        }
        if(*var2 > *var3){
            swap(var2, var3);
        }
    }
}
