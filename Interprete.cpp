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
    //
}

/**
 * @brief Este método obtiene cada comando que procesará otro método de este intérprete.
 * 
 * @param cmd Un comando, siendo estos: insertar, palabras, precios, eliminar y producto.
 */
void Interprete::obtener_comando(string cmd)
{
    if (cmd == "insertar") Interprete::procesar_insertar();
    //if (cmd == "palabras") Interprete::procesar_palabras();
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
    Producto p;
    p.leer();
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

//void Interprete::procesar_palabras() {}


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