#include "Programa.hpp"
#include "Comprobador.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    ofstream salida_ok("correctos.txt");
    ofstream salida_err("errores.txt");
    for (int i = 0; i < 5000; i++) {
        int n = 1000;                                                       // Tamaño de las cadenas
        int m = 100;                                                        // Tamaño de las subcadenas solución
        char A[n], B[n];                                                    // cadenas A y B que se van a comparar
        GeneradorCasos::generar_promedio(A, B, n);                          // Genero las cadenas A y B
        Dato resultado = Programa::solucionar(n, m, A, B);                  // Soluciona el problema con el algoritmo
        bool correcta = Comprobador::comprobar(resultado, A, B, n, m);      // Comprueba la solución
        if (correcta){                                                      // Muestra por pantalla
            salida_ok << "CORRECTA" << endl;
        }                                               
        else {
            salida_err << "CAGASTE" << endl;
            salida_err << "------------------------------" << endl;
            salida_err << "Cadena A: ";
            for (int i = 0; i < n; i++)
                salida_err << A[i];
            salida_err << endl;
            salida_err << "Cadena B: ";
            for (int i = 0; i < n; i++)
                salida_err << B[i];
            salida_err << endl;
            salida_err << "------------------------------" << endl;
            salida_err << "Solución propuesta: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
            Comprobador::comprobar(resultado, A, B, n, m, true);             // Imprime la solución correcta
            salida_err << "------------------------------" << endl;
        }
    }
}