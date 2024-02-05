#ifndef _CARTA_HPP_
#define _CARTA_HPP_

#include <vector>

// Valores das cartas
enum Valor {
    DOIS = 2,
    TRES = 3,
    QUATRO = 4,
    CINCO = 5,
    SEIS = 6,
    SETE = 7,
    OITO = 8,
    NOVE = 9,
    DEZ = 10,
    VALETE = 11,
    RAINHA = 12,
    REI = 13,
    AS = 14
};

// Ordem de precedência dos naipes
enum Naipe {
    PAUS = 1,
    OUROS = 2,
    COPAS = 3,
    ESPADAS = 4
};

class Carta {
    Valor valor;
    Naipe naipe;

    public:
        // Construtor padrão de Carta
        Carta();
        // Construtor completo de Carta
        Carta(Valor*, Naipe*);
        // Destrutor virtual de Carta
        virtual ~Carta();

        // Getter do valor
        Valor getValor() const;
        // Setter do valor
        bool setValor(Valor*);

        // Getter do naipe
        Naipe getNaipe() const;
        // Setter do naipe
        bool setNaipe(Naipe*);

        // Compara duas cartas para ver qual é a maior
        Carta& operator >(const Carta&);

        // // Compara igualdade numérica de duas cartas
        // bool operator ==(const Valor &valor);
};

#endif
