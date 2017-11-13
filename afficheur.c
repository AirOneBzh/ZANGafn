#include <stdlib.h>
#include <stdio.h>

typedef struct{
  int qd[MAX][MAX];
  char ad[MAX];
  int td[MAX][MAX];//{pos etiq;etat1;etat2;etat3;etiquette;etat1';....}
  int id[MAX][MAX];
  int fd[MAX][MAX];
}Automate_d;


int aff_det_term(Automate_d a){
  int i;
  printf("Q = {");
  for(i=1;i<=a.qd[0];i++){
    printf(" %d",i);
  }
  printf(" }\nI = {");
  for(i=1;i<=a.qd[0];i++){
    if(a.id[i]==1){
      printf(" %d",i);
    }
    else{
      printf("  ");
    }
  }
  printf(" }\nF= {");
  for(i=1;i<=a.qd[0];i++){
    if(a.fd[i]==1){
      printf(" %d",i);
    }
    else{
      printf("  ");
    }
  }

}


int main (){
  Automate_d a;
  int i;
  a.qd[0]=7;
  for(i=1;i<8;i++){
    a.qd[i]=1;
  }
  a.id[0]=2;
  a.id[1]=a.id[3]=1;
  a.id[2]=a.id[4]=a.id[5]=a.id[6]=a.id[7]=0;
  a.fd[0]=2;
  a.fd[4]=a.fd[6]=1;
  a.id[1]=a.id[2]=a.id[3]=a.id[5]=a.id[7]=0;
  aff_det_term(a);
}
