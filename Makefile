##########################################################

CFLAGS = -g -O2 -Wall

prog: afficheur
	-rm -rf *.o

afficheur: afficheur.o fonction.o
	$(CC) afficheur.o fonction.o $(CFLAGS) -o afficheur

afficheur.o: afficheur.c
	$(CC) -c afficheur.c $(CFLAGS)

fonction.o: focntion.c fonction.h
	$(CC) -c fonction.c $(CFLAGS)


clean:
	-rm -rf *.o afficheur
