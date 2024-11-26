#include<iostream>
#include <fstream>
#include<cassert>
#include"Image.h"

using namespace std; 

Image::Image(){

    l=0;
    c=0;
    tab=new int[0];
}

Image::~Image(){

    if(tab!=nullptr){
        delete []tab;
    }
}




void Image::charger_image(const string &fichier){
    
  ifstream ifs; //Déclaration d'un objet std::ifstream nommé ifs. Cet objet est utilisé pour lire des données à partir d'un fichier.
  ifs.open(fichier);
  if(ifs.bad()) //verfifie si pas defectueu
    {
        cout<<"Impossible d'ouvrir le fichier "<<fichier<<" en lecture \n";
        exit(1);
    }
    string buff_bin; 
    string buff_colone;
    string buff_line; 
    string buff_intensite;
    string buff_tab;
    string bin; //p2

    //lecture du mot 
    ifs>>bin;
    //verification
   if (bin != "P2") 
    {
        std::cout << "Le fichier n'est pas au format P2 (PGM ASCII)\n"; 
        exit(1);
    }
    //verification si charactere suivant est un commentaire
    ifs >> buff_colone;
    if(buff_colone=="#" || buff_colone=="//")
    {
    getline(ifs,buff_bin); //get line recupere toute la ligne 
    ifs >> buff_colone;
    }
    c= stoi(buff_colone); //c prend pas la valeur du commentaire string to interger

    
//verification si charactere suivant est un commentaire
  ifs>>buff_line; //valeur l et c 
  if(buff_line=="#" || buff_line=="//")
  {
    getline(ifs,buff_bin);
    ifs>> buff_line;
  }
  l=stoi(buff_line);

  //verification si charactere suivant est un commentaire
  ifs >> buff_intensite; //intensite 
  if(buff_intensite=="#" || buff_intensite=="//")
  {
    getline(ifs,buff_intensite); //ici on se fiche de l'intensite max
    ifs>>buff_intensite;
   
  }

  tab=new int[c * l];

  for(int i=0;i<l;i++)
  {
    for(int j=0;j<c;j++)
    {
        ifs >>buff_tab;
        if(buff_tab=="#"|| buff_tab=="//")
        {
            getline(ifs,buff_bin);
            ifs>>buff_tab;
        }
        tab[i * c + j ] = stoi(buff_tab);
    }
  }

}
void Image::sauvgarder_image(const string &fichier){
  
  std::ofstream ofs;
  ofs.open(fichier);
  if(ofs.bad()) 
    {cout<<"Impossible d'ouvrir le fichier "<<fichier<<" en ecriture \n"; exit(1);}
    ofs<<"P2"<<" "<<" # PGM ASCII"<<endl;
    ofs<<c<<" "<<l<<" # Dimensions du graphe C (largeur) et L (hauteur)"<<endl;
    ofs<<"255"<<" "<<" # Intensité maximale (couleur blanche)"<<endl;
    //ecriture du tableau de pixel(graph)
    int buff = 0;

    for(int j=0;j<l;j++)
    {
        for(int i=0; i<c;i++)
        {
            ofs<<tab[j*c+i];
            ofs<< " ";

        }
        ofs<<endl;
    }

  ofs.close();
} 
/** 
int Image::getNord(const int &indice){
    if( indice - c>=0){
        return indice-c;
    }
    else{
        return -1;
    }
}

int Image::getSud(const int &indice){
    if( indice + c<l){
        return indice+c;
    }
    else{
        return -1;
    }
}

int Image::getouest(const int &indice){
    if( indice -1 <){
        return indice+c;
    }
    else{
        return -1;
    }
}


int Image::getest(const int &indice){

}
*/
Etiquette* Image::tab_etat(){

    Etiquette* etats= new Etiquette[l*c];

    for (int i=0; i<l*c;i++){
        if(tab[i]==0){
            etats[i]= Noir;
        }
        else{
            etats[i]=Blanc;
        }
    }
    return etats;
}

int* Image::tab_pred(){

    int* pred=new int[l*c];
    for (int i=0; i<l*c;i++){
        if(tab[i]==0){
            pred[i]= i;
        }
        else{
            pred[i]=-1;
        }
    }
    return pred;

}

int* Image::tab_dist(){
    
    int* dist=new int[l*c];
    for (int i=0;i<l*c;i++){
        if(tab[i]==0){
            dist[i]= 0;
        }
        else{
            dist[i]=-1;
        }
    }
    return dist;
}
/** 
void Image::algorithme_dijkstra(int* &dist, Etiquette* &etiquette, int* &pred){

    int nord;
    int sud;
    int est;
    int ouest;
    int nord_est;
    int nord_ouest;
    int sud_est;
    int sud_ouest;
    //parcour du tableau 

    for(int i=0;i<l*c;i++){
        //calcule voisin 
        if(tab[i]==0){
            nord=i-c;
            sud=i+c;
            est=i+1;
            ouest=i-1;
            nord_est=i-c+1;
            nord_ouest=i-c-1;
            sud_est=i+c+1;
            sud_ouest=i+c-1;
        }

    }
}
*/
void Image::testRegression(){

    cout<<"test constructeur Image init zero"<<endl;
    Image a; 
    assert(a.c==0 && a.l==0);
    assert(a.tab!=nullptr);
    cout<<"ok"<<endl<<endl;


    cout<<"test charger image"<<endl;
    a.charger_image("./data/image_test_pgm.txt");
    assert(a.c==3 && a.l == 2);
    assert(a.tab != nullptr);
    cout<<"ok"<<endl<<endl;


    cout<<"test sauvegarder image"<<endl;
    a.sauvgarder_image("./data/image_sauv_test_pgm.txt");
    Image b;
    b.charger_image("./data/image_sauv_test_pgm.txt");
    assert(a.c==b.c && a.l==b.l && b.tab != nullptr);
    assert(a.tab[0]==b.tab[0]);
    assert(a.tab[3]==b.tab[3]);
    cout<<"ok"<<endl<<endl;


    cout<<"test etiquette pour algo dijktra"<<endl;
    Etiquette* test = a.tab_etat();
    assert(test[0]== Blanc);
    assert(test[4]==Noir);
    delete[]test;
    cout<<"ok"<<endl<<endl;


    cout<<"test predecesseur pour algo dijktra"<<endl;
    int* test2 = a.tab_pred();
    assert(test2[0]==-1 );
    assert(test2[4]==4);
    delete[]test2;
    cout<<"ok"<<endl<<endl;

    cout<<"test dist pour algo dijktra"<<endl;
    int* test3 = a.tab_dist();
    assert(test3[0]==-1 );
    assert(test3[4]==0);
    delete[]test3;
    cout<<"ok"<<endl<<endl;
}