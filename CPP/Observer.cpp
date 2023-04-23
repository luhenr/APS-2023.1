#include <iostream>
#include <vector>
using namespace std;

// Classe Observador
class Observador
{
public:
    virtual void atualizar(int valor) = 0;
};

// Classe Sujeito
class Sujeito
{
private:
    vector<Observador *> observadores;
    int valor;

public:
    void adicionarObservador(Observador *obs)
    {
        observadores.push_back(obs);
    }

    void removerObservador(Observador *obs)
    {
        for (int i = 0; i < observadores.size(); i++)
        {
            if (observadores[i] == obs)
            {
                observadores.erase(observadores.begin() + i);
                break;
            }
        }
    }

    void notificarObservadores()
    {
        for (int i = 0; i < observadores.size(); i++)
        {
            observadores[i]->atualizar(valor);
        }
    }

    void setValor(int novoValor)
    {
        valor = novoValor;
        notificarObservadores();
    }
};

// Classe Observador Concreto
class ObservadorConcreto : public Observador
{
public:
    void atualizar(int valor)
    {
        cout << "Valor atualizado para: " << valor << endl;
    }
};

int main()
{
    Sujeito *sujeito = new Sujeito();
    Observador *obs1 = new ObservadorConcreto();
    Observador *obs2 = new ObservadorConcreto();
    sujeito->adicionarObservador(obs1);
    sujeito->adicionarObservador(obs2);
    sujeito->setValor(5);
    sujeito->removerObservador(obs1);
    sujeito->setValor(10);

    delete sujeito;
    delete obs1;
    delete obs2;
    return 0;
}
