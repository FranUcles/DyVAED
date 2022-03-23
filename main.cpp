#include "Programa.hpp"
#include "Comprobador.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    bool peta = false;
    for (int n = 1; n <= 100; n++)
    {
        for (int m = 1; m < n; m++) {
            char A[n], B[n];                                                    // cadenas A y B que se van a comparar
            GeneradorCasos::generar_promedio(A, B, n);                          // Genero las cadenas A y B
            Dato resultado = Programa::solucionar(n, m, A, B);                  // Soluciona el problema con el algoritmo
            bool correcta = Comprobador::comprobar(resultado, A, B, n, m);      // Comprueba la solución
            if (!correcta) {
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
                cout << "n: " << n << endl;
                cout << "m: " << m << endl;
                cout << "------------------------------" << endl;
                cout << "Solución propuesta: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
                Comprobador::comprobar(resultado, A, B, n, m, true);             // Imprime la solución correcta
                cout << "------------------------------" << endl;
                peta = true;
                break;
            }
        }
    }
    if (!peta)
        cout << "TODO DE LOCOS" << endl;
}