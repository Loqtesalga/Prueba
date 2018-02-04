/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reina.h
 * Author: marcos
 *
 * Created on 22 de noviembre de 2017, 17:33
 */

#ifndef REINA_H
#define REINA_H

#include <GL/glut.h>
#include "Casillas.h"

class Reina {
    
    private:
    
    float x;
    float y;
    float z;
    int color;
    int reina;
    int objeto_seleccionado;
    int pila_matriz;
    //fil y col de la casilla en la q estan
    int fil;
    int col;
    bool eliminada;
    
    
public:
    Reina(){};
    Reina(float _x, float _y, float _z,int _color, int _reina, int _objeto_seleccionado):x(_x), y(_y), z(_z),color(_color),reina(_reina),objeto_seleccionado(_objeto_seleccionado),eliminada(false){};
    Reina(const Reina& orig);
    ~Reina(){};
     Reina& operator=(const Reina &orig){
        x=orig.x;
        y=orig.y;
        z=orig.z;
        color = orig.color;
        reina=orig.reina;
        objeto_seleccionado=orig.objeto_seleccionado;
        pila_matriz=orig.pila_matriz;
        fil=orig.fil;
        col=orig.col;
        eliminada=orig.eliminada;
        
        return *this;
                
    }
    
    void pintarReina();
    int getReina(){return reina;}
    void setPosiciones(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
    void setObjeto(int _obj){objeto_seleccionado=_obj;}
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

#endif /* REINA_H */

