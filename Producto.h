#ifndef TIENDA_PRODUCTO_H
#define TIENDA_PRODUCTO_H

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
    // bool es_anterior(Producto &otro); //
    ~Producto();
};


#endif //TIENDA_PRODUCTO_H
