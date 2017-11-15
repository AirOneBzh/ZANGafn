##########################################################

CFLAGS = -g -O2 -Wall

prog: afficheur
	-rm -rf *.o

afficheur: afficheur.o fonction.o ensemble.o
	$(CC) afficheur.o fonction.o ensemble.o $(CFLAGS) -o afficheur

afficheur.o: afficheur.c
	$(CC) -c afficheur.c $(CFLAGS)

fonction.o: fonction.c fonction.h
	$(CC) -c fonction.c $(CFLAGS)

ensemble.o:ensemble.c ensemble.h
	$(CC) -c ensemble.c $(CFLAGS)


clean:
	-rm -rf *.o afficheur
