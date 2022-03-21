#include "GeneradorCasos.hpp"
#include <iostream>
#include <vector>
using namespace std;

void GeneradorCasos::generar_mejor(char A[], int n, char c) {
    for (int i = 0; i < n; i++)
        A[i] = c;
}
void GeneradorCasos::generar_peor(char A[], int n, char c) {
    for (int i = 0; i < n; i++)
        A[i] = c;
}
void GeneradorCasos::generar_promedio(char A[], int n) {
    for (int i = 0; i < n; i++)
    {
        char valor = 'a' + (rand() % ('z' - 'a' + 1)); // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        A[i] = valor;                                   // Incluye el caracter
    }
}