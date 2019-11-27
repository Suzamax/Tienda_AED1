#ifndef TIENDA_INTERPRETE_H
#define TIENDA_INTERPRETE_H

#include <iostream>
#include "Diccionario.h"
#include "Producto.h"
using namespace std;

class Interprete
{
private:
    DiccP *dp;
public:
    Interprete(DiccP *dic);
    ~Interprete();
    void getCmd(string c);
    void pInsertar();
    void pPalabras();
    void pPrecios();
    void pEliminar();
    void pProducto();
};



#endif //TIENDA_INTERPRETE_H
