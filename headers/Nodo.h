#ifndef TIENDA_NODO_H
#define TIENDA_NODO_H

#include <iostream>
#include <list>
#include <sstream>
#include "Producto.h"
using namespace std;

/**
 * @brief Clase que define los nodos del árbol
 */

class Nodo
{
private:
    Nodo *hijoizquierdo;
    Nodo *hijoderecho;
    double Precio;

public:
    Nodo ();
    ~Nodo();
    double precio ();
    Nodo * getHijoIzquierdo();
    Nodo * getHijoDerecho();
    void insertarproducto (Producto *prod);
};

#endif
