#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/piramide.h"
#include "../objetos/carro.h"
class EscenaUno{
private:
    Op3D *op;
    Piramide piramideUno, piramideDos, piramideTres;
    Carro carro1;
    float pointsA[3], pointsB[3];

public:
    void dibujarEscena();

    EscenaUno();
};

#endif // ESCENAUNO_H_INCLUDED
