#include "Dato.hpp"

Dato::Dato(int posicion, int coincidencias) { 
    this->posicion = posicion;
    this->coincidencias = coincidencias;
}

Dato::Dato() {                                      // Constructor sobrecargado
    Dato(1,0);                                      // Lo ponemos a 1 porque siempre empiezan las soluciones en 1
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

Dato Dato::datoMax(Dato d1, Dato d2) {              // Se considera que un dato es menor que otro si su número de coincidencias es menor y en caso de ser iguales,
                                                    // si la posición también es menor
    if (d1.coincidencias > d2.coincidencias)
        return d1;
    else if (d2.coincidencias > d1.coincidencias)
        return d2;
    if (d1.posicion <= d2.posicion)
        return d1;
    else
        return d2;
}