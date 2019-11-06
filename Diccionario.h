#ifndef TIENDA_DICCIONARIO_H
#define TIENDA_DICCIONARIO_H

#include <iostream>
#include <list>
#include "TablaHash.h"
using namespace std;

class DiccionarioProductos
{
    friend class TablaHash;
    private:
        list<Producto> lista;
        int contador;
        TablaHash tabla;
    public:
        DiccionarioProductos();
        ~DiccionarioProductos();
        void insertar (Producto nuevo); // DONE
        void eliminar (unsigned long int id); // DONE
        void producto (unsigned long int id); // DONE
        void precios (double min, double max); // DONE
        int getContador() { return contador; };
        void sortProductos();
};

#endif //TIENDA_DICCIONARIO_H
