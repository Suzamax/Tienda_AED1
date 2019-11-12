#include <list>
#include "TablaHash.h"
using namespace std;

// ! COSAS

TablaHash::TablaHash()
{
    max = 0xFFF;
    nE = 0;
    T = new list<Par<Producto*> >[max];
}

TablaHash::~TablaHash()
{
    delete T;
}

/**
 * @brief Este método sirve para insertar según un hashing un par palabra-producto.
 * 
 * @param w Palabra del producto a insertar, ya sea a un par existente o a un par nuevo.
 * @param nuevo Producto a insertar, ya sea a un par existente o a uno nuevo.
 */
void TablaHash::insertar(string w, Producto *nuevo)
{
    // ! i = hash(string)
    // Si está w, entonces nuevo se mete a un par ya existente
    // ! list<Par<Producto*> >::iterator loops = pares[i].begin();

    // ! while(loops != pares.end() && loops->get() != w) loops++;
    // Si no, creamos el nuevo par
    // ! else pares[]
}

/**
 * @brief Este método sirve para consultar los productos que se encuentren en la tabla y coincidan con la cadena dada.
 * 
 * @param w Palabra a buscar
 */
void TablaHash::consultar(string w)
{
    
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