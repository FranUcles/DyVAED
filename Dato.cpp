class Dato
{
private:
    int posicion;
    int longitud;
public:
    Dato();
    int getPos();
    int getLong();
    void setPos(int p);
    void setLong(int l);
};

Dato::Dato()
{
    this->posicion = 0;
    this->longitud = 0;
}

int Dato::getPos(){
    return this->posicion;
}

int Dato::getLong(){
    return this->longitud;
}

void Dato::setPos(int p){
    this->posicion = p;
}

void Dato::setLong(int l){
    this->longitud = l;
}