#ifndef _JOGADOR_HPP_
#define _JOGADOR_HPP_

#include "carta.hpp"
#include <string>
#include <vector>

using namespace std;

enum class Status {
    ESPERA = 1,
    APOSTA = 2,
    FORA = 3
};

class Jogador {
    int id;
    string nome;
    int socket;
    vector<Carta*> cartas;
    int pontos;
    Status status;

    public:
        // Construtor padrão de Jogador
        Jogador();
        // Construtor de Jogador com ID, nome, socket e pontos
        Jogador(int, string, int, int);
        // Destrutor virtual de Jogador
        virtual ~Jogador();

        // Getter do ID
        int getID() const;
        // Setter do ID
        bool setID(int);

        // Getter do nome
        string getNome() const;
        // Setter do nome
        bool setNome(string);

        // Getter do socket
        int getSocket() const;
        // Setter do socket
        bool setSocket(int);

        // Getter dos pontos
        int getPontos() const;
        // Setter dos pontos
        bool setPontos(int);

        // Getter do status
        Status getStatus() const;
        // Setter do status
        bool setStatus(Status*);

        // Adiciona uma carta à mão
        bool adicionaCarta(Carta*);

        // Desiste da rodada
        bool fold();

        // Pula a ação para ver a próxima carta
        bool check(vector<Carta*>);

        // Aceita aposta de outro jogador
        bool call(vector<Carta*>);

        // Aposta
        bool bet(vector<Carta*>);
};

#endif
