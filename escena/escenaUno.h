#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/piramide.h"

class EscenaUno{
private:
    Op3D *op;
    Piramide piramideUno, piramideDos;

public:
    void dibujarEscena();

    EscenaUno();
};

#endif // ESCENAUNO_H_INCLUDED
