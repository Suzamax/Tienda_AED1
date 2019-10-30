#ifndef TIENDA_INTERPRETE_H
#define TIENDA_INTERPRETE_H

#include <iostream>
#include "Diccionario.h"
#include "Producto.h"
using namespace std;

class Interprete
{
    public:
        Interprete();
        ~Interprete();
        void obtener_comando(string c, DiccionarioProductos *dp);
        void procesar_insertar(DiccionarioProductos *dp);
        //void procesar_palabras();
        void procesar_precios();
        void procesar_eliminar();
        void procesar_producto();
};



#endif //TIENDA_INTERPRETE_H
