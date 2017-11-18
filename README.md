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
a revoir
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

= = =

##### Automate déterministes

###### trans_d
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
ensemble

# Module automate
## Fonctions
A_defaut  
A_fichier  
A_saisie  
init_aut--omate--  à modif dans fichiers  
det_aut  

## Structures
Automate  
Automate_d  

# Prog afficheur
aff_ens  
aff_trans  
aff_aut  
aff_trans_d  
aff_aut_d  
