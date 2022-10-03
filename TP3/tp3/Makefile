CC = clang -c

all: ensembles

operations_ens.o: operations_ens.h operations_ens.c
	$(CC) operations_ens.c

recherche_souschaine.o: recherche.h recherche_souschaine.c
	$(CC) recherche_souschaine.c

recherche.o: recherche.h recherche.c

sac.o: sac.h sac.c
	$(CC) sac.c

ensembles.o: ensembles.c sac.h operations_ens.h type_ensemble.h
	$(CC) ensembles.c

ensembles: ensembles.o sac.o operations_ens.o recherche_souschaine.o
	$(CC) ensembles.o sac.o operations_ens.o recherche_souschaine.o -o ensembles

clean:
	rm -rf *.o ensembles