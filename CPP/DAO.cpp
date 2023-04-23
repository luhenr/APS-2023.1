#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Classe modelo de dados para clientes
class Cliente
{
private:
    int id;
    string nome;
    string email;
    string telefone;

public:
    Cliente() {}
    Cliente(int id, string nome, string email, string telefone)
        : id(id), nome(nome), email(email), telefone(telefone) {}

    // Getters e Setters
    int getId() const { return id; }
    void setId(int id) { this->id = id; }
    string getNome() const { return nome; }
    void setNome(string nome) { this->nome = nome; }
    string getEmail() const { return email; }
    void setEmail(string email) { this->email = email; }
    string getTelefone() const { return telefone; }
    void setTelefone(string telefone) { this->telefone = telefone; }
};

// Interface DAO para clientes
class ClienteDAO
{
public:
    virtual ~ClienteDAO() {}

    // Inserir um cliente na tabela
    virtual void inserir(const Cliente &cliente) = 0;

    // Atualizar um cliente na tabela
    virtual void atualizar(const Cliente &cliente) = 0;

    // Remover um cliente da tabela
    virtual void remover(int id) = 0;

    // Buscar um cliente na tabela pelo ID
    virtual Cliente buscarPorId(int id) = 0;

    // Buscar todos os clientes na tabela
    virtual vector<Cliente> buscarTodos() = 0;
};

// Implementação DAO para clientes utilizando um vector em memória
class ClienteDAOVector : public ClienteDAO
{
private:
    vector<Cliente> clientes;
    int proximoId;

public:
    ClienteDAOVector() : proximoId(1) {}

    // Inserir um cliente na tabela
    void inserir(const Cliente &cliente) override
    {
        clientes.push_back(cliente);
        clientes.back().setId(proximoId++);
    }

    // Atualizar um cliente na tabela
    void atualizar(const Cliente &cliente) override
    {
        for (auto &c : clientes)
        {
            if (c.getId() == cliente.getId())
            {
                c = cliente;
                break;
            }
        }
    }

    // Remover um cliente da tabela
    void remover(int id) override
    {
        for (auto it = clientes.begin(); it != clientes.end(); ++it)
        {
            if (it->getId() == id)
            {
                clientes.erase(it);
                break;
            }
        }
    }

    // Buscar um cliente na tabela pelo ID
    Cliente buscarPorId(int id) override
    {
        for (auto &c : clientes)
        {
            if (c.getId() == id)
            {
                return c;
            }
        }
        return Cliente();
    }

    // Buscar todos os clientes na tabela
    vector<Cliente> buscarTodos() override
    {
        return clientes;
    }
};

int main()
{
    ClienteDAOVector dao;

    // Inserir um cliente
    Cliente c1(0, "João", "joao@gmail.com", "(11) 99999-9999");
    dao.inserir(c1);
    cout << "Cliente inserido: " << c1.getNome() << endl;

    // Atualizar um cliente
    c1.setNome("João Silva");
    dao.atualizar(c1);
    cout << "Cliente atualizado: " << c1.getNome() << endl;

    // Remover um cliente
    dao.remover(c1.getId());
    cout << "Cliente removido: " << c1.getNome() << endl;
    // Inserir mais clientes
    Cliente c2(0, "Maria", "maria@gmail.com", "(11) 88888-8888");
    dao.inserir(c2);
    Cliente c3(0, "Pedro", "pedro@gmail.com", "(11) 77777-7777");
    dao.inserir(c3);

    // Buscar um cliente pelo ID
    Cliente c4 = dao.buscarPorId(c2.getId());
    cout << "Cliente encontrado: " << c4.getNome() << endl;

    // Buscar todos os clientes
    vector<Cliente> todos = dao.buscarTodos();
    cout << "Clientes cadastrados:" << endl;
    for (auto &c : todos)
    {
        cout << "ID: " << c.getId() << ", Nome: " << c.getNome() << ", Email: " << c.getEmail() << ", Telefone: " << c.getTelefone() << endl;
    }

    return 0;
}
