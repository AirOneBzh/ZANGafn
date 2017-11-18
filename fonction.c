#include <stdio.h>
#include <stdlib.h>
#include "automate.h"



void emonder(Automate *A){
  int i,j;
  int acc=0;
  for(i=1; i<A->q.ens[0]; i++){
    if(A->q.ens[i]!=A->f.ens[i]){
      for(j=1; j<A->t[0]; j+=3){
        if(i!=A->t[j])acc++;
        else{
          if(A->t[j]!=A->t[j+2])acc=0;
          else acc++;
        }
      }
      if(acc==A->t[0]){
        A->q.ens[i]=0;
        A->i.ens[i]=0;
        A->f.ens[i]=0;
      }
    }
  }
}
//##################################################################//
