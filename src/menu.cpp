#include<iostream>
#include"menu.h"
#include<fstream>
#include<cassert>
#include"Image.h"

using namespace std; 

void afficherCentre(const string& texte){

    // Obtenir la largeur du terminal (par défaut si non supporté)
    const int largeurTerminal = 80; 
    int longueurTexte = texte.size();

    // Calculer le nombre d'espaces à gauche pour centrer le texte
    int espaces = (largeurTerminal - longueurTexte) / 2;

    // Ajouter les espaces avant d'afficher le texte
    if (espaces > 0) {
        cout << string(espaces, ' ') << texte <<endl;
    } else {
        cout << texte <<endl; // Si le texte est plus large que la console
    }
};

void boucle(){
Image blanche;
Image crea;
Image charg;
int choix = -1;
int foorme=-1;
int x;
int y;
int taiile_x;
int taiile_y;
int pos_x;
int pos_y;
forme a= vide;
string fichier;

do {

// Affichage du menu
cout<<"effectuer ces etape une par une dans l'ordre!!!!!"<<endl;
afficherCentre("======= MENU =======");
cout<<endl<<endl;
afficherCentre("1. Créer une image");
cout<<endl<<endl;
afficherCentre("2. Charger une image");
cout<<endl<<endl;
afficherCentre("3. Calculer les distances avec Dijkstra et union des forme");
cout<<endl<< endl;
afficherCentre("4: projeter un pixel au choix");
cout<<endl<<endl;
afficherCentre("0. Quitter");
cout<<endl<<endl;
afficherCentre("====================");
cout<<endl<<endl;

cout << "Votre choix : "<<endl;
cin >>choix;


// Gestion des choix avec switch
 switch (choix) {

case 1:{

cout<<"veuillez choisir la dimension x de l'image"<<endl;
cin>>taiile_x;
cout<<endl;
cout<<"veuillez choisir la dimension y de l'image"<<endl;
cin>>taiile_y;
cout<<endl;
cout<<"veuillez choisir la forme"<<endl;
cout<<"RECTANGLE:1"<<endl;
cin>>foorme;
if(foorme==1){
    a=rectangle;
}

cout<<"veuillez choisir les dimension longueur largeur"<<endl;
cout<<"longueur"<<"  ";
cin>>x;
cout<<endl;
cout<<"largeur"<<"  ";
cin>>y;
cout<<endl;
cout<<"choisir position x dans l'image"<<endl;
cin>>pos_x;
cout<<endl;
cout<<"choisir position y dans l'image"<<endl;
cin>>pos_y;
cout<<endl;
Image crea2(taiile_x,taiile_y);
crea2.cree_forme(pos_x,pos_y,rectangle,x,y);
cout<<"cree avec succes"<<endl;
cout<<"sauvegarder cette image dans un fichier "<<endl;
cout<<"entrer nom du fichier"<<endl;
cin>>fichier;
crea2.sauvgarder_image(string ("./data/") + fichier + ".pgm");
cout<<"image sauvegarder dans le fichier suivat:./data/(fichier).pgm"<<endl;

break;
}
case 2:{

cout<<"nous allons charger l'image dans le fichier (./data/chargement_main.pgm)"<<endl;
charg.charger_image("./data/chargement_main.pgm");
cout<<"charger avec succes"<<endl;

break;
}
case 3:{
Image crea3 (taiile_x,taiile_y);
crea3.charger_image(("./data/") + fichier + ".pgm");
cout<<"nous allons maintenant calculer les image de distance sur l'image cree"<<endl;
int *dist=crea3.tab_dist();
Etiquette* etiq= crea3.tab_etat();
int* pred=crea3.tab_pred();
crea3.algorithme_dijkstra(dist,etiq,pred);
cout<<"voici l'affichage des distance des 10 premier terme avec leur predecesseur"<<endl<<endl;
    for(int i =0; i<10;i++){
        cout<<"indice "<<i<<"= "<<dist[i]<<'\t'<<"pred ="<<pred[i]<<endl;
     }
cout<<"maintenant l'image de distance est cree"<<endl;
crea3.construction_image_dist(dist,etiq,pred);
cout<<"effectué avec succes et sauvegarder dans le fichier ./data/img_dist_main.pgm"<<endl;
crea3.sauvgarder_image("./data/img_dist_main.pgm");
cout<<"processus d'union de l'image cree et image charger"<<endl;
crea3.union_image(charg);
crea3.sauvgarder_image("./data/img_dist_main.pgm");
cout<<"l'union des deux image se trouve dans le fichier ./data/img_dist_main.pgm"<<endl;

delete []dist;
delete []etiq;
delete []pred; 

break;
}
case 4:{

Image crea4 (taiile_x,taiile_y);
crea4.charger_image(("./data/") + fichier + ".pgm");
cout<<"choisisser un pixel de coordoner x et y"<<endl;
cout<<"coordonée x"<<endl;
cin>>x;
cout<<"coordonée y"<<endl;
cin>>y;
cout<<"la projection du pixel"<<x<<","<<y<<"sur la forme cree est :"<<endl;
int *dist1=crea4.tab_dist();
Etiquette* etiq1= crea4.tab_etat();
int* pred1=crea4.tab_pred();
crea4.algorithme_dijkstra(dist1,etiq1,pred1);
int indice=crea4.projection(x,y,pred1);
cout<<"la projection est à l'indice"<<indice<<endl;

delete []dist1;
delete []etiq1;
delete []pred1; 

break;
}
case 0:{

cout<<"toutes les image se reinitialise"<<endl;
crea.retour_origine();
charg.retour_origine();
crea.sauvgarder_image("./data/img_dist_main.pgm");
cout<< "Quitter le programme. Au revoir !" << endl;

break;
}

default:

cout << "Choix invalide. Veuillez réessayer." << endl;

break;

}

} while (choix != 0);

};
