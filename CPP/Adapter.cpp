#include <iostream>
#include <memory>

using namespace std;

// Interface alvo
class Alvo {
public:
    virtual ~Alvo() = default;
    virtual void operacao() const = 0;
};

// Classe alvo
class ClasseAlvo : public Alvo {
public:
    void operacao() const override {
        cout << "Operação da classe alvo" << endl;
    }
};

// Interface adaptada
class Adaptada {
public:
    virtual ~Adaptada() = default;
    virtual void outraOperacao() const = 0;
};

// Classe adaptada
class ClasseAdaptada : public Adaptada {
public:
    void outraOperacao() const override {
        cout << "Outra operação da classe adaptada" << endl;
    }
};

// Adaptador
class Adaptador : public Alvo {
public:
    Adaptador(unique_ptr<Adaptada> adaptada) : adaptada_(move(adaptada)) {}
    void operacao() const override {
        adaptada_->outraOperacao();
    }
private:
    unique_ptr<Adaptada> adaptada_;
};

int main() {
    auto classeAlvo = make_unique<ClasseAlvo>();
    classeAlvo->operacao();

    auto classeAdaptada = make_unique<ClasseAdaptada>();
    auto adaptador = make_unique<Adaptador>(move(classeAdaptada));
    adaptador->operacao();

    return 0;
}
