#include "Interprete.h"

Interprete::Interprete()
{
}

Interprete::~Interprete()
{
}

void Interprete::obtener_comando(string cmd, DiccionarioProductos *dp)
{
    if (cmd == "insertar") Interprete::procesar_insertar(dp);
    //if (cmd == "palabras") Interprete::procesar_palabras();
    if (cmd == "precios")  Interprete::procesar_precios();
    if (cmd == "eliminar") Interprete::procesar_eliminar();
    if (cmd == "producto") Interprete::procesar_producto();
}


void Interprete::procesar_insertar(DiccionarioProductos *dp)
{
    Producto p;
    p.leer();
    dp->insertar(p);
    
}

void Interprete::procesar_precios()
{
    float min, max;
    cin >> min;
    cin >> max;
    cin.ignore(20, '\n');
    // ITERAR
}

//void Interprete::procesar_palabras(DiccionarioProductos *dp) {}

void Interprete::procesar_producto()
{
    unsigned long int id;
    cin >> id;
    // ITERAR (encontrar el producto que coincida en ID)
    // MOSTRAR
}

void Interprete::procesar_eliminar()
{
    unsigned long int id;
    cin >> id;

    // ITERAR
    // BORRAR DEL DP
}

/*
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

*/