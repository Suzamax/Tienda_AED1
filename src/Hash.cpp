#include "Hash.h"

/**
 * @brief Función de dispersión.
 *
 * @param w Palabra a la que "hashear"
 * @param s Longitud del array
 * @return int Hash
 */
int Hash::CalcHash(std::string w, int s)
{
    int hash = FNVoffset;
    for(int i = 0; i < w.length(); i++)
    {
        hash = hash * FNVprimo;
        hash = hash ^ w[i];
    }
    return hash % s;
}
