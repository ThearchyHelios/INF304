/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-23 20:59:04
 * @LastEditTime: 2022-11-30 18:16:16
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/Projet_EnsembleTD6-9/curiosity-obs.c
 */

#include "environnement.h"
#include "interprete.h"
#include "programme.h"
#include "generation_terrains.h"
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
// le meme programme que curiosity.c mais avec des modifications pour la performance
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
	erreur_terrain erreur_terrain;
	erreur_programme errp;
	etat_inter etat;
	resultat_inter res;
	int res_obs;

	if (argc != 3)
	{
		printf("Usage : %s <fichier terrain> <fichier programme>\n", argv[0]);
		exit(1);
	}
	erreur_terrain = initialise_environnement(&envt, argv[1]); //initialise l'environnement
	gestion_erreur_terrain(erreur_terrain); //gestion des erreurs

	errp = lire_programme(&prog, argv[2]); //lit le programme
	gestion_erreur_programme(errp); //gestion des erreurs

	init_etat(&etat); //initialise l'etat
	do //boucle de l'interprete
	{
		res = exec_pas(&prog, &envt, &etat);
		afficher_envt(&envt);
	} while (res == OK_ROBOT);

	res_obs = resultat_obs(&envt); //resultat de l'observation

	if (res_obs) {
		printf("Le resultat d'observateur est valide\n");
	} else {
		printf("Le resultat d'observateur est invalide\n");
	}
}
