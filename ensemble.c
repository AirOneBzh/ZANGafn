#include <stdio.h>
#include <stdlib.h>
#include "automate.h"


//manip d'un ensemble
// égalité entre deux ensemble
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
  if(est_etat(*e,n)){
    return 0;
  }
  e->ens[0]++;
  e->ens[n]=1;
  return 1;
}

int supp_etat(ensemble *e,int n){
  if(est_etat((*e),n)){
    e->ens[n]=0;
    e->ens[0]-=1;
    return 1;
  }
  return 0;
}

int etoi(ensemble e,int r[]){
  int i;
  r[0]=0;
  for(i=1;r[0]<e.ens[0];i++){
    if(e.ens[i]==1){
      r[0]++;
      r[r[0]]=i;
    }
  }
  return 1;
}

int itoe(int r[],ensemble e){
  int i;
  e.ens[0]=0;
  for(i=1;e.ens[0]<r[0];i++){
    if(r[e.ens[0]+1]==i){
      e.ens[0]++;
      e.ens[e.ens[0]]=1;
    }
  }
  return 1;
}

//
//
//  Manip des ensemble de transition
//
//

//return trans d'un ens par etiquette sur afn
// retourne nb de transitions
int trans(ensemble t[][MAX], int etat_dep, char etiq,int etat_arr[]){
  int i,c,tmp[MAX];
  for(c=1;c<=t[0][0].ens[1];c++){
    if(t[0][c].ens[0]==etiq){
      break;
    }
  }
  etoi(t[etat_dep][c],tmp);
  for(i=1;i<=tmp[0];i++){
    etat_arr[etat_arr[0]]=tmp[i];
    etat_arr[0]++;
  }
  return 1;
}

int est_trans(ensemble t[][MAX],int etat_dep,char etiq,int etat_arr){
  int i;

  for(i=1;i<=t[0][0].ens[1];i++){
    printf("t[i%c:",t[0][i].ens[0]);
    if(t[0][i].ens[0]==etiq){
      break;
    }
  }
  printf("dep%d i%de%c arr%d\n",etat_dep,i,etiq,etat_arr);
  if(est_etat(t[etat_dep][i],etat_arr)){
    printf("arr%d\n",etat_arr);
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
