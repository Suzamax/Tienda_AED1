#ifndef TIENDA_PRODUCTO_H
#define TIENDA_PRODUCTO_H

#include <iostream>
using namespace std;

class Producto
{
private:
    unsigned long int id;
    string nombre, descripcion;
    float precio;
public:
    Producto();
    void leer();
    void mostrar();
    unsigned long int getID() const {
        return id;
    };
    float getPrec() const {
        return precio;
    }
    string getNombre() const {
        return nombre;
    }
    string getDesc() const {
        return descripcion;
    }
    friend bool operator== (const Producto & uno, const Producto & otro);
    friend bool operator< (const Producto & uno, const Producto & otro);
    ~Producto();
};


#endif //TIENDA_PRODUCTO_H
