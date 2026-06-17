#include <stdio.h>
#include "fonction.h"

int main(void)
{
    Seance carnet[100]; /* ajout d'un max total de 100 séances */
    int nb = 0;         /* nb = nombre pour le nombre de la séance*/
    int choix;

    while (1) // sinon le menu s'affiche qu'une fois jsp pk mais avec ca ca marche
    {
        choix = menu();

        if (choix == 1)
        {
            ajouter_seance(carnet, &nb);
        }
        else if (choix == 2)
        {
            supprimer_seance(carnet, &nb);
        }
        else if (choix == 3)
        {
            afficher_seances(carnet, nb);
        }
        else if (choix == 4)
        {
            maj_seances(carnet, nb);
        }
        else if (choix == 5)
        {
            trie_temps(carnet, nb);
        }
        else if (choix == 6)
        {
            trie_calories(carnet, nb);
        }
        else if (choix == 7)
        {
            printf("\n Fermeture du carnet de suivi sportif\n\n");
            printf("Au revoir !\n");
            break;
        }
        else
        {
            printf("Choix invalide.\n");
        }
    }

    return 0;
}