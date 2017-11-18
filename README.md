<!-- ZANGafn-->

analyser un mot avec un automate/deter un automate/chq module utilise les autres  

note \_d est destiné à l'automate deterministe

# Module ensemble
## Fonctions

##### eg_ens
```
int eg_ens(ensemble ens1,ensemble ens2)
```

* 1 si ens1 = ens2  

##### est_ens

```
int est_ens(ensemble q[],ensemble e)
```

* 1 si e appartient à la liste d'ensemble q

##### est_etat
```
int est_etat(ensemble e,int n)
```

* 1 si l'état n fait partie de l'ensemble e

##### aj_ens
```
int aj_ens(ensemble q[],ensemble e)
```   
* 1 si l'ensemble est ajouté la liste


##### aj_etat
```
int aj_etat(ensemble *e,int n)
```  
* 1 si l'état est ajouté à l'ensemble

##### supp_etat
```
int supp_etat(ensemble *e,int n)
```
* 1 si un état supprimé
* 0 sinon _(l'état pouvait être absent)_

##### trans
```
int trans(Automate A, ensemble ens_dep, char c,ensemble ens_arr)
```
* 1 si un état est renvoyé _(ens_arr)_

##### est_trans
```
int est_trans(int t[],int etat_dep,char etiq,int etat_arr)
```
* 1 si la transition existe

##### aj_trans
```
int aj_trans(int *t,int etat_dep,char etiq,int etat_arr)
```
* 1 si la transition a pu être ajoutée



##### trans_d
```
ensemble trans_d(Automate_d A, ensemble ens_dep, char etiq)
```

##### est_trans_d
```
int est_trans_d(ensemble td[],ensemble ens_dep,char etiq,ensemble ens_arr)
```


##### aj_trans_d
```
int aj_trans_d(ensemble *td[],ensemble ens_dep,char etiq,ensemble ens_arr)
```


<!--
#####
``````

 -->



## Structure
##### ensemble
```
typedef struct {  
  int ens[50];  
}
```

# Module automate
## Fonctions

##### A_defaut
```
void A_defaut(Automate *A)
```
* Insère l'automate de test par défaut dans A

##### A_fichier
```
int A_fichier(Automate *A)
```
* Insère l'automate configuré dans le fichier loader dans A

##### A_saisie
```
int A_saisie(Automate *A)
```
* Demande information par information les données à insérer dans l'automate A

##### init_aut
```
int init_aut(Automate *A)
```
* Propose à l'utilisateur le choix de la configuration de l'automate

##### det_aut  
```
int det_aut(Automate A,Automate *B)
```
* Modifie l'automate B pour qu'il soit l'automate A determinisé

## Structures

##### Automate
```
typedef struct{  
  ensemble q;  
  char a[50];  
  int t[50];  
  ensemble i;  
  ensemble f;  
}Automate;  
```

##### Automate_d  
```
typedef struct{  
  ensemble qd[50];  
  char a[50];  
  ensemble td[50];  
  ensemble id;  
  ensemble fd[50];  
}Automate_d;  
```



# Prog afficheur

##### aff_ens
```
void aff_ens(ensemble e)
```  
* Affiche un ensemble d'états e

##### aff_trans
```
int aff_trans(int t[])
```
* Affiche une liste de transitions d'un AFN

##### aff_aut
```
int aff_aut(Automate A)
```  
* Affiche un AFN

##### aff_trans_d
```
int aff_trans_d(ensemble td[])
```  
* Affiche un tableau de transition entre ensembles d'un AFD

##### aff_aut_d
```
int aff_aut_d(Automate_d a)
```  
* Affiche un AFD
