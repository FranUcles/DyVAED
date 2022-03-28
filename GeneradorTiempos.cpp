#include <iostream>
#include <sys/time.h>
#include "GeneradorTiempos.hpp"
#include "Programa.hpp"
#include "GeneradorCasos.hpp"
using namespace std;

const int NUMERO_PRUEBAS_PROMEDIO = 10; // Numero de pruebas que se realizan para obtener el tiempo promedio más fiablemente

GeneradorTiempos::GeneradorTiempos()
{
    tiempo_mejor = 0;
    tiempo_peor = 0;
    tiempo_promedio = 0;
}

double media(double casos[])
{
    double suma = 0;
    int tamano = NUMERO_PRUEBAS_PROMEDIO;                                           // Tamaño del array de casos
    for (int i = 0; i < tamano; i++)                                                // Suma todos los tiempos
        suma += casos[i];
    return suma / tamano;                                                           // Devuelve la media
}

double caso_promedio(int n, int m)
{
    double casos[NUMERO_PRUEBAS_PROMEDIO];                                          // Array donde guardar los diferentes tiempos del algoritmo
    struct timeval ti,tf;                                                           // Hora de inicio y hora de fin
    double tiempo;                                                                  // Tiempo transcurrido
    for (int i = 0; i < NUMERO_PRUEBAS_PROMEDIO; i++)
    {
        char A[n], B[n];                                                            // Cadenas A y B que se van a comparar
        GeneradorCasos::generar_promedio(A, B, n);                                  // Genero las cadenas A y B
        gettimeofday(&ti,NULL);                                                     // Toma la hora antes del algoritmo
        Programa::solucionar(n, m, A, B);                                           // Solucionar el problema
        gettimeofday(&tf,NULL);                                                     // Toma la hora después del algoritmo
        tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;   // Calcula el tiempo transcurrido
        casos[i] = tiempo;                                                          // Guarda el tiempo que ha tardado el caso i
    }
    return media(casos);
}

double caso_mejor(int n, int m)
{
    char A[n], B[n];                                                                // Cadenas A y B que se van a comparar
    GeneradorCasos::generar_mejor(A, B, n);                                         // Genero las cadenas A y B
    struct timeval ti,tf;                                                           // Hora de inicio y hora de fin
    double tiempo;                                                                  // Tiempo transcurrido
    gettimeofday(&ti,NULL);                                                         // Toma la hora antes del algoritmo
    Programa::solucionar(n, m, A, B);                                               // Solucionar el problema
    gettimeofday(&tf,NULL);                                                         // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;       // Calcula el tiempo transcurrido
    return tiempo;
}

double caso_peor(int n, int m)
{
    char A[n], B[n];                                                                // Cadenas A y B que se van a comparar
    GeneradorCasos::generar_peor(A, B, n, m);                                          // Genero las cadenas A y B
    struct timeval ti,tf;                                                           // Hora de inicio y hora de fin
    double tiempo;                                                                  // Tiempo transcurrido
    gettimeofday(&ti,NULL);                                                         // Toma la hora antes del algoritmo
    Programa::solucionar(n, m, A, B);                                               // Solucionar el problema
    gettimeofday(&tf,NULL);                                                         // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0;       // Calcula el tiempo transcurrido
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