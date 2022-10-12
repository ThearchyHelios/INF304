/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-04 22:25:46
 * @LastEditTime: 2022-10-12 15:51:23
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /TP4/tp4/type_pile.c
 */
#include "type_pile.h"
#include <stdio.h>

/* Cr�er une pile vide */
void creer_pile(PileEntiers *pila)
{
    pila->n = 0;
}

/* Op�rations d'acc�s */

/* Retourne vrai ssi p est vide */
int est_vide(PileEntiers *pila)
{
    if (pila->n != 0)
        return 0;
    else
        return 1;
}

/* Renvoie l'entier en haut de la pile */
/* p doit �tre non vide */
int sommet(PileEntiers *pila)
{
    if (!est_vide(pila))
        return pila->tab[pila->n - 1];
    else
    {
        printf("la pile ne contient aucun element");
        return -1;
    }
}

/* Renvoie le nombre d'�l�ments dans la pile */
int taille(PileEntiers *pila)
{
    return pila->n;
}

/* Afficher les �l�ments de la pile */
void print(PileEntiers *pila)
{
    for (int i = pila->n - 1; i >= 0; i--)
    {
        printf("%d\n", pila->tab[i]);
    }
}

/* Op�rations de modification */

/* Vider la pile pila */
void vider(PileEntiers *pila)
{
    pila->n = 0;
}

/* Empiler un entier x */
/* Pr�condition : taille(pila) < TAILLE_MAX */
void empiler(PileEntiers *pila, int x)
{
    if (pila->n < TAILLE_MAX)
    {
        pila->tab[pila->n] = x;
        pila->n++;
    }
}

/* Supprimer et renvoyer l'entier en haut de la pile */
/* Pr�condition : p non vide */
int depiler(PileEntiers *pila)
{
    if (pila->n > 0)
    {
        int x = pila->tab[pila->n - 1];
        pila->n--;
        return x;
    }
    else
    {
        printf("La pile ne contient aucun element");
        return -1;
    }
}