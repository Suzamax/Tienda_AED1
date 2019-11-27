#include "Diccionario.h"

DiccP::DiccP() {
    arbol = new Arbol();
    raiz = nullptr;
}

DiccP::~DiccP() {
    delete arbol;
    delete raiz;
}

void DiccP::insertar(Producto * p) {
    lista.push_front(*p);
    string s;
    istringstream iss(p->getNombre());
    while (iss >> s) tabla.insertar(Utilidades::tolow(s), p);
    iss.clear();
    iss.str(p->getDesc());
    while (iss >> s) tabla.insertar(Utilidades::tolow(s), p);
    contador++;
    raiz = arbol->insert(raiz, p);
    cout << contador << " productos" << endl;
}

void DiccP::eliminar(unsigned long int id) {
    list<Producto>::iterator loops = lista.begin();

    while(loops != lista.end() && loops->getID() != id) loops++;
    if (loops != lista.end())
    {
        lista.erase(loops);
        contador--;
    }
    
    cout << contador << " productos" << endl;
}

void DiccP::producto(unsigned long int id)
{
    cout << "producto " << id << endl;
    list<Producto>::iterator loops = lista.begin();

    while (loops != lista.end() && loops->getID() != id) loops++;
    if (loops != lista.end()){
        cout << "1. ";
        loops->mostrar();
    } 

    cout << "Total: " << (loops != lista.end()) << " productos" << endl;
}

void DiccP::precios(double min, double max)
{
    cout << "precios " << min << " " << max << endl;
    int i = 0;
    
    list<Producto*> * l = arbol->precios(raiz, min, max);
    i = Utilidades::Mostrar(*l);
    delete l;
    cout << "Total: " << i << " productos" << endl;
}
