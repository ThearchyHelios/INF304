/*
 * @Author: ThearchyHelios
 * @Date: 2020-11-03 16:10:26
 * @LastEditTime: 2022-09-25 16:56:43
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP2/TP2/tri.c
 */

#include "tri.h"

/*
tri_insertion
Donnees : t : tableau d'entiers de taille > n, n : entier > 0
Resultat : le tableau t est trie en ordre croissant
*/
void tri_insertion(tableau_entiers *t)
{
    int i, j;
    int Clef;
    for (j = 1; j < t->taille; j++)
    {
        Clef = t->tab[j];
        i = j - 1;
        while (i >= 0 && t->tab[i] > Clef)
        {
            t->tab[i + 1] = t->tab[i];
            i--;
        }
        t->tab[i + 1] = Clef;
    }
}
