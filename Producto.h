#ifndef TIENDA_PRODUCTO_H
#define TIENDA_PRODUCTO_H

#include <iostream>
using namespace std;

class Producto
{
private:
    unsigned long int identificador;
    string nombre, descripcion;
    float precio;
public:
    Producto();
    void leer();
    void mostrar();
    unsigned long int getIdentificador();

    // bool es_anterior(Producto &otro); // TODO cosas
    ~Producto();
};


#endif //TIENDA_PRODUCTO_H
