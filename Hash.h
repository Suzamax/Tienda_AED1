#ifndef TIENDA_HASH_H
#define TIENDA_HASH_H
#include <iostream>

/**
 * @brief Función de dispersión, usa FNV-1 de 32 bits.
 * 
 */
class Hash
{
private:
    static int FNVprimo = 0x01000193;
    static int FNVoffset = 0x811c9dc5;
public:
    static int CalcHash(std::string w, int size);
};

#endif //TIENDA_HASH_H