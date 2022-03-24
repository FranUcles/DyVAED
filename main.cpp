#include "Programa.hpp"
#include "Comprobador.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
#include <sys/time.h>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    // bool peta = false;
    // for (int n = 1; n <= 100; n++)
    // {
    //     for (int m = 1; m < n; m++) {
    //         char A[n], B[n];                                                    // cadenas A y B que se van a comparar
    //         GeneradorCasos::generar_promedio(A, B, n);                          // Genero las cadenas A y B
    //         Dato resultado = Programa::solucionar(n, m, A, B);                  // Soluciona el problema con el algoritmo
    //         bool correcta = Comprobador::comprobar(resultado, A, B, n, m);      // Comprueba la solución
    //         if (!correcta) {
    //             cout << "CAGASTE" << endl;
    //             cout << "------------------------------" << endl;
    //             cout << "Cadena A: ";
    //             for (int i = 0; i < n; i++)
    //                 cout << A[i];
    //             cout << endl;
    //             cout << "Cadena B: ";
    //             for (int i = 0; i < n; i++)
    //                 cout << B[i];
    //             cout << endl;
    //             cout << "n: " << n << endl;
    //             cout << "m: " << m << endl;
    //             cout << "------------------------------" << endl;
    //             cout << "Solución propuesta: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
    //             Comprobador::comprobar(resultado, A, B, n, m, true);             // Imprime la solución correcta
    //             cout << "------------------------------" << endl;
    //             peta = true;
    //             break;
    //         }
    //     }
    // }
    // if (!peta)
    //     cout << "TODO DE LOCOS" << endl;
    int n = 200000;
    int m = 10000;
    char A[n], B[n];                                                    // cadenas A y B que se van a comparar
    GeneradorCasos::generar_promedio(A, B, n);                          // Genero las cadenas A y B
    struct timeval ti,tf;                                                           // Hora de inicio y hora de fin
    double tiempoDYV;                                                                  // Tiempo transcurrido
    gettimeofday(&ti,NULL);                                                         // Toma la hora antes del algoritmo
    Dato resultado = Programa::solucionar(n, m, A, B);                  // Soluciona el problema con el algoritmo
    gettimeofday(&tf,NULL);                                                         // Toma la hora después del algoritmo
    tiempoDYV = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;       // Calcula el tiempo transcurrido
    struct timeval ti_Dir,tf_Dir;                                                           // Hora de inicio y hora de fin
    gettimeofday(&ti_Dir,NULL); 
    bool correcta = Comprobador::comprobar(resultado, A, B, n, m);      // Comprueba la solución
    gettimeofday(&tf_Dir,NULL); 
    double tiempoDir;
    tiempoDir = (tf_Dir.tv_sec - ti_Dir.tv_sec)*1000 + (tf_Dir.tv_usec - ti_Dir.tv_usec)/1000.0;       // Calcula el tiempo transcurrido
    cout << "Tiempo DyV: " << tiempoDYV << endl;
    cout << "Tiempo Dir: " << tiempoDir << endl;
    if (correcta)
        cout << "TODO GOOD" << endl;
    else 
        cout << "F" << endl;
}