#include <iostream>
#include "carta.hpp"

using namespace std;

// ---------- CONSTRUTORES E DESTRUTOR ----------

Carta::Carta(){};

Carta::Carta(Valor* valor, Naipe* naipe):
    valor(*valor), naipe(*naipe){}

Carta::~Carta(){}

// ---------- GETTERS E SETTERS ----------

Valor Carta::getValor() const{
    return valor;
}

bool Carta::setValor(Valor* valor){
    this->valor = *valor;
    return true;
}

Naipe Carta::getNaipe() const{
    return naipe;
}

bool Carta::setNaipe(Naipe* naipe){
    this->naipe = *naipe;
    return true;
}

// ---------- MÉTODOS ----------

Carta& Carta::operator >(const Carta &carta){
    
    if(this >= &carta)
        return *this;

    naipe = carta.getNaipe();
    valor = carta.getValor();

    return *this;
}
