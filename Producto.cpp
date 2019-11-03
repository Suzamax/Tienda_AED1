#include "Producto.h"

Producto::Producto() {}
Producto::~Producto() {}

void Producto::leer()
{
    cin >> id;
    cin.ignore(20, '\n');
    getline(cin, nombre);
    getline(cin, descripcion);
    cin >> precio;
}

void Producto::mostrar()
{
    cout << nombre << " (" << id << ")" << endl;
    cout << "  " << descripcion << endl;
    cout << "  " << precio << " euros" << endl;
}
