# Quelques prérequis

Pour pouvoir tracer les graphiques, il faut installer la librairie SDL :

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev


--------------------------------------------------------------------------------------
# Description de la démarche

## Approche naïve

1. Tout d'abord, on a commencé par vouloir évaluer un polynôme en n'importe quel valeur alpha de manière classique. Pour cela, on a créé les fichiers poly.c et poly.h, contenant la description des fonctions creerPolynome et remplirPolynome; et les fichiers alpha.c et alpha.h contenant la description de la fonction enAlphaNaif. Ensuite, on a testé nos fonctions en évaluant un polynôme de degré 2, ayant pour coefficient {1,2,3} en une valeur alpha=10. 

Le fichier de données utilisé est le fichier donnees_naif_mk.txt. Vous retrouverez le résultat dans le fichier res_naif_mk.txt dans le dossier output.


## Méthode de Horner

2. Ensuite on a décidé d'évaluer plusieurs polynomes avec la méthode Horner. Pour cela, on a créé une fonction enAlpha dans les fichiers alpha.c et alpha.h. 

Voici les polynomes tests :

1) 1 + 3x**2 + 2 x**3 + 6x**5 en x=3.2
2) x - 4x**2 + 7x**5 - 3x**6 en x=-5.1

Les fichiers de données utilisés sont donnes_h_5_3.2_mk.txt et donnes_h_6_-5.1_mk.txt dans le dossier input. Vous retrouverez les résultats dans les fichiers res_h_5_3.2_mk.txt et res_h_6_-5.1_mk.txt dans le dossier output.


## Calcul des dérivées successives 

3. Ensuite, on a décidé de calculer chacune des dérivées des deux polynômes évalués précédemment. Pour cela, on a créé les fichiers derivees.c et derivees.h contenant une fonction calculerFact et une fonction deriveesEnAlpha. On a ensuite calculer chacune des dérivées du polynôme en alpha. 

Les fichiers de données utilisés sont donnes_d_5_3.2_mk.txt et donnes_d_6_-5.1_mk.txt dans le dossier input. Vous retrouverez les résultats dans les fichiers res_d_5_3.2_mk.txt et res_d_6_-5.1_mk.txt dans le dossier output.


## Méthode de Clenshaw : base de Tchebychev

4. On a décidé d'implémenter l'algorithme de descente qui va nous être utile par la suite. Il s'agit de la fonction methodeDescente qui se situe dans les fichiers matrice.c et matrice.h nouvellement créé. Aussi, on a créé des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur et multiplicationMatriceVect dans ces mêmes fichiers. On a effectuer l'analyse numérique demandé en calculant P6(2) par la méthode de Clenshaw. 

On a donc du appliquer la méthode de descente avec     ( 1  0  0  0  0)
                                                       (-4  1  0  0  0)
                                                   A = ( 1 -4  1  0  0)
                                                       ( 0  1 -4  1  0)
                                                       ( 0  0  1 -4  1)
                                                   
                                                   b = (-4 1 0 0 -2.5)T.

Le fichier de données utilisé est le fichier donnes_AN_P6_2_mk.txt. Vous retrouverez le résultat dans le fichier AN_P6_2_mk.txt dans le dossier output.


## Affichage des polynômes

5. A cet instant, on s'est dit qu'il serait intéressant d'observer l'allure des polynômes. C'est pourquoi on a créé les fichiers renderer.c et renderer.h. On souhaite visualiser l'allure des 2 mêmes polynômes vu précédemment. Vous retrouverez le résultat dans le fichier res_poly_affichage_mk.txt dans le dossier output.


## Calcul de ln(10+6x)

6. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de ln(10+6x) à 10**-4 près. 

On a donc appliqué la méthode de descente avec x=0.2 et x=-0.7

                                  (  1    0    0    0    0)
                                  ( 0.4   1    0    0    0)
                             A2 = (  1   0.4   1    0    0)
                                  (  0    1   0.4   1    0)
                                  (  0    0    1   0.4   1)
                                  ....... jusque k
                                                   
                                  (  1    0    0    0   0)
                                  (-1.4   1    0    0   0)
                             A1 = (  1  -1.4   1    0   0)
                                  (  0    1  -1.4   1   0)
                                  (  0    0    1  -1.4  1)
                                  ....... jusque k
                                                   
                             b = (-1/9  2/81  -1/162  2/1215  -1/2187)T
                             ....... jusque k
                             

Les fichiers de données utilisés sont donnes_ln_0.2_mk.txt et donnes_ln_-0.7_mk.txt dans le dossier input. Vous retrouverez les résultats dans les fichiers res_ln_-0.7_mk.txt et res_ln_0.2_mk.txt dans le dossier output.


## Calcul de (10+x)/(101+20x)

7. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de (10+x)/(101+20x) à 10**-5 près. 

On a donc appliqué la méthode de descente avec x=0.2 et x=-0.7

                                  ( 1    0 )
                             A2 = ( 0.4  1 )
                                   
                                  (  1    0)
                             A1 = (-1.4   1)
                                                   
                             b = (1/1000  -1/10000)T    

Les fichiers de données utilisés sont donnes_10x_0.2_mk.txt et donnes_10x_-0.7_mk.txt dans le dossier input. Vous retrouverez les résultats dans les fichiers res_10x_-0.7_mk.txt et res_10x_0.2_mk.txt dans le dossier output.



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

## Machine 3 (m3)
Nom : ?
Processeur: ?
Mémoire vive: ?
Système d'exploitation : ?
Compilateur: ?
Editeur: ?


--------------------------------------------------------------------------------------
# Description des fichiers


## Données:
    Dossier: input
    Nomenclature: donnees.txt
    Contenu:
        numéro machine (int)
        degré n du polynôme Pn
        coefficient 0
        ...
        coefficient n
        alpha    
        tracer polynome (bool)

## Résultat:
    Dossier: output
    Nomenclature: res_mk.txt (k = numéro de la machine)
    Contenu:
        polynôme Pn
        Pn(alpha)
        { b0, ..., bn }
        { Pn(alpha)^{(0)}, Pn(alpha)^{(1)}, ..., Pn(alpha)^{(n)} }



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
     
     
     Nomenclature : main.cf
     Contenu :
     	--> On demande le numero de la machine (pour les fichiers d'entrée et de sortie).
     	--> creation du polynome Pn
     	--> Tracer le polynome Pn
     	--> calculer Pn(alpha)
     	--> calculer les n dérivées de Pn en alpha
     	--> AN1 : calcul de P6(2)
