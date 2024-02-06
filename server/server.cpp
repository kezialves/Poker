#include "server.hpp"

#include <iostream>
#include <vector>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <pthread.h>    /* POSIX Threads */ 
#include <stdlib.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>    // htons(), inet_addr()
#include <sys/types.h>    // AF_INET, SOCK_STREAM

vector<Jogador*> Server::jogadores;
bool Server::primeiraConexao;
int Server::totalConexoes;

using namespace std;

// Variável global para controlar o acesso a região de memória.
pthread_mutex_t mutex;

// Variável global para o ID dos threads.
#define NUM_THREADS 30

// ---------- CONSTRUTOR E DESTRUTOR ----------

Server::Server(int porta, int portaMargem, int maxJogadoresMesa) :
    porta(porta), portaMargem(portaMargem), maxJogadoresMesa(maxJogadoresMesa){}

Server::~Server(){}

// ---------- GETTERS E SETTERS ----------

int Server::getPorta() const{
    return porta;
}
bool Server::setPorta(int){
    this->porta = porta;
    return true;
}

int Server::getPortaMargem() const{
    return portaMargem;
}
bool Server::setPortaMargem(int){
    this->portaMargem = portaMargem;
    return true;
}

const char* Server::getIP() const{
    return ip;
}

int Server::getMaxJogadoresMesa() const{
    return maxJogadoresMesa;
}

// ---------- MÉTODOS ----------

bool Server::adicionaJogador(Jogador *jogador) {
    jogadores.push_back(jogador);
    return true;
}

int Server::totalJogadores() {
    return jogadores.size();
}

bool Server::vagaDisponivel() {

    if(this->totalJogadores() < this->getMaxJogadoresMesa()) {
        return true;
    }

    return false;
}

bool Server::inicia() {

    int welcomeSocket; // recebe as comunicações iniciais
    int newSocket; // delega a comunicação

    //Structure describing an Internet socket address
    struct sockaddr_in serverAddr; // necessária para passar como parâmetro no ponteiro de função do thread

    socklen_t addr_size; // tamanho do endereço armazenado no socket
    pthread_attr_t attr; // tamanho da stack, endereço da stack
    pthread_attr_init(&attr); //inicializa os atributos do phtread

    //The pthread_detach() function shall indicate to the implementation that storage
    //for the thread thread can be reclaimed when that thread terminates. 
    //If thread has not terminated, pthread_detach() shall not cause it to terminate. 
    //The effect of multiple pthread_detach() calls on the same target thread is unspecified.
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); // quando pode terminar

    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0); // inicializando o socket do servidor para receber as conexões

    serverAddr.sin_family = AF_INET; // inicializando campos do endereço
    serverAddr.sin_port = htons(this->porta); // definindo a porta do endereço
    serverAddr.sin_addr.s_addr = inet_addr(this->ip); 

    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero); // copiando o conteúdo de um endereço para o outro
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)); // adiciona o endereço local já definido para utilizar no nosso próprio socket
    pthread_mutex_init(&mutex, NULL); // inicialização do mutex para controlar o acesso em região crítica da memória

    // socket vai ouvir até NUM_THREADS conexões
    if(listen(welcomeSocket,NUM_THREADS) == 0)
        cout << "Ouvindo." << endl;
    else
        cout << "Erro!" << endl;

    // loop conexões
    while(!primeiraConexao || totalJogadores() > 0){

        cout << "Esperando conexão do jogador..." << endl;

        newSocket = accept(welcomeSocket, (struct sockaddr *) NULL, NULL); // se houver uma nova conexão, definimos o newSocket como socket 
        pthread_mutex_lock(&mutex); // trava o semáforo pela entrada na região crítica
        
        // se não tiver vaga na mesa atual, imprime uma mensagem informando a indisponibilidade de entrar na mesa
        if(!vagaDisponivel()){
            cout << "Mesa cheia no momento! Tente novamente mais tarde." << endl;
        }

        pthread_mutex_unlock(&mutex); // destravar o semáforo para deixar a região crítica livre

        // cria thread para adicionar um novo jogador
        pthread_t newPlayerThread;
        pthread_create (&newPlayerThread, &attr, conexaoNovoJogador, &welcomeSocket);
        // verificar o mutex da thread do jogador para não permitir entrada em jogo em andamento
    }

    // limpa tudo
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutex);

    return true;
}

void *conexaoNovoJogador(void* param) {

    // Se for a primeira conexão no servidor.
    Server::primeiraConexao = true;
    tuple<int,Mesa*>* tupleSocketTable = (tuple<int,Mesa*>*) param;

    // Extraindo os valores da tupla para usar posteriormente.
    int socket = get<0>(*tupleSocketTable);
    Mesa *mesa = get<1>(*tupleSocketTable);

    char buffer[1024];
    recv(socket, buffer, sizeof(buffer), 0);

    int id = 0;
    string nome = "KezJesca";
    
    Jogador jogador(buffer, id, nome, socket);
    Server::adicionaJogador(&jogador);

    cout << jogador.getNome() << " conectou." << endl;

    pthread_exit(NULL);
}

// ---------- MAIN ----------

int main() {

    Server *server = new Server(25555, 10, 10); // porta, portaRange, número máximo de jogadores conectados
    server->inicia();

    return 0;
}
