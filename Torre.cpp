/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Torre.cpp
 * Author: marcos
 * 
 * Created on 20 de noviembre de 2017, 23:26
 */

#include "Torre.h"


Torre::Torre(const Torre& orig) {
    
     x=orig.x;
    y=orig.y;
    z=orig.z;
    color=orig.color;
    torre = orig.torre;
    objeto_seleccionado=orig.objeto_seleccionado;
}





void Torre::pintarTorre(){
    
     GLfloat negro[4]={0,0,0,1};
    GLfloat carne[4]={0.76,0.58,0.38,0}; // Color carne.}
      GLfloat amarillo[4]={1,1,0,1};
    
    
     if(objeto_seleccionado == torre) glMaterialfv(GL_FRONT,GL_EMISSION,amarillo);
        
    else{
         if(color == 0) glMaterialfv(GL_FRONT,GL_EMISSION,negro);
         else    glMaterialfv(GL_FRONT,GL_EMISSION,carne);
    }
    
   
    //4 torres
    
    
     glPushMatrix();
            
            glTranslatef(x+0.12,y+1.95,z-0.01);
            glRotatef(90,0,1,0);
            glScalef(0.3, 0.2, 0.08);
        
          glutSolidCube(0.7);
      glPopMatrix();
    
    
     glPushMatrix();
            
            glTranslatef(x-0.12,y+1.95,z-0.01);
            glRotatef(90,0,1,0);
            glScalef(0.3, 0.2, 0.08);
        
          glutSolidCube(0.7);
      glPopMatrix();
	 
      
      glPushMatrix();
         
            glTranslatef(x,y+1.95,z+0.14);
            glScalef(0.3, 0.2, 0.08);
        
          glutSolidCube(0.7);
      glPopMatrix();
        
      
        glPushMatrix();
         
            glTranslatef(x,y+1.95,z-0.16);
            glScalef(0.3, 0.16, 0.08);
        
          glutSolidCube(0.7);
      glPopMatrix();
        
    
    // plataforma
        
        
       
    glPushMatrix();
         glTranslatef(x,y+1.85,z);
         glRotatef(90,1,0,0);
         glScalef(0.19,0.19,0.1);
        
        glutSolidTorus(0.5,0.5, 20, 20);
    glPopMatrix();
        
    // Cuerpo
        
         GLUquadricObj *tubo;
    tubo=gluNewQuadric();
  gluQuadricDrawStyle(tubo,GLU_FILL);
  
  glPushMatrix();
         glTranslatef(x,y+1.8,z);
         glRotatef(90,1,0,0);
	
        gluCylinder(tubo,0.18,0.18,0.5,20,20); //base, top, tamaño, porciones
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

