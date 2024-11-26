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

 enum Etiquette {
    Noir =0,   // 0
    Gris =1,   // 1
    Blanc =2,   // 2
};

/**
 * @class Image
*/
class Image
{
private:

    int l; /**<longueur d'une image  */
    int c ;  /**<colone(largeur) d'une image  */
    int *tab; /**<tableau 1d de taille l*c qui contiendra l'image */


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
int voisin (const int &indice);


/**
 * @brief fonction qui construit et va renvoyer un tableau de predecesseur pour savoir quelle est le noeud precedant dans le plus cour chemin 
 * @return un pointeur qui pointe sur un tableau dans le tas  attention ne pas oublier le delete les valeur dans ce tab sont des int pour representer l'indice ou se trouve le pixel predesseur 
 */
int* tab_pred();

/**
 * @brief fonction qui construit et va renvoyer un tableau d'etat donc pour savoir si un noeud appartient a la forme ou non en utilisant un type etiquette
 * @return un pointeur qui pointe sur un tableau dans le tas  attention ne pas oublier le delete
 */
Etiquette* tab_etat();

/**
 * @brief fonction qui construit et va renvoyer un tableau de distance pour savoir la distance entre les pixel noir et blanc 
 * @return un pointeur qui pointe sur un tableau dans le tas  attention ne pas oublier le delete les valeur dans ce tab sont des int pour representer l'indice ou se trouve le pixel predesseur 
 */
int* tab_dist();

/**
 * @brief procedure qui modifier les valeur des tableau pris en parametre en utilisant le principe de l'alogorithme de dijkstra 
 * @param dist il s'agit d'un pointeur sur un tableau de int dans le tas qui correspond au valeur la plus petite de la distance entre le pixel et le pixel noir le plus proche 
 * @param etiquette il s'agit d'un pointeur sur un tableau d' "etiquette" enum qui a été cree pour identifier les pixelle viste accessible (voir cm) le tab est stoquer dans le tas 
 * @param pred il s'agit d'un tab de predesseur qui donne quelle est le noeud precedant dans le plus cour chemin 
 * @return un pointeur qui pointe sur un tableau dans le tas  attention ne pas oublier le delete les valeur dans ce tab sont des int pour representer l'indice ou se trouve le pixel predesseur 
 */
void algorithme_dijkstra(int* &dist, Etiquette* &etiquette, int* &pred);


/**
* @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et font bien ce qu’elles sont censées faire, ainsi que les données membres de l'objet sont conformes
*/
static void testRegression();

};

#endif

