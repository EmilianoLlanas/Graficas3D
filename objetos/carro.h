#ifndef CARRO_H_INCLUDED
#define CARRO_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"
#define MAXPOINTS 100

class Carro {
private:
    GLdouble points[4][MAXPOINTS];
    GLdouble modelMatrix[4][MAXPOINTS];
    Op3D *op;

    void loadPoints();

public:
    void draw();
    Carro();
    Carro(Op3D* mainOp);
};

#endif // CARRO_H_INCLUDED
