#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Componente
class Componente {
public:
    virtual ~Componente() = default;
    virtual void operacao() const = 0;
};

// Folha
class Folha : public Componente {
public:
    void operacao() const override {
        cout << "Operação da folha" << endl;
    }
};

// Composto
class Composto : public Componente {
public:
    void adicionar(unique_ptr<Componente> componente) {
        filhos_.push_back(move(componente));
    }
    void operacao() const override {
        cout << "Operação do composto" << endl;
        for (const auto& filho : filhos_) {
            filho->operacao();
        }
    }
private:
    vector<unique_ptr<Componente>> filhos_;
};

int main() {
    auto folha1 = make_unique<Folha>();
    auto folha2 = make_unique<Folha>();
    auto folha3 = make_unique<Folha>();

    auto composto1 = make_unique<Composto>();
    composto1->adicionar(move(folha1));
    composto1->adicionar(move(folha2));

    auto composto2 = make_unique<Composto>();
    composto2->adicionar(move(folha3));
    composto2->adicionar(move(composto1));

    composto2->operacao();

    return 0;
}
