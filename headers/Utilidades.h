#ifndef TIENDA_UTILIDADES_H
#define TIENDA_UTILIDADES_H
#include <iostream>
using namespace std;
/**
 * @brief Función de dispersión, usa FNV-1 de 32 bits.
 */
class Utilidades
{
private:
    static const int FNVprimo = 0x01000193;
    static const int FNVoffset = 0x811c9dc5;
public:
    static int FNV(string w, int s);
    static string tolow(string input);
    static int CalcPrimo(int p);
};

#endif //TIENDA_UTILIDADES_H
