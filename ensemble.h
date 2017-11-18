#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct{
  int ens[MAX];
}ensemble;

int est_ens(ensemble q[],ensemble e);
int est_etat(ensemble e,int n);
int eg_ens(ensemble ens1,ensemble ens2);
int aj_etat(ensemble *e,int n);
int aj_trans(int t[50],int etat_dep,char etiq,int etat_arr);
