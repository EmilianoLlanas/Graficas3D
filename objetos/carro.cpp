#include "carro.h"

Carro::Carro(){
    op = NULL;
    movimiento = 0;
    rotacion = 0;
    loadPoints();
}

Carro::Carro(Op3D* mainOp){
    op = mainOp;
    movimiento = 0;
    rotacion = 0;
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
    points[0][16] = 1.5;
    points[1][16] = 1.5;
    points[2][16] = 0.5;
    points[3][16] = 1;

    points[0][17] = 3;
    points[1][17] = 2.5;
    points[2][17] = 0.5;
    points[3][17] = 1;

    points[0][18] = 5;
    points[1][18] = 2.5;
    points[2][18] = 0.5;
    points[3][18] = 1;

    points[0][19] = 5;
    points[1][19] = 1.5;
    points[2][19] = 0.5;
    points[3][19] = 1;

    points[0][20] = 5;
    points[1][20] = 1.5;
    points[2][20] = 2.5;
    points[3][20] = 1;

    points[0][21] = 5;
    points[1][21] = 2.5;
    points[2][21] = 2.5;
    points[3][21] = 1;

    points[0][22] = 5;
    points[1][22] = 2.5;
    points[2][22] = 0.5;
    points[3][22] = 1;

    points[0][23] = 5;
    points[1][23] = 2.5;
    points[2][23] = 2.5;
    points[3][23] = 1;

    points[0][24] = 3;
    points[1][24] = 2.5;
    points[2][24] = 2.5;
    points[3][24] = 1;

    points[0][25] = 1.5;
    points[1][25] = 1.5;
    points[2][25] = 2.5;
    points[3][25] = 1;

    points[0][26] = 1.5;
    points[1][26] = 1.5;
    points[2][26] = 0.5;
    points[3][26] = 1;

    points[0][27] = 5;
    points[1][27] = 1.5;
    points[2][27] = 0.5;
    points[3][27] = 1;

    points[0][28] = 1.5;
    points[1][28] = 1.5;
    points[2][28] = 0.5;
    points[3][28] = 1;

    points[0][29] = 1.5;
    points[1][29] = 1.5;
    points[2][29] = 2.5;
    points[3][29] = 1;

    points[0][30] = 5;
    points[1][30] = 1.5;
    points[2][30] = 2.5;
    points[3][30] = 1;

    points[0][31] = 1.5;
    points[1][31] = 1.5;
    points[2][31] = 2.5;
    points[3][31] = 1;


}

void Carro::draw(){
    float p1[3] = {0,0,0};
    float p3[3] = {0,1,0};

    op->push();
    if(movimiento==-150){
        movimiento=30;
    }
    op->translation(movimiento,0,0);
    op->rotacionLibre(rotacion,p1, p3);
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    op->pop();
    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {1.0f, 0.0f, 0.0f};

    GLint width = 5;
    GLdouble fillDif = 0.05;
    GLdouble j;
    glColor3fv(colors);
    glPointSize(width);

    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<16;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();

    /*glBegin(GL_LINES);
      for(j=(*p)[0][0]; j<(*p)[2][2];j = j + fillDif){
        glVertex3d((*p)[0][0],(*p)[1][0],j);
        glVertex3d((*p)[0][2],(*p)[1][2],j);
      }
    glEnd();

    glBegin(GL_LINES);
      for(j=(*p)[0][0]; j<(*p)[2][6];j = j + fillDif){
        glVertex3d((*p)[0][0],(*p)[1][0],j);
        glVertex3d((*p)[0][6],(*p)[1][6],j);
      }
    glEnd();
*/





    GLfloat colors2 [3] = {0.0f, 0.0f, 1.0f};
    glColor3fv(colors2);
    glBegin(GL_LINE_LOOP);
      for(i=16;i<32;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();




    /*glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
      }
    glEnd();*/
}
void Carro::update() {
    movimiento -= 0.5;
    //rotacion += 1;
}
