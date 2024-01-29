# Quelques instructions

Pour pouvoir tracer les graphiques, il faut installer :

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev


--------------------------------------------------------------------------------------
# Description de la démarche

## Approche naïve

### A FAIRE (environ 15min)

1. Tout d'abord, on a commencé par vouloir évaluer un polynôme en n'importe quel valeur alpha de manière classique. Pour cela, on a créé les fichiers poly.c et poly.h, contenant la description des fonctions creerPolynome et remplirPolynome; et les fichiers alpha.c et alpha.h contenant la description de la fonction enAlphaNaif. Ensuite, on a testé nos fonctions en évaluant un polynôme de degré 4, ayant pour coefficient {0,1,5,2,4} en une valeur alpha=2. Cette partie correspond au chapitrage "Calcul naïf de Pn" dans le fichier main.c que l'on a ainsi créé.


## Méthode de Horner


2. Ensuite on a décidé d'évaluer le même polynôme mais avec la méthode Horner. Pour cela, on a créé une fonction enAlpha dans les fichiers alpha.c et alpha.h. Cette partie correspond au chapitrage "calculer Pn(alpha) avec Horner" dans le fichier main.c. Vous retrouverez le résultat dans le fichier res_poly_Horner_mk.txt dans le dossier output.


## A FAIRE (corriger fonction deriveesEnAlpha environ 10min + application environ 5min)

3. Ensuite, on a décidé de calculer chacune des dérivées du même polynôme évalué en alpha=2 toujours. Pour cela, on a créé les fichiers derivees.c et derivees.h contenant une fonction fact et une fonction deriveesEnAlpha. On a ensuite calculer chacune des dérivées du polynôme en alpha. Cette partie correspond au chapitrage "calculer les n dérivées de Pn en alpha" dans le fichier main.c. Vous retrouverez le résultat dans le fichier res_poly_deriv_mk.txt dans le dossier output.


## Méthode Clenshaw : base de Tchebychev

4. On a décidé d'implémenter l'algorithme de descente qui va nous être utile par la suite. Il s'agit de la fonction methodeDescente qui se situe dans les fichiers matrice.c et matrice.h nouvellement créé. Aussi, on a créé des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur et multiplicationMatriceVect dans ces mêmes fichiers. On a effectuer l'analyse numérique demandé en calculant P6(2) par la méthode de Cleshaw. Cette partie correspond au chapitrage "calcul de P6(2) avec algo de descente" dans le fichier main.c. Vous retrouverez le résultat dans le fichier AN_P6_2_descente_m2.txt dans le dossier output.


## Affichage des polynômes

### A FAIRE (environ 10min)

5. A cet instant, on s'est dit qu'il serait intéressant d'observer l'allure des polynômes. C'est pourquoi on a créé les fichiers renderer.c et renderer.h. On souhaite visualiser l'allure du polynôme de degré 4 vu précédemment. Cette partie correspond au chapitrage "Tracer le polynome Pn" dans le fichier main.c. Vous retrouverez le résultat dans le fichier res_poly_affichage.txt dans le dossier output.











