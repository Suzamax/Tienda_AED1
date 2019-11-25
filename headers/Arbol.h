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
    Nodo * raiz;
public:
    Arbol();
    ~Arbol();
    // Métodos para redistribuir el árbol
    /// Inserta un producto, llamando a la función de forma recursiva.
    /// @param prod Producto a añadir
    void insertar(Nodo * raiz, Producto *prod);
    /// Evalúa nodos para obtener aquellos entre dos precios.
    /// @param min Precio mínimo
    /// @param max Precio máximo
    list<Producto*> precios(Nodo * raiz, float min, float max);
    // Rotaciones
    void RSI();
    void RSD();
    void RDI();
    void RDD();
};

#endif
