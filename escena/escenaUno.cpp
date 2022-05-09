#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    arbol1 = Arbol(op);
}

void EscenaUno::dibujarEscena(){
    int i;

    op->push(); // Cargar una matriz identidad
    op->translation(-24,0,0);

    for (i = 0; i < 6; i++) {
        arbol1.draw();
        op->translation(8,0,0);
    }

    op->pop();
    op->push();

    op->translation(-24,0,50);


    pointsA[0] = 0; pointsA[1] = 0; pointsA[2] = 0;
    pointsB[0] = 1;

    //op->rotacionLibre(45.0f, pointsA, pointsB);

    for (i = 0; i < 6; i++) {
        arbol1.draw();
        op->translation(8,0,0);
    }

    op->pop();//Matriz Identidad
}

void EscenaUno::actualizarEscena() {
    arbol1.update();
}
