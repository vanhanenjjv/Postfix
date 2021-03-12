#include <iostream>
#include <string.h>

#include "postfix.h"
#include "stack.h"

bool IsShellRequested(int argc, char **argv);
std::string ParseExpression(int argc, char **argv);

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Not enough arguments.\n";
    return 0;
  }

  if (IsShellRequested(argc, argv))
    postfix::Shell(std::cin, std::cout);
  else 
    postfix::Evaluate(ParseExpression(argc, argv));
}

bool IsShellRequested(int argc, char **argv) {
  char shell_option[] = "-p";

  for (int i = 1; i < argc; ++i) 
    if (!strcmp(argv[i], shell_option))
      return true;

  return false;
}

std::string ParseExpression(int argc, char **argv) {
  std::string expression;

  for (int i = 1; i < argc - 1; ++i)
    expression.append(argv[i]).append(" ");

  expression.append(argv[argc - 1]);

  return expression;
}

