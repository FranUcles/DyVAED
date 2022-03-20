#include "Dato.hpp"
#include "Comprobador.hpp"
#include <iostream>
using namespace std;

Dato combinar(int m, int inicio, int final, int A[], int B[], Dato parcial1, Dato parcial2) {
    int pos = inicio; // Inicio de la cadena que es la más coincidente
    int matches = 0; // Numero de coincidencias 

    for (int i = 0; i < m-1; i++)
        if (A[inicio + i] == B[inicio + i])
            matches++;
    Dato parcial3(pos, matches); // Creamos una posible solución inicial
    if (matches == m)
        return parcial3;

    int longitud = min(final - inicio + 1, 2*m - 1);
    for (int i = 1; i <= longitud; i++) {
        if (A[inicio + 1] == B[inicio + 1] && A[inicio + m + i] != B[inicio + m + i])
            matches--;
        else if (A[inicio + 1] != B[inicio + 1] && A[inicio + m + i] == B[inicio + m + i])
            matches++;
        if (matches > parcial3.getLong()) {
            parcial3.setPos(inicio + i);
            parcial3.setLong(matches);
        }
        if (parcial3.getLong() == m) // Comprobamos si es el caso máximo
            return parcial3;
    }
    return Dato::datoMax(parcial3, Dato::datoMax(parcial1, parcial2)); // Devolvemos el máximo de las tres soluciones parciales
}
Dato resolucionDirecta(char A[], char B[], int inicio, int final){
    Dato resultado(inicio, 0);
    int max = 0;
    int cont = 0;

    for(int i = inicio; i<=final; i++){
        if (A[i] == B[i])   cont++;
        else{
            if (cont >= max)    max = cont;
            cont = 0;
        }
    }

    resultado.setLong(max);

    return resultado;

}

int main(int argc, char const *argv[])
{
}