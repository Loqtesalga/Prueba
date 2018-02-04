/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.h
 * Author: marcos
 *
 * Created on 19 de noviembre de 2017, 23:13
 */

#ifndef TABLERO_H
#define TABLERO_H

#include <GL/glut.h>
#include"Casillas.h"

class Tablero {
    
private:
   
    Casillas casillas[8][8];
    
public:
    Tablero();
    Tablero(const Tablero& orig);
    ~Tablero(){};
    
    void inicializarTablero();
    void pintarTablero();
     void pintarBaseTablero();
     void imprimirCasillas();
     Casillas* getCasilla(int pila_nombre);
     Casillas* getCasillaAux(int fil, int col);

};

#endif /* TABLERO_H */

