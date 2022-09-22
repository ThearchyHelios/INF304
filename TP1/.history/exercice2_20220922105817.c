/*
 * @Author: ThearchyHelios
 * @Date: 2022-09-22 10:58:14
 * @LastEditTime: 2022-09-22 10:58:15
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP1/exercice2.c
 */

void Copier(char *fichier1, char *fichier2)
{
    FILE *copie = fopen(fichier2, "w+");
    FILE *source = fopen(fichier1, "r");
    if ((copie != NULL) && (source != NULL))
    {
        char c = fgetc(source);
        while (c != EOF)
        {
            fputs(c, copie);
            c = fgets(source);
        }
    }
    fclose(copie);
    fclose(source);
}