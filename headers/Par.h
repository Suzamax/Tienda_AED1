#ifndef TIENDA_PAR_H
#define TIENDA_PAR_H

#include "Producto.h"
#include <list>

/**
 * @brief Un par palabra-lista de productos.
 * @tparam T Clase arbitraria. En este caso serán punteros a productos.
 */
template <class T>
class Par
{
private:
    string w;
    list<T> *prods; // Lista de productos que contienen la palabra w.
public:
    Par(string w, T obj);
    string getPalabra() {
        return w;
    }
    void meterProducto(T obj);

    Producto devolverProducto();
    ~Par();
};


/**
 * @brief Constructor
 *
 * @tparam T Clase del objeto pasado. Normalmente un puntero a un producto.
 * @param w Palabra.
 * @param obj Producto.
 */
template <class T>
Par<T>::Par(string w, T obj)
{
    this->w = w;
    prods = new list<T>();
    prods->push_front(obj);
}



/**
 * @brief Destructor
 * 
 * @tparam T Clase del objeto. Normalmente punteros a productos.
 */
template <class T>
Par<T>::~Par()
{
    delete prods;
}

/**
 * @brief Método para introducir un producto más a la lista de productos.
 * 
 * @tparam T Tipo, en este caso será un puntero a producto.
 * @param obj Producto.
 */
template <class T>
void Par<T>::meterProducto(T obj)
{
    prods->push_front(obj);
}

template <class T>
Producto Par<T>::devolverProducto()
{
    //Como de momento sólo necesitamos esta operación para la función de dispersión, nos basta con obtener el primer elemento
    return prods.begin();
}

#endif //TIENDA_PAR_H
