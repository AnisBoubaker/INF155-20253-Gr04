#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE* fichier;
    char lecture[1000];

    fichier = fopen("../mon_fichier.txt", "r");
    if(fichier == NULL)
    {
        printf("Erreur d'ouverture du fichier..\n");
        exit(1);
    }


//    fgets(lecture, 1000, fichier);
//    printf("%s", lecture);
//    fgets(lecture, 1000, fichier);
//    printf("%s", lecture);

    while( fgets(lecture, 1000, fichier) )
    {
        printf("%s", lecture);
    }

    fclose(fichier);

    FILE* data;
    int ent1, ent2;
    double reel1;

    data = fopen("../data.txt", "r");
    if(data == NULL)
    {
        printf("Erreur d'ouverture du fichier..\n");
        exit(1);
    }

    fscanf(data,"%d %d %lf", &ent1, &ent2, &reel1);

    printf("Entier1: %d, Entier2: %d, Reel: %lf", ent1, ent2, reel1);

    fclose(data);


    char nom[100];
    char prenom[100];
    int age;
    FILE* personne;

    strcpy(nom, "Valjean");
    strcpy(prenom, "Jean");
    age = 55;

    personne = fopen("../personne.txt", "w");
    if(personne == NULL)
    {
        printf("Erreur d'ouverture du fichier..\n");
        exit(1);
    }

    fprintf(personne, "Bonjour je m'appelle %s %s et j'ai %d ans.\n",
            prenom, nom, age);

    fclose(personne);

    return 0;
}
