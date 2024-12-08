il s'agit du projet de lifcomplexité à temps limité

0) info:
-le but de ce projet etait la realisation d'un module image pour utiliser la notion de graphe en c++
 il etait demander de créer les fonction de chargement et sauvegarde d'image dans un fichier .pgm et l'utilisation de l'algorithme de Disjkstra pour le calcule des plus courte distance pour cree une image de distance (degradé). il fallait aussi cree un menu qui a pour objectif de montrer que nos fonction marche. Ici il sert juste de presentation des fonction un peu comme un test de regression


1) Composition de l'archive :
-data: dossier qui contient les images de distances et les fichiers en format pgm lors de l'execution des fonctions de chargement ou de sauvegarde.
-src: dossier qui contient les fichiers sources, avec le module image et le programme principal (main) utile pour l'execution.
-bin: 
-objet: 

2) Compiler le projet: 

-> comment executer:
      Make  # à executer à la racine du projet#
      ./bin/main  #lancer l'executable #
      ./biin/test #lancer le test de regression
      utiliser le menu pour choisir les fonctions à lancer 
      Utiliser make clean pour supprimer les fichiers .o et l'executable
      

3) Comment générer la documentation  :

Nous utilisons Doxygen pour générer la documentation, qui produit de nombreux fichiers HTML dans le répertoire doc/html.
Ces fichiers sont statiques et peuvent être affichés en utilisant n'importe quel navigateur récent.
Pour générer et visualiser la documentation,il faut suivre c'est deux etape: premierement dans le fichier mere utiliser la commande
"doxygen doc/image.doxy" pour generer la documentation puis pour la visualiser "firefox doc/html/index.html"

4) Test valgrind :

pour effectuer un test valgrind qui ici est utile car on utilise des allocation sur le tas donc on peu verifier les fuites memoire en utilisant valgrind en utilisant la commande valgrind bin/x ou x est le nom de l'executable on utilise cette commande a la racine du projet. 


CREDIT

projet realiser par des etudiant L3 informatique lyon 1:

12006707 TRAD NEDIM
12208286 OTMANE EL MOUKI