#ifndef TIENDA_PAR_H
#define TIENDA_PAR_H

#include "Producto.h"
#include <list>

template <class T>
class Par
{
private:
    string w;
    list<T> *prods;
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

template <class T>
Par<T>::Par(string w, T obj)
{
    this->w = w;
    prods = new list<T>();
    prods->push_front(obj);
}


template <class T>
Par<T>::Par() {}

template <class T>
Par<T>::~Par() {}

template <class T>
void Par<T>::meterProducto(T obj) { prods->push_front(obj); }

template <class T>
list<T>* Par<T>::getList() { return prods; }

#endif //TIENDA_PAR_H
