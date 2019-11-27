#ifndef TIENDA_ARBOL_H
#define TIENDA_ARBOL_H

#include <iostream>
#include <list>
#include <sstream>
#include "Nodo.h"

using namespace std;

class Arbol
{
public:
    Arbol();
    ~Arbol();
    int getAlt(Nodo * n);
    Nodo * insert(Nodo * raiz, Producto *prod);
    Nodo * actAlt(Nodo * n);
    list<Producto*> * precios(Nodo * raiz, float min, float max);
    Nodo * RI(Nodo * n);
    Nodo * RD(Nodo * n);
};

#endif
