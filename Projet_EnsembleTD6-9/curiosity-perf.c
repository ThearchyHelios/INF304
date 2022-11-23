/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-23 20:59:04
 * @LastEditTime: 2022-11-24 00:29:41
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /Projet_EnsembleTD6-9/curiosity-perf.c
 */

#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "generation_terrains.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>

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

	int N, l, h;
	float dObst;
	Terrain T;
	int nb_pas_max, nb_pas_effectues, existe_chemin;
	float moyenne_pas = 0., nb_crashes = 0., nb_sorties = 0., nb_bloque = 0.;
	FILE *graine, *fichier_res;

	if (argc < 9)
	{
		printf("Usage: %s <programme> <nombre_terrain> <largeur> <hauteur> <densité> <graine> <nombre_de_pas> <resFile>\n", argv[0]);
		return 1;
	}

	srand(time(NULL));

	N = strtol(argv[2], NULL, 10);
	l = strtol(argv[3], NULL, 10);
	h = strtol(argv[4], NULL, 10);
	dObst = strtof(argv[5], NULL);

	// test de l et h
	if (l > DIM_MAX || l % 2 == 0)
	{
		printf("Largeur incorrecte : doit être impaire et <= %d\n", DIM_MAX);
		return 1;
	}
	if (h > DIM_MAX || h % 2 == 0)
	{
		printf("Hauteur incorrecte : doit être impaire et <= %d\n", DIM_MAX);
		return 1;
	}
	if ((dObst > 1) || (dObst < 0))
	{
		printf("Densité incorrecte : doit être comprise entre 0 et 1\n");
		return 1;
	}

	nb_pas_max = strtol(argv[7], NULL, 10);
	fichier_res = fopen(argv[8], "w");
	fprintf(fichier_res, "%d\n", N);

	for (int i = 1; i <= N; i++)
	{
		printf("Terrain No.%d\n\n", i);
		graine = fopen(argv[6], "w");
		generation_aleatoire(&T, l, h, dObst);
		ecrire_terrain(graine, &T, (int)l / 2, (int)h / 2);
		fclose(graine);

		fprintf(fichier_res, "%s %d\n", "Terrain:", i);

		/* Initialisation de l'environnement : lecture du terrain,
		 initialisation de la position du robot */
		errt = initialise_environnement(&envt, argv[6]);
		gestion_erreur_terrain(errt);
		/* Affichage du terrain et du robot */
		afficher_envt(&envt);

		/* Lecture du programme */
		errp = lire_programme(&prog, argv[1]);
		gestion_erreur_programme(errp);
		nb_pas_effectues = 0;
		existe_chemin = existe_chemin_vers_sortie(&T);
		if (existe_chemin == 0)
		{
			nb_bloque++;
			printf("Le robot est bloqué \n\n");
			fprintf(fichier_res, "%d\n", -1);
		}
		else
		{

			/* Initialisation de l'état */

			init_etat(&etat);
			do
			{
				res = exec_pas(&prog, &envt, &etat);
				nb_pas_effectues++;

			} while (res == OK_ROBOT && nb_pas_max >= nb_pas_effectues);

			printf("pas = %d\n", nb_pas_effectues);
			/* Affichage du résultat */

			if (res == SORTIE_ROBOT)
			{
				printf("Le robot est sorti :-)\n\n");
				nb_sorties++;
				moyenne_pas += nb_pas_effectues;
				fprintf(fichier_res, "%d\n", nb_pas_effectues);
			}

			else if (res == PLOUF_ROBOT)
			{
				printf("Le robot est tombé dans l'eau :-(\n\n");
				nb_crashes++;
				fprintf(fichier_res, "%d\n", -2);
			}

			else if (res == CRASH_ROBOT)
			{
				printf("Le robot s'est écrasé sur un rocher X-(\n\n");
				nb_crashes++;
				fprintf(fichier_res, "%d\n", -3);
			}
			else if (res == OK_ROBOT)
			{
				nb_bloque++;
				printf("Le nombre de pas effectués depasse le nombre de pas maximum, Le robot est bloqué \n\n");
				fprintf(fichier_res, "%d\n", -1);
			}
		}
	}

	printf("nombre et pourcentage de terrains d'ou le robot est sorti %.0f, %.2f\n", nb_sorties, (nb_sorties * 100) / N);
	printf("nombre et pourcentage de terrains d'ou le robot est bloque: %.0f, %.2f\n", nb_bloque, (nb_bloque * 100) / N);
	printf("nombre et pourcentage de terrains d'ou le robot est rentre dans un obstacle: %.0f, %.2f\n", nb_crashes, (nb_crashes * 100) / N);
	printf("nombre moyen de pas effectués pour les sorties %.2f\n", moyenne_pas / nb_sorties);
	fclose(fichier_res);
}
