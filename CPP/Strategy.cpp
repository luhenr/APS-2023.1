#include <iostream>
using namespace std;

// Classe Estratégia
class Estrategia
{
public:
    virtual void executar() = 0;
};

// Classe Estratégia Concreta A
class EstrategiaA : public Estrategia
{
public:
    void executar()
    {
        cout << "Executando a Estratégia A." << endl;
    }
};

// Classe Estratégia Concreta B
class EstrategiaB : public Estrategia
{
public:
    void executar()
    {
        cout << "Executando a Estratégia B." << endl;
    }
};

// Classe Contexto
class Contexto
{
private:
    Estrategia *estrategia;

public:
    void setEstrategia(Estrategia *novaEstrategia)
    {
        estrategia = novaEstrategia;
    }

    void executarEstrategia()
    {
        estrategia->executar();
    }
};

int main()
{
    Contexto contexto;
    Estrategia *estrategiaA = new EstrategiaA();
    Estrategia *estrategiaB = new EstrategiaB();

    contexto.setEstrategia(estrategiaA);
    contexto.executarEstrategia();

    contexto.setEstrategia(estrategiaB);
    contexto.executarEstrategia();

    delete estrategiaA;
    delete estrategiaB;
    return 0;
}
