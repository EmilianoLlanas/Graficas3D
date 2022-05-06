#ifndef OP3D_H_INCLUDED
#define OP3D_H_INCLUDED

#include <stack>
#include <GL/freeglut.h>
#include <iostream>

struct Modelado{
  GLdouble matrix[4][4];
};

class Op3D{
private:
    std::stack<Modelado *> modelStack;
    Modelado *currentMatrix;

    void mult(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]);
    void assignValues(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]);
public:
    Op3D();

    void translation(GLdouble x, GLdouble y, GLdouble z);
    void scaling(GLdouble x, GLdouble y, GLdouble z);

    void applyModelMatrix(GLdouble *points, GLdouble *result, int lenght);
    void push();
    void pop();
};

#endif // OP3D_H_INCLUDED
