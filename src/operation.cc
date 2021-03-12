#include "operation.h"

#include <cmath>
#include <iostream>
#include <functional>

operation::InvalidOperationException::InvalidOperationException() {}

operation::InvalidOperationException::InvalidOperationException(std::string message) {
  this->message_ = message;
}

std::string operation::InvalidOperationException::message() {
  return this->message_;
}

void operation::Add(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(a + b);
}

void operation::Subtract(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(a - b);
}

void operation::Multiply(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(a * b);
}

void operation::Divide(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(a / b);
}

void operation::Exchange(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(b);
  operands.Push(a);
}

void operation::Sum(Stack<double> &operands) {
  double sum = 0;

  double value;
  while (operands.TryPop(value))
    sum += value;

  operands.Push(sum);
}

void operation::Average(Stack<double> &operands) {
  double sum = 0;
  int count = operands.Count();

  double value;
  while (operands.TryPop(value))
    sum += value;

  operands.Push(sum / count);
}

void operation::Power(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = operands.Pop();
  auto a = operands.Pop();

  operands.Push(std::pow(a, b));
}

void operation::Clear(Stack<double> &operands) {
  operands.Clear();
}

void operation::Modulo(Stack<double> &operands) {
  if (operands.Count() < 2)
    throw InvalidOperationException("Not enough operands.");

  auto b = (int)operands.Pop();
  auto a = (int)operands.Pop();

  operands.Push(a % b);
}

void operation::SquareRoot(Stack<double> &operands) {
  if (operands.Count() < 1)
    throw InvalidOperationException("Not enough operands.");

  auto a = operands.Pop();

  operands.Push(std::sqrt(a));
}

void operation::Print(Stack<double> &operands, bool end) {
  if (operands.IsEmpty())
    return;

  auto a = operands.Pop();

  Print(operands, false);
    
  std::cout << a << " ";

  operands.Push(a);

  if (end)
    std::cout << '\n';
}
