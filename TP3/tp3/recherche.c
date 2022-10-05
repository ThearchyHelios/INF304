/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-02 22:07:01
 * @LastEditTime: 2022-10-05 18:27:47
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF304/TP3/tp3/recherche.c
 */

#include "recherche.h"
#include <assert.h>
#include <string.h>

/* Recherche la sous-chaîne sc dans la chaîne c
   Renvoie :
   - l'indice du début de sc dans c si sc est une sous-chaîne de c
   - -1 si sc n'est pas une sous-chaîne de c
   Précondition : sc n'est pas vide (strlen(sc) > 0)
 */
int recherche(char *c, char *sc)
{
    int lc = strlen(c);
    int lsc = strlen(sc);
    int ic, isc;

    /* Vérification de la précondition */
    assert(lsc > 0);

    ic = 0;
    isc = 0;
    while ((ic < (lc - lsc + 1)) && (isc < lsc))
    {
        /* Recherche de sc dans c à la position  */
        isc = 0;
        while ((isc < lsc) && (c[ic + isc] == sc[isc]))
        {
            isc = isc + 1;
        }
        /* Assertion : (isc = lsc) ou (isc < lsc et c[ic+isc] != sc[isc]) */
        ic = ic + 1;
    }
    /* La sous-chaîne est trouvée si isc = lsc */
    if (isc == lsc)
    {
        /* Sous-chaîne à l'indice ic-1 */
        return ic - 1;
    }
    else
    {
        return -1;
    }
}
