using System;

// Interface de Expressão
interface IExpressao
{
    bool Interpretar(string contexto);
}

// Classe Terminal
class Terminal : IExpressao
{
    private readonly string palavra;

    public Terminal(string palavra)
    {
        this.palavra = palavra;
    }

    public bool Interpretar(string contexto)
    {
        return contexto.Contains(palavra);
    }
}

// Classe Não Terminal
class NaoTerminal : IExpressao
{
    private readonly IExpressao expressao1;
    private readonly IExpressao expressao2;

    public NaoTerminal(IExpressao expressao1, IExpressao expressao2)
    {
        this.expressao1 = expressao1;
        this.expressao2 = expressao2;
    }

    public bool Interpretar(string contexto)
    {
        return expressao1.Interpretar(contexto) && expressao2.Interpretar(contexto);
    }
}

// Classe Contexto
class Contexto
{
    private readonly string contexto;

    public Contexto(string contexto)
    {
        this.contexto = contexto;
    }

    public bool Interpretar(IExpressao expressao)
    {
        return expressao.Interpretar(contexto);
    }
}

// Programa principal
class Program
{
    static void Main(string[] args)
    {
        Contexto contexto = new Contexto("texto de exemplo");

        IExpressao expressao1 = new Terminal("texto");
        IExpressao expressao2 = new Terminal("exemplo");

        IExpressao expressaoComposta = new NaoTerminal(expressao1, expressao2);

        bool resultado = contexto.Interpretar(expressaoComposta);

        Console.WriteLine("A expressão foi " + (resultado ? "verdadeira" : "falsa"));
    }
}
