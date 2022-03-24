#ifndef GeneradorTiempos_hpp
#define GeneradorTiempos_hpp
class GeneradorTiempos                  // Objeto que genera los tiempos del algoritmo
{
private:
    double tiempo_mejor;                // Tiempo mejor generado
    double tiempo_peor;                 // Tiempo peor generado
    double tiempo_promedio;             // Tiempo promedio generado

public:
    GeneradorTiempos();
    void generarTiempos(int n, int m);       // Calcula los tiempos en función de los parámetros
    double getTiempoMejor();            // Obtener el tiempo mejor
    double getTiempoPeor();             // Obtener el tiempo peor
    double getTiempoPromedio();         // Obtener el tiempo promedio
};
#endif