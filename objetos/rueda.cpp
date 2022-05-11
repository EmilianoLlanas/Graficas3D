#include "rueda.h"

Rueda::Rueda(){
    op = NULL;
    movimiento = 0;
    rotacion = 0;
    loadPoints();
}

Rueda::Rueda(Op3D* mainOp){
    op = mainOp;
    movimiento = 0;
    rotacion = 0;
    loadPoints();
}

void Rueda::loadPoints(){

    //puntos rueda

    points[0][0] = 0;
    points[1][0] = 4.25;
    points[2][0] = 0;
    points[3][0] = 1;

    points[0][1] = 0;
    points[1][1] = 4.25;
    points[2][1] = 1;
    points[3][1] = 1;

    points[0][2] = 0;
    points[1][2] = 4.25;
    points[2][2] = 0;
    points[3][2] = 1;

    points[0][3] = 0;
    points[1][3] = 1.25;
    points[2][3] = 0;
    points[3][3] = 1;

    points[0][4] = 0;
    points[1][4] = 1.25;
    points[2][4] = 1;
    points[3][4] = 1;

    points[0][5] = 0;
    points[1][5] = 4.25;
    points[2][5] = 1;
    points[3][5] = 1;

    points[0][6] = 0;
    points[1][6] = 1.25;
    points[2][6] = 1;
    points[3][6] = 1;

    points[0][7] = 0;
    points[1][7] = 1.25;
    points[2][7] = 0;
    points[3][7] = 1;

    points[0][8] = 2.5;
    points[1][8] = 0;
    points[2][8] = 0;
    points[3][8] = 1;

    points[0][9] = 2.5;
    points[1][9] = 0;
    points[2][9] = 1;
    points[3][9] = 1;

    points[0][10] = 0;
    points[1][10] = 1.25;
    points[2][10] = 1;
    points[3][10] = 1;

    points[0][11] = 2.5;
    points[1][11] = 0;
    points[2][11] = 1;
    points[3][11] = 1;

    points[0][12] = 2.5;
    points[1][12] = 0;
    points[2][12] = 0;
    points[3][12] = 1;

    points[0][13] = 5;
    points[1][13] = 1.25;
    points[2][13] = 0;
    points[3][13] = 1;

    points[0][14] = 5;
    points[1][14] = 1.25;
    points[2][14] = 1;
    points[3][14] = 1;

    points[0][15] = 2.5;
    points[1][15] = 0;
    points[2][15] = 1;
    points[3][15] = 1;

    points[0][16] = 5;
    points[1][16] = 1.25;
    points[2][16] = 1;
    points[3][16] = 1;

    points[0][17] = 5;
    points[1][17] = 1.25;
    points[2][17] = 0;
    points[3][17] = 1;

    points[0][18] = 5;
    points[1][18] = 4.25;
    points[2][18] = 0;
    points[3][18] = 1;

    points[0][19] = 5;
    points[1][19] = 4.25;
    points[2][19] = 1;
    points[3][19] = 1;

    points[0][20] = 5;
    points[1][20] = 1.25;
    points[2][20] = 1;
    points[3][20] = 1;

    points[0][21] = 5;
    points[1][21] = 4.25;
    points[2][21] = 1;
    points[3][21] = 1;

    points[0][22] = 5;
    points[1][22] = 4.25;
    points[2][22] = 0;
    points[3][22] = 1;

    points[0][23] = 2.5;
    points[1][23] = 5.5;
    points[2][23] = 0;
    points[3][23] = 1;

    points[0][24] = 2.5;
    points[1][24] = 5.5;
    points[2][24] = 1;
    points[3][24] = 1;

    points[0][25] = 5;
    points[1][25] = 4.25;
    points[2][25] = 1;
    points[3][25] = 1;

    points[0][26] = 2.5;
    points[1][26] = 5.5;
    points[2][26] = 1;
    points[3][26] = 1;

    points[0][27] = 0;
    points[1][27] = 4.25;
    points[2][27] = 1;
    points[3][27] = 1;

    points[0][28] = 2.5;
    points[1][28] = 5.5;
    points[2][28] = 1;
    points[3][28] = 1;

    points[0][29] = 2.5;
    points[1][29] = 5.5;
    points[2][29] = 0;
    points[3][29] = 1;




}

void Rueda::draw(){
    float p1[3] = {0,0,0};
    float p3[3] = {0,0,1};

    op->push();
    if(movimiento==-150){
        movimiento=30;
    }
    op->translation(movimiento,0,0);
    op->rotacionLibre(rotacion,p1, p3);
    op->applyModelMatrix(*points, *modelMatrix, MAXPOINTS);

    op->pop();
    GLdouble (*p)[4][MAXPOINTS] = &modelMatrix;
    GLfloat colors [3] = {1.0f, 1.0f, 1.0f};

    GLint width = 5;
    GLdouble fillDif = 0.05;
    GLdouble j;
    glColor3fv(colors);
    glPointSize(width);

    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<30;i++)
        glVertex3d((*p)[0][i],(*p)[1][i],(*p)[2][i]);
    glEnd();


}
void Rueda::update() {
    movimiento -= 0.5;
}

