#include "GeneradorCasos.hpp"
#include <iostream>
#include <vector>
using namespace std;

char* GeneradorCasos::generar_mejor(int n, char c) {
    vector<char> resultado(n,c);
    return &resultado[0];
}
char* GeneradorCasos::generar_peor(int n, char c) {
    vector<char> resultado(n,c);
    return &resultado[0];
}
char* GeneradorCasos::generar_promedio(int n) {
    vector<char> resultado(n);
    for (int i = 0; i < n; i++)
    {
        char valor = 'a' + (rand() % ('z' - 'a' + 1)); // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        resultado[i] = valor;                          // Concatena los resultados
    }
    return &resultado[0];
}