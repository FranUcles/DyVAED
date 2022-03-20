#include "Dato.hpp"
#include "Comprobador.hpp"
#include <iostream>
using namespace std;

Dato resolucion(char A[], char B[], int n, int m)
{
    Dato solucion;
    int max = 0; // Numero más grande de coincidencias 
    int pos = 0; // Posicion de inicio de la subcadena con el mayor número de coincidencias
    int i = 0;
    while (i <= n-m && max != m) {
        int cont = 0; // Numero de coincidencias de la subcadena que empieza en i
        for (int j = i; j < i + m; j++)
            if (A[j] == B[j])
                cont++;
        if (cont > max) { // Comprobar si es el máximo y actualizar
            max = cont;
            pos = i;
        }
        i++;
    }
    solucion.setCoincidencias(max);
    solucion.setPos(pos + 1); // Ese "+1" es porque las posiciones empiezan a contar desde 1 y no desde 0
    return solucion;
}
bool Comprobador::comprobar(Dato solucion, char A[], char B[], int n, int m)
{
    Dato solucion_correcta = resolucion(A, B, n, m); // Obtiene la solución "correcta"
    // cout << "Posicion (Correcta): " << solucion_correcta.getPos() << endl;
    // cout << "Coincidencias (Correcta): " << solucion_correcta.getCoincidencias() << endl;
    return solucion.getCoincidencias() == solucion_correcta.getCoincidencias() && solucion.getPos() == solucion_correcta.getPos(); // Comprueba si son iguales
}

