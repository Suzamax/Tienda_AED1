#ifndef TIENDA_NODO_H
#define TIENDA_NODO_H

#include <iostream>
#include <list>
#include <sstream>
#include "Producto.h"
#include "Utilidades.h"
using namespace std;

class Nodo
{
private:
    float precio;
    int altura;
    list<Producto*> * lista;
public:
    Nodo * izq;
    Nodo * der;
    Nodo(float precio, Producto * p);
    ~Nodo();
    float getPrecio() { return precio; }
    list<Producto*> * getList() { return lista; }
    int getAlt() { return altura; }
    void setAltura(int h) { altura = h; }
};

#endif
