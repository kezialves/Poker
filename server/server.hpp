#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include "../mesa.hpp"
#include <vector>

using namespace std;

/**
* @brief Classe que representa o servidor.
*/
class Server {

protected:
    Mesa* mesa; ///< Mesa do jogo.
    static vector<Jogador*> jogadores; ///< Todos os jogadores do servidor.
    int porta; ///< Porta de conexão.
    int portaMargem; ///< Para tentar mais de uma porta.
    char ip[10] = "127.0.0.1"; ///< IP (127.0.0.1 é localhost, alterar se cliente e servidor estiverem em máquinas distintas).
    int maxJogadoresMesa; ///< Máximo de jogadores permitidos em uma mesa.

private:
    // Métodos da forma canônica que não usamos.

    /**
    * @brief Setter do IP do servidor.
    * @param IP Valor char* a ser definido para o atributo da classe
    * @return true se for atribuído com sucesso, false caso contrário.
    */
    bool setIP(char*);

    /**
    * @brief Setter do número máximo de jogadores em uma mesa do servidor.
    * @param maxJogadoresMesa Valor int a ser definido para o atributo da classe
    * @return true se for atribuído com sucesso, false caso contrário.
    */
    bool setMaxJogadoresMesa(int);

public:
    static int totalConexoes; ///< Quantas conexões foram feitas. ID para cada player.
    static bool primeiraConexao; ///< Variável de controle da mesa.

    // ---------- CONSTRUTOR E DESTRUTOR ----------

    /**
    * @brief Construtor completo de Server.
    * @param porta Porta de conexão.
    * @param portaMargem Para tentar mais de uma porta.
    * @param maxJogadoresMesa = 6 Máximo de jogadores permitidos em uma mesa.
    */
    Server(int porta, int portaMargem, int maxJogadoresMesa = 6);

    /**
    * @brief Destrutor virtual de Server.
    */
    virtual ~Server();

    // ---------- GETTERS E SETTERS ----------

    /**
    * @brief Getter da porta de conexão do servidor.
    * @return Porta do servidor.
    */
    int getPorta() const;

    /**
    * @brief Setter da porta de conexão do servidor.
    * @param porta Valor int a ser definido para o atributo da classe.
    * @return true se for atribuído com sucesso, false caso contrário.
    */
    bool setPorta(int);

    /**
    * @brief Getter da margem de erro da porta de conexão do servidor.
    * @return Margem de erro da porta do servidor.
    */
    int getPortaMargem() const;

    /**
    * @brief Setter da margem de erro da porta de conexão do servidor.
    * @param portaMargem Valor int a ser definido para o atributo da classe.
    * @return true se for atribuído com sucesso, false caso contrário.
    */
    bool setPortaMargem(int);

    /**
    * @brief Getter do IP do servidor.
    * @return IP do servidor.
    */
    const char* getIP() const;

    /**
    * @brief Getter do número máximo de jogadores em uma mesa do servidor.
    * @return Número máximo de jogadores em uma mesa do servidor.
    */
    int getMaxJogadoresMesa() const;

    // ---------- MÉTODOS ----------

    /**
    * @brief Adiciona um novo jogador ao servidor.
    * @param jogador Novo jogador.
    * @return true caso a operação tenha sucesso, false caso contrário.
    */
    static bool adicionaJogador(Jogador*);

    /**
    * @brief Função que acessa o total de jogadores no servidor.
    * @return Total de jogadores no servidor.
    */
    int totalJogadores();

    /**
    * @brief Verifica se há vaga para um novo jogador na mesa.
    * @return true caso haja vaga, false caso contrário.
    */
    bool vagaDisponivel();

    /**
    * @brief Inicializa o servidor.
    * @return true caso o servidor funcione corretamente, false caso contrário.
    */
    bool inicia();
};

/**
* @brief Função que realiza todo o procedimento de conexão de um novo jogador.
*/
void *conexaoNovoJogador(void*);

// Caso tenha mais de uma mesa.
// /**
// * @brief Distribuição de uma thread nova.
// */
// void *iniciaMesa(void*);

#endif
