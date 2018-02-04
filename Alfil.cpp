/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alfil.cpp
 * Author: marcos
 * 
 * Created on 20 de noviembre de 2017, 18:06
 */

#include "Alfil.h"


Alfil::Alfil(const Alfil& orig) {
    
    x=orig.x;
    y=orig.y;
    z=orig.z;
    color=orig.color;
    alfil=orig.alfil;
    objeto_seleccionado=orig.objeto_seleccionado;
}

void Alfil::pintarAlfil(){
       
    GLfloat negro[4]={0,0,0,1};
    GLfloat carne[4]={0.76,0.58,0.38,0}; // Color carne.}
    GLfloat amarillo[4]={1,1,0,1};
    
    
     if(objeto_seleccionado == alfil) glMaterialfv(GL_FRONT,GL_EMISSION,amarillo);
        
    else{
         if(color == 0) glMaterialfv(GL_FRONT,GL_EMISSION,negro);
         else    glMaterialfv(GL_FRONT,GL_EMISSION,carne);
    }
    
    
      //bola del alfil
    glPushMatrix();	
    
    glTranslatef(x,y+2.15,z);
        glutSolidSphere(0.04, 20, 20); 
    glPopMatrix();
    
     //cabeza del peon
    glPushMatrix();	
    
    glTranslatef(x,y+1.9,z);
        glScalef(0.75,1.5,0.75);
        glutSolidSphere(0.15, 20, 20); 
    glPopMatrix();
    
    
    // cuello
    glPushMatrix();
         glTranslatef(x,y+1.7,z);
         glRotatef(90,1,0,0);
         glScalef(0.15,0.15,0.1);
        
        glutSolidTorus(0.5,0.5, 20, 20);
    glPopMatrix();
    
    
    //cuerpo del peon
    
    GLUquadricObj *tubo;
    tubo=gluNewQuadric();
  gluQuadricDrawStyle(tubo,GLU_FILL);
  
  glPushMatrix();
         glTranslatef(x,y+1.7,z);
         glRotatef(90,1,0,0);
	
        gluCylinder(tubo,0.08,0.12,0.35,20,20); //base, top, tamaño, porciones
 glPopMatrix();

  gluDeleteQuadric(tubo);
  
  //base
    glPushMatrix();
         glTranslatef(x,y+1.3,z);
         glRotatef(90,1,0,0);
         glScalef(0.22,0.22,0.15);
        
        glutSolidTorus(0.5,0.5, 20, 20);
    glPopMatrix();
    
}

