#include "Diccionario.h"

DiccionarioProductos::DiccionarioProductos() {};
DiccionarioProductos::~DiccionarioProductos() {};

/**
 * @brief Método para insertar un producto dado en el diccionario. También ordena la lista.
 * 
 * @param p Producto a insertar.
 */
void DiccionarioProductos::insertar(Producto p) {
    lista.push_front(p);
    // Obtener palabras del producto dado
    Producto *p2 = &lista.front();
    // TODO Añadiir el producto a la tabla.
    // tabla.push
    contador++;
    // ! Comento porque luego meteré el orden en algún lado...
    /*lista.sort([] (const Producto & a, const Producto & b) { 
        return (a.getID() < b.getID());
    });*/
    cout << contador << " productos" << endl;
}

/**
 * @brief Método para eliminar un producto del diccionario y la tabla.
 * 
 * @param id Identificador del producto a eliminar
 */
void DiccionarioProductos::eliminar(unsigned long int id) {
    list<Producto>::iterator loops = lista.begin();

    // ! TODO Eliminar el producto de la tabla

    while(loops != lista.end() && loops->getID() != id) loops++;
    if (loops != lista.end()) // OR loops->getID() == id
    {
        lista.erase(loops);
        contador--;
    }

    cout << contador << " productos" << endl;
}

/**
 * @brief Método para encontrar un producto en base a su identificador.
 * 
 * @param id Identificador del producto a buscar.
 */
void DiccionarioProductos::producto(unsigned long int id)
{
    cout << "producto " << id << endl;
    list<Producto>::iterator loops = lista.begin();

    while (loops != lista.end() && loops->getID() != id) loops++;
    if (loops != lista.end()){
        cout << "1. ";
        loops->mostrar();
    } 

    cout << "Total: "<< (loops != lista.end()) << " productos" << endl;
}

/**
 * @brief 
 * 
 * @param min Precio mínimo
 * @param max Precio máximo
 */
void DiccionarioProductos::precios(double min, double max)
{
    cout << "precios " << min << " " << max << endl;
    int items = 0;

    list<Producto> listaOrd = lista;
    listaOrd.sort([] (const Producto & a, const Producto & b) { 
        return (a.getID() < b.getID());
    });
    list<Producto>::iterator loops = listaOrd.begin();

    while(loops != listaOrd.end())
    {
        
        if (loops->getPrecio() >= min && loops->getPrecio() <= max)
        {
            cout << ++items << ". ";
            loops->mostrar();
        }
        loops++;
    }
    cout << "Total: " << items << " productos" << endl;
}

