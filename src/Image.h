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
/**
 * @brief il s'agit du constructeur par defaut + initialise toutes les valeur a zero 
 */
Image();

/**
 * @brief il s'agit du destructeur 
 */
~Image();//destructeur

/**
 * @brief permet de charger une image donc a partir d'une image on remplis le tableau 1d de pixel avec leur valeur attention le fichier doit etre avec le sigle P2 sinon il ne sera pas traité
 * @param fichier est le fichier que l'on va charger 
 */
void charger_image(const string &fichier);

/**
* @brief permet de sauvgarder l'image l'ordre et la valueur de chaque picxel dans un fichier 
* @param fichier est le fichier dans lequel on va sauvgarder notre image 
* @return 
*/
void sauvgarder_image(const string &fichier);

/**
 * @brief fonction qui calcule le voisin ...
 * @param indice est l'indice du pixel que l'on traite 
 * @return un int qui correspond a l'indice dans le tableau 1d du voisin en question 
 */
int voisin(const int &indice);

/**
* @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et font bien ce qu’elles sont censées faire, ainsi que les données membres de l'objet sont conformes
*/
static void testRegression();

};

#endif

