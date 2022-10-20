
#include "commandes_calculette.h"
#include "type_pile_erreurs.h"
#include <stdio.h>

void ziyada(PileEntiers *pila)
{
    int a = sommet(pila);
    depiler(pila);
    int b = sommet(pila);
    depiler(pila);
    int c = a + b;
    empiler(pila, c);
}

void naqiss(PileEntiers *pila)
{
    if (pila->n >= 2)
    {
        int val1 = depiler(pila);
        int val2 = depiler(pila);
        empiler(pila, (val2 - val1));
    }
    else
    {
        printf("more values needed to apply naqiss");
    }
}

void darb(PileEntiers *pila)
{
    if (pila->n >= 2)
    {
        int val1 = depiler(pila);
        int val2 = depiler(pila);
        empiler(pila, (val2 * val1));
    }
    else
    {
        printf("more values needed to apply darb");
    }
}

void alqissma(PileEntiers *pila)
{
    if (pila->n >= 2)
    {
        int val1 = depiler(pila);
        int val2 = depiler(pila);
        empiler(pila, (val2 / val1));
    }
    else
    {
        printf("more factors needed to apply alqissma");
    }
}

int main(int argc, char **argv)
{
    FILE *fichier = NULL;
    if (argc != 2)
    {
        printf("USE : ./calculette <argument> \n");
        return 0;
    }

    fichier = ouvrir_commandes(argv[1]);
    PileEntiers pila;
    creer_pile(&pila);

    commande command;

    while (!fin_commandes(fichier))
    {
        command = commande_suivante(fichier);
        print_commandes(command);
        switch (command.cmd)
        {
        case VIDER_PILE:
            vider(&pila);
            break;
        case DEPILER_SOMMET:
            depiler(&pila);
            break;
        case EMPILER_VALEUR:
            empiler(&pila, command.arg);
            break;
        case EFFECTUER_ADDITION:
            ziyada(&pila);
            break;
        case EFFECTUER_SOUSTRACTION:
            naqiss(&pila);
            break;
        case EFFECTUER_MULTIPLICATION:
            darb(&pila);
            break;
        case EFFECTUER_DIVISION:
            alqissma(&pila);
            break;
        case COMMANDE_INCORRECTE:
            printf("COMMANDE INCORRECTE \n");
            break;
        }
        print(&pila);
        printf("\n");
    }

    fermer_commandes(fichier);

    return 0;
}