#ifndef __IGVCAMARA
#define __IGVCAMARA

#include <GL/glut.h>

#include "igvPunto3D.h"

typedef enum {
	IGV_PARALELA,
	IGV_FRUSTUM,
	IGV_PERSPECTIVA
} tipoCamara;

typedef enum {
	IGV_VISUALIZACION,
	IGV_SELECCION
} modoCamara;

class igvCamara {

	public:
		// atributos
		
		tipoCamara tipo;	// paralela o perspectiva

		// ventana de visi�n: parametros proyecci�n paralela y frustum
		GLdouble xwmin, xwmax, ywmin, ywmax;

		// ventana de visi�n: parametros proyecci�n perspectiva
		GLdouble 	angulo, raspecto;

		// distancias de planos cercano y lejano
		GLdouble znear, zfar;

		// punto de visi�n	
		igvPunto3D P0;

		// punto de referencia de visi�n	
		igvPunto3D r;

		// vector arriba	
		igvPunto3D V;
                
                bool panoramica;

////// Apartado D: atributos necesarios para generar el volumen alrededor del pixel seleccionado
		modoCamara modo; // camara se utiliza para visualizar (IGV_VISUALIZACION) o para seleccionar (IGV_SELECCION)
		int cursorX, cursorY; // posici�n del viewport seleccionada a partir de la cual hay que generar el volumen
		                      // de visi�n para la selecci�n por lista de impactos
		int ancho_seleccion, alto_seleccion; // tama�o de la ventana para hacer la seleccion por lista de impactos
		
	
                double y;

		// Metodos

	public:
		// Constructores por defecto y destructor
		igvCamara();
		~igvCamara();

		igvCamara(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

		// Metodos
		// define la posici�n de la c�mara
		void set(igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V);

		// define una c�mara de tipo paralela o frustum
		void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _xwmin, double _xwmax, double _ywmin, double _ywmax, double _znear, double _zfar);

		// define una c�mara de tipo perspectiva
		void set(tipoCamara _tipo, igvPunto3D _P0, igvPunto3D _r, igvPunto3D _V,
			                         double _angulo, double _raspecto, double _znear, double _zfar);

//// Apartado D: aplica a los objetos de la escena la transformaci�n de visi�n y la transformaci�n de proyecci�n
//// asociadas a los par�metros de la c�mara. Si el modo es IGV_VISUALIZACION se aplicar�n
//// las transformaciones normalmente, si es IGV_SELECCION hay que implementar que se apliquen para el c�lculo de la
//// seleccion mediante lista de impactos
		void aplicar();

		void zoom(double factor); // realiza un zoom sobre la c�mara

////// Apartado D: m�todos para cambiar el modo de la camara
		void establecerSeleccion(int _ancho_seleccion, int _alto_seleccion,
			                       int _cursorX, int _cursorY) {modo = IGV_SELECCION;
																												 // ancho y alto de la ventana de selecci�n
		                                                     ancho_seleccion = _ancho_seleccion;
																												 alto_seleccion = _alto_seleccion;
		                                                     // pixel pulsado
		                                                     cursorX = _cursorX;
		                                                     cursorY = _cursorY;};
		void establecerVisualizacion() {modo = IGV_VISUALIZACION;};
                	//metodos panoramica
		bool get_panoramica() {return panoramica;};
		void set_panoramica(bool _panoramica){panoramica=_panoramica;};
};

#endif

