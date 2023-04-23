#include <iostream>
using namespace std;

// Componente base
class Componente
{
public:
    virtual void operacao() = 0;
};

// Componente concreto
class ComponenteConcreto : public Componente
{
public:
    void operacao()
    {
        cout << "Executando a operacao do componente concreto." << endl;
    }
};

// Decorador base
class Decorador : public Componente
{
protected:
    Componente *componente;

public:
    Decorador(Componente *c)
    {
        componente = c;
    }
    void operacao()
    {
        componente->operacao();
    }
};

// Decorador concreto
class DecoradorConcreto : public Decorador
{
public:
    DecoradorConcreto(Componente *c) : Decorador(c) {}
    void operacao()
    {
        cout << "Executando a operacao do decorador concreto." << endl;
        componente->operacao();
    }
};

// Programa principal
int main()
{
    Componente *componente = new ComponenteConcreto();
    componente->operacao();

    Componente *decorador = new DecoradorConcreto(componente);
    decorador->operacao();

    delete componente;
    delete decorador;

    return 0;
}
