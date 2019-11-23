#ifndef TIENDA_ARBOL_H
#define TIENDA_ARBOL_H

#include <iostream>
#include <list>
#include <sstream>
#include "Nodo.h"

using namespace std;

/**
 * @brief Clase en la que se almacena un árbol que incluye en sus nodos el precio correspondiente a los productos
 */

// ! De momento he tomado como correcto usar un árbol AVL e incluir las rotaciones dentro de la clase Arbol

class Arbol
{
private:
    Nodo *raiz;
public:
    Arbol ();
    ~Arbol();
    void insertar (Producto *prod);
    void precios (double min, double max);
    // Métodos para redistribuir el árbol
    void RSI (Nodo *&Nod);
    void RSD (Nodo *&Nod);
    void RDI (Nodo *&Nod);
    void RDD (Nodo *&Nod);

};

#endif
