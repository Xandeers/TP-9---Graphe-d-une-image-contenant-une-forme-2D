#include<iostream>
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

void Image::testRegression(){

    cout<<"test constructeur Image"<<endl;
    Image a; 
    assert(a.c==0 && a.l==0);
    assert(tab!=nullptr);
    cout<<"ok"<<endl;
    
}