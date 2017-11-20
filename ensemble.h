#define MAX 50

typedef struct{
  int ens[MAX];
}ensemble;

int est_ens(ensemble q[],ensemble e);
int est_etat(ensemble e,int n);
int eg_ens(ensemble ens1,ensemble ens2);
int aj_etat(ensemble *e,int n);
int aj_trans(int t[50],int etat_dep,char etiq,int etat_arr);
int sep_ens_init(ensemble i,int r[]);
int trans(int t[50], int etat_dep, char c,int etat_arr[]);
int trans_d(ensemble td[50], ensemble ens_dep, char etiq,ensemble ens_arr);
