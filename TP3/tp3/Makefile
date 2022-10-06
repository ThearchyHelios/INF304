CC=clang -Wall -g

all: ensembles

operations_ens.o: operations_ens.c	operations_ens.h
		$(CC) -c operations_ens.c

ensembles.o: ensembles.c operations_ens.h	sac.h	type_ensemble.h
		$(CC) -c ensembles.c

recherche.o: recherche.c recherche.h
		$(CC) -c recherche.c

recherche_souschaine.o: recherche_souschaine.c recherche_souschaine.h recherche.h
		$(CC) -c recherche_souschaine.c

sac.o: sac.c sac.h 
		$(CC) -c sac.c

ensembles: ensembles.o operations_ens.o	sac.o
		$(CC) ensembles.o operations_ens.o	sac.o -o ensembles

clean:
		rm -f test_tri *.o