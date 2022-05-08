#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/arbol.h"

class EscenaUno{
private:
    Op3D *op;
    Arbol arbol1;
    float pointsA[3], pointsB[3];

public:
    void dibujarEscena();

    EscenaUno();
};

#endif // ESCENAUNO_H_INCLUDED
