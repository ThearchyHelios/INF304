/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-22 21:28:24
 * @LastEditTime: 2022-11-22 21:51:34
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP7/curiosity-test.c
 */
#include "environnement.h"
#include "interprete.h"
#include "programme.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gestion_erreur_terrain(erreur_terrain e)
{
    switch (e)
    {
    case OK:
        break;
    case ERREUR_FICHIER:
        printf("Erreur lecture du terrain : erreur d'ouverture du fichier\n");
        exit(1);
    case ERREUR_LECTURE_LARGEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la largeur\n");
        exit(1);
    case ERREUR_LECTURE_HAUTEUR:
        printf("Erreur lecture du terrain : erreur de lecture de la hauteur\n");
        exit(1);
    case ERREUR_LARGEUR_INCORRECTE:
        printf("Erreur lecture du terrain : largeur incorrecte\n");
        exit(1);
    case ERREUR_HAUTEUR_INCORRECTE:
        printf("Erreur lecture du terrain : hauteur incorrecte\n");
        exit(1);
    case ERREUR_CARACTERE_INCORRECT:
        printf("Erreur lecture du terrain : caractère incorrect\n");
        exit(1);
    case ERREUR_LIGNE_TROP_LONGUE:
        printf("Erreur lecture du terrain : ligne trop longue\n");
        exit(1);
    case ERREUR_LIGNE_TROP_COURTE:
        printf("Erreur lecture du terrain : ligne trop courte\n");
        exit(1);
    case ERREUR_LIGNES_MANQUANTES:
        printf("Erreur lecture du terrain : lignes manquantes\n");
        exit(1);
    case ERREUR_POSITION_ROBOT_MANQUANTE:
        printf("Erreur lecture du terrain : position initiale du robot manquante\n");
        exit(1);
    }
}

void affichage_position_programme(erreur_programme e)
{
    int i;
    printf("Ligne %d, colonne %d :\n", e.num_ligne, e.num_colonne);
    printf("%s\n", e.ligne);
    /* Impression de e.num_colonne-1 espaces */
    for (i = 1; i < e.num_colonne; i++)
    {
        printf(" ");
    }
    /* Impression d'un curseur de position */
    printf("^\n");
}

void gestion_erreur_programme(erreur_programme e)
{
    switch (e.type_err)
    {
    case OK_PROGRAMME:
        break;
    case ERREUR_FICHIER_PROGRAMME:
        printf("Erreur lecture du programme : erreur d'ouverture du fichier\n");
        exit(2);
    case ERREUR_BLOC_NON_FERME:
        printf("Erreur lecture du programme : bloc non fermé\n");
        exit(2);
    case ERREUR_FERMETURE_BLOC_EXCEDENTAIRE:
        printf("Erreur lecture du programme : fermeture de bloc excédentaire\n");
        affichage_position_programme(e);
        exit(2);
    case ERREUR_COMMANDE_INCORRECTE:
        printf("Erreur lecture du programme : commande incorrecte\n");
        affichage_position_programme(e);
        exit(2);
    }
}

int main(int argc, char **argv)
{
    Environnement envt;
    Programme prog;
    erreur_terrain errt;
    erreur_programme errp;
    etat_inter etat;
    resultat_inter res;
    char fichier_terrain[50];
    char fichier_programme[50];
    int nb_pas, x, y, xr, yr;
    char e, o, or ;
    FILE *f;

    for (int nb_arguments = 1; nb_arguments < argc; nb_arguments++)
    {
        f = fopen(argv[nb_arguments], "r");
        /* Initialisation de l'environnement : lecture du terrain,
           initialisation de la position du robot */
        fgets(fichier_terrain, 50, f);
        fichier_terrain[strlen(fichier_terrain) - 1] = '\0';
        errt = initialise_environnement(&envt, fichier_terrain);
        gestion_erreur_terrain(errt);

        /* Lecture du programme */
        fgets(fichier_programme, 50, f);
        fichier_programme[strlen(fichier_programme) - 1] = '\0';
        errp = lire_programme(&prog, fichier_programme);
        gestion_erreur_programme(errp);

        fscanf(f, "%d", &nb_pas);

        fscanf(f, "\n%c", &e);

        if (e == 'N' || e == 'F')
        {
            fscanf(f, "%d", &x);
            fscanf(f, "%d", &y);
            fscanf(f, "\n%c", &o);
        }

        /* Initialisation de l'état */
        init_etat(&etat);
        do
        {
            res = exec_pas(&prog, &envt, &etat);
            nb_pas--;
            /* Affichage du terrain et du robot */
            afficher_envt(&envt);
        } while (res == OK_ROBOT && nb_pas != 0);

        if (res == OK_ROBOT)
        {
            res = ARRET_ROBOT;
        }

        /* Affichage du résultat */
        switch (res)
        {
        case OK_ROBOT:
            printf("Robot sur une case libre, programme non terminé (ne devrait pas "
                   "arriver)\n");
            break;
        case SORTIE_ROBOT:
            if (e == 'S')
                printf("L'évenement obtenu correspond bien a l'évenement qui est attendu\n");
            else
                printf("Le robot est sorti :-), L'évenement obtenu [%c] ne correspond pas a l'évenement qui est attendu\n", e);
            break;
        case ARRET_ROBOT:
            if (e == 'N' || e == 'F')
            {
                position(&envt.r, &xr, &yr);
                switch (orient(&envt.r))
                {
                case Nord:
                    or = 'N';
                    break;
                case Est:
                    or = 'E';
                    break;
                case Sud:
                    or = 'S';
                    break;
                case Ouest:
                    or = 'O';
                    break;
                }
                if (xr == x && yr == y && or == o)
                    printf("La position du robot (%d, %d, %c) correspondent a ce qui est attendu: (%d, %d, %c) \n", xr, yr, or, x, y, o);
                else
                    printf("La position du robot: (%d, %d, %c) ne correspondent pas a ce qui est attendu: (%d, %d, %c)\n", xr, yr, or, x, y, o);
            }
            else
                printf("Robot sur une case libre, programme terminé :-/, L'évenement obtenu [%c] ne correspond pas a l'évenement qui est attendu\n", e);
            break;
        case PLOUF_ROBOT:
            if (e == 'P')
                printf("L'évenement obtenu correspond bien a l'évenement qui est attendu\n");
            else
                printf("Le robot est tombé dans l'eau :-(, L'évenement obtenu [%c] ne correspond pas a l'évenement qui est attendu\n", e);
            break;
        case CRASH_ROBOT:
            if (e == 'O')
                printf("L'évenement obtenu correspond bien a l'évenement qui est attendu\n");
            else
                printf("Le robot s'est écrasé sur un rocher X-(, L'évenement obtenu [%c] ne correspond pas a l'évenement qui est attendu\n", e);
            break;
        case ERREUR_PILE_VIDE:
            printf("ERREUR : pile vide\n");
            break;
        case ERREUR_ADRESSAGE:
            printf("ERREUR : erreur d'adressage\n");
            break;
        case ERREUR_DIVISION_PAR_ZERO:
            printf("ERREUR : division par 0\n");
            break;
        }
        fclose(f);
    }
}
