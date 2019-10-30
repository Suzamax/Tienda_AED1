#include "Producto.h"

Producto::Producto() {}
Producto::~Producto() {}

void Producto::leer()
{
    cin >> identificador;
    cin.ignore(20, '\n');
    getline(cin, nombre);
    getline(cin, descripcion);
    cin >> precio;
}

void Producto::mostrar()
{
    cout << nombre << " (" << identificador << ")" << endl;
    cout << "  " << descripcion << endl;
    cout << "  " << precio << " euros" << endl;
}

unsigned long int Producto::getIdentificador()
{
    return identificador;
}
