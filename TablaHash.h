#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include "Par.h"
using namespace std;

class TablaHash
{
    friend class DiccionarioProductos;
    private:
        // Tamaño de la tabla INICIAL
        static const int M = 512;
        // Palabras. Tamaño fijo de la tabla, redistribuible.
        list<Par<Producto*> > pares[M];
        int nE; // nº elementos
    public:
        TablaHash();
        ~TablaHash();
        void insertar(string w, Producto *nuevo);
        void consultar(string w);
        int numElem(void) { return nE; }
};

#endif //TIENDA_TABLAHASH_H