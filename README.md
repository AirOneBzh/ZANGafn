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
1 si ens1 = ens2  
0 sinon
</details>

<details><summary>est_ens</summary>

<code>
int est_ens(ensemble q[],ensemble e)
</code>

Renvoi 1 si e appartient à la liste d'ensemble q
</details>

<details><summary>est_etat</summary>
<code>int est_etat(ensemble e,int n)</code>
</details>

<details><summary>aj_ens</summary>
<code>int aj_ens(ensemble q[],ensemble e)</code>
</details>    

<details><summary>aj_etat</summary>
<code>int aj_etat(ensemble \*e,int n)</code>
</details>   

<details><summary>supp_etat</summary>
<code>int supp_etat(ensemble \*e,int n)</code>
</details>  

<details><summary>trans</summary>
<code>a revoir</code>
</details>    

<details><summary>est_trans</summary>
<code>int est_trans(int t[],int etat_dep,char etiq,int etat_arr)</code>
</details>

<details><summary>aj_trans</summary>
<code>int aj_trans(int \*t,int etat_dep,char etiq,int etat_arr)</code>
</details>  

<details><summary>trans_d</summary>
<code>ensemble trans_d(Automate_d A, ensemble ens_dep, char etiq)</code>
</details>   

<details><summary>est_trans_d </summary>
<code>int est_trans_d(ensemble td[],ensemble ens_dep,char etiq,ensemble ens_arr)</code>
</details>   

<details><summary>aj_trans_d</summary>
<code>int aj_trans_d(ensemble \*td[],ensemble ens_dep,char etiq,ensemble ens_arr)</code>
</details>   

<!--
<details><summary></summary>
<code></code>
</details>
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
