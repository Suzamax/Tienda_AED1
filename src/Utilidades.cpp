#include "Utilidades.h"

int Utilidades::FNV(string w, int s)
{
    unsigned int hash = FNVoffset;
    for (unsigned i = 0; i < w.length(); i++)
    {
        hash = hash * FNVprimo;
        hash = hash ^ w[i];
    }
    return hash % s;
}

string Utilidades::tolow(string input)
{
    string out;
    for (unsigned i = 0; i < input.length(); i++)
    {
        if (input[i] == (char) 0xC3){
            out.push_back(input[i++]);
            if ((input[i] >> 5 & 1) == 0)
            {
                input[i] |= 1 << 5;
                out.push_back(input[i]);
            }
        }
        else if (input[i] > 0x40 && input[i] < 0x5B) // MAYUS
        {
            input[i] |= 1 << 5;
            out.push_back(input[i]);
        }
        else out.push_back(input[i]);
    }
    return out;
}


bool Utilidades::Comparador (Producto* & first, Producto* & second)
{
    return (*first < *second);
}

int Utilidades::Mostrar(list<Producto*> l)
{
    int i = 0;
    l.sort(Utilidades::Comparador);
    l.unique();
    list<Producto*>::iterator loops = l.begin();
    while (loops != l.end())
    {
        Producto *p = *loops;
        cout << ++i << ". ";
        p->mostrar();
        loops++;
    }
    
    return i;
}
