#ifndef IMAGE_
#define IMAGE_
#include<iostream>
using namespace std;

class Image
{
private:

    int l;
    int c ; //longueur, colone(largeur) d'une image 
    int intensiteMax;
    int *tab; //tableau 1d de taille l*c qui contiendra l'image


public: 

Image();//constructeur par defaut + initialise toutes les valeur a zero 

Image(const string &fichier);//construit une image a partir d'un fichier 

~Image();//destructeur

void charger_image(const string &fichier);

void testRegression();//fonction qui permettra de savoir si les fonction de la classe marche correctement 

};

#endif

