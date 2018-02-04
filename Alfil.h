/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alfil.h
 * Author: marcos
 *
 * Created on 20 de noviembre de 2017, 18:06
 */

#ifndef ALFIL_H
#define ALFIL_H

#include <GL/glut.h>
#include "Casillas.h"

class Alfil {
    
private:

    float x;
    float y;
    float z;
    int color;    
    int alfil;
    int objeto_seleccionado;
    int pila_matriz;
    int fil;
    int col;
    bool eliminada;
    
public:
    Alfil(){};
    Alfil(const float &_x, const float &_y, const float &_z, const int &_color,const int &_alfil, const int &_objeto_seleccionado):x(_x),y(_y),z(_z),color(_color),alfil(_alfil),objeto_seleccionado(_objeto_seleccionado),eliminada(false){};
    Alfil(const Alfil& orig);
    ~Alfil(){};
    Alfil& operator=(const Alfil &orig){
        x=orig.x;
        y=orig.y;
        z=orig.z;
        color = orig.color;
        alfil=orig.alfil;
        objeto_seleccionado=orig.objeto_seleccionado;
        pila_matriz=orig.pila_matriz;
        fil=orig.fil;
        col=orig.col;
        eliminada=orig.eliminada;
        
        return *this;
                
    }
    
    
    void pintarAlfil();
    int getAlfil(){return alfil;}
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

#endif /* ALFIL_H */

