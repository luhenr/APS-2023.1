using System;
using System.Collections.Generic;

interface IVisitor {
    void Visit(ElementA element);
    void Visit(ElementB element);
}

class ConcreteVisitor : IVisitor {
    public void Visit(ElementA element) {
        Console.WriteLine("ConcreteVisitor is visiting ElementA");
    }

    public void Visit(ElementB element) {
        Console.WriteLine("ConcreteVisitor is visiting ElementB");
    }
}

interface IElement {
    void Accept(IVisitor visitor);
}

class ElementA : IElement {
    public void Accept(IVisitor visitor) {
        visitor.Visit(this);
    }
}

class ElementB : IElement {
    public void Accept(IVisitor visitor) {
        visitor.Visit(this);
    }
}

class ObjectStructure {
    private readonly List<IElement> elements = new List<IElement>();

    public void Attach(IElement element) {
        elements.Add(element);
    }

    public void Detach(IElement element) {
        elements.Remove(element);
    }

    public void Accept(IVisitor visitor) {
        foreach (var element in elements) {
            element.Accept(visitor);
        }
    }
}

class Program {
    static void Main(string[] args) {
        ObjectStructure structure = new ObjectStructure();
        structure.Attach(new ElementA());
        structure.Attach(new ElementB());

        IVisitor visitor = new ConcreteVisitor();
        structure.Accept(visitor);
    }
}
