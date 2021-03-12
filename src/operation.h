#ifndef OPERATION_H
#define OPERATION_H

#include "stack.h"
#include <string>

namespace operation {
  class InvalidOperationException : public std::exception {
    private:
      std::string message_;

    public:
      InvalidOperationException();
      InvalidOperationException(std::string message);
      std::string message();
  };

  void Add(Stack<double> &);
  void Subtract(Stack<double> &);
  void Multiply(Stack<double> &);
  void Divide(Stack<double> &);
  void Exchange(Stack<double> &);
  void Sum(Stack<double> &);
  void Average(Stack<double> &);
  void Modulo(Stack<double> &);
  void Power(Stack<double> &);
  void SquareRoot(Stack<double> &);
  void Clear(Stack<double> &);
  void Print(Stack<double> &, bool end = true);
};

#endif
