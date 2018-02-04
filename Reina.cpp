/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Reina.cpp
 * Author: marcos
 * 
 * Created on 22 de noviembre de 2017, 17:33
 */

#include "Reina.h"



Reina::Reina(const Reina& orig) {
    
    x=orig.x;
    y=orig.y;
    z=orig.z;
    color=orig.color;
    reina = orig.reina;
    objeto_seleccionado=orig.objeto_seleccionado;
}

void Reina::pintarReina(){
    
    
    
     GLfloat negro[4]={0,0,0,1};
    GLfloat carne[4]={0.76,0.58,0.38,0}; // Color carne.}
      GLfloat amarillo[4]={1,1,0,1};
    
    
     if(objeto_seleccionado == reina) glMaterialfv(GL_FRONT,GL_EMISSION,amarillo);
        
    else{
         if(color == 0) glMaterialfv(GL_FRONT,GL_EMISSION,negro);
         else    glMaterialfv(GL_FRONT,GL_EMISSION,carne);
    }
    
    //corona
    
     
    
    glPushMatrix();
         glTranslatef(x-0.07,y+2.1,z-0.06);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
        
        
        glPushMatrix();
         glTranslatef(x-0.07,y+2.1,z+0.06);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
        
    glPushMatrix();
         glTranslatef(x+0.07,y+2.1,z-0.06);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();    
        
     glPushMatrix();
         glTranslatef(x+0.07,y+2.1,z+0.06);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
     
      glPushMatrix();
         glTranslatef(x+0.1,y+2.1,z);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
    
    
      glPushMatrix();
         glTranslatef(x-0.1,y+2.1,z);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
    
    
     glPushMatrix();
         glTranslatef(x,y+2.12,z);
            glutSolidSphere(0.06, 20, 20); 
        glPopMatrix();
    
    
     glPushMatrix();
         glTranslatef(x,y+2.1,z+0.1);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
    
    
      glPushMatrix();
         glTranslatef(x,y+2.1,z-0.1);
            glutSolidSphere(0.03, 20, 20); 
        glPopMatrix();
    
    
      // cuello
    glPushMatrix();
         glTranslatef(x,y+2,z);
         glRotatef(90,1,0,0);
         glScalef(0.15,0.15,0.2);
        
        glutSolidTorus(0.5,0.5, 20, 20);
    glPopMatrix();
    
    
    //cuerpo del peon
    
    GLUquadricObj *tubo;
    tubo=gluNewQuadric();
  gluQuadricDrawStyle(tubo,GLU_FILL);
  
  glPushMatrix();
         glTranslatef(x,y+1.95,z);
         glRotatef(90,1,0,0);
	
        gluCylinder(tubo,0.08,0.12,0.6,20,20); //base, top, tamaño, porciones
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

