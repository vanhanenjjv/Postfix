#include "postfix.h"

#include <iostream>
#include <sstream>

#include "stack.h"
#include "operation.h"

void postfix::Evaluate(std::string expression) {
  std::stringstream stream(expression);

  postfix::Shell(stream, std::cout);
}

void postfix::Shell(std::istream &input, std::ostream &output) {
  Stack<double> operands;
  std::string token;

  while (!input.eof()) {
    input >> token;

    if (token == "") 
      continue;

    try {
      if      (token == "+") operation::Add(operands);
      else if (token == "-") operation::Subtract(operands);
      else if (token == "/") operation::Divide(operands);
      else if (token == "*") operation::Multiply(operands);
      else if (token == "x") operation::Exchange(operands);
      else if (token == "s") operation::Sum(operands);
      else if (token == "a") operation::Average(operands);
      else if (token == "%") operation::Modulo(operands);
      else if (token == "^") operation::Power(operands);
      else if (token == "v") operation::SquareRoot(operands);
      else if (token == "c") operation::Clear(operands);
      else if (token == "p") operation::Print(operands);
      else                   operands.Push(std::stod(token));
    }
    catch (operation::InvalidOperationException &exception) {
      std::cout << exception.message() << '\n';
    }
    catch (const std::invalid_argument &exception) {
      std::cout << "Invalid token: '" << token << "'.\n";
    }
  }
}
