#include "Programa.hpp"
#include "Comprobador.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    for (int i = 0; i < 5000; i++) {
        int n = 5000; // Tamaño de las cadenas
        int m = 1000; // Tamaño de las subcadenas solución
        char A[n], B[n]; // cadenas A y B que se van a comparar
        GeneradorCasos::generar_promedio(A, B, n); // Genero las cadenas A y B
        Dato resultado = Programa::solucionar(n, m, A, B); // Soluciona el problema con el algoritmo
        bool correcta = Comprobador::comprobar(resultado, A, B, n, m); // Comprueba la solución
        if (correcta) // Muestra por pantalla 
            cout << "CORRECTA" << endl;
        else {
            cout << "CAGASTE" << endl;
            cout << "------------------------------" << endl;
            cout << "Cadena A: ";
            for (int i = 0; i < n; i++)
                cout << A[i];
            cout << endl;
            cout << "Cadena B: ";
            for (int i = 0; i < n; i++)
                cout << B[i];
            cout << endl;
            cout << "------------------------------" << endl;
            cout << "Solución propuesta: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
            Comprobador::comprobar(resultado, A, B, n, m, true);
            cout << "------------------------------" << endl;
            break;
        }
    }
}