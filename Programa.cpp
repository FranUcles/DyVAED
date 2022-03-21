#include "Dato.hpp"
#include "Programa.hpp"
#include <iostream>
using namespace std;

Dato combinar(int m, int inicio, int final, char A[], char B[], Dato parcial1, Dato parcial2) {
    int pos = inicio; // Inicio de la cadena que es la más coincidente
    int matches = 0; // Numero de coincidencias 
    // cout << "Entro al combinar con: " << inicio << " " << final << endl;
    for (int i = 0; i <= m-1; i++)
        if (A[inicio + i - 1] == B[inicio + i - 1]) 
            matches++;
    Dato parcial3(pos, matches); // Creamos una posible solución inicial
    if (matches == m)
        return parcial3;
    int longitud = min(final - inicio + 1 - m, 2*m - 1);
    for (int i = 1; i <= longitud; i++) {
        // cout << "Cadena: " << inicio + i << "-" << inicio + m + i - 1 << endl;
        if (A[inicio + i - 2] == B[inicio + i - 2] && A[inicio + m + i - 2] != B[inicio + m + i - 2])
            matches--;
        else if (A[inicio + i - 2] != B[inicio + i - 2] && A[inicio + m + i - 2] == B[inicio + m + i - 2]) 
            matches++;
        if (matches > parcial3.getCoincidencias()) {
            parcial3.setPos(inicio + i);
            parcial3.setCoincidencias(matches);
        }
        if (parcial3.getCoincidencias() == m) // Comprobamos si es el caso máximo
            return parcial3;
    }
    // cout << "------------------------" << endl;
    // cout << "Al combinar ha llegado: " << endl;
    // cout << "Primera solucion: " << "(" << parcial1.getPos() << "," << parcial1.getCoincidencias() << ")" << endl;
    // cout << "Segunda solucion: " << "(" << parcial2.getPos() << "," << parcial2.getCoincidencias() << ")" << endl;
    // cout << "Tercera solucion: " << "(" << parcial3.getPos() << "," << parcial3.getCoincidencias() << ")" << endl;
    //  cout << "------------------------" << endl;
    return Dato::datoMax(parcial3, Dato::datoMax(parcial1, parcial2)); // Devolvemos el máximo de las tres soluciones parciales
}
Dato resolucionDirecta(char A[], char B[], int inicio, int final){
    Dato resultado(inicio, 0);
    int cont = 0;
    for (int i = inicio; i <= final; i++){
        if (A[i-1] == B[i-1]){
            // cout << "Caracter igual: " << A[i-1] << " = " << B[i-1] << "; en la posicion " << i << endl;
            cont++;
        }
    }
    resultado.setCoincidencias(cont);
    // cout << "Entro a la solucion directa con: " << inicio << " " << final << endl;
    // cout << "Salida solucion directa con: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
    return resultado;
}

Dato DyV(int m, int inicio, int final, char A[], char B[]) {
    int diff = final - inicio + 1; // Numero de elementos de las cadenas
    Dato resultado;
    if (diff < m) // Si el número de elementos es mayor que la m, nunca hay solución
        return resultado;
    else if (diff == m){ // Si es el mismo, se puede resolver por resolución directa
        // cout << "Resuelvo directamente con: " << inicio << " " << final << endl;
        return resolucionDirecta(A, B, inicio, final);
    }
    int medio = inicio + diff/2 - 1; // Dividimos las cadenas por la mitad
    // cout << "Division primera: " << inicio << " " << medio << endl;
    Dato dato1 = DyV(m, inicio, medio, A, B); // Evaluamos la primera mitad
    if (dato1.getCoincidencias() == m)
        return dato1;
    Dato dato2 = DyV(m, medio + 1, final, A, B); // Evaluamos la segunda mitad
    if (dato2.getCoincidencias() == m)
        return dato2;
    int nuevo_inicio = max(inicio, medio - m + 2); // Preparamos el combinar para evitar que se salga de las cadenas
    int nuevo_final = min(final, medio + m - 1); // Preparamos el combinar para evitar que se salga de las cadenas
    resultado = combinar(m, nuevo_inicio, nuevo_final, A, B, dato1, dato2); // Combinamos las soluciones
    // cout << "------------------------" << endl;
    // cout << "Del combinar sale: " << "(" << resultado.getPos() << "," << resultado.getCoincidencias() << ")" << endl;
    // cout << "------------------------" << endl;
    return resultado;
}

Dato Programa::solucionar(int n, int m, char A[], char B[]) {
    return DyV(m, 1, n, A, B);
}