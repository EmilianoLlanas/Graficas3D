#include "arbol.h"

Arbol::Arbol(){
    op = NULL;
    loadPoints();
}

Arbol::Arbol(Op3D* mainOp){
    op = mainOp;
    loadPoints();
}

void Arbol::loadPoints(){
    //Log Bottom
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

    //Log Top
    points[0][4] = 0;
    points[1][4] = 2;
    points[2][4] = 0;
    points[3][4] = 1;

    points[0][5] = 2;
    points[1][5] = 2;
    points[2][5] = 0;
    points[3][5] = 1;

    points[0][6] = 2;
    points[1][6] = 2;
    points[2][6] = 2;
    points[3][6] = 1;

    points[0][7] = 0;
    points[1][7] = 2;
    points[2][7] = 2;
    points[3][7] = 1;

    //Leafs Bottom
    points[0][8] = -1;
    points[1][8] = 2;
    points[2][8] = -1;
    points[3][8] = 1;

    points[0][9] = 3;
    points[1][9] = 2;
    points[2][9] = -1;
    points[3][9] = 1;

    points[0][10] = 3;
    points[1][10] = 2;
    points[2][10] = 3;
    points[3][10] = 1;

    points[0][11] = -1;
    points[1][11] = 2;
    points[2][11] = 3;
    points[3][11] = 1;

    //Leafs Top
    points[0][12] = -1;
    points[1][12] = 7;
    points[2][12] = -1;
    points[3][12] = 1;

    points[0][13] = 3;
    points[1][13] = 7;
    points[2][13] = -1;
    points[3][13] = 1;

    points[0][14] = 3;
    points[1][14] = 7;
    points[2][14] = 3;
    points[3][14] = 1;

    points[0][15] = -1;
    points[1][15] = 7;
    points[2][15] = 3;
    points[3][15] = 1;

}

void Arbol::draw(){
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {0.5529f, 0.2863f, 0.1451f};

    GLint width = 3;
    GLdouble fillDif = 0.1;

    glColor3fv(colors);
    glPointSize(width);

    int i;
    GLdouble j;

    //Log
    glBegin(GL_LINE_LOOP);
      for(i=0;i<4;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();

    glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
        glVertex3d((*p)[0][i+4],(*p)[1][i+4],(*p)[2][i+4]);
      }
    glEnd();

    //Log Fill
    glBegin(GL_LINES);
      for(j=(*p)[0][0]; j<(*p)[0][1];j = j + fillDif){
        glVertex3d(j,(*p)[1][0],(*p)[2][0]);
        glVertex3d(j,(*p)[1][4],(*p)[2][4]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][1]; j<(*p)[2][2];j = j + fillDif){
        glVertex3d((*p)[0][1],(*p)[1][1],j);
        glVertex3d((*p)[0][5],(*p)[1][5],j);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][2]; j>(*p)[0][3];j = j - fillDif){
        glVertex3d(j,(*p)[1][2],(*p)[2][2]);
        glVertex3d(j,(*p)[1][6],(*p)[2][6]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][3]; j>(*p)[2][0];j = j - fillDif){
        glVertex3d((*p)[0][3],(*p)[1][3],j);
        glVertex3d((*p)[0][7],(*p)[1][7],j);
      }
    glEnd();


    //Leafs
    colors[0] = 0.6f; colors[1] = 0.8353f; colors[2] = 0.4706f;
    glColor3fv(colors);

    glBegin(GL_LINE_LOOP);
      for(i=8;i<12;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();

    glBegin(GL_LINE_LOOP);
      for(i=12;i<16;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();

    glBegin(GL_LINES);
      for(i=8;i<12;i++){
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
        glVertex3d((*p)[0][i+4],(*p)[1][i+4],(*p)[2][i+4]);
      }
    glEnd();

    //Leafs Fill
    glBegin(GL_LINES);
      for(j=(*p)[0][8]; j<(*p)[0][9];j = j + fillDif){
        glVertex3d(j,(*p)[1][8],(*p)[2][8]);
        glVertex3d(j,(*p)[1][12],(*p)[2][12]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][9]; j<(*p)[2][10];j = j + fillDif){
        glVertex3d((*p)[0][9],(*p)[1][9],j);
        glVertex3d((*p)[0][13],(*p)[1][13],j);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][10]; j>(*p)[0][11];j = j - fillDif){
        glVertex3d(j,(*p)[1][10],(*p)[2][10]);
        glVertex3d(j,(*p)[1][14],(*p)[2][14]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[2][11]; j>(*p)[2][8];j = j - fillDif){
        glVertex3d((*p)[0][11],(*p)[1][11],j);
        glVertex3d((*p)[0][15],(*p)[1][15],j);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][8]; j<(*p)[0][10];j = j + fillDif){
        glVertex3d(j,(*p)[1][8],(*p)[2][8]);
        glVertex3d(j,(*p)[1][10],(*p)[2][10]);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][12]; j<(*p)[0][14];j = j + fillDif){
        glVertex3d(j,(*p)[1][12],(*p)[2][12]);
        glVertex3d(j,(*p)[1][14],(*p)[2][14]);
      }
    glEnd();

}
