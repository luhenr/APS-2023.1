#include <iostream>
#include <memory>

using namespace std;

// Protótipo
class Prototipo {
public:
    virtual ~Prototipo() = default;
    virtual unique_ptr<Prototipo> clonar() const = 0;
    virtual void operacao() const = 0;
};

// Implementação concreta do protótipo
class ImplementacaoConcreta : public Prototipo {
public:
    unique_ptr<Prototipo> clonar() const override {
        return make_unique<ImplementacaoConcreta>(*this);
    }
    void operacao() const override {
        cout << "Operação da implementação concreta" << endl;
    }
};

int main() {
    auto prototipo = make_unique<ImplementacaoConcreta>();
    auto clone = prototipo->clonar();

    prototipo->operacao();
    clone->operacao();

    return 0;
}
