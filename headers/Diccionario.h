#ifndef TIENDA_DICCIONARIO_H
#define TIENDA_DICCIONARIO_H

#include <iostream>
#include <list>
#include <sstream>
#include "TablaHash.h"
using namespace std;

/**
 * @brief Clase en la que se almacena la lista de productos, nº de productos y una tabla con las correspondencias entre palabras y productos.
 */
class DiccionarioProductos
{
private:
    list<Producto> lista;
    int contador;
    TablaHash tabla;
public:
    DiccionarioProductos();
    ~DiccionarioProductos();
    void insertar (Producto * nuevo); // DONE
    void eliminar (unsigned long int id); // DONE
    void producto (unsigned long int id); // DONE
    void precios (double min, double max); // DONE
    int getContador() { return contador; }
    TablaHash * getTabla() { return &tabla; }
};

#endif //TIENDA_DICCIONARIO_H
