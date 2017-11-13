#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

void emonder(Automate *A){
  int i,j;
  for(i=1; i<A->q[0]; i++){
    for(j=1; j<A->q[0]; j++){
      if(A->q[i]!=A->A->f[i]){
