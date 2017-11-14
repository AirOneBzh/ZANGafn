#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void emonder(Automate *A){
  int i,j;
  int acc=0;
  for(i=1; i<A->q[0]; i++){
    if(A->q[i]!=A->f[i]){
      for(j=1; j<A->t[0]; j+=3){
        if(i!=A->t[j])acc++;
        else{
          if(A->t[j]!=A->t[j+2])acc=0;
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
//##################################################################//
//return trans d'un ens par etiquette
void trans(Automate *A, int *etat, char c,int result[MAX]){
  int i,j;
  result[0]=etat[0];
  for(i=1; i<=etat[0]; i++){
    result[i]=0;
    if(etat[i]==1){
      for(j=2; j<=A->t[0]; j+=3){
        if(A->t[j]==c && i==A->t[j-1]){
          result[A->t[j+1]]=1;
        }
      }
    }
  }
}
