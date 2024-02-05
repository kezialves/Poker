#ifndef _MESA_HPP_
#define _MESA_HPP_

#include "carta.hpp"
#include "jogador.hpp"

using namespace std;

// Quantidade de cartas à mostra em cada rodada
enum class Rodada {
    PRE_FLOP = 2,
    FLOP = 3,
    TURN = 4,
    RIVER = 5
};

class Mesa {
    vector<Carta*> cartas;
    vector<Jogador*> jogadores;
    Rodada rodada;
    int aposta;

    public:
        // Construtor padrão de Mesa
        Mesa();
        // Destrutor virtual de Mesa
        virtual ~Mesa();

        // Iterador das cartas
        typedef vector<Carta*>::iterator CartaIterador;
        CartaIterador cartasInicio();
        CartaIterador cartasFim();

        // Iterador dos jogadores
        typedef vector<Jogador*>::iterator JogadorIterador;
        JogadorIterador jogadoresInicio();
        JogadorIterador jogadoresFim();

        // Getter da rodada
        Rodada getRodada() const;
        // Setter da rodada
        bool setRodada(Rodada*);

        // Getter da aposta
        int getAposta() const;
        // Setter da aposta
        bool setAposta(int);
};

#endif
