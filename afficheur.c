#include <stdlib.h>
#include <stdio.h>
#include "automate.h"
#include <string.h>
#define MAX 50

void aff_ens(ensemble e){
  int i;
  int acc=0;
  fprintf(stdout," {");
  for (i=1;i<10;i++){
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

int aff_trans_d(ensemble td[]){
  int i;
  for(i=1;i<=td[0].ens[0];i++){
    fprintf(stdout,"Transition %d:\n",i);
    aff_ens(td[i*2]);
    fprintf(stdout,"Etiquette : %c\n",td[0].ens[i]);
    aff_ens(td[i*2+1]);
  }
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

int aff_aut_d(Automate_d a){
  int i;
  int j;
  char alph[MAX];
  fprintf(stdout, "Q = \n");
  for(i=1; i<=a.q_d[0].ens[0]; i++){
    aff_ens(a.q_d[i]);
  }
  fprintf(stdout, "A =\n");
  
  fprintf(stdout, "%s \n", a.a);
  fprintf(stdout, "T =\n");
  for(i=1; i<=a.a[0]*a.t_d[0][0]; i++){
    for(j=1; j<=a.a[0]; j++){
<<<<<<< HEAD
      aff_ens(a.t_d[i][0]);
      fprintf(stdout, "%c\n", t_d[0][j]);
      aff_ens(a.t_d[i][j]);
=======
      aff_ens(a.q_d[a.t_d[i][0]]);
      fprintf(stdout, "%c\n", a.t_d[0][j]);
      aff_ens(a.q_d[a.t_d[i][j]]);
>>>>>>> b49c6563213da6aaf176a02bccd4d0853f6ca1c4
    }
  }
  fprintf(stdout, "I=\n");
  aff_ens(a.q_d[a.i_d]);
  fprintf(stdout, "F=\n");
  int acc=0;
  for(i=1; acc<=a.f_d.ens[0];i++){
    if(a.f_d.ens[i]==1){
      aff_ens(a.q_d[i]);
      acc++;
    }
  } return 1;
}

int main (){

  Automate a;
  Automate_d ad;
  init_aut(&a);
  aff_aut(a);
  det_aut(a,&ad);
  aff_aut_d(ad);

  return 1;
}

// je fais le tab de delta dans automate.c
// faut modif est_ aj_ ... en une fonction puisque fonctions est_ utilisées uniquement dans aj_???
// '--> à vérif donc
// q_d_ens qui référence les ensembles remplace ensemble [] en int
// -> corriger fonctions utilisant Ad.td
