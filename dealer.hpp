#ifndef _DEALER_HPP_
#define _DEALER_HPP_

#include "baralho.hpp"
#include "mesa.hpp"

class Dealer {
    Baralho baralho;
    Mesa mesa;

    public:
        // Construtor padrão de Dealer
        Dealer();
        // Construtor completo de Dealer
        Dealer(Baralho*, Mesa*);
        // Destrutor virtual de Dealer
        virtual ~Dealer();

        // Getter do baralho
        Baralho getBaralho() const;
        // Setter do baralho
        bool setBaralho(Baralho*);

        // Getter da mesa
        Mesa getMesa() const;
        // Setter da mesa
        bool setMesa(Mesa*);

        // Distribui as cartas a um jogador
        bool distribui(Jogador*);

        // Distribui carta(s) à mesa
        bool distribui();

        // Atribui o valor da aposta aos pontos do jogador vencedor
        bool premia(Jogador*);
};

#endif
