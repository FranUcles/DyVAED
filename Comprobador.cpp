#include "Comprobador.hpp"
#include <iostream>
#include <vector>
using namespace std;

vector<Dato> resolucion(char A[], char B[], int n, int m)
{
    int max = 0;                                                        // Numero más grande de coincidencias 
    int i = 0;
    vector<Dato> soluciones;
    while (i <= n-m) {
        int cont = 0;                                                   // Numero de coincidencias de la subcadena que empieza en i
        for (int j = i; j < i + m; j++)
            if (A[j] == B[j])
                cont++;
        if (cont == max) {
            Dato posible_solucion(i + 1,cont);
            soluciones.insert(soluciones.end(),posible_solucion);
        }
        if (cont > max) {                                               // Comprobar si es el máximo y actualizar
            Dato posible_solucion(i + 1, cont);
            soluciones.insert(soluciones.begin(), posible_solucion);
            max = cont;
        }
        i++;
    }
    return soluciones;
}
bool Comprobador::comprobar(Dato solucion, char A[], char B[], int n, int m, bool imprimir)
{
    vector<Dato> soluciones_correcta = resolucion(A, B, n, m);                    // Obtiene la solución "correcta"
    bool correcta = false;
    int i = 0;
    while (i < soluciones_correcta.size() && !correcta){
        Dato aux = soluciones_correcta[i];
        correcta = (aux.getCoincidencias() == solucion.getCoincidencias() && aux.getPos() == solucion.getPos());
        i++;
    }
    return correcta; // Comprueba si son iguales
}

