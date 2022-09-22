/*
 * @Author: ThearchyHelios
 * @Date: 2021-09-24 13:57:32
 * @LastEditTime: 2022-09-18 20:18:59
 * @LastEditors: ThearchyHelios
 * @Description: 
 * @FilePath: /TP1/TP1/TP1b/transformation_image.c
 */


#include <stdio.h>
#include "image_io.h"
#include "operations_image.h"
#include "type_image.h"

int main(int argc, char **argv)
{
	Image im_init;
	Image im_inv;

	if (argc != 3)
	{
		printf("Il faut 2 arguments : un fichier image en entree et un fichier "
			   "image en sortie\n");
	}
	else
	{
		lecture_fichier(argv[1], &im_init);
		inverse_video(&im_init, &im_inv);
		ecriture_fichier(argv[2], &im_inv);
	}
}
