#include <stdio.h>
#include <stdlib.h>
#include "automate.h"
#include "afficheur.h"


//manip d'un ensemble
// égalité entre deux ensemble
int eg_ens(ensemble ens1,ensemble ens2){

  int i,j;
  j=0;
  if(ens1.ens[0]==ens2.ens[0]){
    for(i=0;j<ens1.ens[0];i++){
      if(ens1.ens[i]==1 && ens2.ens[i]==1){
        j++;
      }
      if(ens1.ens[i]!=ens2.ens[i]){
        return 0;
      }
    }
  }
  else{
    return 0;
  }
  return 1;
}

//verif si ens e est dans liste ensembles q
int est_ens(ensemble q[],ensemble e){
  int i;
  for(i=0;i<q[0].ens[0];i++){
    if(eg_ens(q[i],e)){
      return 1;
    }
  }
  return 0;
}

//verif si n est un état dans ensemble e 1 oui 0 non
int est_etat(ensemble e,int n){
  if(e.ens[n]==1){
    return 1;
  }
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


//ajout supp d'un état dans un ensemble
// mettre q i ou f pour un état normal initial ou final
int aj_etat(ensemble *e,int n){
  //int i,acc=0;
  if(est_etat(*e,n)){
    return 0;
  }
  e->ens[0]++;
  e->ens[n]=1;
  return 1;
}

void vider_ens(ensemble *e){
  int i;
  for(i=0;i<11;i++){
    e->ens[i]=0;
  }
}

int etoi(ensemble e,int r[]){
  int i,ro;
  ro=0;
  r[0]=e.ens[0];
  for(i=1;ro<=r[0];i++){
    if(e.ens[i]==1){
      ro++;
      r[ro]=i;
    }
  }
  return 1;
}


//
//
//  Manip des ensemble de transition
//
//

//return & d'un ens par etiquette sur afn
// retourne nb de transitions
int trans(ensemble t[][MAX], int etat_dep, char etiq,ensemble *arr){
  int i,tmp[MAX];
  for(i=1;i<=t[0][0].ens[1];i++){
    if(t[0][i].ens[0]==etiq){
      break;
    }
  }
  etoi(t[etat_dep][i],tmp);
  for(i=1;i<=tmp[0];i++){
    aj_etat(arr,tmp[i]);
  }
  return 1;
}

int est_trans(ensemble t[][MAX],int etat_dep,char etiq,int etat_arr){
  int i;

  for(i=1;i<=t[0][0].ens[1];i++){
    if(t[0][i].ens[0]==etiq){
      break;
    }
  }

  if(est_etat(t[etat_dep][i],etat_arr)){
    return 1;
  }
  return 0;
}

int aj_trans(ensemble t[][MAX],int etat_dep,char etiq,int etat_arr){
  int i;
  if(est_trans(t,etat_dep,etiq,etat_arr)){
    return 0;
  }
  for(i=1;i<=t[0][0].ens[1];i++){
    if(t[0][i].ens[0]==etiq){
      break;
    }
  }
  aj_etat(&t[etat_dep][i],etat_arr);
  return 1;
}

int ens_d(ensemble e,ensemble q_d[],int t_d[][MAX]){
  int i;
  if(e.ens[0]==0){
    return 0;
  }

  for(i=1;i<=q_d[0].ens[0];i++){
    if(eg_ens(q_d[i],e)){
      return i;
    }
  }
  q_d[0].ens[0]++;
  q_d[q_d[0].ens[0]]=e;
  t_d[q_d[0].ens[0]][0]=q_d[0].ens[0];
  return q_d[0].ens[0];
}
