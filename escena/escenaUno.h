#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/arbol.h"
#include "../objetos/piramide.h"

class EscenaUno{
private:
    Op3D *op;
    Arbol arbol1;
    Piramide piramide;
    float pointsA[3], pointsB[3];
    void loadIdentity();

public:
    void dibujarEscena();
    void actualizarEscena();

    EscenaUno();
};

#endif // ESCENAUNO_H_INCLUDED
