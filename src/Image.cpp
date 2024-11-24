#include<iostream>
#include <fstream>
#include<cassert>
#include"Image.h"

using namespace std; 

Image::Image(){

    l=0;
    c=0;
    intensiteMax=0;
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
    {cout<<"Impossible d'ouvrir le fichier "<<fichier<<" en lecture \n"; exit(1);}

  int temp;
  string bin; //p2
  ifs >> bin;

  if (bin != "P2") {
        std::cout << "Le fichier n'est pas au format P2 (PGM ASCII)\n"; //verification
        exit(1);
    }

  ifs >> c >> l; //valeur l et c 
  ifs >> temp; //intensite 
  tab = new int[c*l];
  for(int i=0; i<l;i++)
  {
    for(int j=0; j<c; j++)
    {

       ifs>>tab[j*l+i];

    }
  }

  ifs.close();
}


void Image::testRegression(){

    cout<<"test constructeur Image init zero"<<endl;
    Image a; 
    assert(a.c==0 && a.l==0 && intensiteMax==0);
    assert(tab!=nullptr);
    cout<<"ok"<<endl;
    cout<<"test charger image"<<endl;
}