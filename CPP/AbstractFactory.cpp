#include <iostream>
using namespace std;

// Abstract Product A
class Carro
{
public:
    virtual void descricao() = 0;
};

// Concrete Product A1
class Palio : public Carro
{
public:
    void descricao()
    {
        cout << "Fiat Palio" << endl;
    }
};

// Concrete Product A2
class Uno : public Carro
{
public:
    void descricao()
    {
        cout << "Fiat Uno" << endl;
    }
};

// Abstract Product B
class Moto
{
public:
    virtual void descricao() = 0;
};

// Concrete Product B1
class CG : public Moto
{
public:
    void descricao()
    {
        cout << "Honda CG 150" << endl;
    }
};

// Concrete Product B2
class PalioMoto : public Moto
{
public:
    void descricao()
    {
        cout << "Fiat Palio Moto" << endl;
    }
};

// Abstract Factory
class FabricaDeVeiculos
{
public:
    virtual Carro *criarCarro() = 0;
    virtual Moto *criarMoto() = 0;
};

// Concrete Factory 1
class FabricaFiat : public FabricaDeVeiculos
{
public:
    Carro *criarCarro()
    {
        return new Palio();
    }
    Moto *criarMoto()
    {
        return new PalioMoto();
    }
};

// Concrete Factory 2
class FabricaHonda : public FabricaDeVeiculos
{
public:
    Carro *criarCarro()
    {
        return new Palio();
    }
    Moto *criarMoto()
    {
        return new CG();
    }
};

// Função principal
int main()
{
    FabricaDeVeiculos *fabrica;
    Carro *carro;
    Moto *moto;

    // Fabrica Fiat
    fabrica = new FabricaFiat();
    carro = fabrica->criarCarro();
    moto = fabrica->criarMoto();

    carro->descricao();
    moto->descricao();

    // Fabrica Honda
    fabrica = new FabricaHonda();
    carro = fabrica->criarCarro();
    moto = fabrica->criarMoto();

    carro->descricao();
    moto->descricao();

    return 0;
}
