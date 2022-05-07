#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    piramideUno = Piramide(op);
    piramideDos = Piramide(op);
    piramideTres = Piramide(op);
}

void EscenaUno::dibujarEscena(){
    op->push(); // Cargar una matriz identidad

    op->translation(5,0,0); //Matriz global se mueva 5 en x

    op->push(); // Guardamos la matriz global de 5 de traslamiento

    piramideUno.draw();

    op->translation(0,2,0);

    piramideDos.draw();

    op->pop(); //Matriz global de 5 de traslamiento en x

    op->translation(0,0,3);

    pointsA[0] = 0; pointsA[1] = 0; pointsA[2] = 0;
    pointsB[0] = 1; // Rotar X
    pointsB[1] = 0; // Rotar Y
    pointsB[2] = 0; // Rotar Z

    op->rotacionLibre(45.0f, pointsA, pointsB); //Rotacion de 50° en eje Z

    piramideTres.draw();

    op->pop();//Matriz Identidad
}
