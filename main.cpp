#include <iostream>
#include <list>
#include "Producto.h"
#include "Interprete.h"
#include "Diccionario.h"

using namespace std;

int main()
{
    DiccionarioProductos *DP = new DiccionarioProductos();
    string cmd;
    Interprete *shell = new Interprete(DP);
    while (cin >> cmd) shell->obtener_comando(cmd);

    delete shell;

}