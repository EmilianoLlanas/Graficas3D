#include "carro.h"

Carro::Carro(){
    op = NULL;
    loadPoints();
}

Carro::Carro(Op3D* mainOp){
    op = mainOp;
    loadPoints();
}

void Carro::loadPoints(){

    //carrocería principal

    points[0][0] = 0;
    points[1][0] = 0;
    points[2][0] = 0;
    points[3][0] = 1;

    points[0][1] = 6;
    points[1][1] = 0;
    points[2][1] = 0;
    points[3][1] = 1;

    points[0][2] = 6;
    points[1][2] = 0;
    points[2][2] = 3;
    points[3][2] = 1;

    points[0][3] = 0;
    points[1][3] = 0;
    points[2][3] = 3;
    points[3][3] = 1;

    points[0][4] = 0;
    points[1][4] = 0;
    points[2][4] = 0;
    points[3][4] = 1;

    points[0][5] = 0;
    points[1][5] = 1.5;
    points[2][5] = 0;
    points[3][5] = 1;

    points[0][6] = 0;
    points[1][6] = 1.5;
    points[2][6] = 3;
    points[3][6] = 1;

    points[0][7] = 0;
    points[1][7] = 0;
    points[2][7] = 3;
    points[3][7] = 1;

    points[0][8] = 0;
    points[1][8] = 1.5;
    points[2][8] = 3;
    points[3][8] = 1;

    points[0][9] = 6;
    points[1][9] = 1.5;
    points[2][9] = 3;
    points[3][9] = 1;

    points[0][10] = 6;
    points[1][10] = 0;
    points[2][10] = 3;
    points[3][10] = 1;

    points[0][11] = 6;
    points[1][11] = 1.5;
    points[2][11] = 3;
    points[3][11] = 1;

    points[0][12] = 6;
    points[1][12] = 1.5;
    points[2][12] = 0;
    points[3][12] = 1;

    points[0][13] = 6;
    points[1][13] = 0;
    points[2][13] = 0;
    points[3][13] = 1;

    points[0][14] = 6;
    points[1][14] = 1.5;
    points[2][14] = 0;
    points[3][14] = 1;

    points[0][15] = 0;
    points[1][15] = 1.5;
    points[2][15] = 0;
    points[3][15] = 1;

    //Parabrisas y ventanas


}

void Carro::draw(){
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {1.0f, 1.0f, 0.0f};

    GLint width = 5;

    glColor3fv(colors);
    glPointSize(width);

    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<16;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();
    /*glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
      }
    glEnd();*/
}
