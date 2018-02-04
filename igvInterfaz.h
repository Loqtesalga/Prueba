#ifndef __IGVINTERFAZ
#define __IGVINTERFAZ

#include <GL/glut.h>
#include <string>

#include "igvEscena3D.h"
#include "igvCamara.h"

using namespace std;

typedef enum {
	IGV_VISUALIZAR,
	IGV_SELECCIONAR
} modoInterfaz;

class igvInterfaz {
	protected:
		// Atributos
		int ancho_ventana; // ancho inicial de la ventana de visualizacion
		int alto_ventana;  // alto inicial de la ventana de visualizacion

               igvEscena3D escena; // escena que se visualiza en la ventana definida por igvInterfaz
		igvCamara camara; // c�mara que se utiliza para visualizar la escena

///// Apartado D: atributos para la selecci�n mediante el rat�n
		modoInterfaz modo; // IGV_VISUALIZAR: en la ventana se va a visualizar de manera normal la escena, 
		                   // IGV_SELECCIONAR: se ha pulsado sobre la ventana de visualizaci�n, la escena se debe
		                   // visualizar en modo selecci�n para el c�lculo de la lista de impactos
		int cursorX,cursorY; // pixel de la pantalla sobre el que est� situado el rat�n, por pulsar o arrastrar

		int objeto_seleccionado; // c�digo del objeto seleccionado, -1 si no hay ninguno
		
		bool boton_retenido; // indica si el bot�n est� pulsado (true) o se ha soltado (false)
                bool paralela;
                int contador;
                bool animacion, siguiente;

               
                int pieza;
                int casilla;
                
	public:
		// Constructores por defecto y destructor
		igvInterfaz();
		~igvInterfaz();

		// Metodos est�ticos
		// callbacks de eventos
		static void set_glutKeyboardFunc(unsigned char key, int x, int y); // metodo para control de eventos del teclado
		static void set_glutReshapeFunc(int w, int h); // m�todo que define la camara de vision y el viewport
		                                               // se llama autom�ticamente cuano se camba el tama�o de la ventana
		static void set_glutDisplayFunc(); // m�todo para visualizar la escena
    static void set_glutIdleFunc(); // m�todo para animar la escena

///// Apartado D: m�todos para el control de la pulsaci�n y el arrastre del rat�n
		static void  set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y); // control de pulsacion del raton
    static void  set_glutMotionFunc(GLint x,GLint y); // control del desplazamiento del raton con boton pulsado
    static void set_glutSpecialFunc(int key, int x, int y);

		// Metodos

///// Apartado D: m�todos a implementar para realizar la seleccion mediante lista de impactos
		void inicia_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos);
		void finaliza_seleccion(int TAMANO_LISTA_IMPACTOS, GLuint *lista_impactos);

		// crea el mundo que se visualiza en la ventana
		void crear_mundo(void);

		// inicializa todos los par�metros para crear una ventana de visualizaci�n
		void configura_entorno(int argc, char** argv, // parametros del main
			                     int _ancho_ventana, int _alto_ventana, // ancho y alto de la ventana de visualizaci�n
			                     int _pos_X, int _pos_Y, // posicion inicial de la ventana de visualizaci�n
													 string _titulo // t�tulo de la ventan de visualizaci�n
													 ); 
		void inicializa_callbacks(); // inicializa todas los callbacks

		void inicia_bucle_visualizacion(); // visualiza la escena y espera a eventos sobre la interfaz

		// m�todos get_ y set_ de acceso a los atributos
		int get_ancho_ventana(){return ancho_ventana;};
		int get_alto_ventana(){return alto_ventana;};

		void set_ancho_ventana(int _ancho_ventana){ancho_ventana = _ancho_ventana;};
		void set_alto_ventana(int _alto_ventana){alto_ventana = _alto_ventana;};
                
                	//metodos paralela
		bool getParalela() {return paralela;};
		void setParalela(){paralela=!paralela;};
                
                void moverFigura();
                
                
                bool getAnimacion() {return animacion;};
                void setAnimacion(bool animacion){this->animacion = animacion;};

		//metodos contador
		int get_contador() {return contador;};
		void set_contador(){
			contador++;
			if(contador==4){
				contador=0;
			}
		};
                
         
};

#endif



