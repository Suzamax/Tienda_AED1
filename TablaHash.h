#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include "Par.h"
using namespace std;

class TablaHash
{
    friend class DiccionarioProductos;
    private:
        // Palabras
        
        int nE; // nº elementos
    public:
        TablaHash();
        ~TablaHash();
        void insertar(string w, Producto *nuevo);
        void consultar(string w);
        int numElem(void) { return nE; }
};

#endif //TIENDA_TABLAHASH_H