#include "Op3D.h"

Op3D::Op3D(){
    currentMatrix = new Modelado();

    // Assign Values
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if (i == j)
                currentMatrix->matrix[i][j] = 1;
            else
                currentMatrix->matrix[i][j] = 0;
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

void Op3D::translation(GLdouble x, GLdouble y, GLdouble z) {

    GLdouble transalteMatrix [4][4] = {{1,0,0,x}, {0,1,0,y}, {0,0,1,z}, {0,0,0,1}};

    mult(transalteMatrix, currentMatrix->matrix);
}

void Op3D::applyModelMatrix(GLdouble *points, GLdouble *result, int lenght){

    for(int i=0;i<4;i++) {
        for(int j=0;j<lenght;j++) {
            result[j+i*lenght] = 0;

            for(int k=0;k<4;k++) {
                result[j+i*lenght] += currentMatrix->matrix[i][k] * points[j+lenght*k];
            }
        }
    }
}

void Op3D::scaling(GLdouble x, GLdouble y, GLdouble z) {

    GLdouble escaleMatrix [4][4] = {{x,0,0,0}, {0,y,0,0}, {0,0,z,0}, {0,0,0,1}};

    mult(escaleMatrix, currentMatrix->matrix);
}

void Op3D::push() {
    Modelado *temp;
    temp = new Modelado();

    assignValues(temp->matrix, currentMatrix->matrix);

    modelStack.push(temp);
}

void Op3D::pop() {
    modelStack.pop();

    delete(currentMatrix);
    currentMatrix = modelStack.top();
}
