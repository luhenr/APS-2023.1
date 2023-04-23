abstract class Expression {
  void interpret(Context context);
}

class TerminalExpression implements Expression {
  final String _data;
  TerminalExpression(this._data);
  void interpret(Context context) {
    if (context.input.startsWith(_data)) {
      context.output += '1'; // expressão verdadeira
      context.input = context.input.substring(_data.length);
    } else {
      context.output += '0'; // expressão falsa
    }
  }
}

class NonterminalExpression implements Expression {
  final Expression _expression1;
  final Expression _expression2;
  NonterminalExpression(this._expression1, this._expression2);
  void interpret(Context context) {
    _expression1.interpret(context);
    _expression2.interpret(context);
  }
}

class Context {
  String input;
  String output = '';
  Context(this.input);
}

class Interpreter {
  final Expression _expression;
  Interpreter(this._expression);
  void interpret(Context context) {
    _expression.interpret(context);
  }
}

void main() {
  final context = Context('ABCDEF');
  final expression = NonterminalExpression(
    TerminalExpression('AB'),
    NonterminalExpression(
      TerminalExpression('CD'),
      TerminalExpression('EF'),
    ),
  );
  final interpreter = Interpreter(expression);

  interpreter.interpret(context);

  print(context.output);
}
