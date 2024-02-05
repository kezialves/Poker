#include "baralho.hpp"
#include <iostream>

using namespace std;

int main() {

    Baralho* baralho = new Baralho();

    baralho->inicializa();

    for(int i = 0; i < 52; i++) {
        cout << baralho->cartas[i]->getValor() << " - "
             << baralho->cartas[i]->getNaipe() << endl;
    }

    baralho->embaralha();
    
    delete baralho;

    return 0;
}
