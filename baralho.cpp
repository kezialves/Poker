#include "baralho.hpp"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "mesa.hpp"

using namespace std;

// ---------- CONSTRUTOR E DESTRUTOR ----------

Baralho::Baralho(){};
Baralho::~Baralho(){};

// ---------- MÉTODOS ----------

bool Baralho::inicializa() {

    for(int naipe = (int)Naipe::PAUS; naipe <= (int)Naipe::ESPADAS; naipe++) {
        for(int valor = (int)Valor::DOIS; valor <= (int)Valor::AS; valor++) {
            Carta* carta;
            carta->setNaipe((Naipe*)naipe);
            carta->setValor((Valor*)valor);
            this->cartas.push_back(carta);
        }
    }

    return true;
}

bool Baralho::embaralha() {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(this->cartas.begin(), this->cartas.end(), default_random_engine(seed));
    return true;
}

// Carta* Baralho::compraCarta() {

// }
