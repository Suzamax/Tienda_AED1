#include "Diccionario.h"

DiccionarioProductos::DiccionarioProductos() {};
DiccionarioProductos::~DiccionarioProductos() {};


void DiccionarioProductos::insertar(Producto p) {
    lista.push_front(p);
    // Obtener palabras del producto dado
    Producto *p2 = &lista.front();
    // ! TODO
    contador++;
    lista.sort([] (const Producto & a, const Producto & b) { 
        return (a.getID() < b.getID());
    });
    cout << contador << " productos" << endl;
}

void DiccionarioProductos::eliminar(unsigned long int id) {
    list<Producto>::iterator loops = lista.begin();

    while(loops != lista.end() && loops->getID() != id) loops++;
    if (loops != lista.end()) // OR loops->getID() == id
    {
        lista.erase(loops);
        contador--;
    }

    cout << contador << " productos" << endl;
}

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

void DiccionarioProductos::precios(double min, double max)
{
    cout << "precios " << min << " " << max << endl;
    list<Producto>::iterator loops = lista.begin();
    int items = 0;

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

// TODO cosas

