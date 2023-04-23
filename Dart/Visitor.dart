abstract class Visitor {
  void visitElementA(ElementA elementA);
  void visitElementB(ElementB elementB);
}

abstract class Element {
  void accept(Visitor visitor);
}

class ElementA implements Element {
  final String _name;
  ElementA(this._name);
  String get name => _name;
  @override
  void accept(Visitor visitor) {
    visitor.visitElementA(this);
  }
}

class ElementB implements Element {
  final int _value;
  ElementB(this._value);
  int get value => _value;
  @override
  void accept(Visitor visitor) {
    visitor.visitElementB(this);
  }
}

class ConcreteVisitor implements Visitor {
  @override
  void visitElementA(ElementA elementA) {
    print('Visitando ElementA com nome ${elementA.name}');
  }
  @override
  void visitElementB(ElementB elementB) {
    print('Visitando ElementB com valor ${elementB.value}');
  }
}

void main() {
  final elements = <Element>[
    ElementA('ElementA'),
    ElementB(10),
    ElementA('Outro ElementA'),
    ElementB(20),
  ];

  final visitor = ConcreteVisitor();

  elements.forEach((element) {
    element.accept(visitor);
  });
}
