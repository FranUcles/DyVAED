#ifndef GeneradorCasos_hpp
#define GeneradorCasos_hpp
class GeneradorCasos
{
private:
public:
    static void generar_mejor(char A[], char B[], int n);       // Rellena A y B con el caso mejor (las 2 iguales)
    static void generar_peor(char A[], char B[], int n, int m);        // Rellena A y B con el caso peor (las 2 distintas)
    static void generar_promedio(char A[], char B[], int n);    // Rellena A y B con el caso promedio (las 2 random)
};
#endif