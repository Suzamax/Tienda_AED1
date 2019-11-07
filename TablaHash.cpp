#include <list>
#include "TablaHash.h"
using namespace std;

// ! COSAS

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
    // ! else pares.push_front()
}

/**
 * @brief Este método sirve para consultar los productos que se encuentren en la tabla y coincidan con la cadena dada.
 * 
 * @param w Palabra a buscar
 */
void TablaHash::consultar(string w)
{
    
}