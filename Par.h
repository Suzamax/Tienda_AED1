#ifndef TIENDA_PAR_H
#define TIENDA_PAR_H

#include "Producto.h"

template <class T>
class Par
{
private:
    string w;
    list<T*> l;
public:
    Par(string w, T* obj);
    ~Par();
};





#endif //TIENDA_PAR_H