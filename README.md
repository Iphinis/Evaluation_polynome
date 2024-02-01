# Quelques prérequis

Pour pouvoir tracer les graphiques, il faut installer la librairie SDL :

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev


--------------------------------------------------------------------------------------
# Description de la démarche

## Approche naïve

1. Tout d'abord, on a commencé par vouloir évaluer un polynôme en n'importe quel valeur alpha de manière classique. Pour cela, on a créé les fichiers poly.c et poly.h, contenant la description des fonctions creerPolynome et remplirPolynome; et les fichiers alpha.c et alpha.h contenant la description de la fonction enAlphaNaif. Ensuite, on a testé nos fonctions en évaluant un polynôme de degré 2, ayant pour coefficient {1,2,3} en une valeur alpha=10. 

Cette partie correspond au chapitrage "Calcul naïf de Pn en alpha" dans le fichier main.c que l'on a ainsi créé. Le fichier de données utilisé est le fichier donnes.txt. Vous retrouverez le résultat dans le fichier res_mk.txt dans le dossier output.


## Méthode de Horner

2. Ensuite on a décidé d'évaluer le même polynôme mais avec la méthode Horner. Pour cela, on a créé une fonction enAlpha dans les fichiers alpha.c et alpha.h. 

Cette partie correspond au chapitrage "Calcul de Pn en alpha avec Horner" dans le fichier main.c. Le fichier de données utilisé est le fichier donnes.txt. Vous retrouverez le résultat dans le fichier res_mk.txt dans le dossier output.


## Calcul des dérivées successives 

3. Ensuite, on a décidé de calculer chacune des dérivées du même polynôme évalué en alpha=2 toujours. Pour cela, on a créé les fichiers derivees.c et derivees.h contenant une fonction fact et une fonction deriveesEnAlpha. On a ensuite calculer chacune des dérivées du polynôme en alpha. 

Cette partie correspond au chapitrage "Calcul des n dérivées de Pn en alpha" dans le fichier main.c. Le fichier de données utilisé est le fichier donnees_m2.txt. Vous retrouverez le résultat dans le fichier res_mk.txt dans le dossier output.


## Méthode de Clenshaw : base de Tchebychev

4. On a décidé d'implémenter l'algorithme de descente qui va nous être utile par la suite. Il s'agit de la fonction methodeDescente qui se situe dans les fichiers matrice.c et matrice.h nouvellement créé. Aussi, on a créé des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur et multiplicationMatriceVect dans ces mêmes fichiers. On a effectuer l'analyse numérique demandé en calculant P6(2) par la méthode de Cleshaw. 

Cette partie correspond au chapitrage "calcul de P6(2) avec algo de descente" dans le fichier main.c. Le fichier de données utilisé est le fichier donnes_AN_P6(2).txt. Vous retrouverez le résultat dans le fichier AN_P6_2_descente_m2.txt dans le dossier output.


## Affichage des polynômes

### A FAIRE 

5. A cet instant, on s'est dit qu'il serait intéressant d'observer l'allure des polynômes. C'est pourquoi on a créé les fichiers renderer.c et renderer.h. On souhaite visualiser l'allure du polynôme de degré 4 vu précédemment. Cette partie correspond au chapitrage "Tracer le polynome Pn" dans le fichier main.c. Vous retrouverez le résultat dans le fichier res_poly_affichage.txt dans le dossier output.

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
