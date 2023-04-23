class Memento {
  final String _state;
  Memento(this._state);
  String get state => _state;
}

class Originator {
  String _state;
  Originator(this._state);
  Memento createMemento() => Memento(_state);
  void restoreMemento(Memento memento) {
    _state = memento.state;
  }
  String get state => _state;
  set state(String state) {
    _state = state;
  }
}

class Caretaker {
  final List<Memento> _mementos = [];
  void addMemento(Memento memento) {
    _mementos.add(memento);
  }
  Memento getMemento(int index) => _mementos[index];
}

void main() {
  final originator = Originator('State1');
  final caretaker = Caretaker();

  caretaker.addMemento(originator.createMemento());
  originator.state = 'State2';

  caretaker.addMemento(originator.createMemento());
  originator.state = 'State3';

  print('Current state: ${originator.state}');
  originator.restoreMemento(caretaker.getMemento(1));
  print('Restored state: ${originator.state}');
}
