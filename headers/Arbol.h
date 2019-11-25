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
public:
    Arbol();
    ~Arbol();
    int getAltura(Nodo * n);
    /// Inserta un producto, llamando a la función de forma recursiva.
    /// @param raiz Raíz del árbol
    /// @param prod Producto a añadir
    Nodo * insertar(Nodo * raiz, Producto *prod);
    Nodo * actualizarAltura(Nodo * n);
    /// Evalúa nodos para obtener aquellos entre dos precios.
    /// @param min Precio mínimo
    /// @param max Precio máximo
    list<Producto*> precios(Nodo * raiz, float min, float max);
    
    // Rotaciones
    Nodo * RI(Nodo * n);
    Nodo * RD(Nodo * n);
};

#endif
