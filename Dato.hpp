class Dato
{
private:
    int posicion; // Guarda la posición de inicio de la cadena
    int longitud; // Guarda la longitud de la cadena
public:
    Dato();
    int getPos();
    int getLong();
    void setPos(int p);
    void setLong(int l);
    Dato datoMax(Dato d1, Dato d2); // Devuelve el máximo 
};