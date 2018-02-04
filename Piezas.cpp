/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Piezas.cpp
 * Author: marcos
 * 
 * Created on 20 de noviembre de 2017, 17:24
 */

#include<iostream>
#include "Tablero.h"
#include "Piezas.h"
#include "Peon.h"
#include "Alfil.h"

Piezas::Piezas():pila_nombres(0),objeto_seleccionado(0){
    
    //instanciar los objetos de las piezas aquí, y luego en pintar, lo añadimos a la pila de nombres.
    
   // pintarTablero();
    
    //PEONES
    
          
     float aux1=0.63,aux2=0.32;
    
    for(int i=0; i<8; ++i){
        
        ++pila_nombres;        
        Peon p(0.95,-1.5,aux2,0,pila_nombres,objeto_seleccionado);
        peones[i]=p;
        peones[i].setFil(1);
        peones[i].setCol(i);
        aux2+=aux1;
        
     
        
    }
    
     aux2=0.32;
     int col=0;
      for(int i=8; i<16; ++i){
    
       ++pila_nombres; 
        Peon p(4.1,-1.5,aux2,1,pila_nombres,objeto_seleccionado);
        peones[i]=p;
         peones[i].setFil(6);
        peones[i].setCol(col);
        ++col;
        aux2=aux2+aux1;
     }
     
    //ALFIL 
     
        
    
    aux1=0.63;
    aux2=1.58;
    aux1*=3;
    col=2;
    
      for(int i =0; i<2; ++i ){
        ++pila_nombres;
        Alfil f(4.7,-1.3,aux2,1,pila_nombres,objeto_seleccionado);
        alfiles[i]=f;
        alfiles[i].setFil(7);
         alfiles[i].setCol(col);
        
        aux2+=aux1;
        col+=3;
       
      }
    
       aux2=1.58;
       col=2;
       
     for(int i=2; i<4; ++i){
       ++pila_nombres;
       Alfil f(0.35,-1.3,aux2,0,pila_nombres,objeto_seleccionado);
       alfiles[i]=f;
        alfiles[i].setFil(0);
        alfiles[i].setCol(col);
       aux2+=aux1;
       col+=3;
     }
       
    //TORRES  
       
    aux2=0.32;
    aux1=0.63;
    aux1*=7;
    col=0;
    
    for(int i=0; i<2; ++i){
        ++pila_nombres;
        Torre t(0.35,-1.3,aux2,0,pila_nombres,objeto_seleccionado);
        torres[i]=t;
        torres[i].setFil(0);
        torres[i].setCol(col);
        col+=7;
        aux2+=aux1;
    }   
    
     col=0;
     aux2=0.32;
    
     for(int i=2; i<4; ++i){
        ++pila_nombres;
        Torre t(4.7,-1.3,aux2,1,pila_nombres,objeto_seleccionado);
        torres[i]=t;
        torres[i].setFil(7);
        torres[i].setCol(col);
         aux2+=aux1;
         col+=7;
     }
     
     
     //REYES
     
    aux2=0.32;
    aux1=0.63;
    aux1*=3;
    aux2+=aux1;
     
     ++pila_nombres;
     Rey r(4.7,-1.3,aux2,1,pila_nombres,objeto_seleccionado);
     reyes[0]=r;
     reyes[0].setFil(7);
     reyes[0].setCol(3);
     
   
     ++pila_nombres;
     Rey r1(0.35,-1.3,aux2,0,pila_nombres,objeto_seleccionado);
     reyes[1]=r1;
     reyes[1].setFil(0);
     reyes[1].setCol(3);
     
     
     //Caballo
     
    aux2=0.32;
    aux1=0.63;
    aux2+=aux1;
    aux1*=5;
    col=1;
    
    
    
    for(int i=0; i<2; ++i){
        ++pila_nombres;
      //  glPushMatrix(); 
      //      glRotatef(90,0,1,0);
            Caballo c(0.35,-1.3,aux2,0,pila_nombres,objeto_seleccionado);
            caballos[i]=c;
            caballos[i].setFil(0);
            caballos[i].setCol(col);
            aux2+=aux1;
        // glPopMatrix();
        col+=5;
    }
    
    col=1;
     aux2=0.32;
     aux1=0.63;
    aux2+=aux1;
    aux1*=5;
    
    
     for(int i=2; i<4; ++i){
        ++pila_nombres;
 //       glPushMatrix(); 
 //           glRotatef(-180,0,1,0);
            Caballo c(4.7,-1.3,aux2,1, pila_nombres,objeto_seleccionado);
            caballos[i]=c;
              caballos[i].setFil(7);
            caballos[i].setCol(col);
            aux2+=aux1;  
   //     glPopMatrix();
        col+=5;
     }
    
     //REINAS
    
       
     aux2=0.32;
     aux1=0.63;
     aux1*=4;
     aux2+=aux1;
     
     ++pila_nombres;
     Reina re1(4.7,-1.3,aux2,1,pila_nombres,objeto_seleccionado);
     reinas[0]=re1;
     reinas[0].setCol(4);
     reinas[0].setFil(7);
    
     ++pila_nombres;
     Reina re2(0.35,-1.3,aux2,0,pila_nombres,objeto_seleccionado);
     reinas[1]=re2;
     reinas[1].setCol(4);
     reinas[1].setFil(0);
     
    
}

Piezas::Piezas(const Piezas& orig) {
    
 
}

void Piezas::pintarPeones(){
    
    
    //PEONES
        
    // 0.32 para acercar al centro del quad, y 0.63 para avanzar de quad en quad
    
    for(int i=0; i<8; ++i){
        if(!peones[i].getEliminada()){
            glPushMatrix();   
                glPushName(peones[i].getPeon());
                    peones[i].setObjeto(objeto_seleccionado);
                    peones[i].pintarPeon();
                glPopName();
           glPopMatrix();
        }
    }
      
    
    for(int i=8; i<16; ++i){
        if(!peones[i].getEliminada()){
            glPushMatrix();   
                glPushName(peones[i].getPeon());
                    peones[i].setObjeto(objeto_seleccionado);
                    peones[i].pintarPeon();
                glPopName();
            glPopMatrix();
        }
            
    }
      
}

void Piezas::pintarAlfil(){
    
   
    for(int i =0; i<2; ++i ){
        if(!alfiles[i].getEliminada()){
            glPushMatrix();   
               glPushName( alfiles[i].getAlfil());
                    alfiles[i].setObjeto(objeto_seleccionado);
                    alfiles[i].pintarAlfil();
               glPopName();
           glPopMatrix();
        }
         
    }
    
     
    for(int i=2; i<4; ++i){
         if(!alfiles[i].getEliminada()){
            glPushMatrix();   
                glPushName(alfiles[i].getAlfil());
                     alfiles[i].setObjeto(objeto_seleccionado);
                     alfiles[i].pintarAlfil();
                glPopName();
            glPopMatrix(); 
         }
    }
    
}


void Piezas::pintarTorres(){
    
   
    
     for(int i=0; i<2; ++i){
          if(!torres[i].getEliminada()){
            glPushMatrix();   
                glPushName( torres[i].getTorre());
                 torres[i].setObjeto(objeto_seleccionado);
                    torres[i].pintarTorre();
                glPopName();
            glPopMatrix();
          }
     }
     
   
     for(int i=2; i<4; ++i){
          if(!torres[i].getEliminada()){
            glPushMatrix();   
                glPushName(torres[i].getTorre());
                 torres[i].setObjeto(objeto_seleccionado);
                   torres[i].pintarTorre();
                glPopName();
            glPopMatrix();
          }
    }
    
}


void Piezas::pintarReyes(){

     // REYES
     
    if(!reyes[0].getEliminada()){
        glPushMatrix();   
            glPushName(reyes[0].getRey());
                reyes[0].setObjeto(objeto_seleccionado);
                 reyes[0].pintarRey();
            glPopName();
        glPopMatrix();
    }
    
    
   if(!reyes[1].getEliminada()){
        glPushMatrix();   
            glPushName(reyes[1].getRey());
                reyes[1].setObjeto(objeto_seleccionado);
                 reyes[1].pintarRey();
            glPopName();
        glPopMatrix();
   }
    
}


void Piezas::pintarCaballo(){
    
     //caballos al girar 90º lax y la z están cambiadas, ahora la x dirá cual es la posicion en la fila del tablero y la z la columna, además la x es negativa
   
    
    for(int i=0; i<2; ++i){
      if(!caballos[i].getEliminada()){
           glPushMatrix();   
                glPushName( caballos[i].getCaballo());
                              
                     caballos[i].setObjeto(objeto_seleccionado);
                     caballos[i].pintaCaballo();
                               
                glPopName();
            glPopMatrix();
      }
    }
        
    // caballo al girar 90º para calcular columna la z en negativo(toma el valor de x de las otras figuras) y para la fila (-0.32+(0.63*numcolumnas))
    
    for(int i=2; i<4; ++i){
         if(!caballos[i].getEliminada()){
            glPushMatrix();   
                    glPushName(caballos[i].getCaballo());
                 //       glPushMatrix(); 
                   //            glRotatef(270,0,1,0);
                                caballos[i].setObjeto(objeto_seleccionado);
                               caballos[i].pintaCaballo();
                   //     glPopMatrix();
                    glPopName();
            glPopMatrix();
         }
    }
}



void Piezas::pintarReinas(){
    
  
     if(!reinas[0].getEliminada()){  
            glPushName( reinas[0].getReina());
                reinas[0].setObjeto(objeto_seleccionado);
                reinas[0].pintarReina();
            glPopName();
        glPopMatrix();
     }
   
     if(!reinas[1].getEliminada()){ 
        glPushMatrix();   
            glPushName(reinas[1].getReina());
                 reinas[1].setObjeto(objeto_seleccionado);
                reinas[1].pintarReina();
            glPopName();
        glPopMatrix();
     }
    
    
}

Peon* Piezas::actualizarPeon(int pila_nombre, float x, float z, int tipo, int color){
    
    if(tipo==0){
        for(int i=0; i<16; ++i){
          if(peones[i].getPeon()==pila_nombre){
           //   peones[i].setPosiciones(x,-1.5,z);
              return &peones[i];
          }
        }
    }else{
         for(int i=0; i<16; ++i){
          if(peones[i].getFil()==x && peones[i].getCol()==z && peones[i].getColor()!= color){
              peones[i].setEliminada(true);
            return &peones[i];
          }
        }
    }
      return 0;
    
}

Alfil* Piezas::actualizarAlfil(int pila_nombre, float x, float z, int tipo, int color){
 
    if(tipo==0){
        for(int i=0; i<4; ++i){
                if(alfiles[i].getAlfil()==pila_nombre){
              //      alfiles[i].setPosiciones(x,-1.3,z);
                    return &alfiles[i];
                }
            }
    
    }else{
         for(int i=0; i<4; ++i){
            if(alfiles[i].getFil()==x && alfiles[i].getCol()==z && alfiles[i].getColor()!=color ){
                alfiles[i].setEliminada(true);
               return &alfiles[i];
            }
        }
    }
           
     return 0;
}


Torre* Piezas::actualizarTorre(int pila_nombre, float x, float z, int tipo, int color){
    
       
    if(tipo==0){
        for(int i=0; i<4; ++i){
              if(torres[i].getTorre()==pila_nombre){
                //  torres[i].setPosiciones(x,-1.3,z);
                  return &torres[i];
              }
          }
    }else{
        for(int i=0; i<4; ++i){
              if(torres[i].getFil()==x && torres[i].getCol()==z && torres[i].getColor()!= color){
                  torres[i].setEliminada(true);
                  return &torres[i];
              }
          }
    }
      return 0;
}


Caballo* Piezas::actualizarCaballo(int pila_nombre, float x, float z, int tipo, int color){
   
    if(tipo==0){
        
    
        for(int i=0; i<4; ++i){
                if(caballos[i].getCaballo()==pila_nombre){
             //       caballos[i].setPosiciones(x,-1.3,z);
                    return &caballos[i];
                }
        }
    }else{
        for(int i=0; i<4; ++i){
                if(caballos[i].getFil()==x && caballos[i].getCol()==z && caballos[i].getColor()!= color){
                    caballos[i].setEliminada(true);
                    return &caballos[i];
                }
        }
    }
    
    return 0;
    
}


Rey* Piezas::actualizarRey(int pila_nombre, float x, float z, int tipo, int color){
    
    if(tipo==0){
        for(int i=0; i<2; ++i){
                if(reyes[i].getRey()==pila_nombre){
              //      reyes[i].setPosiciones(x,-1.3,z);
                    return &reyes[i];
                }
            }
    }else{
         for(int i=0; i<2; ++i){
                if(reyes[i].getFil()==x && reyes[i].getCol()==z && reyes[i].getColor()!=color){
                    reyes[i].setEliminada(true);
                    return &reyes[i];

                }
            }
    }
    return 0;
    
}


Reina* Piezas::actualizarReina(int pila_nombre, float x, float z, int tipo, int color){
    
    if(tipo==0){
        for(int i=0; i<2; ++i){
              if(reinas[i].getReina()==pila_nombre){
                // reinas[i].setPosiciones(x,-1.3,z);
                 return &reinas[i];
              }
          }
    }else{
        
         for(int i=0; i<2; ++i){
              if(reinas[i].getFil()==x && reinas[i].getCol()==z && reinas[i].getColor()!= color){
                  reinas[i].setEliminada(true);
                  return &reinas[i];
              }
          }
        
    }
      return 0;
      
}


