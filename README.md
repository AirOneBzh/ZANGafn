<!-- ZANGafn-->

analyser un mot avec un automate/deter un automate/chq module utilise les autres  

note \_d est destiné à l'automate deterministe

# Module ensemble
## Fonctions

##### eg_ens
<code>
int eg_ens(ensemble ens1,ensemble ens2)
</code>

* 1 si ens1 = ens2  

##### est_ens

<code>
int est_ens(ensemble q[],ensemble e)
</code>

* 1 si e appartient à la liste d'ensemble q

##### est_etat
<code>
int est_etat(ensemble e,int n)
</code>

* 1 si l'état n fait partie de l'ensemble e

##### aj_ens
<code>
int aj_ens(ensemble q[],ensemble e)
</code>   
* 1 si l'ensemble est ajouté la liste


##### aj_etat
<code>
int aj_etat(ensemble \*e,int n)
</code>  
* 1 si l'état est ajouté à l'ensemble

##### supp_etat
<code>
int supp_etat(ensemble \*e,int n)
</code>
* 1 si un état supprimé
* 0 sinon _(l'état pouvait être absent)_

##### trans
<code>
int trans(Automate A, ensemble ens_dep, char c,ensemble ens_arr)
</code>
* 1 si un état est renvoyé _(ens_arr)_

##### est_trans
<code>
int est_trans(int t[],int etat_dep,char etiq,int etat_arr)
</code>
* 1 si la transition existe

##### aj_trans
<code>
int aj_trans(int \*t,int etat_dep,char etiq,int etat_arr)
</code>
* 1 si la transition a pu être ajoutée



##### trans_d
<code>
ensemble trans_d(Automate_d A, ensemble ens_dep, char etiq)
</code>

##### est_trans_d
<code>
int est_trans_d(ensemble td[],ensemble ens_dep,char etiq,ensemble ens_arr)
</code>


##### aj_trans_d
<code>
int aj_trans_d(ensemble \*td[],ensemble ens_dep,char etiq,ensemble ens_arr)
</code>


<!--
#####
<code></code>

 -->



## Structure
##### ensemble
<code>
typedef struct {  
  int ens[50];  
}
</code>

# Module automate
## Fonctions

##### A_defaut
<code>
void A_defaut(Automate \*A)
</code>
* Insère l'automate de test par défaut dans A

##### A_fichier
<code>
int A_fichier(Automate \*A)
</code>
* Insère l'automate configuré dans le fichier loader dans A

##### A_saisie
<code>
int A_saisie(Automate \*A)
</code>
* Demande information par information les données à insérer dans l'automate A

##### init_aut
<code>
int init_aut(Automate \*A)
</code>
* Propose à l'utilisateur le choix de la configuration de l'automate

##### det_aut  
<code>
int det_aut(Automate A,Automate \*B)
</code>
* Modifie l'automate B pour qu'il soit l'automate A determinisé

## Structures

##### Automate
<code>
typedef struct{  
  ensemble q;  
  char a[50];  
  int t[50];  
  ensemble i;  
  ensemble f;  
}Automate;  
</code>

##### Automate_d  
<code>
typedef struct{  
  ensemble qd[50];  
  char a[50];  
  ensemble td[50];  
  ensemble id;  
  ensemble fd[50];  
}Automate_d;  
</code>



# Prog afficheur

##### aff_ens
<code>
void aff_ens(ensemble e)
</code>  
* Affiche un ensemble d'états e

##### aff_trans
<code>
int aff_trans(int t[])
</code>
* Affiche une liste de transitions d'un AFN

##### aff_aut
<code>
int aff_aut(Automate A)
</code>  
* Affiche un AFN

##### aff_trans_d
<code>
int aff_trans_d(ensemble td[])
</code>  
* Affiche un tableau de transition entre ensembles d'un AFD

##### aff_aut_d
<code>
int aff_aut_d(Automate_d a)
</code>  
* Affiche un AFD
