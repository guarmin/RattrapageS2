#ifndef FONCTION_H
#define FONCTION_H

typedef struct
{
    char nom[70];
    char activite[20];
    int duree;
    int intensite;
    int calories;
} Seance;

int menu(void);
void ajouter_seance(Seance tab[], int *nb);
void supprimer_seance(Seance tab[], int *nb);
void afficher_seances(Seance tab[], int nb);
void maj_seances(Seance tab[], int nb);
void trie_temps(Seance tab[], int nb);
void trie_calories(Seance tab[], int nb);

#endif