#include "jogador.hpp"

// ---------- CONSTRUTORES E DESTRUTOR ----------

Jogador::Jogador(){};

Jogador::Jogador(int id, string nome, int socket, int pontos):
    id(id), nome(nome), socket(socket), pontos(pontos){}

Jogador::~Jogador(){};

// ---------- GETTER E SETTER ----------

int Jogador::getID() const {
    return id;
}

bool Jogador::setID(int id) {
    this->id = id;
    return true;
}

string Jogador::getNome() const {
    return nome;
}

bool Jogador::setNome(string nome) {
    this->nome = nome;
    return true;
}

int Jogador::getSocket() const {
    return socket;
}

bool Jogador::setSocket(int socket) {
    this->socket = socket;
    return true;
}

int Jogador::getPontos() const {
    return pontos;
}

bool Jogador::setPontos(int pontos) {
    this->pontos = pontos;
    return true;
}

Status Jogador::getStatus() const {
    return status;
}

bool Jogador::setStatus(Status* status) {
    this->status = *status;
    return true;
}

// ---------- MÉTODOS ----------

bool Jogador::adicionaCarta(Carta* carta) {
    cartas.push_back(carta);
    return true;
}

// bool Jogador::fold() {
//     this->setStatus(FORA);
// }

// bool Jogador::check(vector<Carta*> cartas) {

// }

// bool Jogador::call(vector<Carta*> cartas) {
    
// }

// bool Jogador::bet(vector<Carta*> cartas) {
    
// }
