#include <stdio.h>

#define NB_MAX_ETUD 60

double moyenne(double tab[], int taille);

int main() {
    int nb_notes;
    double notes[NB_MAX_ETUD];

    do {
        printf("Saisir le nombre de note: ");
        scanf("%d", &nb_notes);
    } while(nb_notes<1 || nb_notes>NB_MAX_ETUD);

    for(int i=0; i < nb_notes; i++)
    {
        printf("Saisir la note num. %d: ", i);
        scanf("%lf", &notes[i]);
    }
    //Afficher le tableau
    for(int i=0; i<nb_notes; i++)
    {
        printf("%.2lf, ", notes[i]);
    }
    printf("\n");

//    //Calcul de la moyenne
//    double moyenne = 0;
//    for(int i=0; i<nb_notes; i++)
//    {
//        moyenne += notes[i];
//    }
//    moyenne /= nb_notes;
//
//    printf("La moyenne des notes est: %.2lf\n", moyenne);

    printf("La moyenne: %.2lf\n", moyenne(notes , nb_notes) );



    return 0;
}

double moyenne(double tab[], int taille)
{
    double somme = 0;
    for(int i=0; i<taille; i++)
    {
        somme += tab[i];
    }
    return somme / taille;
}

double max_tab(double tab[], int taille)
{
    double maximum = tab[0];

    for(int i=1; i<taille; i++)
    {
        if(maximum < tab[i]){
            maximum = tab[i];
        }
    }
    return maximum;
}


int indice_max(double tab[], int taille)
{
    double max = tab[0];
    int indice = 0;

    for(int i=1; i<taille; i++)
    {
        if(max < tab[i]){
            max = tab[i];
            indice = i;
        }
    }

    return indice;
}










