#include <stdio.h>

void cacher_caracteres(char phrase[], int t_phrase, const char a_cacher[], int t_a_cacher);

int main() {

    double dummy = -2343445545545453.56;
    char phrase[] = {'B','o','n','j','o','u','r',' ','t','o','u','t',' ','l','e',' ',
                   'm','o','n','d','e', '\0'};
    char cacher[] = {'o', 'j', 'l', 'n'};

//    for(int i=0; i<21; i++)
//    {
//        printf("%c", phrase[i]);
//    }
//    printf("\n");

    printf("%s\n", phrase);

    cacher_caracteres(phrase, 21, cacher, 4);

//    for(int i=0; i<21; i++)
//    {
//        printf("%c", phrase[i]);
//    }
//    printf("\n");

    printf("%s\n", phrase);

    return 0;
}

void cacher_caracteres(char phrase[], int t_phrase, const char a_cacher[], int t_a_cacher)
{
    for(int i=0; i < t_phrase; i++)
    {
        for(int j=0; j< t_a_cacher; j++)
        {
            if(phrase[i] == a_cacher[j])
            {
                phrase[i] = '*';
            }
        }
    }
}