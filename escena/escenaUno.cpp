#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    arbol1 = Arbol(op);
    piramide = Piramide(op);
}

void EscenaUno::loadIdentity(){
    op->loadIdentity();
}

void EscenaUno::dibujarEscena(){
    int i;
    loadIdentity();

    op->push(); // Cargar una matriz identidad
    op->translation(-24,0,-16);

    for (i = 0; i < 6; i++){
        arbol1.draw();
        op->translation(8,0,0);
    }

    op->pop();
    op->push();

    op->translation(-24,0,16);
    for (i = 0; i < 6; i++){
        arbol1.draw();
        op->translation(8,0,0);
    }

    op->pop();//Matriz Identidad
}

void EscenaUno::actualizarEscena() {
    arbol1.update();
}
