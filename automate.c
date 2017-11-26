#include <stdio.h>
#include <stdlib.h>
#include "automate.h"
#include "afficheur.h"
#include <string.h>

void A_defaut(Automate *A){
  A->q.ens[0]=3;
  A->q.ens[1]=A->q.ens[2]=A->q.ens[3]=1;

  A->a[0]=2;
  A->a[1]='a';
  A->a[2]='b';

  A->t[0]=6;
  A->t[1]=A->t[3]=A->t[4]=A->t[7]=A->t[9]=1;
  A->t[6]=A->t[10]=2;
  A->t[12]=A->t[13]=A->t[15]=A->t[16]=A->t[18]=3;

  A->t[2]=A->t[5]=A->t[14]='a';
  A->t[8]=A->t[11]=A->t[17]='b';

  A->i.ens[0]=1;
  A->i.ens[1]=1;

  A->f.ens[0]=1;
  A->f.ens[3]=1;

}

int A_fichier(Automate *A){
  int i=0,j,k,n,etat1,etat2;
  char ligne[50][20],donnee[30];
  FILE *f;
  char c,etiq;
  fprintf(stdout,"Modifiez le fichier \"loader\" pour insérez votre automate\n");

  f = fopen("loader","r");
  if(f==NULL){
    fprintf(stderr,"Le fichier ne peut pas etre ouvert\n");
    return 0;
  }
  A->q.ens[0]=0;
  A->a[0]=0;
  A->t[0]=0;
  do{
    fgets(ligne[i],50,f);
    if(ligne[i][0]=='E' && ligne[i][1]=='O' && ligne[i][2]=='F'){
      break;
    }
    fgets(donnee,50,f);
    sscanf(ligne[i],"%c%d:",&c,&n);
    for(j=0;j<n;j++){
      if(c=='Q'){
        sscanf(donnee,"%d ",&etat1);
        aj_etat(&A->q,etat1);
        donnee[j*2]=' ';
      }
      if(c=='a'){
        sscanf(donnee,"%c",&etiq);
        A->a[0]++;
        A->a[A->a[0]-0]=etiq;   // -0 pour convertir code ascii en int
        for(k=0;k<n-j;k++){
          donnee[k*2]=donnee[(k+1)*2];
        }
      }
      if(c=='t'){
        sscanf(donnee,"%d%c%d ",&etat1,&etiq,&etat2);
        aj_trans(A->t,etat1,etiq,etat2);
        donnee[j*4]=donnee[j*4+1]=donnee[j*4+2]=' ';
      }
      if(c=='i'){
        sscanf(donnee,"%d",&etat1);
        aj_etat(&A->i,etat1);
        donnee[j*2]=' ';
      }
      if(c=='f'){
        sscanf(donnee,"%d",&etat1);
        aj_etat(&A->f,etat1);
        donnee[j*2]=' ';
      }
    }

    i++;
  }
  while(1);

  return 1;
}


int A_saisie(Automate *A){
  printf("Saisie");
  return 1;
}

int init_aut(Automate *A){
  int x;
  fprintf(stdout,"Quel type de saisie voulez vous?\n1- Automate de base (par defaut)\n2- Lecture par fichier\n3- Saisie manuelle (bon chance)\n");
  fscanf(stdin,"%d",&x);
  if(x==2){
    while(A_fichier(A)==0);
    return 2;
  }
  if(x==3){
    A_saisie(A);
    return 3;
  }
  A_defaut(A);
  return 1;
}


int res_trans_d(Automate A,int t_d[][MAX], ensemble q_d[]){
  int i,j,k,dep[10],arr[10];
  ensemble e;
  for(i=1;i<=q_d[0].ens[0];i++){
    for(j=1;j<=A.a[0];j++){
      etoi(q_d[t_d[i][0]],dep);
      for(k=1;k<=dep[0];k++){
        trans(A.t,dep[k],A.a[j],arr);
      }
      itoe(arr,e);
      t_d[i][j]=ens_d(e,q_d,t_d);
    }
  }
  return 1;
}


// utilisation de l'automate
int det_aut(Automate A,Automate_d *Ad){
  ens_d(A.i,Ad->q_d,Ad->t_d);
  res_trans_d(A,Ad->t_d,Ad->q_d);
  strcpy(Ad->a,A.a);
  Ad->i_d=1;
  return 1;
}

int rec_mot(Automate A,char mot[]){
  int i,j;

  int etats[50][50];
  etoi(A.i,etats[0]);
  for(i=0;i<strlen(mot);i++){
    etats[i+1][0]=0;
    for(j=1;j<=etats[i][0];j++){
      trans(A.t,etats[i][j],mot[i],etats[i+1]);
    }

  }
  for(j=1;j<=etats[i][0];j++){
    if(est_etat(A.f,etats[i][j])){
      return 1;
    }
  }
  return 0;
}

int rec_mot_d(Automate_d A,ensemble q_d[],char mot[]){

  int i;

  for(i=0;i<strlen(mot)-1;i++){

  }
  return 1;
}
