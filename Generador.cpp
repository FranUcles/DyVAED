#include <iostream>
#include<time.h>
using namespace std;

const int NUMERO_PRUEBAS_PROMEDIO = 10;

string generar_string_promedio(int n) {
    string resultado = string();
    srand(time(NULL));  // Da un generador de valores aleatorios con semilla en función de la hora actual
    for (int i = 0; i < n; i++) {
        char valor = 'a' + (rand() % ('z' - 'a' + 1)); // Genera un random, lo acota por el número de letras y se lo añade a la 'a'
        resultado += valor; // Concatena los resultados
    }
    return resultado;
}

string generar_string_igual(int n, char c) {
    string resultado = string();
    for (int i = 0; i < n; i++)
        resultado += c; 
    return resultado;
}

double media(int casos[]){
    int suma = 0;
    int tamano = sizeof(casos)/sizeof(casos[0]); // Tamaño del array de casos
    for (int i = 0; i < tamano; i++)
        suma += casos[i];
    return suma/tamano;
}

double caso_promedio(int n, int m) {
    int casos[NUMERO_PRUEBAS_PROMEDIO];  // Array donde guardar las diferentes salidas de los casos
    for (int i = 0; i < NUMERO_PRUEBAS_PROMEDIO; i++) {
        string cadena_A = generar_string_promedio(n);
        string cadena_B = generar_string_promedio(n);
        // casos[i] = DyV(m, cadena_A, cadena_B);
    }
    return media(casos);
}

double caso_mejor(int n, int m) {
    string cadena_A = generar_string_igual(n, 'a');
    string cadena_B = generar_string_igual(n, 'a');
    // return DyV(m, cadena_A, cadena_B);
}

double caso_peor(int n, int m) {
    string cadena_A = generar_string_igual(n, 'a');
    string cadena_B = generar_string_igual(n, 'b');
    // Algo otra cosa
}

int main(){

}