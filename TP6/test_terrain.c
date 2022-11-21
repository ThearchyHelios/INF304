/*
 * @Author: ThearchyHelios
 * @Date: 2022-11-20 22:59:29
 * @LastEditTime: 2022-11-20 23:58:33
 * @LastEditors: ThearchyHelios
 * @Description:
 * @FilePath: /INF304/TP6/test_terrain.c
 */
#include "terrain.h"
#include <stdio.h>

int main(int argc, char **argv) {
  FILE *f;
  Terrain t;
  int x, y;

  if (argc < 2) {
    printf("Usage : %s <fichier>\n", argv[0]);
    return 1;
  }

  f = fopen(argv[1], "r");
  if (lire_terrain(f, &t, &x, &y) == OK){
    fclose(f);
    afficher_terrain(&t);
    printf("Position initiale du robot : (%d, %d)\n", x, y);
    return 0;
  }
  else if (lire_terrain(f, &t, &x, &y) == ERREUR_FICHIER){
    printf("Erreur de ficher\n");
    return 1;
  }
}
