#include <iostream>

#ifndef TIENDA_DICCIONARIO_H
#define TIENDA_DICCIONARIO_H


class DiccionarioProductos
{
private:
    list<Producto> lista;
    int contador;
public:
    DiccionarioProductos ();
    void insertar (Producto nuevo);
};

#endif //TIENDA_DICCIONARIO_H
