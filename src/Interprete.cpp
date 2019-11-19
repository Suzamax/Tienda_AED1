#include "Interprete.h"

// Para simplificar, llamaré método a las funciones y procedimientos que alberga la clase.

/**
 * @brief Construye un nuevo intérprete.
 *
 * @param dic Diccionario de productos en el cual se van a almacenar los productos.
 */
Interprete::Interprete(DiccionarioProductos *dic)
{
    dp = dic;
}

/**
 * @brief Destruye el intérprete.
 *
 */
Interprete::~Interprete()
{
    // Nada...
}

/**
 * @brief Este método obtiene cada comando que procesará otro método de este intérprete.
 *
 * @param cmd Un comando, siendo estos: insertar, palabras, precios, eliminar y producto.
 */
void Interprete::obtener_comando(string cmd)
{
    if (cmd == "insertar") Interprete::procesar_insertar();
    if (cmd == "palabras") Interprete::procesar_palabras();
    if (cmd == "precios")  Interprete::procesar_precios();
    if (cmd == "eliminar") Interprete::procesar_eliminar();
    if (cmd == "producto") Interprete::procesar_producto();
}

/**
 * @brief Este método lee "insertar" y a continuación inserta el producto leído en el diccionario.
 *
 */
void Interprete::procesar_insertar()
{
    Producto *p = new Producto();
    p->leer();
    dp->insertar(p);
    
}

/**
 * @brief Obtiene dos precios y evalúa en el diccionario qué productos se incluyen entre el mínimo y máximo.
 *
 */
void Interprete::procesar_precios()
{
    double min, max;
    cin >> min;
    cin >> max;
    cin.ignore(20, '\n');
    dp->precios(min, max);
}

/**
 * @brief Buscar productos por la palabra dada, y los muestra.
 */
void Interprete::procesar_palabras() {
    string palabra;
    cin >> palabra;
    cout << "palabras " << palabra << endl;
    palabra = Utilidades::tolow(palabra);
    // Se obtienen los productos de la palabra.
    TablaHash *tabla = dp->getTabla();
    Par<Producto*> *par = tabla->consultar(palabra);
    // Hacer esto si el par es válido
    if (par->getPalabra() == palabra)
    {
        list<Producto*> *lista = par->getList();
        lista->sort([] (const Producto *a, const Producto *b) {
            return (a->getID() < b->getID());
        });
        list<Producto*>::iterator loops = lista->begin();
        int i = 0;
        while (loops != lista->end())
        {
            Producto *p = *loops;
            cout << ++i << ". ";
            p->mostrar();
            loops++;
        }
        cout << "Total: " << i << " productos" << endl;
    }
    else cout << "Total: 0 productos" << endl;
}


/**
 * @brief Muestra un producto especificado por el identificador dado.
 *
 */
void Interprete::procesar_producto()
{
    unsigned long int id;
    cin >> id;
    dp->producto(id);
}

/**
 * @brief Destruye el producto especificado por el identificador dado.
 *
 */
void Interprete::procesar_eliminar()
{
    unsigned long int id;
    cin >> id;
    dp->eliminar(id);
}
