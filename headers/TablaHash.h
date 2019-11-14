#ifndef TIENDA_TABLAHASH_H
#define TIENDA_TABLAHASH_H

#include <iostream>
#include <array>
#include "Par.h"
#include "Hash.h"
using namespace std;

class TablaHash
{
    friend class DiccionarioProductos;
    private:
        // Tamaño de la tabla
        int max;
        // Palabras. Tamaño fijo de la tabla, redistribuible.
        // Nota para los profesores: No tiene sentido usar un list en este caso. Mejor un ARRAY.
        Par<Producto*> *T;
        int nE; // nº elementos
    public:
        TablaHash();
        ~TablaHash();
        void insertar(string w, Producto *nuevo); // Insertar un nuevo par
        list<Par<Producto*> > consultar(string w); // Consultar palabra
        int numElem(void) { return nE; }
        void reestructurar();
};

#endif //TIENDA_TABLAHASH_H
