#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/arbol.h"
#include "../objetos/carro.h"
class EscenaUno{
private:
    Op3D *op;
    Carro carro1;
    Arbol arbol1;
    float pointsA[3], pointsB[3];
    void loadIdentity();

public:
    void dibujarEscena();
    void actualizarEscena();

    EscenaUno();
};

#endif // ESCENAUNO_H_INCLUDED
