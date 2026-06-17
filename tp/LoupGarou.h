#ifndef loups_garou_h
#define loups_garou_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nom[50];
    int role; // 0 = villageois 1 = loup-garou
    int vote;
    int vivant; // 1 = vivant 0 = mort
} Joueur;

int menu1();
int menu2();
void ajout_joueur(Joueur tab[], int *nb);
void role(Joueur tab[], int *nb);
void affichage_Vivant_Mort(Joueur tab[], int nb);
void Tour_Loups(Joueur tab[], int nb);
void Vote_village(Joueur tab[], int nb);
void Rapport(Joueur tab[], int nb);
void lancer_partie(Joueur tab[], int nb);

#endif