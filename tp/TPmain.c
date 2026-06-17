#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LoupGarou.h"

int main()
{
    Joueur joueurs[30];
    int nb = 0;
    int choix;

    srand((unsigned)time(NULL));

    while (1)
    {
        choix = menu1();

        if (choix == 1)
        {
            ajout_joueur(joueurs, &nb);
        }
        else if (choix == 2)
        {
            lancer_partie(joueurs, nb);
        }
        else if (choix == 3)
        {
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