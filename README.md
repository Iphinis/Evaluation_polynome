# Quelques prérequis

Pour pouvoir tracer les graphiques, il faut installer la librairie SDL avec ces 2 commandes bash :

sudo apt-get install libsdl2-dev

sudo apt-get install libsdl2-ttf-dev


--------------------------------------------------------------------------------------
# Description de la démarche

## Introduction
Pour compiler & exécuter correctement le code et de la même façon sur toutes les machines, nous avons créé un Makefile. Le compilateur est gcc mais il est possible de le changer en modifiant le paramètre CC du Makefile.

Nous avons décidé de mettre en places 2 modes d'exécution de notre code : automatique (mode 1) et manuel (mode 2). Le mode est choisi au début de l'exécution.

 - Le mode automatique demande uniquement le numéro de machine qu'on note k, et va lire les données du dossier input/ pour écrire les résultats des instructions qui vont être effectuées dans output/mk/. Il n'y a donc rien à saisir à part le numéro de la machine, comme dit, tout est automatique.

 - Le mode manuel est une interface homme-machine en ligne de commande qui permet d'interagir avec le programme en direct à l'aide de commandes qui sont affichées à l'écran. Il ne lit/n'écrit pas dans des fichiers. C'est uniquement pour tester en direct toutes les fonctions à disposition.


## Approche naïve

1. Tout d'abord, on a commencé par vouloir évaluer un polynôme en n'importe quel valeur alpha de manière classique. Pour cela, on a créé les fichiers poly.c et poly.h, contenant la description des fonctions creerPolynome et remplirPolynome; et les fichiers alpha.c et alpha.h contenant la description de la fonction enAlphaNaif.

A cet instant, on s'est dit qu'il serait intéressant d'observer l'allure des polynômes. C'est pourquoi on a créé les fichiers renderer.c et renderer.h qui utilisent la librairie SDL (cf prérequis).

Ensuite, on a testé nos fonctions en évaluant un polynôme de degré 3, ayant pour coefficient {1,-2,3,4} en une valeur alpha=-0.75.

Le fichier de données utilisé est le fichier donnees_naif.txt. Il est constitué comme suit :

5 : Degré du polynôme
1 0 3 2 0 6 : coefficients
3.2 : alpha

Vous retrouverez le résultat dans le fichier output/mk/res_naif_mk.txt, avec k qui est le numéro de la machine qui a exécuté le code.


## Méthode de Horner

2. Ensuite on a décidé d'évaluer plusieurs polynomes avec la méthode de Horner. Pour cela, on a créé une fonction enAlpha dans les fichiers alpha.c et alpha.h.

Voici les polynomes tests (dont celui vu précédemment) :

1) 1 + 3x**2 + 2 x**3 + 6x**5 en x=3.2
2) x - 4x**2 + 7x**5 - 3x**6 en x=-5.1

Les fichiers de données utilisés sont input/donnees_hd_5_3.2.txt et input/donnees_hd_6_-5.1.txt. Ils sont constitués comme suit :

5 : degré du polynome
1 0 3 2 0 6 : coefficients
3.2 : alpha

6 : degré du polynome
0 1 -4 0 0 7 -3 : coefficients
-5.1 : alpha

Vous retrouverez les résultats dans les fichiers output/mk/res_hd_5_3.2_mk.txt et output/mk/res_hd_6_-5.1_mk.txt.


## Calcul des dérivées successives

3. Ensuite, on a décidé de calculer chacune des dérivées des deux polynômes évalués précédemment. Pour cela, on a créé les fichiers derivees.c et derivees.h contenant une fonction calculerFact et une fonction deriveesEnAlpha. On a ensuite calculer chacune des dérivées du polynôme en alpha.

Les fichiers de données utilisés sont les mêmes que précédement : input/donnees_hd_5_3.2.txt et input/donnees_hd_6_-5.1.txt.

Vous retrouverez les résultats dans les mêmes fichiers output/mk/res_hd_5_3.2_mk.txt et output/mk/res_hd_6_-5.1_mk.txt.


## Méthode de Clenshaw : base de Tchebychev

4. On a tout d'abord implémenté l'algorithme de descente, bien que cette méthode ne soit pas efficace. Il s'agit de la fonction methodeDescente qui se situe dans les fichiers matrice.c et matrice.h nouvellement créés. Aussi, on a créé des fonctions creerMatrice; afficherMatrice; creerVecteur; afficherVecteur et multiplicationMatriceVect dans ces mêmes fichiers.

Le fichier de données utilisé est le fichier input/donnees_AN_P6_2_d.txt. Il est constitué comme suit :

6 : degré dupolynome dans la base de Tchebychev
2.1 3 -2.5 0 0 1 -4 : coefficients dans la base de Tchebychev
2 : alpha
2.1 3 -2.5 0 0 1 -4 : coefficients dans la base de Tchebychev


Vous retrouverez le résultat dans le fichier output/mk/res_AN_P6_2_d_mk.txt.


5. Ensuite, on a implémenté l'algorithme de Clenshaw, bien moins couteux que la méthode de descente. Le fichier de données utilisé est le même que précédemment : input/donnees_AN_P6_2.txt.

Vous retrouverez le résultat dans le fichier output/res_AN_P6_2_c_mk.txt.

On visualise l'allure des 2 mêmes polynômes vu précédemment avec la librairie SDL.


## Calcul de ln(10+6x)

6. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de ln(10+6x) à 10**{-4} près.

On a donc appliqué l'algorithme de Clenshaw avec alpha=-1 dans un premier temps; puis ensuite avec des valeurs proches : alpha=0.1 et alpha=0.2.

Les fichiers de données utilisés sont input/donnees_ln_0.2.txt ; input/donnees_ln_0.1.txt et input/donnees_ln_1.txt. Ils sont constitués comme suit :

0.2 ;
0.1 ;
1 ;
Ce sont les valeurs de alpha

Vous retrouverez les résultats dans les fichiers output/mk/res_ln_0.2_mk.txt ; output/mk/res_ln_0.1_mk.txt et output/mk/res_ln_1_mk.txt dans le dossier output.


## Calcul de (10+x)/(101+20x)

7. L'objectif de cette partie est d'appliquer la méthode de Clenshaw pour déterminer une approximation de la valeur de (10+x)/(101+20x) à 10**{-5} près. 

On a donc appliqué l'algorithme de Clenshaw avec alpha=0.2 et alpha=-0.7.

Les fichiers de données utilisés sont input/donnees_10x_0.2.txt et input/donnees_10x_-0.7.txt. Ils sont constitués comme suit :

0.2 ;
-0.7 ;
Ce sont les valeurs de alpha

Vous retrouverez les résultats dans les fichiers output/mk/res_10x_-0.7_mk.txt et output/mk/res_10x_0.2_mk.txt.



--------------------------------------------------------------------------------------
# Caractéristiques machine

## Machine 1 (m1)
Nom: po-d82fx93
Processeur: Intel® Core™ i7-10810U CPU @ 1.10GHz × 12
Mémoire vive: 8 gb
Système d'exploitation: Ubuntu 22.04.3 LTS 64-bit
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Editeur utilisé: VSCode

## Machine 2 (m2)
Nom : po-d82fx93
Processeur: Intel® Core™ i7-10810U CPU @ 1.10GHz × 12
Mémoire vive: 8,0 Gio
Système d'exploitation : Ubuntu 22.04.3 LTS 64-bits
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Editeur utilisé: VSCode

## Machine 3 (m3)
Nom : boar207-15
Processeur: 12th Gen Intel® Core™ i7-12700 × 20
Mémoire vive: 32.0 Gio
Système d'exploitation : Ubuntu 22.04.3 LTS 64-bits
Compilateur: gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
Editeur utilisé: gedit


--------------------------------------------------------------------------------------
# Description des fichiers


## Données:
Dossier: input   
    Nomenclature : donnees_....txt
    Contenu :
        Données servant au bon déroulement de notre démarche. Leur contenu a donc déjà été expliqué précédemment.


## Résultat:
Dossier: output
    Dossier : mk
        Nomenclature : res_..._mk.txt
        Contenu : 
            Résultats des fichiers donnees_..._mk.txt


## Codes:
Dossier: src

    Dossier : alpha
        Nomenclature: alpha.c
        Contenu:
            Prototype: double enAlphaNaif(polynome p, double alpha)
                Description: Evaluation naïve de Pn en alpha
                Paramètres: p (polynome), alpha (double)
            
            Prototype: double enAlpha(polynome p, double alpha, double* b)
                Description: Evaluation de Pn en alpha par la méthode de Horner
                Paramètres: p (polynome), alpha (double), b (tableau de taille p.deg + 1)
            
            Prototype: double enAlphaC(double alpha, double* b, int n)
                Description: Evaluation de Pn en alpha par la méthode de Clenshaw
                Paramètres: alpha (double), b (tableau de taille n), n (int)


        Nomenclature: alpha.h
        Contenu:
    	    --> Déclaration des fonctions de alpha.c


    Dossier : derivees
        Nomenclature: derivees.c
        Contenu:
            Prototype: int calculerFact(int n)
                Description: Remplit le tableau de factorielles contenant 0!, 1!, ..., n!
                Paramètre : n (entier)
            
            Prototype: void deriveesEnAlpha(polynome p, double alpha, double* b, double* deriv)
                Description: Calcule les dérivées de Pn évaluées en alpha
                Paramètres : p (polynome), alpha (double), b (tableau de taille p.deg + 1), deriv (tableau de taille p.deg + 1)


        Nomenclature: derivees.h
        Contenu:
            --> Déclaration des fonctions de derivees.c
    
    
    Dossier : matrices
        Nomenclature: matrices.c
        Contenu:
            Prototype: double **creerMatrice(double alpha, int n)
                Description: Crée une matrice carrée de taille nxn en demandant à l'utilisateur chacun des coefficients de la matrice
                Paramètre : n (entier)
            
            Prototype: void afficherMatrice(double **matrice, int n)
                Description: Afficher une matrice de taille n
                Paramètres : matrice, n (entier)
            
            Prototype: double *creerVecteur(int n, int mode)
                Description: Crée un vecteur à n composantes en les demandant à l'utilisateur
                Paramètre : n (entier)
            
            Prototype: void afficherVecteur(double *vecteur, int n)
                Description: Afficher un vecteur de dimension n
                Paramètres : vecteur (double *), n (entier)
            
            Prototype: double *methodeDescente(double **matrice, double *b, int n)
                Description: Resoudre un système linéaire par la methode de descente
                Paramètres : matrice (triangulaire inférieure), n (entier)
            
            Prototype: double *multiplicationMatriceVect(double **matrice, double *x, int n)
                Description: Mutliplier une matrice par un vecteur
                Paramètres : matrice, vecteur, n (entier)


        Nomenclature: matrices.h
        Contenu:
            --> Déclaration des fonctions de matrices.c


    Dossier : poly
        Nomenclature: poly.c
        Contenu:
            Prototype: polynome creerPolynome(int deg)
                Description: Crée un polynôme et le renvoie
                Paramètre: deg (entier)
            
            Prototype: void remplirPolynome(polynome p, int mode)
                Description: Remplit un polynôme
                Paramètre: p (polynome), mode (entier)
            
            Prototype: void afficherPolynome(polynome p)
                Description: Affiche un polynôme
                Paramètre: p (polynome)
            
            Prototype: polynome lirePolynome(int mode)
                Description: Lit un polynôme depuis le flux d'entrée et le renvoie
                Paramètre: mode (entier)


        Nomenclature: poly.h
        Contenu:
            --> Déclaration des fonctions de poly.c


    Dossier : renderer
        Nomenclature: arial.ttf
        Contenu:
            Description: Police d'écriture utilisée lors du rendu par la librairie graphique SDL

        Nomenclature: renderer.c
        Contenu:
            Prototype: void tracerPoints(SDL_Renderer* renderer, int screenWidth, int screenHeight, polynome p, int nombrePoints, double xMin, double xMax, double yMin, double yMax)
                Description: Trace une série de points du polynôme sur un rendu SDL
                Paramètres : renderer, screenWidth, screenHeight, p, nombrePoints, xMin, xMax, yMin, yMax
            
            Prototype: void tracerPolynome(polynome p)
                Description: Initialise une fenêtre SDL et trace le polynôme
                Paramètre : p (polynome)


        Nomenclature: renderer.h
        Contenu:
            --> Déclaration des fonctions de renderer.c


Nomenclature: main.c
        Contenu:
            Prototype: void definirEntree(char* nom_fonction)
                Description: Redirige le flux stdin vers un fichier de données correspondant à une fonction spécifique
                Paramètre : nom_fonction (chaine de caractères)
            
            Prototype: void definirSortie(char* nom_fonction, int machine)
                Description: Redirige le flux stdout vers un fichier de résultat correspondant à une fonction spécifique sur une machine donnée
                Paramètres : nom_fonction (chaine de caractères), machine (entier)
            
            Prototype: void modeAutomatique(int machine)
                Description: Mode automatique : lit et écrit dans les fichiers d'entrée/sortie en fonction du numéro de la machine
                Paramètre : machine (entier)
            
            Prototype: void modeManuel()
                Description: Mode manuel : interaction homme-machine pour manipuler les fonctions en direct
            
            Prototype: int main()
                Description: Point d'entrée du programme. Le programme peut fonctionner en deux modes distincts : automatique ou manuel.
                    - En mode automatique, l'utilisateur doit fournir uniquement le numéro de la machine (k). Le programme va lire les données depuis le dossier "input/" et écrire les résultats des instructions dans le dossier "output/mk/", où mk est le numéro de la machine spécifiée.
                    - En mode manuel, l'utilisateur peut interagir avec le programme en temps réel via une interface en ligne de commande. Aucune lecture ni écriture de fichiers n'est effectuée. Ce mode est principalement utilisé pour tester les fonctionnalités du programme.
                Entrées: Aucune entrée requise.
                Sorties: Le programme renvoie 0 en cas de succès.