#ifndef TIENDA_DICCIONARIO_H
#define TIENDA_DICCIONARIO_H

#include <iostream>
#include <list>
#include <sstream>
#include "TablaHash.h"
#include "Arbol.h"
using namespace std;

class DiccP
{
private:
    list<Producto> lista;
    int contador;
    TablaHash tabla;
    Arbol * arbol;
    Nodo * raiz;
public:
    DiccP();
    ~DiccP();
    void insertar (Producto * nuevo);
    void eliminar (unsigned long int id);
    void producto (unsigned long int id);
    void precios (double min, double max);
    int getContador() { return contador; }
    TablaHash * getTabla() { return &tabla; }
};

#endif //TIENDA_DICCIONARIO_H
