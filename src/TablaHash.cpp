#include <list>
#include <algorithm>
#include "TablaHash.h"
// #include "math.h" // No hace falta, hacemos un parsing a Entero
using namespace std;

// ! COSAS

TablaHash::TablaHash()
{
    // Max debe ser PREMOH.
    max = 0x18000; //Utilidades::CalcPrimo(0xFFFF);
    nE = 0;
    // Inicializo array con tamaño máximo y todo vacío.
    T = new list<Par<Producto*> >[max];
}

TablaHash::~TablaHash()
{
    delete[] T;
}

/**
 * @brief Este método sirve para insertar según un hashing un par palabra-producto.
 *
 * @param w Palabra del producto a insertar, ya sea a un par existente o a un par nuevo.
 * @param nuevo Producto a insertar, ya sea a un par existente o a uno nuevo.
 */
void TablaHash::insertar(string w, Producto * nuevo)
{
    unsigned hash = Utilidades::FNV(w, max);
    
    // Si está, metemos el producto. También hay que comprobar el ignoto caso
    // de que haya sinonimia con el hash. Todo a la vez.
    list<Par<Producto*> >::iterator loops = T[hash].begin();
    while (loops != T[hash].end() && loops->getPalabra() != w) loops++;
        
    if (loops != T[hash].end())
    {
        loops->meterProducto(nuevo);
        nE++;
    }

    // Si no, creamos el nuevo par
    else {
        Par<Producto*> *par = new Par<Producto*>(w, nuevo);
        T[hash].push_back(*par);
        nE++;
    }
    // reestructurar();
     
}

/**
 * @brief Este método sirve para consultar los productos que se encuentren en la tabla y coincidan con la cadena dada.
 *
 * @param hash Hash a buscar
 */
Par<Producto*> * TablaHash::consultar(unsigned hash, string w) const
{
    list<Par<Producto*> >::iterator loops = T[hash].begin();
    while (loops != T[hash].end() && loops->getPalabra() != w) loops++;
    if (loops != T[hash].end()) return &(*loops);
    return NULL;
}


/**
 * @brief Método para reestructurar
 */
void TablaHash::reestructurar()
{
    /*
    if (nE > (2 * max))
    {
        unsigned b = max;
        // Aumentar max al siguiente primo después de 2*max
        max = Utilidades::CalcPrimo(max);
        // Hacemos una tabla con el nuevo tamaño e insertamos todos los pares en ella
        Par<Producto*> * TAux = new Par<Producto*>[max];
        Par<Producto*> * aux = nullptr;
        for (unsigned i = 0; i < max; i++)
        {
            TAux[i] = * aux;
        }
        //unsigned hash, hash2;
        for (unsigned i = 0; i < b; i++)
		{
            * aux = T[i];
            if (aux != nullptr)
            {
                // TODO here
                
            }
        }
        // Cambiamos la lista de nuestro objeto por la lista nueva
        // ! Falta eliminar memoria contenida en T
		delete[] T; // Liberamos tabla
        T = TAux; // Metemos la nueva tabla
    }
     */
}
