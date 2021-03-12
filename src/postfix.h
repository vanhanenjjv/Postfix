#ifndef POSTFIX_H
#define POSTFIX_H

#include <string>

namespace postfix {
  void Evaluate(std::string expression);
  void Shell(std::istream &input, std::ostream &output);
}

#endif
