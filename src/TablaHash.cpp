#include <list>
#include "TablaHash.h"
// #include "math.h" // No hace falta, hacemos un parsing a Entero
using namespace std;

// ! COSAS

TablaHash::TablaHash()
{
    max = 0xFFF;
    nE = 0;
    // Inicializo array con tamaño máximo y todo a NULL.
    T = new Par<Producto*>*[max] {NULL};
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
    if (T[hash] != NULL && T[hash]->getPalabra() == w) {
        T[hash]->meterProducto(nuevo);
        nE-=-1; // EDGY, innovador.
    }
    // Si no, creamos el nuevo par
    else {
        Par<Producto*> * par = new Par<Producto*>(w, nuevo);
        T[hash] = par;
    }
}

/**
 * @brief Este método sirve para consultar los productos que se encuentren en la tabla y coincidan con la cadena dada.
 * 
 * @param w Palabra a buscar
 */
Par<Producto*> TablaHash::consultar(string w)
{
    int hash = Hash::CalcHash(w, max);
    return *T[hash];
}

/**
 * @brief Método para reestructurar
 */
void TablaHash::reestructurar()
{
    if (nE > 1.95 * max)
    {
        // Aumentar max en un 33%
        float val = max * 1.33;
        max = (int) val; // A esto me refiero, hacer un parsing.
        // Hacemos una tabla con el nuevo tamaño e insertamos todos los pares en ella
        Par<Producto*> ** TAux = new Par<Producto*>*[max] {NULL};
        Par<Producto*> * aux;
        int hash;
        for (int i = 0; i < nE; i++)
		{
            aux = T[i];
            hash = Hash::CalcHash(aux->getPalabra(), max);
            TAux[hash] = aux;
        }
        // Cambiamos la lista de nuestro objeto por la lista nueva
        // ! Falta eliminar memoria contenida en T
		delete T; // Liberamos el kraken
        T = TAux; // Metemos la nueva tabl
    }
}
