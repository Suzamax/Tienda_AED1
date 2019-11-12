#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include <array>
#include "Par.h"
using namespace std;

class TablaHash
{
    friend class DiccionarioProductos;
    private:
        // Tamaño de la tabla
        int max;
        // Palabras. Tamaño fijo de la tabla, redistribuible.
        list<Par<Producto*> > *T;
        int nE; // nº elementos
    public:
        TablaHash();
        ~TablaHash();
        void insertar(string w, Producto *nuevo); // Insertar un nuevo par
        void consultar(string w); // Consultar palabra
        int numElem(void) { return nE; }
        void reestructurar();
};

#endif //TIENDA_TABLAHASH_H