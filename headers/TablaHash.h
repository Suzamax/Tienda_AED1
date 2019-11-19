#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include <array>
#include "Par.h"
#include "Utilidades.h"
using namespace std;

class TablaHash
{
private:
    // Tamaño de la tabla
    int max;
    // Palabras con sus productos. Tamaño variable de la tabla, redistribuible.
    // Nota para los profesores: No tiene sentido usar un list en este caso. Mejor un ARRAY.
    int nE; // nº elementos
    Par<Producto*> *T;
public:
    TablaHash();
    ~TablaHash();
    void insertar(string w, Producto *nuevo); // Insertar un nuevo par
    Par<Producto*>* consultar(string w); // Consultar palabra
    int getNumElem() { return nE; }
    int getMax() { return max; }
    void reestructurar(); // Rehash
};

#endif //TIENDA_TABLAHASH_H
