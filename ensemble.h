typedef struct{
  int ens[MAX];
} ensemble;

int eg_ens(ensemble ens1,ensemble ens2);
int aj_ens(Automate_d A,ensemble e);
int aj_etat(ensemble e,int n);
int est_etat(ensemble qd[],ensemble e);
