using System;
using System.Collections.Generic;

// A classe Flyweight representa a parte compartilhada dos objetos.
class Flyweight {
    private readonly string intrinsicState;

    public Flyweight(string intrinsicState) {
        this.intrinsicState = intrinsicState;
    }

    public void Operation(string extrinsicState) {
        Console.WriteLine("Intrinsic state: {0}", intrinsicState);
        Console.WriteLine("Extrinsic state: {0}", extrinsicState);
    }
}

// A classe FlyweightFactory é responsável por criar e gerenciar objetos Flyweight.
class FlyweightFactory {
    private readonly Dictionary<string, Flyweight> flyweights = new Dictionary<string, Flyweight>();

    public Flyweight GetFlyweight(string key) {
        if (!flyweights.ContainsKey(key)) {
            flyweights[key] = new Flyweight(key);
        }
        return flyweights[key];
    }

    public int CountFlyweights() {
        return flyweights.Count;
    }
}

// A classe Client é responsável por utilizar os objetos Flyweight.
class Client {
    private readonly FlyweightFactory flyweightFactory;

    public Client(FlyweightFactory flyweightFactory) {
        this.flyweightFactory = flyweightFactory;
    }

    public void Operation(string key, string extrinsicState) {
        Flyweight flyweight = flyweightFactory.GetFlyweight(key);
        flyweight.Operation(extrinsicState);
    }
}

// A classe Program contém o método Main que cria e usa os objetos.
class Program {
    static void Main(string[] args) {
        FlyweightFactory flyweightFactory = new FlyweightFactory();
        Client client1 = new Client(flyweightFactory);
        Client client2 = new Client(flyweightFactory);

        client1.Operation("A", "1");
        client1.Operation("B", "2");
        client1.Operation("C", "3");

        client2.Operation("A", "4");
        client2.Operation("B", "5");

        Console.WriteLine("Number of flyweights created: {0}", flyweightFactory.CountFlyweights());
    }
}
