#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct{
  int ens[MAX];
}ensemble;

int est_ens(ensemble q[],ensemble e);
int est_etat(ensemble e,int n);
int eg_ens(ensemble ens1,ensemble ens2);
