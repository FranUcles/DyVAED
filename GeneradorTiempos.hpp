class GeneradorTiempos // Objeto que genera los tiempos del algoritmo
{
private:
    double tiempo_mejor;
    double tiempo_peor;
    double tiempo_promedio;

public:
    GeneradorTiempos();
    void generarTiempos(int n, int m); // Calcula los tiempos en función de los parámetros
    double getTiempoMejor(); // Obtener el tiempo mejor
    double getTiempoPeor(); // Obtener el tiempo peor
    double getTiempoPromedio(); // Obtener el tiempo promedio
};