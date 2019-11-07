#ifndef TIENDA_PAR_H
#define TIENDA_PAR_H

#include "Producto.h"

/**
 * @brief Un par palabra-lista de productos.
 * 
 * @tparam T Clase arbitraria. En este caso serán punteros a productos.
 */
template <class T>
class Par
{
private:
    string w;
    list<T> prods*; // Lista de productos que contienen la palabra w.
public:
    Par(string w, T obj);
    void meterProducto(T obj);
    ~Par();
};





#endif //TIENDA_PAR_H