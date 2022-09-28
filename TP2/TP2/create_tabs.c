/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-22 16:02:38
 * @LastEditTime: 2022-09-22 16:19:18
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP2/TP2/create_tabs.c
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "type_tableau.h"

// create tabs with the number entered

int main(int argc, char **argv)
{
    int nombre_fichers;
    printf("Entrez le nombre de fichiers à créer : ");
    scanf("%d", &nombre_fichers);
    
    for (int i = 1; i <= nombre_fichers; i++)
    {
        char nom_fichier[20];
        sprintf(nom_fichier, "tab%d.txt", i);
        FILE *fichier = fopen(nom_fichier, "w");
        

        fclose(fichier);
    }
}