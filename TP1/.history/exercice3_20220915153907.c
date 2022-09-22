/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-15 15:34:59
 * @LastEditTime: 2022-09-15 15:38:12
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP1/exercice3.c
 */


#include <stdio.h>

// Question: Écrire un programme C de nom exercice3.c qui lit un fichier caractère par caractère et copie son contenu dans un autre fichier. Les noms des deux fichiers seront passés en argument de la ligne de commande, un message d'erreur sera affiché si la ligne de commande est incorrecte. Compilez et testez ce programme.

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: <input file> <output file>");
        return 1;
    } else {
        FILE *input = fopen(argv[1], "r");
        FILE *output = fopen(argv[2], "w");
        char c;
        while ((c = fgetc(input)) != EOF) {
            fputc(c, output);
        }
        fclose(input);
        fclose(output);
    }}  
