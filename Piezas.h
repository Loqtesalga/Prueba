/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piezas.h
 * Author: marcos
 *
 * Created on 20 de noviembre de 2017, 17:24
 */

#ifndef PIEZAS_H
#define PIEZAS_H

#include "Tablero.h"
#include "Alfil.h"
#include "Peon.h"
#include "Torre.h"
#include"Caballo.h"
#include "Rey.h"
#include "Reina.h"

class Piezas {

protected:
    Peon peones[16];
    Alfil alfiles[4];
    Torre torres[4];
    Caballo caballos[4];
    Rey reyes[2];
    Reina reinas[2];
    int objeto_seleccionado;
    int pila_nombres;
      
    
public:
    
    Piezas();
    Piezas(const Piezas& orig);
    ~Piezas(){};

    void setObjetoSeleccionado(int _objeto_seleccionado){ objeto_seleccionado=_objeto_seleccionado;}
   
    void pintarPeones();
    void pintarCaballo();
    void pintarAlfil();
    void pintarReyes();
    void pintarReinas();
    void pintarTorres();
    
    
    Peon* actualizarPeon(int pila_nombre, float x, float z, int tipo,int color);
    Alfil* actualizarAlfil(int pila_nombre, float x, float z, int tipo, int color);
    Torre* actualizarTorre(int pila_nombre, float x, float z, int tipo, int color);
    Caballo* actualizarCaballo(int pila_nombre, float x, float z,int tipo, int color);
    Rey* actualizarRey(int pila_nombre, float x, float z, int tipo,int color);
    Reina* actualizarReina(int pila_nombre, float x, float z, int tipo,int color);
    
    
    
   
    
};

#endif /* PIEZAS_H */

