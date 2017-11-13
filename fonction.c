#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void emonder(Automate *A){
  int i,j;
  int acc=0;
  for(i=1; i<A->q[0]; i++){
    if(A->q[i]!=A->A->f[i]){
      for(j=1; j<A->t[0]; j+=3){
        if(i!=t[j])acc++;
        else{
          if(t[j]!=t[j+2])acc=0;
          else acc++;
        }
      }
      if(acc==A->t[0]){
        A->q[i]=0;
        A->i[i]=0;
        A->f[i]=0;
      }
    }
  }
}
