#include "igvMaterial.h"

// Metodos constructores 

igvMaterial::igvMaterial () {
	
}

igvMaterial::~igvMaterial () {

}

igvMaterial::igvMaterial (const igvMaterial& p) {	//de copia
	Ka = p.Ka;
	Kd = p.Kd;
	Ks = p.Ks;
	Ns = p.Ns;
}

igvMaterial::igvMaterial(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}

// Metodos publicos 

void igvMaterial::aplicar(void) {

// APARTADO C
// Aplicar los valores de los atributos del objeto igvMaterial:

    GLfloat coeRefAmbiental[] = {Ka[0],Ka[1],Ka[2]};
    GLfloat coeRefDifuso[] = {Kd[0],Kd[1],Kd[2]};
    GLfloat coeRefEspecular[] = {Ks[0],Ks[1],Ks[2]};
    GLfloat emision[] = {0,0,0};
// - coeficiente de reflexi�n de la luz ambiental
// - coeficiente de reflexi�n difuso
// - coeficiente de reflesi�n especular
// - exponente de Phong
// establecer como color de emisi�n (0.0, 0.0, 0.0) (el objeto no es una fuente de luz)
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coeRefAmbiental);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coeRefDifuso);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coeRefEspecular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,Ns);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emision);





}

void igvMaterial::set(igvColor _Ka, igvColor _Kd, igvColor _Ks, double _Ns) {
	Ka = _Ka;
	Kd = _Kd;
	Ks = _Ks;
	Ns = _Ns;
}



