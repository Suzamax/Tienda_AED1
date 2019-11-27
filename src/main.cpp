#include <iostream>
#include <list>
#include "Producto.h"
#include "Interprete.h"
#include "Diccionario.h"

using namespace std;

int main()
{
    DiccP *DP = new DiccP();
    string cmd;
    Interprete *shell = new Interprete(DP);
    while (cin >> cmd) shell->getCmd(cmd);
    delete shell;
    delete DP;
}
