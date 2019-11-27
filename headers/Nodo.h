#ifndef TIENDA_NODO_H
#define TIENDA_NODO_H

#include <iostream>
#include <list>
#include <sstream>
#include "Producto.h"
#include "Utilidades.h"
using namespace std;

/**
 * @brief Clase que define los nodos del árbol
 */

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
    list<Producto*> * getLista() { return lista; }
    int getAltura() { return altura; }
    void setAltura(int h) { altura = h; }
    /*
        void setHijoIzquierdo(Nodo * n) { izq = n; }
        Nodo * getHijoIzquierdo() { return izq; }
        void setHijoDerecho(Nodo * n) { der = n; }
        Nodo * getHijoDerecho() { return der; }
    */
};

#endif
