#include <iostream>
#include <sys/time.h>
#include "Generador.hpp"
using namespace std;

Generador::Generador()
{
    tiempo_mejor = 0;
    tiempo_peor = 0;
    tiempo_promedio = 0;
}

const int NUMERO_PRUEBAS_PROMEDIO = 10;

string generar_string_promedio(int n)
{
    string resultado = string();
    srand(time(NULL)); // Da un generador de valores aleatorios con semilla en función de la hora actual
    for (int i = 0; i < n; i++)
    {
        char valor = 'a' + (rand() % ('z' - 'a' + 1)); // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        resultado += valor;                            // Concatena los resultados
    }
    return resultado;
}

string generar_string_igual(int n, char c)
{
    string resultado = string();
    for (int i = 0; i < n; i++)
        resultado += c;
    return resultado;
}

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
        string cadena_A = generar_string_promedio(n);
        string cadena_B = generar_string_promedio(n);
        gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
        // DyV(m, cadena_A, cadena_B);
        gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
        tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
        casos[i] = tiempo;
    }
    return media(casos);
}

double caso_mejor(int n, int m)
{
    string cadena_A = generar_string_igual(n, 'a');
    string cadena_B = generar_string_igual(n, 'a');
    struct timeval ti,tf; // Hora de inicio y hora de fin
    double tiempo; // Tiempo transcurrido
    gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
    // DyV(m, cadena_A, cadena_B);
    gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
    return tiempo;
}

double caso_peor(int n, int m)
{
    string cadena_A = generar_string_igual(n, 'a');
    string cadena_B = generar_string_igual(n, 'b');
    struct timeval ti,tf; // Hora de inicio y hora de fin
    double tiempo; // Tiempo transcurrido
    gettimeofday(&ti,NULL); // Toma la hora antes del algoritmo
    // DyV(m, cadena_A, cadena_B);
    gettimeofday(&tf,NULL); // Toma la hora después del algoritmo
    tiempo = (tf.tv_sec - ti.tv_sec)*1000 + (tf.tv_usec - ti.tv_usec)/1000.0; // Calcula el tiempo transcurrido
    return tiempo;
}

void Generador::generarTiempos(int n, int m)
{
    this->tiempo_mejor = caso_mejor(n,m);
    this->tiempo_peor = caso_peor(n,m);
    this->tiempo_promedio = caso_promedio(n,m);
}

double Generador::getTiempoPeor()
{
    return this->tiempo_peor;
}
double Generador::getTiempoMejor()
{
    return this->tiempo_mejor;
}
double Generador::getTiempoPromedio()
{
    return this->tiempo_promedio;
}