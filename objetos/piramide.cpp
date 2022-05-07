#include "piramide.h"

Piramide::Piramide(){
    op = NULL;
    loadPoints();
}

Piramide::Piramide(Op3D* mainOp){
    op = mainOp;
    loadPoints();
}

void Piramide::loadPoints(){

    points[0][0] = 0;
    points[1][0] = 0;
    points[2][0] = 0;
    points[3][0] = 1;

    points[0][1] = 2;
    points[1][1] = 0;
    points[2][1] = 0;
    points[3][1] = 1;

    points[0][2] = 2;
    points[1][2] = 0;
    points[2][2] = 2;
    points[3][2] = 1;

    points[0][3] = 0;
    points[1][3] = 0;
    points[2][3] = 2;
    points[3][3] = 1;

    points[0][4] = 1;
    points[1][4] = 1.5;
    points[2][4] = 1;
    points[3][4] = 1;
}

void Piramide::draw(){
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {0.4f, 0.7f, 0.4f};

    GLint width = 3;

    glColor3fv(colors);
    glPointSize(width);

    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<4;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();
    glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3d((*p)[0][4],(*p)[1][4],(*p)[2][4]);
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
      }
    glEnd();
}
