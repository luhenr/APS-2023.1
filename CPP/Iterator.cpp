#include <iostream>
#include <vector>

using namespace std;

// Definindo a interface do Iterator
class Iterator {
public:
    virtual int proximo() = 0;
    virtual bool temProximo() = 0;
};

// Implementando o Iterator para percorrer um vetor de inteiros
class IteratorVetor : public Iterator {
private:
    vector<int>* vetor; // Ponteiro para o vetor
    int indice; // Índice do elemento atual

public:
    IteratorVetor(vector<int>* vetor) {
        this->vetor = vetor;
        this->indice = 0;
    }

    // Retorna o próximo elemento do vetor
    int proximo() {
        if (!temProximo()) {
            throw out_of_range("Fim da iteração alcançado");
        }
        return (*vetor)[indice++];
    }

    // Verifica se ainda existe um próximo elemento no vetor
    bool temProximo() {
        return indice < vetor->size();
    }
};

int main() {
    vector<int> vetor = {1, 2, 3, 4, 5};
    IteratorVetor it(&vetor);

    while (it.temProximo()) {
        cout << it.proximo() << " ";
    }
    cout << endl;

    return 0;
}
