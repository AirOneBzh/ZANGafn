#include <stdio.h>
#include <stdlib.h>
#include <limits.h>                //pour ajouter/enlever un etat {n(=cardinal de l'ensemble, postion 1= bool, position 2 = bool, ....}
#DEFINE  MAX 50
#include <ensemble.h>





typedef struct{
  int q[MAX];//pos 0=nb d'états;1 si présent état i pos i;0 sinon
  char a[MAX];
  int t[MAX];//pos 0=nb trans; {etat1;etiquette;etat2}
  int i[MAX];//même que q
  int f[MAX];//même que q
}Automate;

typedef struct{
  int qb[MAX][MAX];
  char ab[MAX];
  int tb[MAX][MAX];//{pos etiq;etat1;etat2;etat3;etiquette;etat1';....}
  int ib[MAX][MAX];
  int fb[MAX][MAX];
}Automate_d;
