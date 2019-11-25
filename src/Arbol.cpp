#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}
Arbol::~Arbol() {}

void Arbol::insertar(Nodo * r, Producto *p)
{
    if (r == nullptr)
        r = new Nodo(p->getPrecio(), p);
    else if (p->getPrecio() < r->getPrecio())
    {
        if (r->getHijoIzquierdo() != nullptr) insertar(r->getHijoIzquierdo(), p);
        else r->setHijoIzquierdo(new Nodo(p->getPrecio(), p));
    }
    else if (p->getPrecio() > r->getPrecio())
    {
        if (r->getHijoDerecho() != nullptr) insertar(r->getHijoDerecho(), p);
        else r->setHijoDerecho(new Nodo(p->getPrecio(), p));
    }
    else // if (p->getPrecio() == r->getPrecio())
        r->getLista()->push_front(p);
}


list<Producto*> Arbol::precios(Nodo * r, float min, float max)
{
    if (r == nullptr)
    {
        list<Producto*> * l = new list<Producto*>();
        return *l;
    }
    if (r->getPrecio() < min && r->getHijoDerecho() != nullptr)
        return precios(r->getHijoDerecho(), min, max);
    else if (r->getPrecio() > max && r->getHijoIzquierdo() != nullptr)
        return precios(r->getHijoIzquierdo(), min, max);
    else
    {
        list<Producto*> *list1 = new list<Producto*>();
        list<Producto*>::iterator loops = list1->begin();
        while (loops != list1->end())
        {
            list1->push_front(*loops);
            loops++;
        }
        if (r->getHijoIzquierdo() != nullptr) list1->merge(precios(r->getHijoIzquierdo(), min, max), Utilidades::Comparador);
        if (r->getHijoDerecho() != nullptr) list1->merge(precios(r->getHijoDerecho(), min, max), Utilidades::Comparador);
        return *list1;
    }
}


