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
        int max = 512;
        // Palabras. Tamaño fijo de la tabla, redistribuible.
        list<Par<Producto*> > pares[];
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