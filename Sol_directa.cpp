#include "Dato.hpp"

Dato resolucionDirecta(char A[], char B[], int inicio, int final){
    Dato resultado = Dato (inicio, 0);
    int max = 0;
    int cont = 0;
    for(int i = inicio; i<=final; i++){
        if (A[i] == B[i])   
            cont++;
        else{
            if (cont >= max)    
                max = cont;
            cont = 0;
        }
    }
    resultado.setCoincidencias(max);
    return resultado;
}