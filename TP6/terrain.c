/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-20 22:59:29
 * @LastEditTime: 2022-11-20 23:52:37
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP6/terrain.c
 */

#include "terrain.h"
#include "robot.h"
#include <stdio.h>
#include <string.h>

erreur_terrain lire_terrain(FILE *f, Terrain *t, int *x, int *y)
{
	int l, h;	// Dimensions du terrain
	int rx, ry; // Coordonnées initiales du robot

	if (f == NULL)
	{
		return ERREUR_FICHIER;
	}

	// Lecture de la largeur
	// À compléter
	fscanf(f, "%d", &l);

	// Lecture de la hauteur
	// À compléter
	fscanf(f, "%d", &h);

	// Initialisation des dimensions du terrain
	t->largeur = l;
	t->hauteur = h;

	// Lecture du terrain
	// À compléter
	// soit 'C' pour représenter la position initiale du robot.
	// supprimer le '\0' de la fin de la ligne

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < l; j++)
		{
			char c;
			fscanf(f, "%c", &c);
			switch (c)
			{
			case '.':
				t->tab[i][j] = LIBRE;
				break;
			case '#':
				t->tab[i][j] = ROCHER;
				break;
			case '~':
				t->tab[i][j] = EAU;
				break;
			case 'C':
				t->tab[i][j] = LIBRE;
				rx = i;
				ry = j;
				break;
			default:
				break;
			}
		}
	}

	// Initialisation de la position du robot
	// À compléter
	*x = rx;
	*y = ry;

	return OK;
}

/* À compléter */

int largeur(Terrain *t)
{
	return t->largeur;
}

int hauteur(Terrain *t)
{
	return t->hauteur;
}

void afficher_terrain(Terrain *t)
{
	for (int i = 0; i < t->hauteur; i++)
	{
		for (int j = 0; j < t->largeur; j++)
		{
			switch (t->tab[i][j])
			{
			case LIBRE:
				printf(".");
				break;
			case ROCHER:
				printf("#");
				break;
			case EAU:
				printf("~");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

void ecrire_terrain(FILE *f, Terrain *t, int x, int y)
{
	fprintf(f, "%d %d", t->largeur, t->hauteur);
	for (int i = 0; i < t->hauteur; i++)
	{
		for (int j = 0; j < t->largeur; j++)
		{
			if (i == x && j == y)
			{
				fprintf(f, "C");
			}
			else
			{
				switch (t->tab[i][j])
				{
				case LIBRE:
					fprintf(f, ".");
					break;
				case ROCHER:
					fprintf(f, "#");
					break;
				case EAU:
					fprintf(f, "~");
					break;
				default:
					break;
				}
			}
		}
		fprintf(f, "");
	}
}

int est_case_libre(Terrain *t, int x, int y)
{
	int l = largeur(t);
	int h = hauteur(t);
	if (x < 0 || x >= l || y < 0 || y >= h)
	{
		return 0;
	}
	if (t->tab[x][y] == LIBRE)
	{
		return 1;
	}
	return 0;
}