class Flyweight {
  final String _sharedState;
  Flyweight(this._sharedState);
  String get sharedState => _sharedState;
  void operation(String uniqueState) {
    print('Operação sendo realizada com o estado compartilhado $_sharedState e o estado único $uniqueState');
  }
}

class FlyweightFactory {
  final Map<String, Flyweight> _flyweights = <String, Flyweight>{};
  Flyweight getFlyweight(String sharedState) {
    return _flyweights.putIfAbsent(sharedState, () => Flyweight(sharedState));
  }
  int getFlyweightCount() {
    return _flyweights.length;
  }
}

void main() {
  final factory = FlyweightFactory();
  final flyweight1 = factory.getFlyweight('Estado Compartilhado');
  final flyweight2 = factory.getFlyweight('Estado Compartilhado');
  final flyweight3 = factory.getFlyweight('Outro Estado Compartilhado');

  flyweight1.operation('Estado Único 1');
  flyweight2.operation('Estado Único 2');
  flyweight3.operation('Estado Único 3');

  print('Número de Flyweights criados: ${factory.getFlyweightCount()}');
}
