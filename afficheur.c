#include <stdlib.h>
#include <stdio.h>
#define MAX 50

typedef struct{
  int qd[MAX][MAX];
  char ad[MAX];
  int td[MAX][MAX];//{pos etiq;etat1;etat2;etat3;etiquette;etat1';....}
  int id[MAX];
  int fd[MAX][MAX];
}Automate_d;


int aff_det_term(Automate_d a){
  int i,j,ne,ni;
  ne=a.qd[0][1];
  printf("Q = {");
  for(i=1;i<=ne;i++){
    printf("{");
    ni=a.qd[i][0];
    for(j=1;j<=ni;j++){
      printf(" %d",i);
    }
    printf("}\n");
  }
  printf(" }\nI = {");
  for(i=1;i<=a.id[0];i++){
    if(a.id[i]==1){
      printf(" %d",i);
    }
    else{
      printf("  ");
    }
  }
  printf(" }\nF= {");
  for(i=1;i<=a.fd[0][0];i++){
    for(j=1;j<=a.fd[i][0];j++){
      if(a.fd[i][j]==1){
        printf(" %d",j);
      }
      else{printf("  ");}
      printf("\n");
    }

  }
  return 1;
}


int main (){
  Automate_d a;
  int i;
// etats
  a.qd[0][0]=7;
  a.qd[0][1]=4;
    
  a.qd[1][0]=2;
  a.qd[1][1]=a.qd[1][3]=1;

  a.qd[2][0]=2;
  a.qd[2][1]=a.qd[2][2]=1;

  a.qd[3][0]=3;
  a.qd[3][4]=a.qd[3][5]=a.qd[3][7]=1;

  a.qd[4][0]=2;
  a.qd[4][6]=a.qd[4][7]=1;
// initiaux
  a.id[0]=2;
  a.id[1]=a.id[3]=1;
//finaux
  a.fd[0][0]=2;
  a.fd[1][4]=a.fd[1][5]=a.fd[1][7]=1;

  a.fd[2][0]=2;
  a.fd[2][6]=a.fd[2][7]=1;

  aff_det_term(a);
  return 1;
}
