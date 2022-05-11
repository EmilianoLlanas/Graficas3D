#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();

    carro1= Carro(op);


    arbol1 = Arbol(op);
    alien = Alien(op);

    rueda1=Rueda(op);
}

void EscenaUno::loadIdentity(){
    op->loadIdentity();
}

void EscenaUno::dibujarEscena(){
    int i;
    loadIdentity();
    op->push();

    op->translation(-5,5,5);

    alien.draw();

    op->pop();
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

    op->push();
    carro1.draw();
    op->pop();




    op->push();

    op->translation(.5,0,-.3f);
    op->scaling(.3f,.3f,.3f);

    rueda1.draw();

    op->pop();

    op->push();

    op->translation(15,0,-.3f);
    op->scaling(.3f,.3f,.3f);

    rueda1.draw();

    op->pop();

    op->push();
    op->translation(.5f,0,10);
    op->scaling(.3f,.3f,.3f);

    rueda1.draw();
    op->pop();

    op->push();
    op->translation(15,0,10);
    op->scaling(.3f,.3f,.3f);

    rueda1.draw();

    op->pop();
}

void EscenaUno::actualizarEscena() {
    arbol1.update();
    carro1.update();
    rueda1.update();
    alien.update();

}
