#include <stdio.h>
#include <stdlib.h>
#include <limits.h>                //pour ajouter/enlever un etat {n(=cardinal de l'ensemble, postion 1= bool, position 2 = bool, ....}
#include "ensemble.h"
#define  MAX 50




typedef struct{
  ensemble q;//pos 0=nb d'états;1 si présent état i pos i;0 sinon
  char a[MAX];
  ensemble t;//pos 0=nb trans; {etat1;etiquette;etat2}
  ensemble i;//même que q
  ensemble f;//même que q
}Automate;

typedef struct{
  ensemble qd[MAX];
  char a[MAX];
  ensemble td[MAX];//{etiq;etat1;etat2;etat3;-1;etat1';....}
  ensemble id;
  ensemble fd[MAX];//colonne = ensemble
}Automate_d;
