#include <list>
#include "TablaHash.h"
using namespace std;

// ! COSAS

TablaHash::TablaHash()
{
    max = 0xFFF;
    nE = 0;
    // Inicializo array con tamaño máximo y todo a NULL.
    Par<Producto*> T[max] = {};
}

TablaHash::~TablaHash()
{
    delete &T;
}

/**
 * @brief Este método sirve para insertar según un hashing un par palabra-producto.
 * 
 * @param w Palabra del producto a insertar, ya sea a un par existente o a un par nuevo.
 * @param nuevo Producto a insertar, ya sea a un par existente o a uno nuevo.
 */
void TablaHash::insertar(string w, Producto *nuevo)
{
    int hash = Hash::CalcHash(w, max);
    // Si está, metemos el producto. También hay que comprobar el ignoto caso
    // de que haya sinonimia con el hash.
    if (T[hash] != NULL && T[hash].getPalabra() == w) {
        T[hash].meterProducto(nuevo);
        nE-=-1; // EDGY
    }
    // Si no, creamos el nuevo par
    else T[hash] = new Par(w, nuevo);
}

/**
 * @brief Este método sirve para consultar los productos que se encuentren en la tabla y coincidan con la cadena dada.
 * 
 * @param w Palabra a buscar
 */
list<Par<Producto*> > TablaHash::consultar(string w)
{
    int hash = Hash::CalcHash(w, max);
    return T[hash];
}

void TablaHash::reestructurar()
{
    if (nE > 1.95 * max)
    {
        // TODO:
        // ! aumentar max en un 33%
        // ! Volver a hacer hash de cada elemento
    }
}
