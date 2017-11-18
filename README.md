<!-- ZANGafn-->

analyser un mot avec un automate/deter un automate/chq module utilise les autres  

note \_d est destiné à l'automate deterministe

# Module ensemble
## Fonctions
<details><summary>eg_ens</summary>

<code>
int eg_ens(ensemble ens1,ensemble ens2)
</code>
  Renvoi
* 1 si ens1 = ens2  
* 0 sinon
</details>

<details><summary>
est_ens
</summary>

```
int est_ens(ensemble q[],ensemble e)
```  
Renvoi 1 si e appartient à la liste d'ensemble q
</details>

est_etat  
aj_ens  
aj_etat  
supp_etat  
trans  
est_trans  
aj_trans  
trans_d  
est_trans_d  
aj_trans_d  

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
