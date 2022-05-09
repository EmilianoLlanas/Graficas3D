#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    arbol1 = Arbol(op);
    alien = Alien(op);
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
    for (i = 0; i < 6; i++) {
        arbol1.draw();
        op->translation(8,0,0);
    }

    op->pop();//Matriz Identidad

    op->push();

    op->translation(5,2,5);
    alien.draw();

    op->pop();
}
