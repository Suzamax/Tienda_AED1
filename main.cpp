#include <iostream>
#include <list>
#include "Producto.cpp"
#include "Interprete.cpp"
#include "Diccionario.cpp"

using namespace std;

int main()
{
    string cmd;
    while (cin >> cmd) Interprete(cmd);
}