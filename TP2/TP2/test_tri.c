/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-27 11:13:23
 * @LastEditTime: 2022-09-29 08:46:52
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP2/TP2/test_tri.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "es_tableau.h"
#include "tri.h"

char nomFichier[256];
int oracle(tableau_entiers t)
{
    int i;
    for (i = 0; i < t.taille - 1; i++)
    {
        if (t.tab[i] > t.tab[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// void test_tri_insertion(int argc, char *argv[])
// {
//     int i = 0;
//     tableau_entiers t;

//     while (argc > i)
//     {
//         lire_tableau(argv[i], &t);
//         strcpy(nomFichier, argv[i]);
//         strcat(nomFichier, "output");
//         tri_insertion(&t);
//         if (oracle(t) == 0)
//         {
//             printf("Erreur client \n");
//         }
//         ecrire_tableau(nomFichier, &t);
//         i++;
//     }
// }

void test_tri_insertion(int argc, char **argv)
{ /* À compléter */
    tableau_entiers t;
    FILE *ftab;
    int i = 0;
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
        strcat(nom_fichier, ".out");
        ecrire_tableau(nom_fichier, &t);
    }

    while (argc > i)
    {
        lire_tableau(argv[i], &t);
        strcpy(nom_fichier, argv[i]);
        strcat(nom_fichier, ".out");
        tri_insertion(&t);
        if (oracle(t) == 0)
        {
            printf("Erreur client \n");
        }
        ecrire_tableau(nom_fichier, &t);
        i++;
    }
}

void test_tri_insertion_alea(int argc, char **argv)
{
    tableau_entiers t;
    t.taille = 100;
    int i = 0;
    for (i = 0; i <= 99; i++)
    {
        t.tab[i] = rand() % 200;
    }

    strcpy(nomFichier, argv[1]);
    // copy table to file
    ecrire_tableau(nomFichier, &t);
    strcat(nomFichier, ".out");
    tri_insertion(&t);
    // if (oracle(t) == 0)
    // {
    //     printf("Erreur client \n");
    // }
    ecrire_tableau(nomFichier, &t);
}