#include "Dato.hpp"
#include "Comprobador.hpp"
#include <iostream>
using namespace std;

Dato DyV(int m, int inicio, int final, int A[], int B[]) {
    int diff = final - inicio + 1; // Numero de elementos de las cadenas
    Dato resultado;
    if (diff < m) // Si el número de elementos es mayor que la m, nunca hay solución
        return resultado;
    else if (diff == m){ // Si es el mismo, se puede resolver por resolución directa
        // return resolucionDirecta(m, inicio, final, A, B);
    }
    int medio = inicio + diff/2; // Dividimos las cadenas por la mitad
    Dato dato1 = DyV(m, inicio, medio, A, B); // Evaluamos la primera mitad
    if (dato1.getLong() == m)
        return dato1;
    Dato dato2 = DyV(m, medio, final, A, B); // Evaluamos la segunda mitad
    if (dato2.getLong() == m)
        return dato2;
    int nuevo_inicio = max(inicio, medio - m + 1); // Preparamos el combinar para evitar que se salga de las cadenas
    int nuevo_final = min(final, medio + m - 1); // Preparamos el combinar para evitar que se salga de las cadenas
    // resultado = combinar(m, nuevo_inicio, nuevo_final, A, B, dato1, dato2); // Combinamos las soluciones
    return resultado;
}

int main(int argc, char const *argv[])
{
}
