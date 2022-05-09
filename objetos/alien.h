#ifndef ALIEN_H_INCLUDED
#define ALIEN_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"

#define MAXPOINTS 6

class Alien {
private:
    GLdouble points[4][MAXPOINTS];
    GLdouble modelMatrix[4][MAXPOINTS];
    Op3D *op;

    void loadPoints();

public:
    void draw();
    Alien();
    Alien(Op3D* mainOp);
};

#endif // ALIEN_H_INCLUDED
