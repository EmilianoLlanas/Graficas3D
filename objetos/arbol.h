#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"
#define MAXPOINTS 16

class Arbol {
private:
    GLdouble points[4][MAXPOINTS];
    GLdouble modelMatrix[4][MAXPOINTS];
    Op3D *op;

    float movimiento;
    void loadPoints();

public:
    void draw();
    void update();
    Arbol();
    Arbol(Op3D* mainOp);
};

#endif // ARBOL_H_INCLUDED