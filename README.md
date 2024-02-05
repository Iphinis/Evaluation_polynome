# Quelques prérequis

Pour pouvoir tracer les graphiques, il faut installer la librairie SDL :

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev


--------------------------------------------------------------------------------------
# Description de la démarche

## Introduction
Pour exécuter correctement le code et de la même façon sur toutes les machines, nous avons créé un Makefile. Le compilateur est gcc mais il est possible de le changer en modifiant le paramètre CC du Makefile.

Nous avons décidé de mettre en places 2 modes d'exécution de notre code : automatique (mode 1) et manuel (mode 2). Le mode est choisi au début de l'exécution.

 - Le mode automatique demande uniquement le numéro de machine qu'on note k, et va lire les données du dossier input/ pour écrire les résultats des instructions qui vont être effectuées dans output/mk/. Il n'y a donc rien à saisir à part le numéro de la machine, comme dit, tout est automatique.

 - Le mode manuel est une interface homme-machine en ligne de commande qui permet d'interagir avec le programme en direct à l'aide de commandes qui sont affichées à l'écran. Il ne lit/n'écrit pas dans des fichiers. C'est uniquement pour tester en direct toutes les fonctions à disposition.


## Approche naïve

1. Tout d'abord, on a commencé par vouloir évaluer un polynôme en n'importe quel valeur alpha de manière classique. Pour cela, on a créé les fichiers poly.c et poly.h, contenant la description des fonctions creerPolynome et remplirPolynome; et les fichiers alpha.c et alpha.h contenant la description de la fonction enAlphaNaif.

A cet instant, on s'est dit qu'il serait intéressant d'observer l'allure des polynômes. C'est pourquoi on a créé les fichiers renderer.c et renderer.h qui utilisent la librairie SDL (cf prérequis).

Ensuite, on a testé nos fonctions en évaluant un polynôme de degré 3, ayant pour coefficient {1,-2,3,4} en une valeur alpha=-0.75.

Le fichier de données utilisé est le fichier donnees_naives.txt. Il est constitué comme suit :

3 : Degré du polynôme
1 -2 3 4 : coefficients
-0.75 : alpha

Vous retrouverez le résultat dans le fichier res_naif_mk.txt dans le dossier output/mk/, avec k qui est le numéro de la machine qui a exécuté le code.


## Méthode de Horner

2. Ensuite on a décidé d'évaluer plusieurs polynomes avec la méthode Horner. Pour cela, on a créé une fonction enAlpha dans les fichiers alpha.c et alpha.h. 

Voici les polynomes tests :

1) 1 + 3x**2 + 2 x**3 + 6x**5 en x=3.2
2) x - 4x**2 + 7x**5 - 3x**6 en x=-5.1

Les fichiers de données utilisés sont donnees_hd_5_3.2_mk.txt et donnees_hd_6_-5.1_mk.txt dans le dossier input. Ils sont constitués comme suit :

5 : degré du polynome
1 0 3 2 0 6 : coefficients
3.2 : alpha

6 : degré du polynome
0 1 -4 0 0 7 -3 : coefficients
-5.1 : alpha

Vous retrouverez les résultats dans les fichiers res_hd_5_3.2_mk.txt et res_hd_6_-5.1_mk.txt dans le dossier output.


## Calcul des dérivées successives 

3. Ensuite, on a décidé de calculer chacune des dérivées des deux polynômes évalués précédemment. Pour cela, on a créé les fichiers derivees.c et derivees.h contenant une fonction calculerFact et une fonction deriveesEnAlpha. On a ensuite calculer chacune des dérivées du polynôme en alpha. 

Les fichiers de données utilisés sont les meême que précédement : donnees_hd_5_3.2_mk.txt et donnees_hd_6_-5.1_mk.txt dans le dossier input. Ils sont constitués comme suit :

Vous retrouverez les résultats dans les mêmes fichiers res_hd_5_3.2_mk.txt et res_hd_6_-5.1_mk.txt dans le dossier output.


## Méthode de Clenshaw : base de Tchebychev

4. On a tout d'abord implémenter l'algorithme de descente, bien que cette méthode ne soit pas efficace. Il s'agit de la fonction methodeDescente qui se situe dans les fichiers matrice.c et matrice.h nouvellement créé. Aussi, on a créé des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur et multiplicationMatriceVect dans ces mêmes fichiers.

Le fichier de données utilisé est le fichier donnees_AN_P6_2_d.txt. Il est constitué comme suit :

6 : degré dupolynome dans la base de Tchebychev
2.1 3 -2.5 0 0 1 -4 : coefficients dans la base de Tchebychev
2 : alpha
2.1 3 -2.5 0 0 1 -4 : coefficients dans la base de Tchebychev


Vous retrouverez le résultat dans le fichier res_AN_P6_2_d_mk.txt dans le dossier output.


5. Ensuite, on a implémenté l'algorithme de Clenshaw, bien moins couteux que la méthode de descente. Le fichier de données utilisé est le même que précédemment : donnees_AN_P6_2.txt. 

Vous retrouverez le résultat dans le fichier res_AN_P6_2_c_mk.txt dans le dossier output.

On visualise l'allure des 2 mêmes polynômes vu précédemment avec SDL.


## Calcul de ln(10+6x)

6. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de ln(10+6x) à 10**-4 près. 

On a donc appliqué l'algorithme de Clenshaw avec alpha=-1 dans un premier temps; puis ensuite avec des valeurs proches : alpha=0.1 et alpha=0.2.

Les fichiers de données utilisés sont donnees_ln_0.2.txt ; donnees_ln_0.1.txt et donnees_ln_1.txt dans le dossier input. Ils sont constitués comme suit :

0.2 ou 0.1 ou 1 : alpha

Vous retrouverez les résultats dans les fichiers res_ln_0.2_mk.txt ; res_ln_0.1_mk.txt et res_ln_1_mk.txt dans le dossier output.


## Calcul de (10+x)/(101+20x)

7. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de (10+x)/(101+20x) à 10**-5 près. 

On a donc appliqué l'algorithme de Clenshaw avec alpha=0.2 et alpha=-0.7.

Les fichiers de données utilisés sont donnees_10x_0.2.txt et donnees_10x_-0.7.txt dans le dossier input. Ils sont constitués comme suit :

0.2 ou -0.7 : alpha

Vous retrouverez les résultats dans les fichiers res_10x_-0.7_mk.txt et res_10x_0.2_mk.txt dans le dossier output.



--------------------------------------------------------------------------------------
# Caractéristiques machine

## Machine 1 (m1)
Nom: po-d82fx93
Processeur: Intel® Core™ i7-10810U CPU @ 1.10GHz × 12
Mémoire vive: 8 gb
Système d'exploitation: Ubuntu 22.04.3 LTS 64-bit
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Editeur: VSCODE

## Machine 2 (m2)
Nom : po-d82fx93
Mémoire vive: 8,0 Gio
Processeur: Intel® Core™ i7-10810U CPU @ 1.10GHz × 12
Système d'exploitation : Ubuntu 22.04.3 LTS 64-bits
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Editeur: VSCODE


--------------------------------------------------------------------------------------
# Description des fichiers


## Données:
Dossier: input

    Dossier : Auto
    Nomenclature: donnees_auto_mk.txt
    Contenu:
        Données permettant une lecture automatique du main afin d'obtenir tout les résultats possible à partir d'un polynome. Les résultats sont stockés dans un fichier res_auto_mk.txt dans le dossier Auto du dossier output.
   
   Dossier : Man_mk
   Nomenclature : donnees_..._mk.txt
   Contenu : 
   	Données servant au bon déroulement de notre démarche. Leurs contenu a donc déjà été expliqué précédemment.


## Résultat:
Dossier: output
    
    Dossier : Auto
    Nomenclature: res_auto_mk.txt (k = numéro de la machine)
    Contenu:
        Résultats des fichiers donnees_auto_mk.txt
    
    Dossier : Man_mk
    Nomenclature : res_..._mk.txt
    Contenu : 
    	Résultats des fichiers donnees_..._mk.txt


## Codes:
Dossier: src

    Dossier : alpha
    Nomenclature: alpha.c
    Contenu:
        --> fonction enAlpha ayant pour paramètres un polynôme p; un scalaire alpha et un tableau b. La fonction permet de remplir le tableau b de sorte à ce que la somme de toutes ces composantes correspondent à la valeur du polynôme p évalué en alpha
   
   
    Dossier : alpha
    Nomenclature: alpha.h
    Contenu:
    	--> Définition de la fonction enAlpha
    
    
    Dossier : matrices
    Nomenclature: matrice.c
    Contenu:
    	--> fonction creerMatrice ayant pour paramètre un entier n. La fonction permet de creer une Matrice de taille n*n en demandant à l'utilisateur chacune des composantes de la matrice
    	--> fonction afficherMatrice ayant pour paramètre une matrice matrice et un entier n. La fonction permet d'afficher la matrice matrice de taille n*n.
    	--> fonction creerVecteur ayant pour paramètre un entier n. La fonction permet de creer un vecteur de taille n en demandant à l'utilisateur chacune des composantes du vecteur
    	--> fonction afficherVecteur ayant pour paramètre un vecteur vecteur et un entier n. La fonction permet d'afficher le vecteur vecteur de taille n.
    	--> fonction methodeDescente ayant pour paramètres une matrice matrice, un vecteur b et un entier n. La fonction renvoie le vecteur x solution du système linéaire matrice*x=b par application de la méthode de descente
    	--> fonction multiplicationMatriceVect ayant pour paramètres une matrice matrice, un vecteur x et un entier n. La fonction renvoie le vecteur solution du produit matrice*x.

	
     Dossier : matrices
     Nomenclature : matrice.h
     Contenu :
     	--> Définition des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur; methodeDescente et multiplicationMatriceVect
     
     
     Dossier : poly
     Nomenclature : poly.c
     Contenu :
     	--> fonction creerPolynome ayant pour paramètre un entier deg. La fonction renvoie un polynome p de degré deg nouvellement créer 
     	--> fonction remplirPolynome ayant pour paramètre un polynome p. La fonction permet de remplir le polynome p en demandant à l'utilisateur de renseigner chacun de ses coefficients
     	--> fonction afficherPolynome ayant pour paramètre un polynome p. La fonction permet d'afficher chacun es coefficient du polynome p
     
     
     Dossier : poly
     Nomenclature : poly.h
     Contenu :
     	--> structure polynome permettant de créer un nouvel objet polynome
     	--> définition des fonctions creerPolynome; remplirPolynome et afficherPolynome
     
     
     Dossier : derivees
     Nomenclature : derivees.c
     Contenu :
     	--> fonction fact ayant pour paramètre un entier k. La fonction renvoie un tableau contenant toutes les valeurs des factorielles allant de 0 à k
     
     
     Dossier : derivees
     Nomenclature : derivees.h
     Contenu :
     	--> définition de la fonction fact
     
     
     Dossier : renderer
     Nomenclature : renderer.c
     Contenu :
     	--> ...................
     
     
     Dossier : renderer
     Nomenclature : renderer.h
     Contenu :
     	--> ...................
     
     
     Nomenclature : main.c
     Contenu :
     	--> On demande le numero de la machine (pour les fichiers d'entrée et de sortie).
     	--> creation du polynome Pn
     	--> Tracer le polynome Pn
     	--> calculer Pn(alpha)
     	--> calculer les n dérivées de Pn en alpha
     	--> AN1 : calcul de P6(2)
