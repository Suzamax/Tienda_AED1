#include "Arbol.h"

Arbol::Arbol() {}
Arbol::~Arbol() {}

int Arbol::getAltura(Nodo * n)
{
    if (n == nullptr) return 0;
    return n->getAltura();
}

Nodo * Arbol::insertar(Nodo * r, Producto *p)
{
    if (r == nullptr)
        return new Nodo(p->getPrecio(), p);
    else if (p->getPrecio() < r->getPrecio())
    {
        if (r->izq == nullptr)
            r->izq = new Nodo(p->getPrecio(), p);
        else r->izq = insertar(r->izq, p);
    }
        //insertar(r->getHijoIzquierdo(), p);
    else if (p->getPrecio() > r->getPrecio())
    {
        if (r->der == nullptr)
            r->der = new Nodo(p->getPrecio(), p);
        else r->der = insertar(r->der, p);
    }
        //insertar(r->getHijoDerecho(), p);
    else // if (p->getPrecio() == r->getPrecio())
        r->getLista()->push_front(p);
    
    r = actualizarAltura(r);
    
    int eq = getAltura(r->izq) - getAltura(r->der);
    
    // Rotación doble a la ...
    if (eq >= 1 && r->izq->getPrecio() < p->getPrecio())
    {
        r->izq = RI(r->izq);
        return RD(r);
    }
    // Rotación simple a la derecha
    else if(eq >= 1 && r->izq->getPrecio() > p->getPrecio())
        return RD(r);
    // Rotación simple a la izquierda
    else if(eq <= -1 && r->der->getPrecio() < p->getPrecio())
        return RI(r);
    // Rotación doble a la ...
    else if(eq <= -1 && r->der->getPrecio() > p->getPrecio())
    {
        r->der = RD(r->der);
        return RI(r);
    }
    // Y si no...
    return r;
}

Nodo * Arbol::actualizarAltura(Nodo * n)
{
    n->setAltura(1 + max(getAltura(n->izq), getAltura(n->der)));
    return n;
}

list<Producto*> Arbol::precios(Nodo * r, float min, float max)
{
    list<Producto*> * l = new list<Producto*>();

    if (r == nullptr) return *l;

    if (r->getPrecio() < min && r->der != nullptr)
        return precios(r->der, min, max);
    else if (r->getPrecio() > max && r->izq != nullptr)
        return precios(r->izq, min, max);
    else if (r->getPrecio() >= min && r->getPrecio() <= max)
    {
        list<Producto*>::iterator loops = r->getLista()->begin();
        while (loops != r->getLista()->end())
        {
            l->push_front(*loops);
            loops++;
        }
        if (r->izq != nullptr) l->merge(precios(r->izq, min, max), Utilidades::Comparador);
        if (r->der != nullptr) l->merge(precios(r->der, min, max), Utilidades::Comparador);
        return *l;
    }
    else return *l;
}

Nodo * Arbol::RI (Nodo * n)
{
    Nodo * rd = n->der;
    Nodo * rdi = rd->izq;
    
    n->der = rdi;
    rd->izq = n;
    
    rd = actualizarAltura(rd);
    n = actualizarAltura(n);
    
    return rd;
}

Nodo * Arbol::RD (Nodo * n)
{
    Nodo * ri = n->izq;
    Nodo * rid = ri->der;
    
    n->izq = rid;
    ri->der = n;
    
    ri = actualizarAltura(ri);
    n = actualizarAltura(n);
    
    return ri;
}
