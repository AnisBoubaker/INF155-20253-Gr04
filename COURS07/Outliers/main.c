#include <stdio.h>
#include <math.h>

#define MAX_COLS 10

int ecarttype_tab(const double data[][MAX_COLS], int nb_lignes, int nb_colonnes);
double moyenne_tab(const double tab[][MAX_COLS], int nb_lignes, int nb_colonnes);
int outliers(double data[][MAX_COLS], int nb_lignes, int nb_colonnes, double etype);
void ma_fonction(int a, int b);
void tab_positif(int tab[], int taille);

int main() {
    double donnees[10][MAX_COLS] = {
            {20.5, 25, 32, 18},
            {345, 20, 28, 29},
            {0, 19, 21, 25}
    };

    printf("La moyenne: %.2lf\n", moyenne_tab(donnees, 3, 4));
    double etype = ecarttype_tab(donnees, 3, 4);
    printf("L'ecart type: %.2lf\n", etype);

    printf("Nombre de valeurs aberrantes: %d\n", outliers(donnees, 3, 4, etype));

    int val1 = -100, val2 = 30;
    ma_fonction(val1, val2);

    int tab_1d[10] = {10, 20, -30, 40, -50, 60};
    tab_positif(tab_1d, 6);

    for(int i=0; i<6; i++){
        printf("%d, ", tab_1d[i]);
    }
    printf("\n");

    return 0;
}

void ma_fonction(int a, int b)
{
    if(a < 0){
        a = 0;
    }
}
void tab_positif(int tab[], int taille)
{
    for(int i=0; i<taille; i++)
    {
        if(tab[i] < 0){
            tab[i] = 0;
        }
    }
}



double moyenne_tab(const double tab[][MAX_COLS], int nb_lignes, int nb_colonnes)
{
    double somme = 0 ;
    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            somme += tab[i][j];
            tab[i][j]=0;
        }
    }
    return somme / (nb_lignes*nb_colonnes);
}

//Fonctionb qui compte le nombre de données aberrantes et met leurs valeurs à la moyenne.
int outliers(double data[][MAX_COLS], int nb_lignes, int nb_colonnes, double etype)
{
    double moyenne = moyenne_tab(data, nb_lignes, nb_colonnes);
    int compteur = 0;

    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            if( data[i][j] < moyenne-3*etype || data[i][j]>moyenne+3*etype)
            {
                compteur++;
                data[i][j] = moyenne;
            }
        }
    }
    return compteur;
}

int ecarttype_tab(const double data[][MAX_COLS], int nb_lignes, int nb_colonnes)
{
    double variance = 0;
    double moyenne = moyenne_tab(data, nb_lignes, nb_colonnes);

    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            variance += pow(data[i][j]-moyenne, 2);
        }
    }
    variance = variance / (nb_lignes*nb_colonnes);
    return sqrt(variance);
}