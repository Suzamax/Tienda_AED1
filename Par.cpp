#include "Par.h"

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