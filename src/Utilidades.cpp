#include "Utilidades.h"

/**
 * @brief Función de dispersión. FNV-1
 *
 * @param w Palabra a la que "hashear"
 * @return int Hash
 */
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

int Utilidades::CalcPrimo(int p)
{
    int i, j = 2;
    for(i = p + 1; i < (p * 2); i++)
    {
        j = 2;
        while (j < i && i % j != 0) j++;
        if (i == j) return i;
    }
    return 0;
}


/**
 * @brief Conversor de palabras a minúsculas
 * @param input Una palabra
 * @return string Palabra en minúsculas
 */
string Utilidades::tolow(string input)
{
    string out;
    for (unsigned i = 0; i < input.length(); i++)
    {
        if (input[i] == (char) 0xC3){
            out.push_back(input[i++]);
            // Tengo que usar un switch, tengo otra solución que imprimiría calçot en lugar de calÇot
            switch(input[i])
            {
                case (char) 0x81: out.push_back((char) 0xA1); break;
                case (char) 0x89: out.push_back((char) 0xA9); break;
                case (char) 0x8D: out.push_back((char) 0xAD); break;
                case (char) 0x93: out.push_back((char) 0xB3); break;
                case (char) 0x9A: out.push_back((char) 0xBA); break;
                case (char) 0x9C: out.push_back((char) 0xBC); break;
                case (char) 0x91: out.push_back((char) 0xB1); break;
                default: out.push_back(input[i]);
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
