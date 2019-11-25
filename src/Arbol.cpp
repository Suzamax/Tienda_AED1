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
        if (r->getHijoIzquierdo() == nullptr)
            r->setHijoIzquierdo(new Nodo(p->getPrecio(), p));
        else r->setHijoIzquierdo(insertar(r->getHijoIzquierdo(), p));
    }
        //insertar(r->getHijoIzquierdo(), p);
    else if (p->getPrecio() > r->getPrecio())
    {
        if (r->getHijoDerecho() == nullptr)
            r->setHijoDerecho(new Nodo(p->getPrecio(), p));
        else r->setHijoDerecho(insertar(r->getHijoDerecho(), p));
    }
        //insertar(r->getHijoDerecho(), p);
    else // if (p->getPrecio() == r->getPrecio())
        r->getLista()->push_front(p);
    
    r = actualizarAltura(r);
    
    int eq = getAltura(r->getHijoIzquierdo()) - getAltura(r->getHijoDerecho());
    
    // Rotación doble a la ...
    if (eq > 1 && r->getHijoIzquierdo()->getPrecio() < p->getPrecio())
    {
        r->setHijoIzquierdo(RI(r->getHijoIzquierdo()));
        return RD(r);
    }
    // Rotación simple a la derecha
    else if(eq > 1 && r->getHijoIzquierdo()->getPrecio() > p->getPrecio())
        return RD(r);
    // Rotación simple a la izquierda
    else if(eq < -1 && r->getHijoDerecho()->getPrecio() < p->getPrecio())
        return RI(r);
    // Rotación doble a la ...
    else if(eq < -1 && r->getHijoDerecho()->getPrecio() > p->getPrecio())
    {
        r->setHijoDerecho(RI(r->getHijoDerecho()));
        return RI(r);
    }
    // Y si no...
    return r;
}

Nodo * Arbol::actualizarAltura(Nodo * n)
{
    n->setAltura(1 + max(getAltura(n->getHijoIzquierdo()), getAltura(n->getHijoDerecho())));
    return n;
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

Nodo * Arbol::RI (Nodo * n)
{
    Nodo * rd = n->getHijoDerecho();
    Nodo * rdi = rd->getHijoIzquierdo();
    
    n->setHijoDerecho(rdi);
    rd->setHijoIzquierdo(n);
    
    rd = actualizarAltura(rd);
    n = actualizarAltura(n);
    
    return rd;
}

Nodo * Arbol::RD (Nodo * n)
{
    Nodo * ri = n->getHijoIzquierdo();
    Nodo * rid = ri->getHijoDerecho();
    
    n->setHijoIzquierdo(rid);
    ri->setHijoDerecho(n);
    
    ri = actualizarAltura(ri);
    n = actualizarAltura(n);
    
    return ri;
}
