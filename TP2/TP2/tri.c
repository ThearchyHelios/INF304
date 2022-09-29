/*
 * @Author: ThearchyHelios
 * @Date: 2020-11-03 16:10:26
 * @LastEditTime: 2022-09-29 11:59:33
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP2/TP2/tri.c
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
    for (i = 1; i < t->taille; i++)
    {
        Clef = t->tab[i];
        j = i - 1;
        while ((j >= 0) && (Clef <= (t->tab[j] - 1)))
        {
            t->tab[j + 1] = t->tab[j];
            j--;
        }
        t->tab[j + 1] = Clef;
    }
}
