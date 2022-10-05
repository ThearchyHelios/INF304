/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-02 22:07:01
 * @LastEditTime: 2022-10-05 18:28:17
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /INF304/TP3/tp3/type_ensemble.h
 */
#ifndef _TYPE_ENSEMBLE_H_
#define _TYPE_ENSEMBLE_H_

#include "sac.h"

/* Cardinal maximum d'un ensemble */
#define CARD_MAX 500

/* Type ensemble */
/* Un ensemble est défini par un sac, et une séquence de couples (i,j) :
   ces couples sont les coordonnées des valeurs de l'ensemble dans
   le sac. */

/* Type couple */
typedef struct
{
    int a;
    int b;
} couple;

typedef struct
{
    /* Le sac d'où sont issues les valeurs de l'ensemble */
    sac *valeurs;
    /* Le cardinal de l'ensemble */
    int card;
    /* Le tableau de couples */
    couple indices[CARD_MAX];
} ensemble;

#endif /* _TYPE_ENSEMBLE_H_ */
