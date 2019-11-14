#ifndef TIENDA_INTERPRETE_H
#define TIENDA_INTERPRETE_H

#include <iostream>
#include "Diccionario.h"
#include "Producto.h"
using namespace std;

/**
 * @brief El intérprete de comandos de este programa. En función de lo que lea llamará a uno de sus métodos.
 */
class Interprete
{
    private:
        DiccionarioProductos *dp;
    public:
        Interprete(DiccionarioProductos *dic);
        ~Interprete();
        void obtener_comando(string c);
        void procesar_insertar();
        void procesar_palabras();
        void procesar_precios();
        void procesar_eliminar();
        void procesar_producto();
};



#endif //TIENDA_INTERPRETE_H
