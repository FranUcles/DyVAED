class Dato
{
private:
    int posicion; // Guarda la posición de inicio de la cadena
    int coincidencias; // Guarda las coincidencias de la cadena
public:
    Dato();
    Dato(int posicion, int coincidencias);
    int getPos();
    int getCoincidencias();
    void setPos(int p);
    void setCoincidencias(int l);
    static Dato datoMax(Dato d1, Dato d2); // Devuelve el máximo 
};