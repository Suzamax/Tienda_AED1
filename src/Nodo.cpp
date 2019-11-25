#include "Nodo.h"

Nodo::Nodo(float precio, Producto * p)
{
    this->precio = precio;
    lista = new list<Producto*>();
    lista->push_front(p);
    izq = nullptr;
    der = nullptr;
}

Nodo::~Nodo()
{
    delete lista;
}

