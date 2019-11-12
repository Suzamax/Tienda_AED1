#include "Producto.h"

Producto::Producto() {}
Producto::~Producto() {}

/**
 * @brief Lee los datos a almacenar en la instancia objeto Producto creada.
 * Primero obtiene el identificador y luego las líneas del nombre y descripción del producto, y termina leyendo el precio.
 * 
 */
void Producto::leer()
{
    cin >> id;
    cin.ignore(20, '\n');
    getline(cin, nombre);
    getline(cin, descripcion);
    cin >> precio;
}

/**
 * @brief Escribe en la pantalla el producto de la instancia actual.
 * 
 */
void Producto::mostrar()
{
    cout << nombre << " (" << id << ")" << endl;
    cout << "  " << descripcion << endl;
    cout << "  " << precio << " euros" << endl;
}
