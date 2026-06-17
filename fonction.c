#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int menu()
{
    printf("\n===== CARNET DE SUIVI SPORTIF =====\n\n");
    printf("1. Ajouter une seance \n");
    printf("2. Supprimer une seance \n");
    printf("3. Afficher les seances \n");
    printf("4. Mettre a jour toutes les seances \n");
    printf("5. Trier les seances par duree \n");
    printf("6. Trier les seances par calories \n");
    printf("7. Quitter \n");

    int choix;
    printf("\nVotre choix : ");
    scanf("%d", &choix);

    return choix;
}

void ajouter_seance(Seance tab[], int *nb)
{
    if (*nb >= 100)
    {
        printf("Le carnet est plein, impossible d'ajouter une nouvelle seance.\n");
        return;
    }

    Seance s;

    printf("Nom de la seance ( !! priviligie des _ au lieu des espaces sinon le programme bug !!): ");
    scanf("%s", &s.nom);

    printf("\nType d'activite (course / velo / musculation) : ");
    scanf("%s", &s.activite);

    printf("\nDuree de la seance en minutes : ");
    scanf("%d", &s.duree);

    printf("\nIntensite de depart : ");
    scanf("%d", &s.intensite);

    printf("\nCalories estimes: ");
    scanf("%d", &s.calories);

    tab[*nb] = s;
    (*nb)++;

    printf("Seance ajoutee avec succes\n");
}

void supprimer_seance(Seance tab[], int *nb)
{
    char nom[50];
    printf("Nom de la seance a supprimer : ");
    scanf("%s", nom);

    int i;
    int trouve = -1;

    for (i = 0; i < *nb; i++)
    {
        if (strcmp(tab[i].nom, nom) == 0)
        {
            trouve = i;
            break;
        }
    }

    if (trouve == -1)
    {
        printf("Seance non trouvee.\n");
        return;
    }

    for (i = trouve; i < *nb - 1; i++)
    {
        tab[i] = tab[i + 1];
    }

    (*nb)--;
    printf("Seance supprimee avec succes.\n");
}

void afficher_seances(Seance tab[], int nb)
{
    printf("\n==== LISTE DES SEANCES ====\n\n");
    if (nb == 0)
    {
        printf("Aucune seance enregistree.\n");
        return;
    }

    for (int i = 0; i < nb; i++)
    {
        printf("\nSeance %d :\n", i + 1);
        printf("  Nom       : %s\n", tab[i].nom);
        printf("  Activite  : %s\n", tab[i].activite);
        printf("  Duree     : %d min\n", tab[i].duree);
        printf("  Intensite : %d\n", tab[i].intensite);
        printf("  Calories  : %d\n", tab[i].calories);
    }
}

void maj_seances(Seance tab[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        if (strcmp(tab[i].activite, "course") == 0)
        {
            tab[i].calories += 50;
        }
        else if (strcmp(tab[i].activite, "musculation") == 0)
        {
            tab[i].intensite += 1;
        }
        else if (strcmp(tab[i].activite, "velo") == 0)
        {
            tab[i].calories += 30;
            tab[i].intensite += 1;
        }
    }

    printf("Toutes les seances ont ete mises a jour.\n");
}

void trie_temps(Seance tab[], int nb)
{
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = 0; j < nb - 1 - i; j++)
        {
            if (tab[j].duree > tab[j + 1].duree)
            {
                Seance temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    printf("Seances triees par duree.\n");
}

void trie_calories(Seance tab[], int nb)
{
    /*tri a bulle des seances en fonction de calories ( manque de temps)*/
    printf("\n \n trie calorique non disponible\n");
}