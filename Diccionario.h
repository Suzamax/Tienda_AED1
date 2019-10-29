#ifndef TIENDA_DICCIONARIO_H
#define TIENDA_DICCIONARIO_H

#include <iostream>
#include <list>
#include "Producto.h"

using namespace std;

class DiccionarioProductos
{
private:
    list<Producto> lista;
    int contador;
public:
    DiccionarioProductos ();
    void insertar (Producto nuevo);
    // TODO Muchas cosas
};

#endif //TIENDA_DICCIONARIO_H
