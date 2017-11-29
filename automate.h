#include "ensemble.h"

  //ensemble q_d  // fait une référence d'un ensemble permet
                 // permet un enregistrement d'un ensemble
                // remplacé par son indice dans tab_delta

         // contient les références des ensembles lignes colonnes
        // colonne 0 etat_dep
       // col i < 0 etat_arr; trans_d (id(etat_dep), etiq[i], id(etat_arr))

typedef struct{
  ensemble q;//pos 0=nb d'états;1 si présent état i pos i;0 sinon
  char a[MAX];
<<<<<<< HEAD
  int t[MAX];//pos 0=nb trans; {etat1;etiquette;etat2}
  ensemble i;//même que q
  ensemble f;//même que q
=======
  ensemble t[MAX][MAX]; 
  ensemble i;     //même que q
  ensemble f;    //même que q
>>>>>>> 75ea209c1084bb9edbef5a8543f317eed2ffe20d
}Automate;

typedef struct{
  ensemble q_d[MAX];
  char a[MAX];
  int t_d[MAX][MAX];   // transitions d'un déter et tableau delta
  int i_d;       // indice de l'ensemble initial dans q_d
  ensemble f_d; // ensemble des indices des ensembles des etats finaux dans q_d
}Automate_d;



int init_aut(Automate *A);
void A_defaut(Automate *A);
int rec_mot(Automate A,char mot[]);
int rec_mot_d(Automate_d A,ensemble q_d[],char mot []);
int det_aut(Automate A,Automate_d *Ad);
int aj_ens_d(ensemble e,ensemble q_d[]);
