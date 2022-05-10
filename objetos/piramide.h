#ifndef PIRAMIDE_H_INCLUDED
#define PIRAMIDE_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"
#define MAXPOINTS 5

class Piramide {
private:
    GLdouble points[4][MAXPOINTS];
    GLdouble modelMatrix[4][MAXPOINTS];
    Op3D *op;

    void loadPoints();

public:
    void draw();
    Piramide();
    Piramide(Op3D* mainOp);
};

#endif // PIRAMIDE_H_INCLUDED
