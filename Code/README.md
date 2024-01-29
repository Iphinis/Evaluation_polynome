# Caractéristiques de la machine 1 (m1)
Nom: po-d82fx93
Processeur: Intel® Core™ i7-10810U CPU @ 1.10GHz × 12\
Système d'exploitation: Ubuntu 22.04.3 LTS 64-bit\
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0\
Editeur: VSCODE

# Caractéristiques de la machine 2 (m2)
## PC de Hugo (je compléterais plus tard)

# Caractéristiques de la machine 3 (m3)
## ...


--------------------------------------------------------------------------------------
# Description des fichiers


# Données:
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

# Résultat:
    Dossier: output
    Nomenclature: res_mk.txt (k = numéro de la machine)
    Contenu:
        polynôme Pn
        Pn(alpha)
        { b0, ..., bn }
        { Pn(alpha)^{(0)}, Pn(alpha)^{(1)}, ..., Pn(alpha)^{(n)} }



# Codes:
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
     	--> AN : calcul de P6(2) avec algo de descente
     

