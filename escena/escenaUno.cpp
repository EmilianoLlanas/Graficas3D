#include "escenaUno.h"

EscenaUno::EscenaUno(){
    op = new Op3D();
    piramideUno = Piramide(op);

    piramideDos = Piramide(op);
    piramideTres = Piramide(op);

    carro1= Carro(op);


}

void EscenaUno::dibujarEscena(){
    op->push(); // Cargar una matriz identidad

    //op->translation(5,0,0); //Matriz global se mueva 5 en x

    op->push(); // Guardamos la matriz global de 5 de traslamiento

    carro1.draw();

    //piramideUno.draw();

    //op->translation(0,2,0);

    //piramideDos.draw();

    /*op->pop(); //Matriz global de 5 de traslamiento en x
    op->pop(); //Matriz identidad

    pointsA[0] = 0; pointsA[1] = 0; pointsA[2] = 0;
    pointsB[0] = 0; pointsB[1] = 0; pointsB[2] = 1;

    op->rotacionLibre(90.0f,  pointsA, pointsB);

    piramideTres.draw();*/
}
