/*
 * @Author: ThearchyHelios
 * @Date: 2020-11-03 16:10:26
 * @LastEditTime: 2022-09-28 17:12:20
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /TP2/TP2/exec_test_tri.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "es_tableau.h"
#include "test_tri.h"
#include "tri.h"
#include "type_tableau.h"

int main(int argc, char **argv)
{

    tableau_entiers t;
    // FILE *ftab;
    char nom_fichier[256];

    if (argc < 2)
    {
        printf("Usage: %s <fichier d'entree>\n", argv[0]);
    }
    else
    {
        /* À modifier pour les exercices 3 à 6 */
        // lire_tableau(argv[1], &t);
        // tri_insertion(&t);
        // test_tri_insertion(argc, argv);
        test_tri_insertion_alea(argc, argv);
        // strcpy(nom_fichier, argv[1]);
        // strcat(nom_fichier, ".out");
        // ecrire_tableau(nom_fichier, &t);

        // test_tri_insertion(argc, argv);

        // test_tri_insertion_alea(argc, argv);
    }
}
