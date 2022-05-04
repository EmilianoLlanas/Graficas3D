#include "piramide.h"

Piramide::Piramide(){}

void Piramide::draw(){
    glColor3f(0.4f,0.7f,0.4f);
    int i;
    glBegin(GL_LINE_LOOP);
      for(i=0;i<4;i++)
        glVertex3f(points[i][0],points[i][1],points[i][2]);
    glEnd();
    glBegin(GL_LINES);
      for(i=0;i<4;i++){
        glVertex3f(points[4][0],points[4][1],points[4][2]);
        glVertex3f(points[i][0],points[i][1],points[i][2]);
        }
    glEnd();
}
