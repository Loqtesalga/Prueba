/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caballo.cpp
 * Author: marcos
 * 
 * Created on 21 de noviembre de 2017, 0:18
 */

#include "Caballo.h"



Caballo::Caballo(const Caballo& orig) {
    
    x=orig.x;
    y=orig.y;
    z=orig.z;
    color=orig.color;
    caballo=orig.caballo;
    objeto_seleccionado=orig.objeto_seleccionado;
}



void Caballo::pintaCaballo(){
    
    
    GLfloat negro[4]={0,0,0,1};
    GLfloat carne[4]={0.76,0.58,0.38,0}; // Color carne.}
     GLfloat amarillo[4]={1,1,0,1};
    
    
     if(objeto_seleccionado == caballo) glMaterialfv(GL_FRONT,GL_EMISSION,amarillo);
        
    else{
         if(color == 0) glMaterialfv(GL_FRONT,GL_EMISSION,negro);
         else    glMaterialfv(GL_FRONT,GL_EMISSION,carne);
    }
    
    //ojos
    
         glPushMatrix();
        
            glTranslatef(x-0.05,y+1.88,z+0.07);
            glutSolidSphere(0.02, 20, 20); 
        glPopMatrix();
        
        glPushMatrix();
        
            glTranslatef(x+0.05,y+1.88,z+0.07);
            glutSolidSphere(0.02, 20, 20); 
        glPopMatrix();
        
       
        
        //puntos de ocico
        
        
          glPushMatrix();
        
            glTranslatef(x+0.04,y+1.75,z+0.235);
            glutSolidSphere(0.01, 20, 20); 
        glPopMatrix();
        
        
         glPushMatrix();
        
            glTranslatef(x-0.04,y+1.75,z+0.235);
            glutSolidSphere(0.01, 20, 20); 
        glPopMatrix();
    
    
      
        // cabeza
         glPushMatrix();
         glTranslatef(x,y+1.87,z);
            glutSolidSphere(0.08, 20, 20); 
        glPopMatrix();

        
        
        //orejas
        
        
        
           GLUquadricObj *oreja2;
       oreja2=gluNewQuadric();
      gluQuadricDrawStyle(oreja2,GLU_FILL);

      glPushMatrix();
             glTranslatef(x+0.03,y+2.03,z);
           
              glRotatef(90,1,0,0);


            gluCylinder(oreja2,0,0.04,0.1,20,20); //base, top, tamaño, porciones
     glPopMatrix();

      gluDeleteQuadric(oreja2);
        
        
        
          GLUquadricObj *oreja1;
       oreja1=gluNewQuadric();
      gluQuadricDrawStyle(oreja1,GLU_FILL);

      glPushMatrix();
             glTranslatef(x-0.03,y+2.03,z);
           
              glRotatef(90,1,0,0);


            gluCylinder(oreja1,0,0.04,0.1,20,20); //base, top, tamaño, porciones
     glPopMatrix();

      gluDeleteQuadric(oreja1);
        
       
        
        //coleta
        
        
          glPushMatrix();
         glTranslatef(x,y+1.89,z-0.07);
            glutSolidSphere(0.05, 20, 20); 
        glPopMatrix();
        
         glPushMatrix();
         glTranslatef(x,y+1.79,z-0.08);
            glutSolidSphere(0.05, 20, 20); 
        glPopMatrix();
        
        
          glPushMatrix();
         glTranslatef(x,y+1.69,z-0.09);
            glutSolidSphere(0.05, 20, 20); 
        glPopMatrix();
        
         glPushMatrix();
         glTranslatef(x,y+1.59,z-0.1);
            glutSolidSphere(0.05, 20, 20); 
        glPopMatrix();
        
        


        //morro


        GLUquadricObj *tubo1;
        tubo1=gluNewQuadric();
      gluQuadricDrawStyle(tubo1,GLU_FILL);

      glPushMatrix();
             glTranslatef(x,y+1.76,z+0.2);
           
              glRotatef(210,1,0,0);


            gluCylinder(tubo1,0.06,0.08,0.2,20,20); //base, top, tamaño, porciones
     glPopMatrix();

      gluDeleteQuadric(tubo1);


      //ocico


         glPushMatrix();
         glTranslatef(x,y+1.75,z+0.2);
            glutSolidSphere(0.06, 20, 20); 
        glPopMatrix();


      //cuerpo



          GLUquadricObj *tubo;
        tubo=gluNewQuadric();
      gluQuadricDrawStyle(tubo,GLU_FILL);

      glPushMatrix();
             glTranslatef(x,y+1.9,z);
             glRotatef(90,1,0,0);

            gluCylinder(tubo,0.08,0.15,0.7,20,20); //base, top, tamaño, porciones
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


