using System;
using System.Collections.Generic;

class Originator {
    private string state;

    public void SetState(string state) {
        this.state = state;
    }

    public string GetState() {
        return state;
    }

    public Memento Save() {
        return new Memento(state);
    }

    public void Restore(Memento memento) {
        state = memento.GetState();
    }
}

class Memento {
    private readonly string state;

    public Memento(string state) {
        this.state = state;
    }

    public string GetState() {
        return state;
    }
}

class Caretaker {
    private readonly List<Memento> mementos = new List<Memento>();
    private readonly Originator originator;

    public Caretaker(Originator originator) {
        this.originator = originator;
    }

    public void Save() {
        mementos.Add(originator.Save());
    }

    public void Restore(int index) {
        originator.Restore(mementos[index]);
    }
}

class Program {
    static void Main(string[] args) {
        Originator originator = new Originator();
        Caretaker caretaker = new Caretaker(originator);

        originator.SetState("State 1");
        caretaker.Save();

        originator.SetState("State 2");
        caretaker.Save();

        originator.SetState("State 3");

        Console.WriteLine("Current state: " + originator.GetState());

        caretaker.Restore(1);

        Console.WriteLine("Restored state: " + originator.GetState());
    }
}
