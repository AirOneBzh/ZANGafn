#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


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
