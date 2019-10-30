#include <iostream>
#include <list>
#include "Producto.h"
#include "Interprete.h"
#include "Diccionario.h"

using namespace std;

int main()
{
    DiccionarioProductos DP;
    string cmd;
    Interprete shell;
    while (cin >> cmd) shell.obtener_comando(cmd, &DP);

}