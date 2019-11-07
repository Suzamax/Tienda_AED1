#ifndef TIENDA_PRODUCTO_H
#define TIENDA_PRODUCTO_H

#include <iostream>
using namespace std;

/**
 * @brief Clase para almacenar un producto.
 * 
 */
class Producto
{
private:
    unsigned long int id;
    string nombre, descripcion;
    double precio;
public:
    Producto();
    void leer();
    void mostrar();
    unsigned long int getID() {
        return id;
    };
    unsigned long int getID() const {
        return id;
    };
    double getPrecio() {
        return precio;
    }
    // bool es_anterior(Producto &otro); // TODO cosas
    ~Producto();
};


#endif //TIENDA_PRODUCTO_H
