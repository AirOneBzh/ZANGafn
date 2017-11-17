#include <stdlib.h>
#include <stdio.h>
#include "fonction.h"

#define MAX 50

void aff_ens_etat(ensemble e){
  int i;
  int acc=0;
  printf("{");
  for (i=1;acc<e.ens[0];i++){
    if(e.ens[i]==1){
      printf(" %d",i);
      acc++;
    }
  }
  printf(" };");
}

int aff_det_term(Automate_d a){
  int i;
  printf("Q = {");
  for(i=1;i<=a.qd[0].ens[1];i++){
    aff_ens_etat(a.qd[i]);
  }
  printf("}\nI={");
  aff_ens_etat(a.id);
  printf("}\nQ={");
  for(i=1;i<=a.fd[0].ens[0];i++){
    aff_ens_etat(a.fd[i]);
  }
  printf("}\n");


  return 1;
}


int main (){
  Automate_d a;
// etats
  a.qd[0].ens[0]=7;
  a.qd[0].ens[1]=4;

  a.qd[1].ens[0]=2;
  a.qd[1].ens[1]=a.qd[1].ens[3]=1;
  a.qd[2].ens[0]=2;
  a.qd[2].ens[1]=a.qd[2].ens[2]=1;
  a.qd[3].ens[0]=3;
  a.qd[3].ens[4]=a.qd[3].ens[5]=a.qd[3].ens[7]=1;
  a.qd[4].ens[0]=2;
  a.qd[4].ens[6]=a.qd[4].ens[7]=1;

  a.id=a.qd[1];

  a.fd[0].ens[0]=2;
  a.fd[1]=a.qd[3];
  a.fd[2]=a.qd[4];

  aff_det_term(a);

  printf("eg%d\n",eg_ens(a.fd[1],a.qd[2]));
  return 1;
}
