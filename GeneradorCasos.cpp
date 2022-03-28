#include "GeneradorCasos.hpp"
#include <iostream>
using namespace std;

void GeneradorCasos::generar_mejor(char A[], char B[], int n) {
    for (int i = 0; i < n; i++) {                       // Rellena todo con carácteres iguales
        A[i] = 'a'; 
        B[i] = 'a';
    }
}
void GeneradorCasos::generar_peor(char A[], char B[], int n, int m) {
    int cont = 0;
    for (int i = 0; i < n; i++){                        // Rellena todo con carácteres iguales, pero distintos entre sí
        if (cont < m - 1){
            A[i] = 'a';
            B[i] = 'a';
            cont++;
        } else {
            A[i] = 'a';
            B[i] = 'b';
            cont = 0;
        }
    }
}
void GeneradorCasos::generar_promedio(char A[], char B[],  int n) {
    for (int i = 0; i < n; i++)
    {
        char valor = 'a' + (rand() % ('z' - 'a' + 1));  // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        A[i] = valor;                                   // Incluye el caracter
        valor = 'a' + (rand() % ('z' - 'a' + 1));       // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        B[i] = valor;                                   // Incluye el caracter
    }
}