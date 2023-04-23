#include <iostream>
using namespace std;

class subSistemaA
{
public:
    void operacaoA()
    {
        cout << "operacaoA subSistemaA" << endl;
    }
};

class subSistemaB
{
public:
    void operacaoB()
    {
        cout << "operacaoB subSistemaB" << endl;
    }
};

class subSistemaC
{
public:
    void operacaoC()
    {
        cout << "operacaoC subSistemaC" << endl;
    }
};

class Facade
{
public:
    Facade()
    {
        m_subSistemaA = new subSistemaA();
        m_subSistemaB = new subSistemaB();
        m_subSistemaC = new subSistemaC();
    }

    ~Facade()
    {
        delete m_subSistemaA;
        delete m_subSistemaB;
        delete m_subSistemaC;
    }

    void operation1()
    {
        cout << "operacao 1\n";
        m_subSistemaA->operacaoA();
        m_subSistemaB->operacaoB();
    }

    void operation2()
    {
        cout << "operacao 2\n";
        m_subSistemaB->operacaoB();
        m_subSistemaC->operacaoC();
    }

private:
    subSistemaA *m_subSistemaA;
    subSistemaB *m_subSistemaB;
    subSistemaC *m_subSistemaC;
};

int main()
{
    Facade facade;

    facade.operation1();
    facade.operation2();

    return 0;
}
