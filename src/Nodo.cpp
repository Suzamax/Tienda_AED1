#include "Nodo.h"

Nodo::Nodo() {};
Nodo::~Nodo() {};

double Nodo::precio()
{
    return Precio;
}

void Nodo::insertarproducto(Producto *prod)
{
    lista.push_front(prod);
}

Nodo* Nodo::getHijoIzquierdo()
{
    return hijoizquierdo;
}

Nodo* Nodo::getHijoDerecho()
{
    return hijoderecho;
}
