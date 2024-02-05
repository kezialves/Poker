#include "mesa.hpp"

// ---------- CONSTRUTOR E DESTRUTOR ----------

Mesa::Mesa(){};
Mesa::~Mesa(){};

// ---------- ITERADORES ----------

Mesa::CartaIterador Mesa::cartasInicio() {
    return cartas.begin();
}

Mesa::CartaIterador Mesa::cartasFim() {
    return cartas.end();
}

Mesa::JogadorIterador Mesa::jogadoresInicio() {
    return jogadores.begin();
}

Mesa::JogadorIterador Mesa::jogadoresFim() {
    return jogadores.end();
}

// ---------- GETTERS E SETTERS ----------

Rodada Mesa::getRodada() const {
    return rodada;
}

bool Mesa::setRodada(Rodada* rodada) {
    this->rodada = *rodada;
    return true;
}

int Mesa::getAposta() const {
    return aposta;
}

bool Mesa::setAposta(int aposta) {
    this->aposta = aposta;
    return true;
}
