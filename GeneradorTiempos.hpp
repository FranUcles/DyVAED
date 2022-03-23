#ifndef GeneradorTiempos_hpp
#define GeneradorTiempos_hpp
class GeneradorTiempos                  // Objeto que genera los tiempos del algoritmo
{
private:
    long double tiempo_mejor;                // Tiempo mejor generado
    long double tiempo_peor;                 // Tiempo peor generado
    long double tiempo_promedio;             // Tiempo promedio generado

public:
    GeneradorTiempos();
    void generarTiempos(int n, int m);       // Calcula los tiempos en función de los parámetros
    long double getTiempoMejor();            // Obtener el tiempo mejor
    long double getTiempoPeor();             // Obtener el tiempo peor
    long double getTiempoPromedio();         // Obtener el tiempo promedio
};
#endif