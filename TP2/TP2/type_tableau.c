/*
 * @Author: ThearchyHelios
 * @Date: 2020-11-03 16:10:26
 * @LastEditTime: 2022-09-22 15:31:29
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP2/TP2/type_tableau.c
 */
#include "type_tableau.h"

/* Copie le tableau t1 dans t2
   Pré-condition : t1 et t2 sont alloués
 */
void copie_tableau(tableau_entiers *t1, tableau_entiers *t2)
{
    int i;

    t2->taille = t1->taille;

    for (i = 0; i < t1->taille; i++)
    {
        t2->tab[i] = t1->tab[i];
    }
}
