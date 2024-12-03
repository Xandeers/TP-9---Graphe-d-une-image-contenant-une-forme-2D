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

 enum forme {
    
    vide=0,   // 0
    rectangle =1,   // 1
    croix =2,
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
 * @brief il s'agit du constructeur par defaut + initialise toutes les valeur a zero 
 */
Image(int x, int y);


/**
 * @brief il s'agit du destructeur 
 */
~Image();//destructeur

/**
 * @brief modifie la taille du tab de l'image
 */
void set_tab(const int &l, const int &c);
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
 * @brief cette procedure est la procedure qui appeler toute les autre fonction afin de pouvoir cree l'image de distance elle va donc nous cree les tableau et aussi utiliser l'algorithme de dijkstra pour modifier les valeur des pixel 
 */
void construction_image_dist(int* &dist, Etiquette* &etiquette, int* &pred);


/**
 * @brief procedure qui permet de sauvegarder une image de distance elle verifira que cette img est bien un image de distance 
 */
void sauv_img_dist(const string &fichier);

/**
 * @brief fonction qui a partir d'une image de distance prend un pixel et nous donne le pixel appartenant a la forme le plus proche du pixel 
 * @param indice il s'agit de l'indice du pixel de l'image
 * @param pred il s'agit du pointeur sur le tableau de predecesseur qui est stoquer dans le tas  
 * @return l'indice du pixel de la forme le plus proche et si le pixel appartient deja a la forme alors il renvoit son indice 
 */
int projection(const int &indice,int* &pred);

/**
 * @brief fonction qui a partir d'une image de distance prend un pixel et nous donne le pixel appartenant a la forme le plus proche du pixel 
 * @param indiceX il s'agit de l'indice X du pixel de l'image
 * @param indiceY il s'agit de l'indice Y du pixel de l'image
 * @param pred il s'agit du pointeur sur le tableau de predecesseur qui est stoquer dans le tas  
 * @return l'indice du pixel de la forme le plus proche et si le pixel appartient deja a la forme alors il renvoit son indice 
 */
int projection(const int &X,const int &Y,int* &pred);

/**
 * @brief fonction qui nous dit si il s'agit d'une image de distance sera tres utile pour l'union car on la calcule avec une image de distance et cela permet de savoir si on a besoin de calculer l'image de distance 
 * @return un booleen 
 */
bool img_de_dist();

/**
 * @brief fonction qui cree une image qui est l'union de deux image donc l'union de deux forme 
 * @param b est la deuxieme image avec laquelle on va faire l'union des deux formes 
 * @return retourne une nouvelle image DE DISTANCE qui est constituer de l'union des deux 
 */
Image union_image(Image &b);

/**
 * @brief fonction qui a partir de deux image ou les tableau ont deja été cree sans calculer l'algo de drijska on fait l'union des deux 
 * @param dist il s'agit du tableau de distance de l'image 1  
 * @param etiquette il s'agit du tableau d'etat de l'image 1
 * @param pred il s'agit du tableau de predecesseur de l'image 1
 * @param dist2 il s'agit du tableau de distance de l'image 2  
 * @param etiquette2 il s'agit du tableau d'etat de l'image 2
 * @param pred2 il s'agit du tableau de predecesseur de l'image 2
 */
Image union_image(int* &dist, Etiquette* &etiquette, int* &pred,int* &dist2, Etiquette* &etiquette2, int* &pred2);

/**
 * @brief procedure qui transforme l'image de distance en image d'origine 
 */
void retour_origine();


/**
 * @brief precedure qui cree une image avec une forme au choix on choisie aussi les dimension (utile pour le menu )
 * @param x il s'agit de la longueur l de l'image 
 * @param y il s'agit de la longueur c de l'image 
 * @param posx il s'agit de la position x du centre de la forme 
 * @param posy il s'agit de la position y du centre de la forme 
 * @param a il s'agit de la forme choisi par l'utilisateur 
 * @param largeur il s'agit de la longueur de la forme
 * @param hauteur il s'agit de la hauteur de la forme
 */
void cree_forme(const int &posx,const int &posy, forme a, int longeur,int hauteur);

/**
* @brief Effectue une série de tests vérifiant que toutes les fonctions fonctionnent et font bien ce qu’elles sont censées faire, ainsi que les données membres de l'objet sont conformes
*/
static void testRegression();

};

#endif

