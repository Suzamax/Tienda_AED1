#include <list>
#include <algorithm>
#include "TablaHash.h"
using namespace std;

TablaHash::TablaHash()
{
    max = 0x18000;
    nE = 0;
    T = new list<Par<Producto*> >[max];
}

TablaHash::~TablaHash()
{
    delete[] T;
}

void TablaHash::insertar(string w, Producto * nuevo)
{
    unsigned hash = Utilidades::FNV(w, max);

    list<Par<Producto*> >::iterator loops = T[hash].begin();
    while (loops != T[hash].end() && loops->getPalabra() != w) loops++;
        
    if (loops != T[hash].end())
    {
        loops->meterProducto(nuevo);
        nE++;
    }
    else {
        Par<Producto*> *par = new Par<Producto*>(w, nuevo);
        T[hash].push_back(*par);
        nE++;
    }
     
}

Par<Producto*> * TablaHash::consultar(unsigned hash, string w) const
{
    list<Par<Producto*> >::iterator loops = T[hash].begin();
    while (loops != T[hash].end() && loops->getPalabra() != w) loops++;
    if (loops != T[hash].end()) return &(*loops);
    return NULL;
}
