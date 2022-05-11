#ifndef OP3D_H_INCLUDED
#define OP3D_H_INCLUDED

#include <stack>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>

class Matrix{
public:
  GLdouble a[4][4];
};

class Op3D{
private:
    std::stack<Matrix *> modelStack;
    Matrix *currentMatrix;
    GLdouble T[4][4];
    GLdouble E[4][4];

    float pi;

    void mult(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]);
    void assignValues(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]);
    float DegToRad(float g);

    void rotateZ(float deg);
    void rotateXD(float deg);
    void rotateYD(float deg);
public:
    Op3D();
    void loadIdentity(GLdouble a[4][4]);

    void translation(GLdouble x, GLdouble y, GLdouble z);
    void scaling(GLdouble x, GLdouble y, GLdouble z);
    void rotacionLibre(float theta, float p1[3], float p2[3]);

    void applyModelMatrix(GLdouble *points, GLdouble *result, int lenght);
    void push();
    void pop();
};

#endif // OP3D_H_INCLUDED
