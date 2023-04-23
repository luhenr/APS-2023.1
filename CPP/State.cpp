#include <iostream>
using namespace std;

// Classe State
class Estado
{
public:
    virtual void lidarComEstado() = 0;
};

// Classe ConcreteStateA
class EstadoA : public Estado
{
public:
    void lidarComEstado()
    {
        cout << "Lidando com o estado A." << endl;
    }
};

// Classe ConcreteStateB
class EstadoB : public Estado
{
public:
    void lidarComEstado()
    {
        cout << "Lidando com o estado B." << endl;
    }
};

// Classe Contexto
class Contexto
{
private:
    Estado *estadoAtual;

public:
    Contexto()
    {
        estadoAtual = new EstadoA();
    }

    void setEstado(Estado *novoEstado)
    {
        estadoAtual = novoEstado;
    }

    void lidarComEstadoAtual()
    {
        estadoAtual->lidarComEstado();
    }
};

int main()
{
    Contexto contexto;

    contexto.lidarComEstadoAtual();
    contexto.setEstado(new EstadoB());
    contexto.lidarComEstadoAtual();

    return 0;
}
