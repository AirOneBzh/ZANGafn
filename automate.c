#include <stdio.h>
#include <stdlib.h>
#include "automate.h"

void A_defaut(Automate *A){
  A->q.ens[0]=3;
  A->q.ens[1]=A->q.ens[2]=A->q.ens[3]=1;

  A->a[0]=2;
  A->a[1]='a';
  A->a[2]='b';

  A->t.ens[0]=6;
  A->t.ens[1]=A->t.ens[3]=A->t.ens[4]=A->t.ens[7]=A->t.ens[9]=1;
  A->t.ens[6]=A->t.ens[10]=2;
  A->t.ens[12]=A->t.ens[13]=A->t.ens[15]=A->t.ens[16]=A->t.ens[18]=3;

  A->t.ens[2]=A->t.ens[5]=A->t.ens[14]='a';
  A->t.ens[8]=A->t.ens[11]=A->t.ens[17]='b';

  A->i.ens[0]=1;
  A->i.ens[1]=1;

  A->f.ens[0]=1;
  A->f.ens[3]=1;

}
/*
int A_fichier(Automate A){
  char nom[30];
  char *ligne;
  FILE* f;
  fprintf(stdout,"Veuillez insérer le nom du fichier: (avec l'extension si présente)\n");
  fscanf(stdin,"%s",nom);
  f=fopen(nom,"r" );
  if(f==NULL){
    fprintf(stderr,"Le fichier ne peut pas etre ouvert\n");
    return 0;
  }
  do{
    fgets(f,50,ligne);
  }
  while(ligne!=NULL);
  return 1;
}

int A_saisie(){
  printf("Saisie");
  return 1;
}
*/
int init_automate(Automate *A){
  int x;

  fprintf(stdout,"Quel type de saisie voulez vous?\n1- Automate de base (par defaut)\n2- Lecture par fichier\n3- Saisie manuelle (bon chance)\n");
  fscanf(stdin,"%d",&x);
  /*if(x==2){
    while(A_fichier(A)==0);
    return A;
  }
  */
  if(x==3){

    return 3;
  }
  A_defaut(A);
  return 1;
}
