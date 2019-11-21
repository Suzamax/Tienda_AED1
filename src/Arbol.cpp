#include "Arbol.h"

Nodo::Nodo() {};
Nodo::~Nodo() {};

double Nodo::precio(){
    return Precio;
}

void Nodo::insertarproducto(Producto *prod) {
    lista.push_front(prod);
}

Nodo* Nodo::getHijoIzquierdo(){
    return hijoizquierdo;
}

Nodo* Nodo::getHijoDerecho(){
    return hijoderecho;
}

Arbol::Arbol() {};
Arbol::~Arbol() {};

void Arbol::insertar (Producto *prod){
/*
    Nodo *n = raiz;
     // Recorremos un árbol para ver si hay algún nodo con el mismo precio que nuestro producto
    while (n != nullptr){
        //Si encontramos un nodo, insertamos el producto en su lista
        if(n->precio() == prod->getPrecio()){
            n->insertarproducto(prod);
            break;
        }
        // Si esto no ocurre avanzamos en el árbol
        else{
            if(n->getHijoDerecho()->precio() < prod->getPrecio()) {
                n = n->getHijoDerecho();
            }
            else{
                n = n->getHijoIzquierdo();
            }
        } 
    }
    */
}