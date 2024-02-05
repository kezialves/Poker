#ifndef _BARALHO_HPP_
#define _BARALHO_HPP_

#include "carta.hpp"
#include <vector>

using namespace std;

class Baralho {

    public:
        vector<Carta*> cartas;
        
        // Construtor de Baralho
        Baralho();
        // Destrutor virtual de Baralho
        virtual ~Baralho();

        // Inicializa o baralho com 52 cartas 
        bool inicializa();

        // Embaralha o deck
        bool embaralha();

        // Realiza a compra de uma carta do monte
        Carta* compraCarta();
};

#endif
