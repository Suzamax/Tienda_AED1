#include <iostream>
#include <list>
#include "Producto.h"
#include "Interprete.h"
#include "Diccionario.h"

using namespace std;

/**
 * @brief Programa principal. Crea un diccionario de productos y un intérprete.
 * Mientras el intérprete reciba comandos, se ejecutará este programa.
 * 
 * @return int Devuelve cero si se termina de ejecutar con éxito.
 */
int main()
{
    DiccionarioProductos *DP = new DiccionarioProductos();
    string cmd;
    Interprete *shell = new Interprete(DP);
    while (cin >> cmd) shell->obtener_comando(cmd);

    delete shell;
    delete DP;
}