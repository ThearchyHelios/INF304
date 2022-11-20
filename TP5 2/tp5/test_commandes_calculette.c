/*
 * @Author: ThearchyHelios
 * @Date: 2022-10-04 22:25:48
 * @LastEditTime: 2022-10-12 15:48:14
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /TP4/tp4/test_commandes_calculette.c
 */
#include "commandes_calculette.h"

int main(int argc, char **argv)
{
    FILE *fichier = NULL;
    if (argc != 2)
    {
        printf("mauvaise utilisation : donnez un nom de fichier en argument\n");
        return 0;
    }

    fichier = ouvrir_commandes(argv[1]);

    commande command;

    while (!fin_commandes(fichier))
    {
        command = commande_suivante(fichier);
        print_commandes(command);
    }
    fermer_commandes(fichier);

    return 0;
}
