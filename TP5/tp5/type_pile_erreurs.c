/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-18 21:49:56
 * @LastEditTime: 2022-10-19 12:31:39
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP5/tp5/type_pile_erreurs.c
 */

#include "type_pile_erreurs.h"
#include <stdio.h>
#include <stdlib.h>

erreur_pile creer_pile(PileEntiers *p)
{
    if (p == NULL)
    {
        return POINTEUR_NUL;
    }
    p->n = 0;
    return OK;
}

/* Opérations d'accès */

/* Retourne vrai ssi p est vide */
int est_vide(PileEntiers *pila)
{
    if (pila->n != 0)
    {
        return OK;
    }
    else
    {
        return PILE_VIDE;
    }
}

/* Renvoie l'entier en haut de la pile */
/* p doit être non vide */
erreur_pile sommet(PileEntiers *pila, int *res)
{
    if (pila->n == 0)
    {
        return PILE_VIDE;
    }
    else
    {
        *res = pila->tab[pila->n - 1];
        return OK;
    }
}

/* Renvoie le nombre d'éléments dans la pile */
int taille(PileEntiers *pila)
{
    return pila->n;
}

/* Afficher les éléments de la pile */
void print(PileEntiers *pila)
{
    for (int i = pila->n - 1; i >= 0; i--)
    {
        printf("%d\n", pila->tab[i]);
    }
}

/* Opérations de modification */

/* Vider la pile pila */
erreur_pile vider(PileEntiers *pila)
{
    if (pila == NULL)
    {
        return POINTEUR_NUL;
    }
    pila->n = 0;
    return OK;
}

/* Empiler l'entier e dans la pile pila */
/* pila doit être non pleine */
erreur_pile empiler(PileEntiers *pila, int e)
{
    if (pila->n == TAILLE_MAX)
    {
        return PILE_PLEINE;
    }
    else
    {
        pila->tab[pila->n] = e;
        pila->n++;
        return OK;
    }
}

/* Dépiler l'entier en haut de la pile pila */
/* pila doit être non vide */
erreur_pile depiler(PileEntiers *pila, int *resultat){
    if (pila->n == 0)
    {
        return PILE_VIDE;
    }
    else if (pila->n == NULL){
        return POINTEUR_NUL;
    }
    else
    {
        *resultat = pila->tab[pila->n - 1];
        pila->n--;
        return OK;
    }
}