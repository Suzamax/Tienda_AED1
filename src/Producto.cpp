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

bool operator== (const Producto & uno, const Producto & otro)
{
    if (uno.getID() != otro.getID())
        return uno.getNombre() != otro.getNombre();
    return false;
}

bool operator< (const Producto & uno, const Producto & otro)
{
    return uno.getID() < otro.getID();
}
