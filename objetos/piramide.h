#ifndef PIRAMIDE_H_INCLUDED
#define PIRAMIDE_H_INCLUDED

#include <GL/glut.h>
#include "../utilidades/Op3D.h"
#define MAXPOINTS 5

class Piramide {
private:
    GLfloat points[MAXPOINTS][3] = {{0,0,2},{2,0,2},{2,0,0},{0,0,0},{1,1.5,1}};
    Op3D op;

public:

    void draw();
    Piramide();
};

#endif // PIRAMIDE_H_INCLUDED
