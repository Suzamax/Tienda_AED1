#ifndef TIENDA_UTILIDADES_H
#define TIENDA_UTILIDADES_H
#include <iostream>
#include <list>
#include "Producto.h"
using namespace std;

class Utilidades
{
private:
    static const int FNVprimo = 0x01000193;
    static const int FNVoffset = 0x811c9dc5;
public:
    static int FNV(string w, int s);
    static string tolow(string input);
    static int CalcPrimo(int p);
    static bool Comparador(Producto* & first, Producto* & second);
    static int Mostrar(list<Producto*> l);
};

#endif //TIENDA_UTILIDADES_H
