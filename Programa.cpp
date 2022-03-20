#include "Dato.hpp"
#include "Comprobador.hpp"
#include <iostream>
using namespace std;

Dato DyV(int m, int inicio, int final, char A[], char B[]) {
    int diff = final - inicio + 1; // Numero de elementos de las cadenas
    Dato resultado;
    if (diff < m) // Si el número de elementos es mayor que la m, nunca hay solución
        return resultado;
    else if (diff == m){ // Si es el mismo, se puede resolver por resolución directa
        return resolucionDirecta(A, B, inicio, final);
    }
    int medio = inicio + diff/2; // Dividimos las cadenas por la mitad
    Dato dato1 = DyV(m, inicio, medio, A, B); // Evaluamos la primera mitad
    if (dato1.getCoincidencias() == m)
        return dato1;
    Dato dato2 = DyV(m, medio, final, A, B); // Evaluamos la segunda mitad
    if (dato2.getCoincidencias() == m)
        return dato2;
    int nuevo_inicio = max(inicio, medio - m + 1); // Preparamos el combinar para evitar que se salga de las cadenas
    int nuevo_final = min(final, medio + m - 1); // Preparamos el combinar para evitar que se salga de las cadenas
    resultado = combinar(m, nuevo_inicio, nuevo_final, A, B, dato1, dato2); // Combinamos las soluciones
    return resultado;
}

Dato combinar(int m, int inicio, int final, char A[], char B[], Dato parcial1, Dato parcial2) {
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
        if (matches > parcial3.getCoincidencias()) {
            parcial3.setPos(inicio + i);
            parcial3.setCoincidencias(matches);
        }
        if (parcial3.getCoincidencias() == m) // Comprobamos si es el caso máximo
            return parcial3;
    }
    return Dato::datoMax(parcial3, Dato::datoMax(parcial1, parcial2)); // Devolvemos el máximo de las tres soluciones parciales
}
Dato resolucionDirecta(char A[], char B[], int inicio, int final){
    Dato resultado(inicio, 0);
    int max = 0;
    int cont = 0;
    for (int i = inicio; i <= final; i++){
        if (A[i] == B[i])
            cont++;
        else{
            if (cont >= max)
                max = cont;
            cont = 0;
        }
    }
    resultado.setCoincidencias(max);
    return resultado;
}

int main(int argc, char const *argv[])
{
}