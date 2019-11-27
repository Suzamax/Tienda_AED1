#include "Arbol.h"

Arbol::Arbol() {}
Arbol::~Arbol() {}

int Arbol::getAlt(Nodo * n)
{
    if (n == nullptr) return 0;
    return n->getAlt();
}

Nodo * Arbol::insert(Nodo * r, Producto *p)
{
    if (r == nullptr)
        return new Nodo(p->getPrec(), p);
    else if (p->getPrec() < r->getPrecio())
    {
        if (r->izq == nullptr)
            r->izq = new Nodo(p->getPrec(), p);
        else r->izq = insert(r->izq, p);
    }
    else if (p->getPrec() > r->getPrecio())
    {
        if (r->der == nullptr)
            r->der = new Nodo(p->getPrec(), p);
        else r->der = insert(r->der, p);
    }
    else r->getList()->push_front(p);
    
    r = actAlt(r);
    
    int eq = getAlt(r->izq) - getAlt(r->der);
    
    if (eq > 1 && r->izq != nullptr && r->izq->getPrecio() < p->getPrec())
    {
        r->izq = RI(r->izq);
        return RD(r);
    }
    else if(eq > 1 && r->izq != nullptr && r->izq->getPrecio() > p->getPrec())
        return RD(r);
    else if(eq < -1 && r->der != nullptr && r->der->getPrecio() < p->getPrec())
        return RI(r);
    else if(eq < -1 && r->der != nullptr && r->der->getPrecio() > p->getPrec())
    {
        r->der = RD(r->der);
        return RI(r);
    }
    return r;
}

Nodo * Arbol::actAlt(Nodo * n)
{
    n->setAltura(1 + max(getAlt(n->izq), getAlt(n->der)));
    return n;
}

list<Producto*> * Arbol::precios(Nodo * r, float min, float max)
{
    if (r == nullptr) return new list<Producto*>();
    else if (r->getPrecio() < min && r->der != nullptr)
        return precios(r->der, min, max);
    else if (r->getPrecio() > max && r->izq != nullptr)
        return precios(r->izq, min, max);
    else if (r->getPrecio() >= min && r->getPrecio() <= max)
    {
        list<Producto*> * l = new list<Producto*>();
        list<Producto*>::iterator loops = r->getList()->begin();
        while (loops != r->getList()->end())
            l->push_front(*loops++);
        if (r->izq != nullptr) l->merge(*precios(r->izq, min, max), Utilidades::Comparador);
        if (r->der != nullptr) l->merge(*precios(r->der, min, max), Utilidades::Comparador);
        return l;
    }
    else return new list<Producto*>();
}

Nodo * Arbol::RI (Nodo * n)
{
    Nodo * rd = n->der;
    Nodo * rdi = rd->izq;
    n->der = rdi;
    n = actAlt(n);
    rd->izq = n;
    return actAlt(rd);
}

Nodo * Arbol::RD (Nodo * n)
{
    Nodo * ri = n->izq;
    Nodo * rid = ri->der;
    n->izq = rid;
    n = actAlt(n);
    ri->der = n;
    return actAlt(ri);
}
