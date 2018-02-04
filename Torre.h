/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Torre.h
 * Author: marcos
 *
 * Created on 20 de noviembre de 2017, 23:26
 */

#ifndef TORRE_H
#define TORRE_H

#include <GL/glut.h>
#include "Casillas.h"

class Torre {
    
private:

    float x;
    float y;
    float z;
    int color;  
    int torre;
    int objeto_seleccionado;
    int pila_matriz;
     //fil y col de la casilla en la q estan
    int fil;
    int col;
    bool eliminada;
    
public:
    Torre(){};
    Torre(float _x, float _y, float _z,int _color, int _torre, int _objeto_seleccionado):x(_x), y(_y), z(_z),color(_color),torre(_torre),objeto_seleccionado(_objeto_seleccionado), eliminada(false){};
    Torre(const Torre& orig);
    ~Torre(){};
     Torre& operator=(const Torre &orig){
        x=orig.x;
        y=orig.y;
        z=orig.z;
        color = orig.color;
        torre=orig.torre;
        objeto_seleccionado=orig.objeto_seleccionado;
        pila_matriz=orig.pila_matriz;
        fil=orig.fil;
        col=orig.col;
        eliminada=orig.eliminada;
        
        return *this;
                
    }

    void pintarTorre();
    int getTorre(){return torre;}
     void setPosiciones(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
     void setPilaMatriz(int pila){ pila_matriz=pila;}
     int getPilaMatriz(){return pila_matriz;}
      void setObjeto(int _obj){objeto_seleccionado=_obj;}
    
    void setFil(int _fil){fil=_fil;};
    int getFil(){return fil;}
    
    void setCol(int _col){col=_col;}
    int getCol(){return col;}
    
    int getColor(){return color;}
    
    void setEliminada(bool _eliminada){eliminada=_eliminada;}
    bool getEliminada(){return eliminada;}
};

#endif /* TORRE_H */

