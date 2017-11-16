#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "ensemble.h"

//manip d'un ensemble
int eg_ens(ensemble ens1,ensemble ens2){
  int i,j;
  j=0;
  if(ens1.ens[0]==ens2.ens[0]){
    for(i=0;j<ens1.ens[0];i++){
      if (ens1.ens[i]==1){
        j++;
      }
    }
    if(j==ens1.ens[0]){
      return 1;
    }
  }
  return 0;
}


//manip des états d'un ensemble
int est_etat(ensemble qd[],ensemble e){
  int i;
  for(i=0;i<qd[0];i++){
    if (qd[i]==e){
      return 1;
    }
  }
  return 0;
}

int aj_etat(ensemble e,int n){
  if(est_etat(e,n)){
    return 0;
  }
  else{
    e.ens[n]=1;
    e.ens[0]+=1;
    return 1;
  }
}




int aj_ens(Automate_d A,ensemble e){
  if(is_ens(A,e)){
    return 0;
  }
  else{
    A.qd[0].ens[0]+=1;
    a.qd[A.qd[0].ens[0]]=e;
  }
}
