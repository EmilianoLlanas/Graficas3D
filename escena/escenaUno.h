#ifndef ESCENAUNO_H_INCLUDED
#define ESCENAUNO_H_INCLUDED

#include "../utilidades/Op3D.h"
#include "../objetos/piramide.h"

class EscenaUno{
private:
    Piramide piramideUno;
    Op3D op;

public:
    void dibujarEscena();

    EscenaUno();

};

#endif // ESCENAUNO_H_INCLUDED
