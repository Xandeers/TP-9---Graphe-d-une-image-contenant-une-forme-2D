#ifndef IMAGE_
#define IMAGE_
#include<iostream>
using namespace std;

/**
 * @file Image.h
 * @brief header de la class Image
 * @author p2006707 p2208286
 * @date 2024
 */

/**
 * @class Punchman
*/
class Image
{
private:

    int l;
    int c ; //longueur, colone(largeur) d'une image 
    int *tab; //tableau 1d de taille l*c qui contiendra l'image


public: 

Image();//constructeur par defaut + initialise toutes les valeur a zero 

~Image();//destructeur

void charger_image(const string &fichier);

/**
* @brief 
* @param 
* @return 
*/
void sauvgarder_image(const string &fichier);

/**
* @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et font bien ce qu’elles sont censées faire, ainsi que les données membres de l'objet sont conformes
*/
static void testRegression();

};

#endif

