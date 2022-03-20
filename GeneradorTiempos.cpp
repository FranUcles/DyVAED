#include <iostream>
#include <sys/time.h>
#include "GeneradorTiempos.hpp"
#include "Programa.hpp"
#include "GeneradorCasos.hpp"
using namespace std;

GeneradorTiempos::GeneradorTiempos()
{
    tiempo_mejor = 0;
    tiempo_peor = 0;
    tiempo_promedio = 0;
}

const int NUMERO_PRUEBAS_PROMEDIO = 10;



double media(double casos[])
{
    double suma = 0;
    int tamano = sizeof(casos) / sizeof(casos[0]); // Tamaño del array de casos
    for (int i = 0; i < tamano; i++)
        suma += casos[i];
    return suma / tamano;
}

double caso_promedio(int n, int m)
{
    double casos[NUMERO_PRUEBAS_PROMEDIO]; // Array donde guardar las diferentes salidas de los casos
    struct timeval ti,tf; // Hora de inicio y hora de fin
    double tiempo; // Tiempo transcurrido
    for (int i = 0; i < NUMERO_PRUEBAS_PROMEDIO; i++)
    {
        char A[] = GeneradorCasos.generar_promedio(n, 'a');
        char B[] = GeneradorCasos.generar_promedio(n, 'a');
        gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
        Programa::solucionar(m, 1, n, A, B);
        gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
        tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
        casos[i] = tiempo;
    }
    return media(casos);
}

double caso_mejor(int n, int m)
{
    char A[] = GeneradorCasos.generar_mejor(n, 'a');
    char B[] = GeneradorCasos.generar_mejor(n, 'a');
    struct timeval ti,tf; // Hora de inicio y hora de fin
    double tiempo; // Tiempo transcurrido
    gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
    Programa::solucionar(m, 1, n, A, B);
    gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
    return tiempo;
}

double caso_peor(int n, int m)
{
    char A[] = GeneradorCasos.generar_peor(n, 'a');
    char B[] = GeneradorCasos.generar_peor(n, 'b');
    struct timeval ti,tf; // Hora de inicio y hora de fin
    double tiempo; // Tiempo transcurrido
    gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
    Programa::solucionar(m, 1, n, A, B);
    gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
    return tiempo;
}

void GeneradorTiempos::generarTiempos(int n, int m)
{
    this->tiempo_mejor = caso_mejor(n, m);
    this->tiempo_peor = caso_peor(n, m);
    this->tiempo_promedio = caso_promedio(n, m);
}

double GeneradorTiempos::getTiempoPeor()
{
    return this->tiempo_peor;
}
double GeneradorTiempos::getTiempoMejor()
{
    return this->tiempo_mejor;
}
double GeneradorTiempos::getTiempoPromedio()
{
    return this->tiempo_promedio;
}