#include<iostream>
#include<fstream>
#include<cassert>
#include<queue>
#include<algorithm>
#include"Image.h"

using namespace std; 

struct Noeud {
    int dist;   // Distance
    int index;  // Index du pixel

    // Comparateur pour la file de priorité (ordre croissant sur la distance)
 bool operator>(const Noeud& other) const {
        return dist > other.dist;
    }
};

Image::Image(){

    l=0;
    c=0;
    tab=nullptr;
}

Image::Image(int x, int y){
    l=x;
    c=y;
    tab=new int[l*c];
    for(int i=0;i<l*c;i++){
        tab[i]=255;
    }
}

Image::~Image(){

    if(tab!=nullptr){
        delete []tab;
    }
}


void Image::set_tab(const int &l, const int &c){

    tab = new int[l*c];    
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
  
  ofstream ofs;
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
            dist[i]=100000;
        }
    }
    return dist;
}

void Image::algorithme_dijkstra(int* &dist, Etiquette* &etiquette, int* &pred){

     // File de priorité pour Dijkstra (stocke l'index du pixel et sa distance). Ils sont triés dans l'ordre croissant selon le premier élément de la paire (grâce à std::greater).
       priority_queue<Noeud,vector<Noeud>, greater<Noeud>> pq; 

    //initialisation de la file de prio on ajoute les pixel noir avec leur distance connu a 0
    for(int i=0; i<l*c;i++){
        if(tab[i]==0){
            pq.push(Noeud{0,i});
        }
    }
    // Déplacements possibles (horizontal, vertical, diagonal)
    const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
    const int costs[] = {2, 2, 2, 2, 3, 3, 3, 3}; 

    // Boucle principale de l'algorithme
    while (!pq.empty()) {
        // Extraire le pixel avec la plus petite distance
        Noeud actuel = pq.top();
        pq.pop();
    
     int buff_dist = actuel.dist;
    int buff_index = actuel.index;

    // Si  visite continuer
     if (etiquette[buff_index] ==Gris)
     {
     continue;
     }
     else{
        // Marquer comme vu
        etiquette[buff_index] =Gris;
     }
     // Convertir l'index en coordonnées 2D
        int x = buff_index % c; // Colonne
        int y = buff_index / c; // Ligne

    // calcul des voisin 
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i]; 

             // verif si les coordone sont ok 
            if (nx >= 0 && nx < c && ny >= 0 && ny < l) {
                int voisin_index = ny * c + nx; //index 1d voisin
                int nouv_dist = buff_dist + costs[i];

                if (nouv_dist < dist[voisin_index]) {
                    dist[voisin_index] = nouv_dist; // actualise le distance
                    pred[voisin_index] = buff_index; // sauvegarde le pred
                    pq.push(Noeud{nouv_dist, voisin_index}); // Ajouter 

        }
    }
   }
  }
}

void Image::construction_image_dist(int* &dist, Etiquette* &etiquette, int* &pred){

  // Trouver la distance max
    int maxDist = 0;
    for (int i = 0; i < l * c; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
        }
    }

    // Si la distance max est ok alors normaliser les pixels
    if (maxDist > 0) {
        for (int i = 0; i < l * c; i++) {
            if (dist[i] == maxDist) {
                tab[i] = 255; // pixel avec dist max
            } else if (dist[i] != 0) {
                tab[i] = (dist[i] * 255) / maxDist; 
            }
        }
    }
}

int Image::projection(const int &indice,int* &pred){

if(indice<l*c){ //si image 3x3 on demande l'indice 12 probleme 

    if(tab[indice]==0){ //si il s'agit d'un pixel noir 
        return indice; 
    }
    else{
        int buff=pred[indice];
        while(tab[buff]!=0)
        {
            buff=pred[buff];
        }
        return buff;
    }
}
else{

    cout<<"attention le pixel demander et hors image"<<endl;
    return -1; 
}
}

int Image::projection(const int &X, const int &Y, int* &pred){

    return projection(X*c+Y,pred);
}

bool Image::img_de_dist(){
    for(int i=0;i<l*c;i++){
        if(tab[i]!=0 && tab[i]!=255){

            return true;
        }
        
    }
    return false;
}

Image Image::union_image(Image &b){

    
    if(img_de_dist()==false)//si image 1 n'est pas une image de dist
    {
        int* distan = tab_dist();
        int* prede = tab_pred();
        Etiquette* etiqe =tab_etat();

        algorithme_dijkstra(distan,etiqe,prede);
        construction_image_dist(distan,etiqe,prede);
        delete []distan;
        delete []prede;
        delete []etiqe;
    }
     if(b.img_de_dist()==false)//si image 2 n'est pas une image de dist
    {
        int* distan2 =b.tab_dist();
        int* prede2 =b.tab_pred();
        Etiquette* etiqe2 =b.tab_etat();

        b.algorithme_dijkstra(distan2,etiqe2,prede2);
        b.construction_image_dist(distan2,etiqe2,prede2);
        delete []distan2;
        delete []prede2;
        delete []etiqe2;
    }
    //maintenant dans peu importe les image choisie ont a deux image de distance
    
    Image uni(l,c);

    for( int i =0;i<l*c ;i++){
        if(tab[i]==0 || b.tab[i]==0){//si l'un des deux fait partie de la forme donc pixel noir 

            uni.tab[i]=0;
        }
        else{
            uni.tab[i]=min(tab[i],b.tab[i]);
        }
    }
    //maintenant uni est une image de l'union des deux 
   return uni;
}

Image Image::union_image(int* &dist, Etiquette* &etiquette, int* &pred,int* &dist2, Etiquette* &etiquette2, int* &pred2){

    //donc on a deja dijkstra qui a été calculer et les tableau deja remplis 
    Image add (l,c);

     for (int i=0;i<l*c;i++){
        if(dist[i]==0 || dist2[i]==0){ //donc un pixel est noir 
            add.tab[i]=0;
        }
        else{
            add.tab[i]=min(dist[i],dist2[i]);//en attendant tab de i prend la dist 
        }
     }
     int buff=0;
      for (int i = 0; i < l * c; i++) {
        if (dist[i] > buff) {
            buff = dist[i];
        } 
        //on a la distance max on peu maintenant normaliser 
    }
    for(int i=0;i<l*c;i++){
        add.tab[i]=(add.tab[i]*255)/buff;
    }
    return add;

    
     
     

}

void Image::retour_origine(){

    for(int i=0;i<l*c;i++){
        if(tab[i]!=0){
            tab[i]=255;
        }
    }
}

void Image::cree_forme(const int &posx,const int &posy, forme a, int longueur,int hauteur){

     if (a == rectangle) {
        // Parcourir les pixels correspondant au rectangle
        for (int i = 0; i < longueur; i++) {
            for (int j = 0; j < hauteur; j++) {
                // Calculer les coordonnées globales
                int x = posx + i; // Déplacement horizontal
                int y = posy + j; // Déplacement vertical

                // Vérifier que les coordonnées sont dans les limites de l'image
                if (x >= 0 && x < c && y >= 0 && y < l) {
                    tab[y * c + x] = 0; // Remplir le pixel avec noir
                }
            }
        }
    }
}
    


void Image::testRegression(){

    cout<<"test constructeur Image init zero"<<endl;
    Image a; 
    assert(a.c==0 && a.l==0);
    //assert(a.tab!=nullptr);
    cout<<"ok"<<endl<<endl;


    cout<<"test charger image"<<endl;
    a.charger_image("./data/image_test_pgm.txt");
    assert(a.c==5 && a.l == 3);
    assert(a.tab != nullptr);
    cout<<"ok"<<endl<<endl;


    cout<<"test sauvegarder image"<<endl;
    a.sauvgarder_image("./data/image_sauv_test_pgm.txt");
    a.sauvgarder_image("./data/creationsauvegarde.pgm");
    Image b;
    b.charger_image("./data/image_sauv_test_pgm.txt");
    
    assert(a.c==b.c && a.l==b.l && b.tab != nullptr);
    assert(a.tab[0]==b.tab[0]);
    assert(a.tab[3]==b.tab[3]);
    cout<<"ok"<<endl<<endl;


    cout<<"test etiquette pour algo dijktra"<<endl;
    Etiquette* test = a.tab_etat();
    assert(test[0]== Blanc);
    assert(test[9]==Noir);
    delete[]test;
    cout<<"ok"<<endl<<endl;


    cout<<"test predecesseur pour algo dijktra"<<endl;
    int* test2 = a.tab_pred();
    assert(test2[0]==-1 );
    assert(test2[9]==9);
    delete[]test2;
    cout<<"ok"<<endl<<endl;


    cout<<"test dist pour algo dijktra"<<endl;
    int* test3 = a.tab_dist();
    assert(test3[0]==100000 );
    assert(test3[9]==0);
    delete[]test3;
    cout<<"ok"<<endl<<endl;


    cout<<"test disjsktra + affichage des 10 premier"<<endl;
    Image c; 
    c.charger_image("./data/test.pgm"); 
    int *dist=c.tab_dist();
   Etiquette* etiq= c.tab_etat();
    int* pred=c.tab_pred();
    c.algorithme_dijkstra(dist,etiq,pred);
    for(int i =0; i<10;i++){
        cout<<"indice "<<i<<"= "<<dist[i]<<'\t'<<"pred ="<<pred[i]<<endl;
     }
     delete []dist;
     delete []etiq;
     delete []pred; 
     cout<<"ok"<<endl<<endl; //pas de assert mais verifier plusieur fois avec des tab de taille diff


    cout<<"test construction image distance"<<endl;
    Image d;
    d.charger_image("./data/test2_img_dist.pgm");
    int* dist2=d.tab_dist();
    int* pred2=d.tab_pred();
    Etiquette* etiq2=d.tab_etat();
    d.algorithme_dijkstra(dist2,etiq2,pred2);
    d.construction_image_dist(dist2,etiq2,pred2);
    d.sauvgarder_image("./data/test.pgm");
    //d.sauvgarder_image("./data/image_sauv_test_pgm.txt");
     delete []dist2;
     delete []etiq2;
     delete []pred2; 
     cout<<"ok"<<endl<<endl;

     
     cout<<"Test projection de pixel"<<endl;
     Image x; 
     x.charger_image("./data/test2_img_dist.pgm");
     int* dist3=x.tab_dist();
     int* pred3 =x.tab_pred();
     Etiquette* etiq3 =x.tab_etat();
     x.algorithme_dijkstra(dist3,etiq3,pred3); //pour la projection il n'y a pas besoin forcement de construire l'image de distance donc moins "complexe","energivore"
    int qqc = x.projection(189,pred3);
    int qqc2 = x.projection(190,pred3);
    assert(qqc == 190);
    assert(qqc2 == 190);
    cout<<"ok"<<endl<<endl;


    cout<<"Test projection de pixel X et Y"<<endl;
    int coordoner = x.projection(6,9,pred3);
    assert(coordoner==190);
    cout<<"ok"<<endl<<endl;
    delete []dist3;
    delete []pred3;
    delete []etiq3;

    cout<<"test fonction booleen"<<endl;
    Image g;
    g.charger_image("./data/test2_img_dist.pgm");
    assert(g.img_de_dist()==false);
     int* dist4=g.tab_dist();
     int* pred4 =g.tab_pred();
     Etiquette* etiq4 =g.tab_etat();
     g.algorithme_dijkstra(dist4,etiq4,pred4);
     assert(g.img_de_dist()==false);
     g.construction_image_dist(dist4,etiq4,pred4);
     assert(g.img_de_dist()==true);
     cout<<"ok"<<endl<<endl;


    cout<<"Test Union"<<endl;
    Image n;
    n.charger_image("./data/image_union.pgm");
    Image m;
    m.charger_image("./data/image_test_pgm.txt");
    Image union_forme= n.union_image(m);
    assert(union_forme.tab[9]==0 && union_forme.tab[11]==0);
    union_forme.sauvgarder_image("./data/image_union_dist.pgm");
    int* dista2=n.tab_dist();
    int* prede2=n.tab_pred();
    Etiquette* etiqe2=n.tab_etat();
    int* dista3=m.tab_dist();
    int* prede3=m.tab_pred();
    Etiquette* etiqe3=m.tab_etat();
    Image union_forme2=n.union_image(dista2,etiqe2,prede2,dista3,etiqe3,prede3);
    assert(union_forme2.tab[9]==0 && union_forme2.tab[11]==0);
    union_forme2.sauvgarder_image("./data/image_union_dist.pgm");
    cout<<"ok"<<endl;

            /////////////////////////// C'est fonction sont la pour le menu///////////////////////////

    cout<<"test creation d'image"<<endl;
    int x1=15;
    int y1= 15; 
    Image crea(x1,y1);
    crea.cree_forme(0,0,rectangle,10,5);
    crea.sauvgarder_image("./data/creation_test.pgm");

    
}
    
