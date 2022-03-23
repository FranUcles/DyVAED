#include "GeneradorTiempos.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

#define SEPARADOR "; ";

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    ofstream fichero_mejor_tiempo("tiempo_mejor.csv");
    ofstream fichero_peor_tiempo("tiempo_peor.csv");
    ofstream fichero_promedio_tiempo("tiempo_promedio.csv");
    fichero_mejor_tiempo << setprecision(20);
    fichero_peor_tiempo << setprecision(20);
    fichero_promedio_tiempo << setprecision(20);
    for (int n = 1; n <= 100; n++)
    {
        for (int m = 1; m < n; m++) {
            GeneradorTiempos generador;
            generador.generarTiempos(n,m);
            fichero_mejor_tiempo << generador.getTiempoMejor() << SEPARADOR;
            fichero_peor_tiempo << generador.getTiempoPeor() << SEPARADOR;
            fichero_promedio_tiempo << generador.getTiempoPromedio() << SEPARADOR;
            // cout << "---------------------------------------------------------" << endl;
            // cout << "Tiempos con (n,m) = " << "(" << n << "," << m << ")"<< endl;
            // cout << "Tiempo mejor: " << generador.getTiempoMejor() << endl;
            // cout << "Tiempo peor: " << generador.getTiempoPeor() << endl;
            // cout << "Tiempo promedio: " << generador.getTiempoPromedio() << endl;
            // cout << "---------------------------------------------------------" << endl;
        }
        fichero_mejor_tiempo << endl;
        fichero_peor_tiempo << endl;
        fichero_promedio_tiempo << endl;
    }
}