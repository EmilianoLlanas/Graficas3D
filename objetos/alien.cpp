#include "alien.h"

Alien::Alien(){
    op = NULL;
    loadPoints();
}

Alien::Alien(Op3D* mainOp){
    op = mainOp;
    loadPoints();
}

void Alien::loadPoints(){

    points[0][0] = 0;
    points[1][0] = 0;
    points[2][0] = 0;
    points[3][0] = 1;

    points[0][1] = 4;
    points[1][1] = 0;
    points[2][1] = 0;
    points[3][1] = 1;

    points[0][2] = 4;
    points[1][2] = 0;
    points[2][2] = 4;
    points[3][2] = 1;

    points[0][3] = 0;
    points[1][3] = 0;
    points[2][3] = 4;
    points[3][3] = 1;

    points[0][4] = 2;
    points[1][4] = 3;
    points[2][4] = 2;
    points[3][4] = 1;

    points[0][5] = 2;
    points[1][5] = -3;
    points[2][5] = 2;
    points[3][5] = 1;
}

void Alien::draw(){
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {0.42f, 0.66f, 1.77f};

    GLint width = 3;
    GLdouble fillDif = 0.1;

    int i;
    GLdouble j;

    glColor3fv(colors);
    glPointSize(width);

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

    glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3d((*p)[0][5],(*p)[1][5],(*p)[2][5]);
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
      }
    glEnd();

    //Fill
    glBegin(GL_LINES);
      for(j=(*p)[0][0]; j<(*p)[0][1];j = j + fillDif){
        glVertex3d(j,(*p)[1][0],(*p)[2][0]);
        glVertex3d((*p)[0][4],(*p)[1][4],(*p)[2][4]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][0]; j<(*p)[0][1];j = j + fillDif){
        glVertex3d(j,(*p)[1][0],(*p)[2][0]);
        glVertex3d((*p)[0][5],(*p)[1][5],(*p)[2][5]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][2]; j>(*p)[0][3];j = j - fillDif){
        glVertex3d(j,(*p)[1][2],(*p)[2][2]);
        glVertex3d((*p)[0][4],(*p)[1][4],(*p)[2][4]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][2]; j>(*p)[0][3];j = j - fillDif){
        glVertex3d(j,(*p)[1][2],(*p)[2][2]);
        glVertex3d((*p)[0][5],(*p)[1][5],(*p)[2][5]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][1]; j<(*p)[2][2];j = j + fillDif){
        glVertex3d((*p)[0][1],(*p)[1][1],j);
        glVertex3d((*p)[0][4],(*p)[1][4],(*p)[2][4]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][1]; j<(*p)[2][2];j = j + fillDif){
        glVertex3d((*p)[0][1],(*p)[1][1],j);
        glVertex3d((*p)[0][5],(*p)[1][5],(*p)[2][5]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][3]; j>(*p)[2][0];j = j - fillDif){
        glVertex3d((*p)[0][3],(*p)[1][3],j);
        glVertex3d((*p)[0][4],(*p)[1][4],(*p)[2][4]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][3]; j>(*p)[2][0];j = j - fillDif){
        glVertex3d((*p)[0][3],(*p)[1][3],j);
        glVertex3d((*p)[0][5],(*p)[1][5],(*p)[2][5]);
      }
    glEnd();


}
