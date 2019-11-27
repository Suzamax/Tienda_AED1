#include "Nodo.h"

Nodo::Nodo(float precio, Producto * p)
{
    this->precio = precio;
    lista = new list<Producto*>();
    lista->push_front(p);
    izq = nullptr;
    der = nullptr;
    altura = 0;
}

Nodo::~Nodo()
{
    delete lista;
    delete izq;
    delete der;
}


