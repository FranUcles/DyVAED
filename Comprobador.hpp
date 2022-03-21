#ifndef Comprobador_hpp
#define Comprobador_hpp
#include "Dato.hpp"
class Comprobador
{
private:
public:
    static bool comprobar(Dato solucion, char A[], char B[], int n, int m, bool imprimir = false); // Función para comprobar que la solución pasada es la correcta
};
#endif