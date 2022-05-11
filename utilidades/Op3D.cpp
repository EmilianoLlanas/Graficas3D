#include "Op3D.h"

Op3D::Op3D(){
    currentMatrix = new Matrix();
    pi = 3.14159265359;

    loadIdentity(currentMatrix->a);
    loadIdentity(T);
    loadIdentity(E);
}

void Op3D::loadIdentity(GLdouble a[4][4]){
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}

void Op3D::mult(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]) {
    GLdouble result[4][4];

    // Multiply
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            result[i][j]=0;

            for(int k=0;k<4;k++) {
                result[i][j]+= matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    assignValues(matrixB, result);
}

void Op3D::assignValues(GLdouble (&matrixA)[4][4], GLdouble (&matrixB)[4][4]){
    // Assign Values
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            matrixA[i][j] = matrixB[i][j];
        }
    }
}

void Op3D::rotateZ(float deg){
    GLdouble rotateMatrix[4][4] = {{cos(deg), -1*sin(deg), 0, 0}, {sin(deg), cos(deg), 0, 0}, {0,0,1,0}, {0,0,0,1}};

    mult(rotateMatrix, currentMatrix->a);
}

void Op3D::rotateXD(float deg){
    GLdouble rotateMatrix[4][4] = {{1,0,0,0}, {0, cos(deg), -sin(deg), 0}, {0, sin(deg), cos(deg), 0}, {0,0,0,1}};

    mult(rotateMatrix, currentMatrix->a);
}

void Op3D::rotateYD(float deg){
    GLdouble rotateMatrix[4][4] = {{cos(deg), 0, sin(deg), 0}, {0, 1, 0, 0}, {-sin(deg), 0, cos(deg), 0}, {0,0,0,1}};

    mult(rotateMatrix, currentMatrix->a);
}

float Op3D::DegToRad(float g)
{
      return ((g*pi)/180);
}

void Op3D::translation(GLdouble x, GLdouble y, GLdouble z) {

    loadIdentity(T);
    T[0][3] = x;
    T[1][3] = y;
    T[2][3] = z;
    mult(T, currentMatrix->a);
}

void Op3D::applyModelMatrix(GLdouble *points, GLdouble *result, int lenght){

    for(int i=0;i<4;i++) {
        for(int j=0;j<lenght;j++) {
            result[j+i*lenght] = 0;

            for(int k=0;k<4;k++) {
                result[j+i*lenght] += currentMatrix->a[i][k] * points[j+lenght*k];
            }
        }
    }
}

void Op3D::scaling(GLdouble x, GLdouble y, GLdouble z) {

    loadIdentity(E);
    E[0][0] = x;
    E[1][1] = y;
    E[2][2] = z;
    mult(E, currentMatrix->a);
}

void Op3D::rotacionLibre(float theta, float p1[3], float p2[3]){
    push();
    loadIdentity(currentMatrix->a);

    float V = sqrt( pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));

    float a = (p2[0] - p1[0]) / V;
    float b = (p2[1] - p1[1]) / V;
    float c = (p2[2] - p1[2]) / V;

    float d = sqrt(pow(b,2) + pow(c,2));

    float alpha;
    if (d == 0)
        alpha = asin(0);
    else
        alpha = asin(b/d);

    float beta = asin(a / sqrt(pow(a,2) + pow(d,2)));

    translation(-p1[0], -p1[1], -p1[2]);

    rotateXD(alpha);

    rotateYD(beta);

    rotateZ(DegToRad(theta));

    rotateYD(-beta);

    rotateXD(-alpha);

    translation(p1[0], p1[1], p1[2]);

    Matrix temp;
    assignValues(temp.a, currentMatrix->a);

    pop();
    mult(currentMatrix->a, temp.a);
    assignValues(currentMatrix->a, temp.a);
}

void Op3D::push() {
    Matrix *temp;
    temp = new Matrix();

    assignValues(temp->a, currentMatrix->a);

    modelStack.push(temp);
}

void Op3D::pop() {
    delete(currentMatrix);

    currentMatrix = modelStack.top();
    modelStack.pop();
}
