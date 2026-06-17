#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LoupGarou.h"

int menu1()
{
    printf("\n ===== LOUP GAROU ===== \n\n");
    printf("1. Ajouter des joueurs \n");
    printf("2. Ajout Loup-Garou\n");
    printf("3. Lancer la partie\n");
    printf("4. Quitter\n");

    int choix;
    printf("\n Votre choix :\n");
    scanf("%d", &choix);

    return choix;
}

int menu2()
{
    printf("\n ===== TOUR DE JEU ===== \n\n");
    printf("1. Lancer le tour de nuit (les loups attaquent)\n");
    printf("2. Lancer le vote du village (jour)\n");
    printf("3. Quitter la partie\n");

    int choix;
    printf("\nVotre choix : ");
    scanf("%d", &choix);

    return choix;
}

void ajout_joueur(Joueur tab[], int *nb)
{
    if (*nb >= 30)
    {
        printf("Nombre maximum de joueurs atteint.\n");
        return;
    }

    printf("Nom du joueur : ");
    scanf("%s", tab[*nb].nom);
    tab[*nb].vivant = 1;
    tab[*nb].role = 0;

    (*nb)++;
    printf("Joueur ajoute. Total : %d joueur(s).\n", *nb);
}

void role(Joueur tab[], int *nb)
{
    int nb_loups;

    do
    {
        printf("\n Combien voulez-vous de loup-garou ?\n(superieur ou egal a 1 et inferieur au nombre de joueurs) : ");
        scanf("%d", &nb_loups);
    } while (nb_loups < 1 || nb_loups >= *nb);

    int attribues = 0;
    while (attribues < nb_loups)
    {
        int index = rand() % (*nb);
        if (tab[index].role == 0)
        {
            tab[index].role = 1;
            attribues++;
        }
    }

    printf("\nLes roles ont ete attribues secretement.\n");
}

void affichage_Vivant_Mort(Joueur tab[], int nb)
{
    printf("\n===== JOUEURS VIVANTS =====\n");
    for (int i = 0; i < nb; i++)
    {
        if (tab[i].vivant == 1)
        {
            printf("- %s\n", tab[i].nom);
        }
    }
}

void Tour_Loups(Joueur tab[], int nb)
{
    int villageois_vivants[30];
    int compteur = 0;

    for (int i = 0; i < nb; i++)
    {
        if (tab[i].role == 0 && tab[i].vivant == 1)
        {
            villageois_vivants[compteur] = i;
            compteur++;
        }
    }

    if (compteur == 0)
    {
        printf("\nIl ne reste plus aucun villageois a eliminer.\n");
        return;
    }

    int tirage = rand() % compteur;
    int victime = villageois_vivants[tirage];

    tab[victime].vivant = 0;

    printf("\nLes loups-garous ont frappe cette nuit...\n");
    printf("%s a ete devore !\n", tab[victime].nom);
}
void Vote_village(Joueur tab[], int nb)
{
    char nom[50];
    printf("\nQuel joueur le village decide-t-il d'eliminer ? ");
    scanf("%s", nom);

    int trouve = -1;
    for (int i = 0; i < nb; i++)
    {
        if (strcmp(tab[i].nom, nom) == 0 && tab[i].vivant == 1)
        {
            trouve = i;
            break;
        }
    }

    if (trouve == -1)
    {
        printf("Joueur invalide ou deja mort.\n");
        return;
    }

    tab[trouve].vivant = 0;

    if (tab[trouve].role == 1)
    {
        printf("%s etait un loup-garou ! Bien joue.\n", tab[trouve].nom);
    }
    else
    {
        printf("%s etait un simple villageois...\n", tab[trouve].nom);
    }
}

void Rapport(Joueur tab[], int nb)
{
    int loups_vivants = 0, loups_total = 0;
    int villageois_vivants = 0, villageois_total = 0;

    for (int i = 0; i < nb; i++)
    {
        if (tab[i].role == 1)
        {
            loups_total++;
            if (tab[i].vivant == 1)
                loups_vivants++;
        }
        else
        {
            villageois_total++;
            if (tab[i].vivant == 1)
                villageois_vivants++;
        }
    }

    printf("\n===== RAPPORT DE LA PARTIE =====\n");
    printf("Loups-garous : %d vivant(s) sur %d\n", loups_vivants, loups_total);
    printf("Villageois   : %d vivant(s) sur %d\n", villageois_vivants, villageois_total);
    printf("\nDetail des joueurs :\n");

    for (int i = 0; i < nb; i++)
    {
        printf("- %s : %s", tab[i].nom, tab[i].vivant ? "vivant" : "mort");
        if (tab[i].vivant == 0)
        {
            printf(" (%s)", tab[i].role == 1 ? "loup-garou" : "villageois");
        }
        printf("\n");
    }

    if (loups_vivants == 0)
    {
        printf("\n>>> Les villageois ont gagne la partie ! <<<\n");
    }
    else if (villageois_vivants == 0)
    {
        printf("\n>>> Les loups-garous ont gagne la partie ! <<<\n");
    }
}

void lancer_partie(Joueur tab[], int nb)
{
    if (nb < 4)
    {
        printf("\nIl faut au moins 4 joueurs pour lancer la partie.\n");
        return;
    }

    role(tab, &nb);

    int choix;
    while (1)
    {
        choix = menu2();

        if (choix == 1)
        {
            Tour_Loups(tab, nb);
            affichage_Vivant_Mort(tab, nb);
        }
        else if (choix == 2)
        {
            Vote_village(tab, nb);
            Rapport(tab, nb);
        }
        else if (choix == 3)
        {
            printf("Fin de la partie.\n");
            break;
        }
        else
        {
            printf("Choix invalide.\n");
        }
    }
}