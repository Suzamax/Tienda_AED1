#include "Diccionario.h"

DiccionarioProductos::DiccionarioProductos() {};
DiccionarioProductos::~DiccionarioProductos() {};

/**
 * @brief Método para insertar un producto dado en el diccionario. También ordena la lista.
 *
 * @param p Producto a insertar.
 */
void DiccionarioProductos::insertar(Producto * p) {
    lista.push_front(*p);
    // Obtener palabras del producto dado
    string s; // Un string auxiliar.
    istringstream iss(p->getNombre());
    while (iss >> s) tabla.insertar(Utilidades::tolow(s), p);
    iss.clear(); // Esto se hace para quitarme de enmedio el primer string al llegar a EOL.
    iss.str(p->getDesc()); // Redefino el string a usar.
    while (iss >> s) tabla.insertar(Utilidades::tolow(s), p);
    contador++;
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
 * @brief Método para encontrar los productos con precios entre los dos dados.
 *
 * @param min Precio mínimo
 * @param max Precio máximo
 */
void DiccionarioProductos::precios(double min, double max)
{
    cout << "precios " << min << " " << max << endl;
    int items = 0;
    
    list<Producto>::iterator loops = lista.begin();

    while(loops != lista.end())
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

void DiccionarioProductos::sortProductos()
{
    // ! Comento porque luego meteré el orden en algún lado...
    /*lista.sort([] (const Producto & a, const Producto & b) {
        return (a.getID() < b.getID());
    });*/
}
