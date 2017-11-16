#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "ensemble.h"


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

//return trans d'un ens par etiquette sur afn
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
// trans mais sur afd
ensemble trans_d(Automate_d *A, ensemble ens_dep, char etiq){
  int i;
  ensemble e;
  if(1-est_trans(A.td))
  for(i=1; i<=A->td[0].ens[0]; i++){
    if(eg_ens(A->td[i],ens_dep) && A->td[0].ens[i]==etiq){
      return A->td[i+1];
    }
    else{
      return A->td[0];
    }
  }
  return e;
}


int est_trans(ensemble td[],ensemble e1,char etiq,ensemble e2){
  int i;
  for(i=1;i<td[0];i++){
    if(td[i]==e1 && td[i+1]==e2 && td[0].ens[i]==etiq){
      return 1;
    }
  }
  return 0;
}

// ajouter transition etat / initial /final
int aj_trans(Automate_d *A,ensemble ens_dep,char etiq,ensemble ens_arr){
  int i=0,test=0;         // test -> si etiquette est dans alphabet =1 sinon =0
  while(A->a[i]!='\0' && test==0){
    if(A->a[i]==etiq)test=1;
    i++;
  }
  if(est_trans(A->td,ens_dep,etiq,ens_arr))test=0;
  if(test == 1){
      A->td[A->td[0].ens[0]*2+1]=ens_dep;
      A->td[A->td[0].ens[0]*2+2]=ens_arr;
      A->td[0].ens[A->td[0].ens[0]+1]=etiq;
      A->td[0].ens[0]++;
      return 1;  //une trans ajoutée
    }

  return 0;   //aucune transition ajoutée
}
