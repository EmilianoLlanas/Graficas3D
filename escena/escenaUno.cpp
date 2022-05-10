#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    arbol1 = Arbol(op);
    alien = Alien(op);
}

void EscenaUno::loadIdentity(){
    op->loadIdentity();
}

void EscenaUno::dibujarEscena(){
    int i;
    loadIdentity();

    op->push(); // Cargar una matriz identidad

    //op->translation(-8,0,0);
    arbol1.draw();

    /*op->push();
    op->translation(16,0,0);
    arbol1.draw();


    op->pop();
    op->translation(0,0,8);
    arbol1.draw();*/

    op->pop();//Matriz Identidad

    op->push();

    op->translation(5,2,5);
    alien.draw();

    op->pop();
}

void EscenaUno::actualizarEscena() {
    arbol1.update();
}
