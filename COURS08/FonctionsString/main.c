#include <stdio.h>
#include <string.h>
#define TAILLE_MAX 100

int main() {

    char ch1[TAILLE_MAX] = "Bonjour";
    char ch2[TAILLE_MAX];


    // ch2 = ch1; //Interdit on ne peut pas affecter un tableau
    strcpy(ch2, ch1);
    printf("Contenu de chaine2: %s\n", ch2);

    strncpy(ch1, "Allo bonjour comment ça va?", TAILLE_MAX);
    printf("Contenu de chaine1: %s\n", ch1);

    //Concatener
    char prenom[TAILLE_MAX] = "Jean";
    char nom[TAILLE_MAX] = "Valjean";
    char nom_complet[TAILLE_MAX];

    strncpy(nom_complet, prenom, TAILLE_MAX);
    strcat(nom_complet, " ");
    strcat(nom_complet, nom);
    //Option avec sprintf:
    //sprintf(nom_complet, "%s %s", prenom, nom);
    printf("Le nom complet: %s\n", nom_complet);

    //Sprintf
    char personne[] = "Marie";
    int age = 22;
    char presentation[TAILLE_MAX] ;
    sprintf(presentation, "Bonjour, je m'appelle %s et j'ai %d ans.", personne, age);
    printf("Dans presentation: %s\n", presentation);


    //Comparaisons
    char chaine1[TAILLE_MAX] = "abcd";
    char chaine2[TAILLE_MAX] = "abcdx";

    if(strcmp(chaine1, chaine2)==0 )
    {
        printf("Les deux chaines sont identiques.\n");
    }
    else
    {
        printf("Les deux chaines sont differentes.\n");
    }

    return 0;
}
