/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Casillas.h
 * Author: marcos
 *
 * Created on 5 de diciembre de 2017, 0:51
 */

#ifndef CASILLAS_H
#define CASILLAS_H

class Casillas {

private:
    
    int fil;
    int col;
    
    float x;
    float y;
    float z;
    int pila_nombre;
    bool ocupada;
    
public:
    Casillas(){};
    Casillas(float _x, float _y, float _z, int _pila_nombre, bool _ocupada ):x(_x),y(_y),z(_z),pila_nombre(_pila_nombre),ocupada(_ocupada){};
    Casillas(const Casillas& orig){
        
        fil=orig.fil;
        col=orig.col;
        
        x=orig.x;
        y=orig.y;
        z=orig.z;
        
        pila_nombre=orig.pila_nombre;
        ocupada=orig.ocupada;
        
        
    };
    ~Casillas(){};
    
    Casillas& operator=(const Casillas &orig){
        
        fil=orig.fil;
        col=orig.col;
        
        x=orig.x;
        y=orig.y;
        z=orig.z;
        
        pila_nombre=orig.pila_nombre;
        ocupada=orig.ocupada;
        
        return (*this);
    }

    void setX(float _x){ x=_x;};
    float getX(){return x;};
    
    void setY(float _y){ y=_y;};
    float getY(){return y;}
    
    void setZ(float _z){ z=_z;};
    float getZ(){return z;};
    
    void setPilanombre(int _pila_nombres){ pila_nombre=_pila_nombres;};
    int getPilanombre(){return pila_nombre;};
    
    void setOcupada(bool _ocupada){ocupada=_ocupada;};
    bool getOcupada(){return ocupada;};
    
    bool operator==(const Casillas &ca) const {return (x==ca.x)&&(y==ca.y)&&(z==ca.z);}
    
    void setFil(int _fil){ fil=_fil;}
    int getFil(){return fil;}
    
    void setCol (int _col) {col=_col;}
    int getCol(){ return col;}
};

#endif /* CASILLAS_H */

