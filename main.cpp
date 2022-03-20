#include "Comprobador.hpp"
#include "Dato.hpp"
#include "Programa.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
#include <thread>
using namespace std;

using std::this_thread::sleep_for;

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 50; i++) {
        int n = 10;
        int m = 5;
        char A[] = GeneradorCasos::generar_promedio(n); // Genera la cadena A
        sleep_for(std::chrono::milliseconds(500)); // Espera para generar otra aleatoria
        char B[] = GeneradorCasos::generar_promedio(n); // Genera la cadena B
        Dato resultado = Programa::solucionar(n, m, A, B); // Soluciona el problema con el algoritmo
        bool correcta = Comprobador::comprobar(resultado, A, B, n, m); // Comprueba la solución
        if (correcta) // Muestra por pantalla 
            cout << "CORRECTA" << endl;
        else
            cout << "CAGASTE" << endl;
    }
}