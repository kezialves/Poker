#include "dealer.hpp"
#include <string.h>

// ---------- CONSTRUTORES E DESTRUTOR ----------

Dealer::Dealer(){};

Dealer::Dealer(Baralho* baralho, Mesa* mesa):
    baralho(*baralho), mesa(*mesa){}

Dealer::~Dealer(){};

// ---------- GETTERS E SETTERS ----------

Baralho Dealer::getBaralho() const {
    return baralho;
}

bool Dealer::setBaralho(Baralho* baralho) {
    this->baralho = *baralho;
    return true;
}

Mesa Dealer::getMesa() const {
    return mesa;
}

bool Dealer::setMesa(Mesa* mesa) {
    this->mesa = *mesa;
    return true;
}

// ---------- MÉTODOS ----------

bool Dealer::distribui(Jogador* jogador) {

    Carta* carta;

    for(int i = 0; i < 2; i++) {
        carta = baralho.compraCarta();
        jogador->adicionaCarta(carta);
    }
}

bool Dealer::distribui() {

    if(strcmp(mesa.getRodada(), "PRE_FLOP")) {
    
    }
}

bool Dealer::premia(Jogador* jogador) {
    // Dá os pontos ao vencedor
    jogador->setPontos(this->mesa.getAposta());
    // Zera a aposta
    this->mesa.setAposta(0);
}
