/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 15:53:08
 * @LastEditTime: 2022-09-15 15:57:25
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP1/exercice4.c
 */

// Question 4: Écrire un programme C de nom exercice4.c qui lit dans un fichier (dont le nom est fourni sur la ligne de commande) une date au format "jour mois année" (comme 18 octobre 1966) avec le jour sur la première ligne, le mois sur la deuxième ligne et l'année sur la troisième, et affiche un entier représentant la somme du jour et de l'année (comme 1984, somme de 18 et 1966).

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Votre commande nest pas correcte. \n Usage: <input file>");
        return 1;
    }
    else
    {
        FILE *input = fopen(argv[1], "r");
        int day, year;
        char month[10];
        fscanf(input, "%d %s %d", &day, month, &year);
        printf("%d", day + year);
        fclose(input);
    }
}