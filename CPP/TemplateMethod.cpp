#include <iostream>

using namespace std;

class Base {
public:
    void metodoTemplate() {
        operacaoPrimitiva1();
        operacaoPrimitiva2();
        if (gancho()) {
            operacaoPrimitiva3();
        }
    }

private:
    virtual void operacaoPrimitiva1() = 0;
    virtual void operacaoPrimitiva2() = 0;
    virtual void operacaoPrimitiva3() = 0;
    virtual bool gancho() {
        return true;
    }
};

class Derivada : public Base {
private:
    void operacaoPrimitiva1() override {
        cout << "Derivada: operacaoPrimitiva1" << endl;
    }

    void operacaoPrimitiva2() override {
        cout << "Derivada: operacaoPrimitiva2" << endl;
    }

    void operacaoPrimitiva3() override {
        cout << "Derivada: operacaoPrimitiva3" << endl;
    }

    bool gancho() override {
        return false;
    }
};

int main() {
    Base* base = new Derivada();
    base->metodoTemplate();
    delete base;
    return 0;
}
