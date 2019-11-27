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
    unsigned max;
    unsigned nE; // nº elementos
    list<Par<Producto*> > * T;
public:
    TablaHash();
    ~TablaHash();
    void insertar(string w, Producto *nuevo); // Insertar un nuevo par
    Par<Producto*> * consultar(unsigned hash, string w) const; // Consultar palabra
    unsigned getNumElem() { return nE; }
    unsigned getMax() { return max; }
};

#endif //TIENDA_TABLAHASH_H
