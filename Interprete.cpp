#include "Interprete.h"

// TODO Apañar esto con la nueva información

void procesar_insertar()
{
    p.leer(); // TODO Qué es P? Dónde se declara? Obviamente habrá que pasar el objeto...
    cout << ++i << " productos" << endl;
}

void procesar_palabras()
{
    string palabras;
    getline(cin, palabras);
    cout << "palabras" << palabras << endl << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void procesar_precios()
{
    float max, min;
    cin >> min;
    cin >> max;
    cin.ignore(20, '\n');
    cout << "precios " << min << " " << max << endl << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void procesar_eliminar()
{
    cout << --i << " productos" << endl;
}

void procesar_producto()
{
    unsigned long int id;
    cin >> id;
    cout << "producto " << id << endl << "1. ";
    p.mostrar();
    cout << "Total: 1 producto" << endl;
}

void Interprete (string cmd)
{
    if (cmd == "insertar") procesar_insertar();
    if (cmd == "palabras") procesar_palabras();
    if (cmd == "precios")  procesar_precios();
    if (cmd == "eliminar") procesar_eliminar();
    if (cmd == "producto") procesar_producto();
}