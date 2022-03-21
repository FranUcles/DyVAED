#ifndef Dato_hpp
#define Dato_hpp
class Dato
{
private:
    int posicion; // Guarda la posición de inicio de la cadena
    int coincidencias; // Guarda las coincidencias de la cadena
public:
    Dato();
    Dato(int posicion, int coincidencias);
    int getPos(); // Devuelve la posición de inicio de la cadena
    int getCoincidencias(); // Devuelve el número de coincidencias 
    void setPos(int p); // Establece la posición
    void setCoincidencias(int l); // Establece el número de coincidencias
    static Dato datoMax(Dato d1, Dato d2); // Devuelve el máximo 
};
#endif