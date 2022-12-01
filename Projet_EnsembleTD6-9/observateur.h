/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-26 18:06:12
 * @LastEditTime: 2022-12-01 12:01:38
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /Projet_EnsembleTD6-9/observateur.h
 */
#ifndef _OBSERVATEUR_H_
#define _OBSERVATEUR_H_

typedef enum{ A, G, D, M } Alphabet;

typedef enum{ Init, Mes, Erreur } Etat;

/* Renvoie l’état initial de l’automate */
Etat initial();

/* Fonction de transition de l’automate */
Etat transition(Etat e, Alphabet c);

int est_final(Etat e);

#endif