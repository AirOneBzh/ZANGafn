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

  ensemble trans_d(Automate_d *A, ensemble ens_dep, char etiq){
    int i;
    ensemble e;
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
  /*
  // ajouter transition etat / initial /final
  int aj_trans(Automate_d *A,ensemble ens_dep,char etiq,ensemble ens_arr){
  int i=0,test=0,res[MAX];         // test -> si etiquette est dans alphabet =1 sinon =0
  while(A->A[i]!='\0' && test==0){
  if(A->A[i]==e)test=1;
  i++;
}

if(test == 1){
if(eg_ens(trans(&A,ens_dep,e),ens_arr)==0){
A->td[A->td[0].ens[0]*2+1]=dep;
A->td[A->td[0].ens[0]*2+2]=arr;
A->td[0].ens[A->td[0].ens[0]+1]=e;
A->td[0].ens[0]++;
return 1;  //une trans ajoutée
}
}
else{
return 0;   //aucune transition ajoutée
}
}

int aj_etat(Automate_d *A,ensemble ens){

}


// manip ensemble -> module ensemble à ajouter


*/
