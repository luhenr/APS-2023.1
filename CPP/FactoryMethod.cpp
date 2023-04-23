#include <iostream>
#include <string>

using namespace std;

class Produto {
    public:
        virtual void operacao() = 0;
};

class ProdutoConcreto : public Produto {
    public:
        void operacao() override {
            cout<<"ProdutoConcreto:: operacao()"<<endl;
        }
};

class Fabrica {
    public:
        virtual Produto* factoryMethod() = 0;

        void outraOperacao() {
            Produto* produto = factoryMethod();
            produto->operacao();
            delete produto;
        } 
};

class FabricaConcreta : public Fabrica {
    public:
        Produto* factoryMethod() override {
            return new ProdutoConcreto();
        }
};

int main(){
    Fabrica* fabrica = new FabricaConcreta();
    fabrica->outraOperacao();
    delete fabrica;
    return 0;
}