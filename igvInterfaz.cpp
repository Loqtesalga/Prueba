#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "igvInterfaz.h"

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {

    	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
  
        casilla=0;
        pieza=0;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	// crear c�maras
	interfaz.camara.set(IGV_PARALELA, igvPunto3D(3.0,2.0,4),igvPunto3D(0,0,0),igvPunto3D(0,1.0,0),
		                                -1*4.5, 1*4.5, -1*4.5, 1*4.5, -1*3, 200);
}

void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicializaci�n de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicializaci�n de la ventana de visualizaci�n
	glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(_ancho_ventana,_alto_ventana);
  glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
  glClearColor(0.752941,0.752941,0.752941,1); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
  glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	glEnable(GL_TEXTURE_2D); // activa el uso de texturas

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
    
        //inicializamos el ajedrez en el modo de juego
        interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(-2.5,5,2.5),igvPunto3D(2.5,0,2.5),igvPunto3D(1,0,0),70,1,1,-1);
        interfaz.camara.aplicar();
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutSpecialFunc(int key, int x, int y) {
	// Apartado F: manejo de las teclas especiales del teclado para mover la posici�n del foco
    	switch (key) {
            case GLUT_KEY_RIGHT: // Apartado E: aumentar en 0.1 la componente x del foco
                
                if(interfaz.camara.P0[X] <12){
                    interfaz.setParalela();

                            if(interfaz.getParalela() == false){
                                interfaz.camara.P0[X]+=0.2;
                              
                                      interfaz.camara.P0[Y]=interfaz.camara.y+0.2;
                                      

                                    interfaz.camara.aplicar();
                            }
                            if(interfaz.getParalela() == true){
                                
                                  interfaz.camara.P0[X]+=0.2;
                             
                                    interfaz.camara.P0[Y]=interfaz.camara.y+0.2;

                                    interfaz.camara.aplicar();
                            }
                }
                
          
                   
            break;
            case GLUT_KEY_LEFT: // Apartado E: disminuir en 0.1 la componente x del foco
                      

                if(interfaz.camara.P0[X] > 0.4){
                     interfaz.setParalela();
                     
			if(interfaz.getParalela() == false){
                                interfaz.camara.P0[X]-=0.2;
                             
                                    interfaz.camara.P0[Y]=interfaz.camara.y-0.2;
                                    interfaz.camara.aplicar();
                        }
                        if(interfaz.getParalela() == true){
                              interfaz.camara.P0[X]-=0.2;
                           
                                 interfaz.camara.P0[Y]=interfaz.camara.y-0.2;
                                 
                                interfaz.camara.aplicar();
                        }
                    }
                        
                       
            break;             
            case GLUT_KEY_UP: // Apartado E: aumentar en 0.1 la componente y del foco
                        interfaz.setParalela();
                if(interfaz.camara.P0[Y] < 5.2){
			if(interfaz.getParalela() == false){
                            interfaz.camara.P0[Y]+=0.2;
                         interfaz.camara.y=interfaz.camara.P0[Y];
				interfaz.camara.aplicar();
			}
			if(interfaz.getParalela() == true){
				interfaz.camara.P0[Y]+=0.2;
                                interfaz.camara.y=interfaz.camara.P0[Y];
				interfaz.camara.aplicar();
			}
                }
                        
                        
            break;
            break;
            case GLUT_KEY_DOWN: // Apartado E: disminuir en 0.1 la componente y del foco
                      interfaz.setParalela();

                    if(interfaz.camara.P0[Y] > 0.2){
                      
			if(interfaz.getParalela() == false){
                            interfaz.camara.P0[Y]-=0.2;
                              interfaz.camara.y=interfaz.camara.P0[Y];
				interfaz.camara.aplicar();
			}
			if(interfaz.getParalela() == true){
				interfaz.camara.P0[Y]-=0.2;
                                  interfaz.camara.y=interfaz.camara.P0[Y];
				interfaz.camara.aplicar();
			}
                        
                    }
                    
    }

       

	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
			case 'p': // cambia el tipo de proyección de paralela a perspectiva y viceversa
			interfaz.setParalela();

			if(interfaz.getParalela() == false){
				interfaz.camara.set(IGV_PERSPECTIVA,igvPunto3D(6.0,4.0,8),igvPunto3D(0,0,0),igvPunto3D(0,1,0),50,1,1,-1);
				interfaz.camara.aplicar();
			}
			if(interfaz.getParalela() == true){
				interfaz.camara.set(IGV_PARALELA, igvPunto3D(6.0,4.0,8),igvPunto3D(0,0,0),igvPunto3D(0,1.0,0),-5, 5, -5, 5, -3, 200);
				interfaz.camara.aplicar();
			}	
		break;

		case 'v': // cambia la posición de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva
		
			// ES PARALELA (0)
			if(interfaz.getParalela()==true){

				if(interfaz.get_contador() == 0){
					interfaz.camara.set(IGV_PARALELA,igvPunto3D(2,0,0),igvPunto3D(0,0,0),igvPunto3D(0,1,0),-5,5,-5,5,-3,200);
					interfaz.camara.aplicar();
                                       
					interfaz.set_contador();					
				}else if(interfaz.get_contador() == 1){
					interfaz.camara.set(IGV_PARALELA, igvPunto3D(0,5,0),igvPunto3D(0,0,0),igvPunto3D(1,0,0),-5,5,-5,5,-3,200);
					interfaz.camara.aplicar();
                                     
					interfaz.set_contador();
				}else if(interfaz.get_contador() == 2){
					interfaz.camara.set(IGV_PARALELA,igvPunto3D(0,0,2),igvPunto3D(0,0,0),igvPunto3D(0,1,0),-5,5,-5,5,-3,200);
					interfaz.camara.aplicar();
                                       
					interfaz.set_contador();

				}else if(interfaz.get_contador() == 3){
					interfaz.camara.set(IGV_PARALELA, igvPunto3D(6,4,8),igvPunto3D(0,0,0),igvPunto3D(0,1,0),-5,5,-5,5,-3,200);
					interfaz.camara.aplicar();
					//incremento en 1 ("4")
					interfaz.set_contador();

				}
			}else if(interfaz.getParalela()==false){

				if(interfaz.get_contador() == 0){
					interfaz.camara.set(IGV_PERSPECTIVA,igvPunto3D(12,0,0),igvPunto3D(0,0,0),igvPunto3D(0,1,0),50,1,1,-1);
					interfaz.camara.aplicar();
					//incremento en 1 ("1")
					interfaz.set_contador();
				}else if(interfaz.get_contador() == 1){
					
					interfaz.camara.set(IGV_PERSPECTIVA,igvPunto3D(0,12,0),igvPunto3D(0,0,0),igvPunto3D(1,0,0),50,1,1,-1);
					interfaz.camara.aplicar();
					//incremento en 1 ("2")
					interfaz.set_contador();
				}else if(interfaz.get_contador() == 2){
					interfaz.camara.set(IGV_PERSPECTIVA,igvPunto3D(0,0,12),igvPunto3D(0,0,0),igvPunto3D(0,1,0),50,1,1,-1);
					interfaz.camara.aplicar();
					//incremento en 1 ("3")
					interfaz.set_contador();

				}else if(interfaz.get_contador() == 3){
					interfaz.camara.set(IGV_PERSPECTIVA,igvPunto3D(6,4,8),igvPunto3D(0,0,0),igvPunto3D(0,1,0),50,1,1,-1);
					interfaz.camara.aplicar();
					//incremento en 1 ("4")
					interfaz.set_contador();
				}
			}
		break;
                
                case '1': // JUGADOR 1
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(-2.5,5,2.5),igvPunto3D(2.5,0,2.5),igvPunto3D(1,0,0),70,1,1,-1);
                        interfaz.camara.aplicar();
                       
		break;
                
                 case '2': // JUGADOR 2
			interfaz.camara.set(IGV_PERSPECTIVA, igvPunto3D(9,6,2.5),igvPunto3D(2.5,0,2.5),igvPunto3D(0,1,0),55,1,1,-1);
                        interfaz.camara.aplicar();
                       
		break;
 		 
		case '+': // zoom in
			interfaz.camara.zoom(-0.05);
			interfaz.camara.aplicar();
		break;
		
		case '-': // zoom out
			interfaz.camara.zoom(0.05);
			interfaz.camara.aplicar();
		break;
		case 'e': // activa/desactiva la visualizacion de los ejes
			interfaz.escena.set_ejes(interfaz.escena.get_ejes()?false:true);
	  break;
    case 27: // tecla de escape para SALIR
      exit(1);
    break;
  }
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
  interfaz.set_ancho_ventana(w);
  interfaz.set_alto_ventana(h);

	// establece los par�metros de la c�mara y de la proyecci�n
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
    
     if(interfaz.camara.get_panoramica() == false){
        GLuint lista_impactos[1024]; // array con la lista de impactos cuando se visualiza en modo selecci�n

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

            // se establece el viewport
            glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

            // Apartado D: antes de aplicar las transformaciones de c�mara y proyecci�n hay comprobar el modo,
            if (interfaz.modo == IGV_SELECCIONAR) {
              // Apartado D: si se est� seleccionando se pasa a modo selecci�n de OpenGL y se pasan los par�metros de selecci�n a la c�mara
            interfaz.inicia_seleccion(1024,lista_impactos);
            }

            // aplica las transformaciones en funci�n de los par�metros de la c�mara y del modo (visualizaci�n o selecci�n)
            interfaz.camara.aplicar();

            // visualiza la escena
            interfaz.escena.visualizar();

            if (interfaz.modo == IGV_SELECCIONAR) {
                    // Apartado D: salir del modo seleccion y procesar la lista de impactos
                    interfaz.finaliza_seleccion(1024,lista_impactos); 
            }else {
                    // refresca la ventana
                    glutSwapBuffers();
            }
        
        }
}


void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {

// Apartado D: comprobar que se ha pulsado el bot�n izquierdo 
    if(boton == 0){
        
      
// Apartado D: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
// pasar a modo IGV_SELECCIONAR

          if(estado == GLUT_DOWN){
                interfaz.boton_retenido = true;
                interfaz.modo = IGV_SELECCIONAR;
// Apartado D: guardar el pixel pulsado

                interfaz.cursorX = x;
                interfaz.cursorY = y;
        }else{
                interfaz.boton_retenido=false;
        }
// Apartado D: renovar el contenido de la ventana de vision 
           glutPostRedisplay();
             
    }   
     

}





void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {

    int movX = 0, movY = 0;
// Apartado E: si el bot�n est� retenido y hay alg�n objeto seleccionado,
// comprobar el objeto seleccionado y la posici�n del rat�n y actualizar
// convenientemente el grado de libertad del objeto correspondiente 

    if(interfaz.boton_retenido){
            movX = x - interfaz.cursorX;
            movY = y - interfaz.cursorY;
    }
    
  
    
    switch (interfaz.objeto_seleccionado) {
		case 1:
               
                break;
                case 2:
                    
                break;
		
    }
    
    
    // Apartado E: guardar la nueva posici�n del rat�n 
        interfaz.cursorX = x;
	interfaz.cursorY = y;

// Apartado E: renovar el contenido de la ventana de vision 
        glutPostRedisplay();
        
}



void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);
	glutSpecialFunc(set_glutSpecialFunc);
        
        

        glutMouseFunc(set_glutMouseFunc); 
        glutMotionFunc(set_glutMotionFunc); 
        //glutIdleFunc(set_glutIdleFunc);
}


void igvInterfaz::inicia_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {
	// Apartado D: establecer d�nde se van a almacenar los impactos
    glSelectBuffer(TAMANO_LISTA_IMPACTOS,lista_impactos);

  // Apartado D: pasar a modo de seleccion de OpenGL

    	glRenderMode(GL_SELECT);
	// Apartado D: establecer la camara en modo seleccion con los par�metros necesarios para realizar la selecci�n
	// para el alto y el ancho de la ventana de selecci�n probar diferentes tama�os y comprobar la amplitud de la selecci�n
    interfaz.camara.establecerSeleccion(1,1,cursorX,cursorY);

}

int procesar_impactos(int numero_impactos,GLuint *lista_impactos) {
/* Apartado D: esta funci�n debe devolver el c�digo del objeto seleccionado, que no tiene porque coincidir con el nombre
   asignado con la pila de nombres, y si se han utilizado nombres jer�rquicos hay que tener en cuenta que
	 esta funci�n s�lo devolver un �nico c�digo */

	// Apartado D: recorrer la lista de impactos con numero_impactos impactos,
	// guardar el m�s pr�ximo al observador (minima Z)
	// para empezar, considerar que la m�nima Z tiene un valor de 0xffffffff (el tope del tipo GLuint)
        GLuint zminima = 0xffffffff;
	GLuint nombres = 0;
	int recorre = 0;	
	int aux = 0;
	
	for(int i = 0; i < numero_impactos; i++){
                aux = lista_impactos[recorre];
		if(lista_impactos[recorre+1] < zminima){
                    zminima = lista_impactos[recorre+1];		    
                    nombres = lista_impactos[recorre+3];	
		}
		recorre = recorre + 3 + aux;				
	}

	// Apartado D: a partir de la información del impacto con la mínima Z, devolver el código del objeto que le
	// corresponde: como la escena no se almacena en ninguna estructura de datos, para devolver el objeto seleccionado
	// utilizar aquí directamente los nombres asignados a los objetos de la escena
	if(nombres > 0)
            return nombres;
	

	return(-1);


}

void igvInterfaz::finaliza_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos) {

	// Apartado D: volver a modo visualizacion OpenGL y obtener el n�mero de impactos  

         int num_impactos = glRenderMode(GL_RENDER);
	// Apartado D: si hay impactos pasar a procesarlos con la funcion int procesar_impactos(numero_impactos,lista_impactos);
	// obteniendo el objeto seleccionado, si lo hay

         if(num_impactos > 0){
		objeto_seleccionado=procesar_impactos(num_impactos,lista_impactos);
	}else{
		objeto_seleccionado = 0;
	}
	escena.objetoSeleccionado(objeto_seleccionado);
        
      

       //aqui va el código para mover la ficha.......
       interfaz.moverFigura();  
          
          
          
	// Apartado D: seleccion terminada, pasar a visualizaci�n normal

        interfaz.modo = IGV_VISUALIZAR;
	// Apartado D: establecer la camara en modo visualizaci�n
        interfaz.camara.establecerVisualizacion();

}



void igvInterfaz::moverFigura(){
 
    
        
        for(int i=1; i<=32; ++i)
          if(interfaz.objeto_seleccionado==i){
              interfaz.pieza=objeto_seleccionado;
              interfaz.casilla=0;
              break;
          }
        
        
        for(int i=33; i<=96; ++i)
          if(interfaz.objeto_seleccionado==i){
              interfaz.casilla=objeto_seleccionado;
             break;
          }
        
        
        
        if(interfaz.casilla!=0 && interfaz.pieza!=0){
               std::cout << "pieza: " << interfaz.pieza << " casilla " << interfaz.casilla<< std::endl;
               
               //le pasamos a la escena los objeto seleccionados, falta crear un metodo en la escena, que actualice la posicion de la ficha seleccionada
               
               escena.casillaSeleccionada(interfaz.casilla);
               escena.piezaSeleccionada(interfaz.pieza);
               //aqui se dirigira el movimiento
               
               escena.moverFigura();
               interfaz.pieza=0;
               interfaz.casilla=0;
            
        }
            
         
        
     
       
    
}