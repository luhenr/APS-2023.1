#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe abstrata do Mediador
class Mediador {
public:
    virtual void enviarMensagem(string mensagem, class Colega* colega) = 0;
};

// Classe Colega
class Colega {
protected:
    Mediador* mediador;

public:
    Colega(Mediador* m) : mediador(m) {}

    virtual void enviar(string mensagem) = 0;
    virtual void receber(string mensagem) = 0;
};

// Implementação concreta de Colega
class ColegaConcreto : public Colega {
public:
    ColegaConcreto(Mediador* m) : Colega(m) {}

    void enviar(string mensagem) override {
        cout << "Enviando a mensagem: " << mensagem << endl;
        mediador->enviarMensagem(mensagem, this);
    }

    void receber(string mensagem) override {
        cout << "Recebendo a mensagem: " << mensagem << endl;
    }
};

// Implementação concreta do Mediador
class MediadorConcreto : public Mediador {
protected:
    vector<Colega*> colegas;

public:
    void adicionarColega(Colega* colega) {
        colegas.push_back(colega);
    }

    void enviarMensagem(string mensagem, Colega* remetente) override {
        for (auto colega : colegas) {
            if (colega != remetente) {
                colega->receber(mensagem);
            }
        }
    }
};

// Função principal
int main() {
    MediadorConcreto* mediador = new MediadorConcreto();
    ColegaConcreto* colega1 = new ColegaConcreto(mediador);
    ColegaConcreto* colega2 = new ColegaConcreto(mediador);

    mediador->adicionarColega(colega1);
    mediador->adicionarColega(colega2);

    colega1->enviar("Olá, colega!");
    colega2->enviar("Oi, tudo bem?");
    
    delete mediador;
    delete colega1;
    delete colega2;
    
    return 0;
}
