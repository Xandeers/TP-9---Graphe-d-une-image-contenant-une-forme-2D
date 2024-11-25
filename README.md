README 

il s'agit du projet de lifcomplexité ..
A REMPLIR

composition de l'archive :
.....



compiler le projet: 

executer a la racine du projet la commande : make 
pour supprimer les executable et les fichier .obj il faut utiliser la commande make clean 

comment executer:


      Comment générer la documentation  :

Nous utilisons Doxygen pour générer la documentation, qui produit de nombreux fichiers HTML dans le répertoire doc/html.
 Ces fichiers sont statiques et peuvent être affichés en utilisant n'importe quel navigateur récent.
 Pour générer et visualiser la documentation,il faut suivre c'est deux etape: premierement dans le fichier mere utiliser la commande
"doxygen doc/image.doxy" pour generer la documentation puis pour la visualiser "firefox doc/html/index.html"

test valgrind :

pour effectuer un test valgrind qui ici est utile car on utilise des allocation sur le tas donc on peu verifier les fuites memoire en utilisant valgrind en utilisant la commande valgrind bin/x ou x est le nom de l'executable on utilise cette commande a la racine du projet 


        CREDIT

projet realiser par des etudiant l3 informatique lyon 1:

12006707 TRAD NEDIM
12208286 OTMANE EL MOUKI