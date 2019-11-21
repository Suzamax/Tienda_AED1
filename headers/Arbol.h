#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <list>
#include <sstream>
#include "Producto.h"
using namespace std;

/**
 * @brief Clase que define los nodos del árbol
 */

class Nodo
{
    private:
    Nodo *hijoizquierdo;
    Nodo *hijoderecho;
    double Precio;
    list<Producto*> lista;

    public:
    Nodo ();
    ~Nodo();
    double precio ();
    Nodo * getHijoIzquierdo();
    Nodo * getHijoDerecho();
    void insertarproducto (Producto *prod);

};

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
    void RSI (Nodo *&Nod);
    void RSD (Nodo *&Nod);
    void RDI (Nodo *&Nod);
    void RDD (Nodo *&Nod);

};

#endif