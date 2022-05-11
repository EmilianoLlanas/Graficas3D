#ifndef RUEDA_H_INCLUDED
#define RUEDA_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"
#define MAXPOINTS 35

class Rueda {
private:
    GLdouble points[4][MAXPOINTS];
    GLdouble modelMatrix[4][MAXPOINTS];
    Op3D *op;

    float movimiento, rotacion;
    void loadPoints();

public:
    void draw();
    void update();
    Rueda();
    Rueda(Op3D* mainOp);
};

#endif // RUEDA_H_INCLUDED

