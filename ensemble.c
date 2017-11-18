#include <stdio.h>
#include <stdlib.h>
#include "automate.h"


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

//verif si ens e est dans liste ensembles q
int est_ens(ensemble q[],ensemble e){
  return 1;
}

//verif si n est un état dans ensemble e 1 oui 2 non
int est_etat(ensemble e,int n){
  return 0;
}

//ajoute un ensemble à une liste ensemble d'ensemble
int aj_ens(ensemble q[],ensemble e){
  if(est_ens(q,e)){
    return 0;
  }
  q[0].ens[0]+=1;
  q[q[0].ens[0]]=e;
  return 1;
}

//return trans d'un ens par etiquette sur afn
ensemble trans(Automate A, ensemble ens_dep, char c){
  int i,j;
  ensemble res;
  res.ens[0]=ens_dep.ens[0];
  for(i=1; i<=ens_dep.ens[0]; i++){
    if(ens_dep.ens[i]==1){
      for(j=2; j<=A.t[0]; j+=3){
        if(A.t[j]==c && i==A.t[j-1]){
          res.ens[A.t[j+1]]=1;
        }
      }
    }
  }
  return res;
}

int est_trans_d(ensemble td[],ensemble ens_dep,char etiq,ensemble ens_arr){
  int i;
  for(i=1;i<td[0].ens[0];i++){
    if(eg_ens(td[i],ens_dep) && eg_ens(td[i+1],ens_arr) && td[0].ens[i]==etiq){
      return 1;
    }
  }
  return 0;
}

// trans mais sur afd
ensemble trans_d(Automate_d A, ensemble ens_dep, char etiq){
  int i;
  ensemble e;
  e.ens[0]=0;

  for(i=1; i<=A.td[0].ens[0]; i++){
    if(eg_ens(A.td[i],ens_dep) && A.td[0].ens[i]==etiq){
      return A.td[i+1];
    }
  }
  return e;
}

int est_trans(int t[],int etat_dep,char etiq,int etat_arr){
  int i;
  for(i=0;i<t[0];i++){
    if(etat_dep==t[i] && etiq==t[i+1] && etat_arr==t[i+2]){
      return 1;
    }
  }
  return 0;
}

int aj_trans(int *t,int etat_dep,char etiq,int etat_arr){
  int n = t[0];
  if(est_trans(t,etat_dep,etiq,etat_arr)){
    return 0;
  }
  t[n*3+1]=etat_dep;
  t[n*3+2]=etiq;
  t[n*3+3]=etat_arr;
  t[0]++;

  return 1;
}

// ajouter transition etat / initial /final
int aj_trans_d(ensemble *td[],ensemble ens_dep,char etiq,ensemble ens_arr){
  if(est_trans_d(*td,ens_dep,etiq,ens_arr)){
    return 0;   //aucune transition ajoutée
  }
  (*td[td[0]->ens[0]*2+1])=ens_dep;
  (*td[td[0]->ens[0]*2+2])=ens_arr;
  td[0]->ens[td[0]->ens[0]+1]=etiq;
  td[0]->ens[0]++;
  return 1;  //une trans ajoutée
}

//ajout supp d'un état dans un ensemble
// mettre q i ou f pour un état normal initial ou final
int aj_etat(ensemble *e,int n){
  if(est_etat(*e,n)){
    return 0;
  }
  e->ens[0]++;
  e->ens[n]=1;
  return 1;
}

int supp_etat(ensemble e,int n){
  if(est_etat(e,n)){
    e.ens[n]=0;
    e.ens[0]-=1;
    return 1;
  }
  return 0;
}
