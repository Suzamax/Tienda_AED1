#include "Diccionario.h"

DiccionarioProductos::DiccionarioProductos() {};
DiccionarioProductos::~DiccionarioProductos() {};

void DiccionarioProductos::insertar(Producto p) {
    lista.push_front(p);
}

// TODO cosas

