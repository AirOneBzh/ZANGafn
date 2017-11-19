#include <stdlib.h>
#include <stdio.h>
#include "automate.h"

#define MAX 50

void aff_ens(ensemble e){
  int i;
  int acc=0;
  fprintf(stdout," {");
  for (i=1;acc<e.ens[0];i++){
    if(e.ens[i]==1){
      fprintf(stdout," %d",i);
      acc++;
    }
  }
  fprintf(stdout," }\n");
}

int aff_trans(int t[]){
  int i;
  fprintf(stdout," { ");
  for(i=0;i<t[0];i++){
    fprintf(stdout,"(%d,%c,%d) ",t[i*3+1],t[i*3+2],t[i*3+3]);
  }
  fprintf(stdout,"}\n");
  return 1;
}

int aff_trans_d();

int aff_aut_d(Automate_d a){
  int i;
  fprintf(stdout,"Q = {");
  for(i=1;i<=a.qd[0].ens[1];i++){
    aff_ens(a.qd[i]);
  }
  fprintf(stdout,"}I={");
  aff_ens(a.id);
  fprintf(stdout,"}Q={");
  for(i=1;i<=a.fd[0].ens[0];i++){
    aff_ens(a.fd[i]);
  }
  fprintf(stdout,"}\n");


  return 1;
}

//affiche un automate dans le terminal
int aff_aut(Automate A){
  int i;
  fprintf(stdout,"Q=");
  aff_ens(A.q);
  fprintf(stdout,"A= { ");
  for(i=1;i<=A.a[0];i++){
    fprintf(stdout,"%c ",A.a[i]);
  }
  fprintf(stdout,"}\nT=");
  aff_trans(A.t);
  fprintf(stdout,"I=");
  aff_ens(A.i);
  fprintf(stdout,"F=");
  aff_ens(A.f);
  printf("\n");

  return 1;
}

int main (){
  Automate a;
  ensemble ens;
  init_aut(&a);
  aff_aut(a);
  aff_ens(ens);
  rec_mot(a,"abb");
  return 1;
}

//init d'un automate par défaut et avec lecture de fichier avec affichage
// a faire affichage de ses transitions
