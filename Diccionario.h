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
    DiccionarioProductos();
    ~DiccionarioProductos();
    void insertar (Producto nuevo);
    void eliminar (unsigned long int id);
    void producto (unsigned long int id);
    void precios (double min, double max);
    int getContador() {
        return contador;
    };
};

#endif //TIENDA_DICCIONARIO_H
