#include "Comprobador.hpp"
#include "Dato.hpp"
#include "Programa.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 50; i++) {
        int n = 10; // Tamaño de las cadenas
        int m = 5; // Tamaño de las subcadenas solución
        char A[n], B[n]; // cadenas A y B que se van a comparar
        GeneradorCasos::generar_promedio(A, B, n); // Genero las cadenas A y B
        Dato resultado = Programa::solucionar(n, m, A, B); // Soluciona el problema con el algoritmo
        bool correcta = Comprobador::comprobar(resultado, A, B, n, m); // Comprueba la solución
        if (correcta) // Muestra por pantalla 
            cout << "CORRECTA" << endl;
        else
            cout << "CAGASTE" << endl;
    }
}