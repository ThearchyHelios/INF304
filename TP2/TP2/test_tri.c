/*
 * @Author: ThearchyHelios
 * @Date: 2020-11-03 16:10:26
 * @LastEditTime: 2022-09-22 15:50:18
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP2/TP2/test_tri.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "es_tableau.h"
#include "tri.h"

void test_tri_insertion(int argc, char **argv)
{ /* À compléter */
    tableau_entiers t;
    FILE *ftab;
    char nom_fichier[256];

    if (argc < 2)
    {
        printf("Usage: %s <fichier d'entree>\n", argv[0]);
    }
    else
    {
        lire_tableau(argv[1], &t);
        tri_insertion(&t);
        strcpy(nom_fichier, argv[1]);
        strcat(nom_fichier, "_tri");
        ecrire_tableau(nom_fichier, &t);
    }
}

void test_tri_insertion_alea(int argc, char **argv)
{ /* À compléter */
}
