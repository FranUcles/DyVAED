#include "Dato.hpp"

Dato::Dato()
{
    this->posicion = 0;
    this->coincidencias = 0;
}

Dato::Dato(int posicion, int coincidencias) {
    this->posicion = posicion;
    this->coincidencias = coincidencias;
}

int Dato::getPos(){
    return this->posicion;
}

int Dato::getCoincidencias(){
    return this->coincidencias;
}

void Dato::setPos(int p){
    this->posicion = p;
}

void Dato::setCoincidencias(int c){
    this->coincidencias = c;
}

Dato Dato::datoMax(Dato d1, Dato d2) {
    if (d1.coincidencias > d2.coincidencias)
        return d1;
    else if (d2.coincidencias > d1.coincidencias)
        return d2;
    if (d1.posicion <= d2.posicion)
        return d1;
    else
        return d2;
}