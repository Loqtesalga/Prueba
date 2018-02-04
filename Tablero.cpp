/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tablero.cpp
 * Author: marcos
 * 
 * Created on 19 de noviembre de 2017, 23:13
 */

#include<iostream>
#include "Tablero.h"

Tablero::Tablero():casillas(){ //en el constructor cargamos el valor de cada casilla en la matriz, para su posterior uso, después utilizamos el método pintarTablero para pintarlas

    inicializarTablero();
}

void Tablero::inicializarTablero(){
    
         
        int col=0;
        int fil=0;
        float tam_x = 5.0;
	float tam_z = 5.0;
        float div_x=8;
        float div_z=8;
        
        float posx;
        float posy; 
        float posz;
        
        
        float inicio_text_x = 0.0;
        float inicio_text_z = 0.0;
        float inc_x_text = 1/div_x;
        float inc_z_text = 1/div_z;
        int pila_nombres=32;
        
        int filas=0;

        for(float i = 0; i < tam_x ; i += (tam_x/div_x)){
            inicio_text_x += inc_x_text;
            inicio_text_z = 0;
            
            for(float j = 0; j < tam_z ; j += (tam_z/div_z)){		
                filas++;
                ++pila_nombres;
                                    
                posx=(i+(i+(tam_x/div_x)))/2;
                posy=0.0;
                posz=(j+(j+(tam_z/div_z)))/2;

                //comprobamos que la casilla de inicio esta ocupada
                if((pila_nombres >= 33 && pila_nombres<=48) || (pila_nombres >=81 && pila_nombres<=96)){
                    Casillas c(posx,posy,posz,pila_nombres,true);
                    casillas[fil][col]=c;

                }else{
                     Casillas c(posx,posy,posz,pila_nombres,false);
                     casillas[fil][col]=c;
                }
         
                casillas[fil][col].setCol(col);
                casillas[fil][col].setFil(fil);
                                 
               
                inicio_text_z += inc_z_text;
                ++col;
            }
            
            filas++;
            ++fil;
            col=0;
            
    }
        
       
    
    
}

void Tablero::pintarTablero(){
    
    //malla de quads para pintar los cuadrados
    
        GLfloat blanco[4]={1,1,1,1};
        GLfloat negro[4]={0,0,0,1};
	
       
        int col=0;
        int fil=0;
        float tam_x = 5.0;
	float tam_z = 5.0;
        float div_x=8;
        float div_z=8;
        
        float posx;
        float posy; 
        float posz;
        
        
        float inicio_text_x = 0.0;
        float inicio_text_z = 0.0;
        float inc_x_text = 1/div_x;
        float inc_z_text = 1/div_z;
        int pila_nombres=32;
        
        int filas=0;



        for(float i = 0; i < tam_x ; i += (tam_x/div_x)){
            inicio_text_x += inc_x_text;
            inicio_text_z = 0;
            
            for(float j = 0; j < tam_z ; j += (tam_z/div_z)){		
                filas++;
                ++pila_nombres;
               
                    glPushMatrix(); 
                   glPushName(casillas[fil][col].getPilanombre());             
                 
                
                glBegin(GL_QUADS);
                
                //esto es para pintar de color las casillas
                if(filas%2==0)
                        glMaterialfv(GL_FRONT,GL_EMISSION,blanco);
                else
                    glMaterialfv(GL_FRONT,GL_EMISSION,negro);
                
                 
                      //  glNormal3f(0,1,0);

                    //    glTexCoord2f(inicio_text_x, inicio_text_z);		
                        glVertex3f(i, 0.0, j);

                      //  glTexCoord2f(inicio_text_x , inicio_text_z + inc_z_text);			
                        glVertex3f(i, 0.0, j + (tam_z/div_z) );

                        //glTexCoord2f(inicio_text_x + inc_x_text , inicio_text_z + inc_z_text);
                        glVertex3f(i + (tam_x/div_x) , 0.0, j + (tam_z/div_z)  );

                       // glTexCoord2f(inicio_text_x + inc_x_text , inicio_text_z);
                        glVertex3f(i + (tam_x/div_x) , 0.0, j);
             
                                         
                        
                glEnd();
                                     

                     
                     glPopName();
                glPopMatrix();
                inicio_text_z += inc_z_text;
                ++col;
            }
            
            filas++;
            ++fil;
            col=0;
            
    }
        
        pintarBaseTablero();
    
}




void Tablero::pintarBaseTablero(){
    
     // cubo que será el tablero del quad
    
       GLfloat marron[4]={0.36,0.25,0.20};
    
        glPushMatrix();
            glMaterialfv(GL_FRONT, GL_EMISSION,marron);
            glTranslatef(2.5,-0.25,2.5);
            glScalef(8, 0.4, 8);
        
          glutSolidCube(0.7);
      glPopMatrix();
  
}


void Tablero::imprimirCasillas(){
     for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            std::cout << casillas[i][j].getX() << std::endl;
        }
     }
}

Casillas* Tablero::getCasilla(int pila_nombre){
     for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            if(casillas[i][j].getPilanombre()==pila_nombre)
                return &(casillas[i][j]);
        }
    }
}

Casillas* Tablero::getCasillaAux(int fil, int col){
    
    return &casillas[fil][col];
}


