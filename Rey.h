/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rey.h
 * Author: marcos
 *
 * Created on 21 de noviembre de 2017, 17:40
 */

#ifndef REY_H
#define REY_H

#include <GL/glut.h>
#include "Casillas.h"

class Rey {
 
private:
    
    float x;
    float y;
    float z;
    int color;
    int rey;
    int objeto_seleccionado;
    int pila_matriz;
     //fil y col de la casilla en la q estan
    int fil;
    int col;
    bool eliminada;
    
public:
    Rey(){};
    Rey(float _x, float _y, float _z,int _color,int _rey, int _objeto_seleccionado):x(_x), y(_y), z(_z),color(_color),rey(_rey),objeto_seleccionado(_objeto_seleccionado),eliminada(false){};
    Rey(const Rey& orig);
    ~Rey(){};
     Rey& operator=(const Rey &orig){
        x=orig.x;
        y=orig.y;
        z=orig.z;
        color = orig.color;
        rey=orig.rey;
        objeto_seleccionado=orig.objeto_seleccionado;
        pila_matriz=orig.pila_matriz;
        fil=orig.fil;
        col=orig.col;
        eliminada=orig.eliminada;
        
        return *this;
                
    }
    
    void pintarRey();
    int getRey(){return rey;}
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

#endif /* REY_H */

