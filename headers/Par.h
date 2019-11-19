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
    Par();
    string getPalabra() {
        return w;
    }
    void meterProducto(T obj);
    list<T>* getList();
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
 * @brief Constructor por defecto. Agujeros negros.
 */
template <class T>
Par<T>::Par()
{
    // NULL BOIS
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
list<T>* Par<T>::getList()
{
    return prods;
}

#endif //TIENDA_PAR_H
