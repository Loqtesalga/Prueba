#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#include <GL/glut.h>

#include "Alfil.h"
#include "Peon.h"
#include "Caballo.h"
#include "Reina.h"
#include "Torre.h"
#include "Rey.h"
#include "Piezas.h"
#include "Tablero.h"
#include "igvFuenteLuz.h"
#include "igvMallaTriangulos.h"

class igvEscena3D {
	protected:
		// Atributos

		bool ejes;
                //Apartado E:
                float Rdifuso, Respecular,Ephong;
                
                //Apartado F:
                float Xfoco, Yfoco;
                 int objeto_seleccionado;
                 
                 int pieza_seleccionada;
                 int casilla_seleccionada;
                 
                 Piezas p; // contiene las piezas y las casillas dle tablero
                 Tablero t;
                

	public:
		// atributos p�blicos
		igvMallaTriangulos *malla; // malla de tri�ngulos asociada a la escena

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos est�ticos

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la escena
                void visualizar();

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};
                
                //get y set apartado E:
                
                void setRespecular(float _Respecular){Respecular=_Respecular;};
                float getRespecular(){return Respecular;};
                
                void setRdifuso(float _Rdifuso){Rdifuso=_Rdifuso;};
                float getRdifuso(){return Rdifuso;};
                
                void setEphong(float _Ephong){ Ephong=_Ephong;};
                float getEphong() {return Ephong;};
                
                //get y set Apartado F:
                void setXfoco(float _Xfoco){Xfoco=_Xfoco;};
                float getXfoco(){return Xfoco;};
                
                void setYfoco(float _Yfoco){Yfoco=_Yfoco;};
                float getYfoco(){return Yfoco;};
                
                void piezaSeleccionada(int _selec){ pieza_seleccionada=_selec;}
                void casillaSeleccionada(int _selec){ casilla_seleccionada=_selec ;}
                
                void objetoSeleccionado(int objeto){objeto_seleccionado=objeto;};
                
                             
                void pintarPeon(int x, int y, int z, int num);
                void pintarPiezas();
                
                void textoJugador(char text[],int jugador);
                
                
                //movimiento
                void moverFigura();

};

#endif
