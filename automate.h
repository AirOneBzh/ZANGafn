#include "ensemble.h"


typedef struct{
  ensemble q;//pos 0=nb d'états;1 si présent état i pos i;0 sinon
  char a[MAX];
  int t[MAX];//pos 0=nb trans; {etat1;etiquette;etat2}
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

int init_aut(Automate *A);
void A_defaut(Automate *A);
