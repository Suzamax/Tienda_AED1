#include "Diccionario.h"

DiccionarioProductos::DiccionarioProductos() {};
DiccionarioProductos::~DiccionarioProductos() {};

/**
 * @brief Conversor de palabras a minúsculas
 * @param input Una palabra
 * @return string Palabra en minúsculas
 */
string DiccionarioProductos::tolow(string input)
{
    string out;
    for (unsigned i = 0; i < input.length(); i++)
    {
        if (input[i] == (char) 0xC3){
            out.push_back(input[i++]);
            if ((input[i] >> 5 & 1) == 0)
            {
                input[i] |= 1 << 5;
                out.push_back(input[i]);
            }
        }
        else if (input[i] > 0x40 && input[i] < 0x5B) // MAYUS
        {
            input[i] |= 1 << 5;
            out.push_back(input[i]);
        }
        else out.push_back(input[i]);
    }
    return out;
}


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
    string s; // Un string auxiliar.
    istringstream iss(p2->getNombre());
    while (iss >> s) tabla.insertar(tolow(s), p2);
    iss.clear(); // Esto se hace para quitarme de enmedio el primer string al llegar a EOL.
    iss.str(p2->getDesc()); // Redefino el string a usar.
    while (iss >> s) tabla.insertar(tolow(s), p2);
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
