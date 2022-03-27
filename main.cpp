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
    fichero_mejor_tiempo << setprecision(10);
    fichero_peor_tiempo << setprecision(10);
    fichero_promedio_tiempo << setprecision(10);
    for (int i = 1000; i < 10000000; i = i +1000){
        fichero_mejor_tiempo << i << SEPARADOR;
        fichero_peor_tiempo << i << SEPARADOR;
        fichero_promedio_tiempo << i << SEPARADOR;
    }
    fichero_mejor_tiempo << endl;
    fichero_peor_tiempo << endl;
    fichero_promedio_tiempo << endl;
    for (int n = 20000; n <= 10000000; n = n + 1000)
    {
        fichero_mejor_tiempo << n << SEPARADOR;
        fichero_peor_tiempo << n << SEPARADOR;
        fichero_promedio_tiempo << n << SEPARADOR;
        for (int m = 1000; m < n; m = m + 1000) {
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
    // int n = 20000;
    // int m = 10000;
    // GeneradorTiempos generador;
    // generador.generarTiempos(n,m);
    // fichero_mejor_tiempo << generador.getTiempoMejor() << SEPARADOR;
    // fichero_peor_tiempo << generador.getTiempoPeor() << SEPARADOR;
    // fichero_promedio_tiempo << generador.getTiempoPromedio() << SEPARADOR;
    // // cout << "---------------------------------------------------------" << endl;
    // // cout << "Tiempos con (n,m) = " << "(" << n << "," << m << ")"<< endl;
    // // cout << "Tiempo mejor: " << generador.getTiempoMejor() << endl;
    // // cout << "Tiempo peor: " << generador.getTiempoPeor() << endl;
    // // cout << "Tiempo promedio: " << generador.getTiempoPromedio() << endl;
    // // cout << "---------------------------------------------------------" << endl;
    // fichero_mejor_tiempo << endl;
    // fichero_peor_tiempo << endl;
    // fichero_promedio_tiempo << endl;
}