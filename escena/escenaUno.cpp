#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    piramideUno = Piramide(op);
    piramideDos = Piramide(op);
}

void EscenaUno::dibujarEscena(){
    op->push();
    op->translation(5,0,0);
    op->push();

    piramideUno.draw();

    op->pop();
    op->scaling(2,2,2);

    piramideDos.draw();
}
