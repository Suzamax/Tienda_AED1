#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include <array>
#include <list>
#include "Par.h"
#include "Utilidades.h"
using namespace std;

class TablaHash
{
private:
    // Tamaño de la tabla
    unsigned max;
    // Palabras con sus productos. Tamaño variable de la tabla, redistribuible.
    unsigned nE; // nº elementos
    list<Par<Producto*> > * T;
public:
    TablaHash();
    ~TablaHash();
    void insertar(string w, Producto *nuevo); // Insertar un nuevo par
    Par<Producto*> * consultar(unsigned hash, string w) const; // Consultar palabra
    unsigned getNumElem() { return nE; }
    unsigned getMax() { return max; }
    void reestructurar(); // Rehash
};

#endif //TIENDA_TABLAHASH_H
