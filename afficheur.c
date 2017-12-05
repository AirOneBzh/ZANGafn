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
  fprintf(stdout," }");
}

int aff_trans(ensemble t[][MAX]){
  int i,j,k,arr[MAX];
  fprintf(stdout,"{ ");
  for(i=1;i<=t[0][0].ens[0];i++){      //.ens[0] = nb etats dep
    for(j=1;j<=t[0][0].ens[1];j++){   // .ens[1] = nb alphabet
      etoi(t[i][j],arr);
      for(k=1;k<=arr[0];k++){
        fprintf(stdout, "(%d %c %d) ", i, t[0][j].ens[0],arr[k]);
      }
    }
  }
  fprintf(stdout,"}");
  return 1;
}

int aff_trans_d(int t_d[][MAX],ensemble q_d[]){
  int i,j;
  for(i=1; i<=q_d[0].ens[0]; i++){ //nombre d'états dep
  for(j=1; j<=t_d[0][0]; j++){       // t_d[0][0]     = lg alphabet
    aff_ens(q_d[i]);
    fprintf(stdout,": %c :",t_d[0][j]);
    aff_ens(q_d[t_d[i][j]]);
    printf("\n");
  }
  printf("\n");
}
return 1;
}


//affiche un automate dans le terminal
int aff_aut(Automate A){
  int i;
  fprintf(stdout,"Q=");
  aff_ens(A.q);
  fprintf(stdout,"\nA= { ");
  for(i=1;i<=A.a[0];i++){
    fprintf(stdout,"%c ",A.a[i]);
  }
  fprintf(stdout,"}\nT= ");
  aff_trans(A.t);
  fprintf(stdout,"\nI=");
  aff_ens(A.i);
  fprintf(stdout,"\nF=");
  aff_ens(A.f);
  printf("\n");

  return 1;
}

int aff_aut_d(Automate_d a){
  int i;
  char alph[MAX];
  fprintf(stdout, "\n\nQ = \n");
  for(i=1; i<=a.q_d[0].ens[0]; i++){
    aff_ens(a.q_d[i]);
    fprintf(stdout," : %d\n",i);
  }
  fprintf(stdout, "\nA = { ");
  i=1;
  while(a.a[i]!='\0'){
    fprintf(stdout,"%c ",a.a[i]);
    i++;
  }
  fprintf(stdout,"%s",alph);
  fprintf(stdout,"}\n");

  fprintf(stdout, "T =\n");
  aff_trans_d(a.t_d,a.q_d);
  fprintf(stdout, "\nI=\n");
  aff_ens(a.q_d[a.i_d]);
  fprintf(stdout, "\nF=\n");
  int acc=0;
  for(i=1; acc<a.f_d.ens[0];i++){
    if(a.f_d.ens[i]==1){
      aff_ens(a.q_d[i]);
      acc++;
    }
  }
  fprintf(stdout,"\n");
  return 1;
}

int main (){
  Automate a;
  Automate_d ad;
  init_aut(&a);
  aff_aut(a);
  det_aut(a,&ad);
  aff_aut_d(ad);
  rec_mot(a,"abaababb");
  return 1;
}

// je fais le tab de delta dans automate.c
// faut modif est_ aj_ ... en une fonction puisque fonctions est_ utilisées uniquement dans aj_???
// '--> à vérif donc
// q_d_ens qui référence les ensembles remplace ensemble [] en int
// -> corriger fonctions utilisant Ad.td
