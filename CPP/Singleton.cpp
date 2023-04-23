#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton &obterInstancia()
    {
        static Singleton instancia;
        return instancia;
    }

    void fazerAlgo()
    {
        cout << "Singleton::fazerAlgo()" << endl;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    Singleton() {}
};

int main()
{
    Singleton &singleton = Singleton::obterInstancia();
    singleton.fazerAlgo();

    return 0;
}
