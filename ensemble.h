#define MAX 50

typedef struct{
  int ens[MAX];
}ensemble;

int est_ens(ensemble q[],ensemble e);
int est_etat(ensemble e,int n);
int eg_ens(ensemble ens1,ensemble ens2);
int aj_etat(ensemble *e,int n);
int aj_trans(int t[50],int etat_dep,char etiq,int etat_arr);
int etoi(ensemble e,int r[]);
int itoe(int r[],ensemble e);
int trans(int t[50], int etat_dep, char c,int etat_arr[]);
int ens_d(ensemble e,ensemble q_d[],int t_d[][MAX]);
