#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "Casillas.h"
#include "igvEscena3D.h"
#include "igvFuenteLuz.h"
#include "igvMaterial.h"
#include "igvTextura.h"
#include "Tablero.h"
#include "Piezas.h"
  

// Metodos constructores 

igvEscena3D::igvEscena3D ():p(),t() {
	
         ejes = true;
         Rdifuso=0.15;
         Respecular=0.5;
         Ephong=120;
         Xfoco=3;
         Yfoco=1;
         pieza_seleccionada=0;
         casilla_seleccionada=0;
         
        

}

igvEscena3D::~igvEscena3D() {
}



// Metodos publicos 

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
        
  

}


void igvEscena3D::moverFigura(){
    
    
    
    int color_ficha=0;
    Casillas *nueva=t.getCasilla(casilla_seleccionada);
    Peon *peon;
    Caballo *caballo;
    Alfil *alfil;
    Torre *torre;
    Rey *rey;
    Reina * reina;
    std::string figura;
    
      
              
        peon=p.actualizarPeon(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);

        if(!peon){
            torre = p.actualizarTorre(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);
            if(!torre){
                caballo= p.actualizarCaballo(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);
                if(!caballo){
                    alfil=p.actualizarAlfil(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);
                    if(!alfil){
                        rey = p.actualizarRey(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);
                        if(!rey){
                            
                            reina=p.actualizarReina(pieza_seleccionada,nueva->getX(),nueva->getZ(),0,0);
                            Casillas *anterior=t.getCasillaAux(reina->getFil(),reina->getCol());
                            anterior->setOcupada(false);
                            reina->setFil(nueva->getFil());
                            reina->setCol(nueva->getCol());
                            color_ficha=reina->getColor();
                            figura="Reina";
                        
                        }else{ //else rey
                            Casillas *anterior=t.getCasillaAux(rey->getFil(),rey->getCol());
                            anterior->setOcupada(false);
                            rey->setFil(nueva->getFil());
                            rey->setCol(nueva->getCol());
                            color_ficha=rey->getColor();
                            figura="Rey";
                        }
                    }else{ //else alfil
                        Casillas *anterior=t.getCasillaAux(alfil->getFil(),alfil->getCol());
                        anterior->setOcupada(false);
                        alfil->setFil(nueva->getFil());
                        alfil->setCol(nueva->getCol());
                        color_ficha=alfil->getColor();
                        figura="Alfil";
                        
                    }
                }else{ // else caballo
                    Casillas *anterior=t.getCasillaAux(caballo->getFil(),caballo->getCol());
                    anterior->setOcupada(false);
                    caballo->setFil(nueva->getFil());
                    caballo->setCol(nueva->getCol());
                    color_ficha=caballo->getColor();
                    figura="Caballo";
                }
            }else{ //else de torre
                Casillas *anterior=t.getCasillaAux(torre->getFil(),torre->getCol());
                anterior->setOcupada(false);
                torre->setFil(nueva->getFil());
                torre->setCol(nueva->getCol());
                color_ficha=torre->getColor();
                figura="Torre";
             
            }
        }else{ //else peon
                       
            Casillas *anterior=t.getCasillaAux(peon->getFil(),peon->getCol());
            anterior->setOcupada(false);
            peon->setFil(nueva->getFil());
            peon->setCol(nueva->getCol());
            color_ficha=peon->getColor();
            figura="Peon";
            
         
         }
        
        
        Alfil *alfil1 = p.actualizarAlfil(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       Caballo * caballo1 =  p.actualizarCaballo(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       Peon *peon1 = p.actualizarPeon(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       Reina *reina1 = p.actualizarReina(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       Rey *rey1 = p.actualizarRey(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       Torre *torre1 = p.actualizarTorre(0,nueva->getFil(),nueva->getCol(),1,color_ficha);
       
       if((!(alfil1==0 && caballo1==0 && peon1 ==0 && reina1 ==0 && rey1==0 && torre1==0)) || nueva->getOcupada()==false){ // comprueba q la casilla a la que movemos este libre, u ocupada por una de nuestro color
         
           if(figura=="Peon"){
                peon->setPosiciones(nueva->getX(), -1.5, nueva->getZ());
           }else if(figura=="Torre"){
               torre->setPosiciones(nueva->getX(), -1.3, nueva->getZ());
           }else if(figura=="Caballo"){
                 caballo->setPosiciones(nueva->getX(), -1.3, nueva->getZ());
           }else if(figura == "Alfil"){
                 alfil->setPosiciones(nueva->getX(), -1.3, nueva->getZ());
           }else if(figura=="Rey"){
                rey->setPosiciones(nueva->getX(), -1.3, nueva->getZ());
           }else if(figura=="Reina"){
                 reina->setPosiciones(nueva->getX(), -1.3, nueva->getZ());
           }
          
         
           
         
          
         
           
           
           
           
           
           
           
           nueva->setOcupada(true);
        
       }
    
       
         
       
    }   
    
    //si no esta ocupada, actualizamos casillas ocupadas y movemos ficha
  
     
     



void igvEscena3D::pintarPiezas(){
     
    glInitNames();    
    
    p.setObjetoSeleccionado(objeto_seleccionado);
    
    p.pintarPeones();
    p.pintarAlfil();
    p.pintarCaballo();
    p.pintarReyes();
    p.pintarTorres();
    p.pintarReinas();
    
    t.pintarTablero();
       
    glPopMatrix();  
      
}



void pintarFondo(){ //el fondo es un cubo, paa así poder visualizarlo desde cualquier perspectiva
    
      
    glTranslatef(2.5,0,2.5);
     glScalef(12,12,12);
     glBegin(GL_QUADS);
    
                glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1,  1);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1, -1,  1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1,  1,  1);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1,  1,  1);

		glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1, -1);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1,  1, -1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1,  1, -1);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1, -1, -1);

		glTexCoord2f(0.0, 1.0); glVertex3f(-1,  1, -1);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1,  1,  1);
		glTexCoord2f(1.0, 0.0); glVertex3f( 1,  1,  1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1,  1, -1);

		glTexCoord2f(1.0, 1.0); glVertex3f(-1, -1, -1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1, -1, -1);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1, -1,  1);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1,  1);

		glTexCoord2f(1.0, 0.0); glVertex3f( 1, -1, -1);
		glTexCoord2f(1.0, 1.0); glVertex3f( 1,  1, -1);
		glTexCoord2f(0.0, 1.0); glVertex3f( 1,  1,  1);
		glTexCoord2f(0.0, 0.0); glVertex3f( 1, -1,  1);

		glTexCoord2f(0.0, 0.0); glVertex3f(-1, -1, -1);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1, -1,  1);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1,  1,  1);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1,  1, -1);
    
        glEnd();
   
}


void igvEscena3D::textoJugador(char text[], int jugador){
  
   
     GLfloat rojo[]={1,0,0,1.0};
    glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
     
    // Position of the text to be printer
    if(jugador ==1) glRasterPos3f(0, -2,1.7);
    else glRasterPos3f(5, -1.5,3.3);
  
    for(int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    
}

void igvEscena3D::visualizar(void) {
	// crear el modelo
    
                  
              
	glPushMatrix(); // guarda la matriz de modelado

         glShadeModel(GL_SMOOTH);         // Esto hace que al dibujar las sombran en los objetos, se vean mas parejas haciendo que se vean mejor.

          glClearColor(0.0, 0.0, 0.0, 0.0);
         glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);       //Esto hace que opengl calcule las perspectivas de la mejor forma, quita un poco de rendimiento, pero hace que las perspectivas se vean un poco mejor.
        
      

        // luces se aplican antes de las transformaciones a la escena para que permanezcan fijas

        // APARTADO B: Define y aplica la luz puntual especificada en el gui�n de pr�cticas

        igvPunto3D posLuzPuntual(1.0, 10, 0);
        igvColor colorAmbiental(0.0, 0.0, 0.0, 1.0);
        igvColor colorDifuso(0.2, 0.2, 0.2, 1); // color de la luz mas o menos brillo
        igvColor colorEspecular(1, 1.0, 1.0, 1.0);

        igvFuenteLuz luzPuntual(GL_LIGHT0, posLuzPuntual,colorAmbiental,colorDifuso,colorEspecular,1.0,0.0,0.0);
        luzPuntual.aplicar();

       char text1[] = "JUGADOR 1";
       char text2[] = "JUGADOR 2";
        glPushMatrix();
            textoJugador(text1,1);
             textoJugador(text2,0);
        glPopMatrix (); 
       
         pintarPiezas();
        igvTextura mapa("tesi.bmp");
        mapa.aplicar();
        pintarFondo();

              
             
                       
                
	glPopMatrix (); // restaura la matriz de modelado
}
