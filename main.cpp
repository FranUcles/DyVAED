#include "Programa.hpp"
#include "Comprobador.hpp"
#include "GeneradorTiempos.hpp"
#include "GeneradorCasos.hpp"
#include <iostream>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 1){
        cout << "Error" << endl;
        return -1;
    }
    if (strcmp(argv[1], "1") == 0){
        if (argc != 6){
            cout << "Faltan parámetros" << endl;
            return -2;
        }
        int n = atoi(argv[2]);
        int m = atoi(argv[3]);
        char A[n], B[n];
        for (int i = 0; i < n; i++){ // Rellena los arrays
            A[i] = argv[4][i];
            B[i] = argv[5][i];
        }
        Dato solucion = Programa::solucionar(n, m, A, B);
        cout << "La solución es: " <<  endl;
        cout << "Posición: " << solucion.getPos() << endl;
        cout << "Coincidencias: " << solucion.getCoincidencias() << endl;
    } else if (strcmp(argv[1], "2") == 0){
        if (argc != 4){
            cout << "Faltan parámetros" << endl;
            return -2;
        }
        int n = atoi(argv[2]);
        int m = atoi(argv[3]);
        srand(time(NULL)); // Semilla para el random
        GeneradorTiempos generador;
        generador.generarTiempos(n,m);
        cout << "Tiempos para tamaños: (n,m) = (" << n << "," << m << ")" << endl;
        cout << "Tiempo mejor: " << generador.getTiempoMejor() << " ms" << endl;
        cout << "Tiempo peor: " << generador.getTiempoPeor() << " ms" << endl; 
        cout << "Tiempo promedio: " << generador.getTiempoPromedio() << " ms" << endl;  
    } else if (strcmp(argv[1], "3") == 0){
        if (argc < 3){
            cout << "Faltan parámetros" << endl;
            return -2;
        }
        int numero_casos = atoi(argv[2]);
        srand(time(NULL));
        bool mal = false; // Bandera por si alguno sale mal
        int i = 0;
        while (i < numero_casos && !mal){
            int n = rand() % 10 + 1;
            int m = rand() % n + 1;
            char A[n], B[n];
            GeneradorCasos::generar_promedio(A, B, n);
            Dato resultado = Programa::solucionar(n, m, A, B);
            bool correcta = Comprobador::comprobar(resultado, A, B, n, m);
            if (!correcta)
                mal = true;
            i++;
        }
        if (mal)
            cout << "Programa incorrecto" << endl;
    } else {
        cout << "Código no reconocido" << endl;
        return -3;
    }
    return 0;
}