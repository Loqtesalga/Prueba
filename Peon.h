/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Peon.h
 * Author: marcos
 *
 * Created on 20 de noviembre de 2017, 10:11
 */

#ifndef PEON_H
#define PEON_H

#include <GL/glut.h>
#include "Casillas.h"
//si color = 0, es blanco, si color es = 1, es negro

class Peon {
private:
    
    float x;
    float y;
    float z;
    int color;
    int peon;
    int objeto_seleccionado;
    int pila_matriz;
     //fil y col de la casilla en la q estan
    int fil;
    int col;
    bool eliminada;
    
public:
    Peon(){};
    Peon(float _x, float _y, float _z,int _color,int _peon,int objeto_seleccionado):x(_x), y(_y), z(_z),color(_color),peon(_peon),objeto_seleccionado(objeto_seleccionado),eliminada(false){};
    Peon(const Peon& orig);
    ~Peon(){};
     Peon& operator=(const Peon &orig){
        x=orig.x;
        y=orig.y;
        z=orig.z;
        color = orig.color;
        peon=orig.peon;
        objeto_seleccionado=orig.objeto_seleccionado;
        pila_matriz=orig.pila_matriz;
        fil=orig.fil;
        col=orig.col;
        eliminada=orig.eliminada;
        
        return *this;
                
    }

    void pintarPeon();
    int getPeon(){return peon;}
    void setObjeto(int _obj){objeto_seleccionado=_obj;}
    void setPosiciones(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
    void setPilaMatriz(int pila){ pila_matriz=pila;}
    int getPilaMatriz(){return pila_matriz;}
    
   
    void setFil(int _fil){fil=_fil;};
    int getFil(){return fil;}
    
    void setCol(int _col){col=_col;}
    int getCol(){return col;}
    
    int getColor(){return color;}

    void setEliminada(bool _eliminada){eliminada=_eliminada;}
    bool getEliminada(){return eliminada;}
    
};

#endif /* PEON_H */

