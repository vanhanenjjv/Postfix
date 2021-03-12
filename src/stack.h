#ifndef STACK_H
#define STACK_H

#include "list.h"

template<typename T>
class Stack {
  private:
    List<T> items_;
    
  public:
    Stack() {}

    Stack<T> *Clone() {
      Stack<T> *copy = new Stack<T>();

      for (int i = 0; i < this->items_.Count(); ++i)
        copy->Push(this->items_[i]);

      return copy;
    }

    bool IsEmpty() {
      return items_.Count() == 0; 
    }

    int Count() { 
      return items_.Count();
    }

    void Clear() { 
      items_.Clear();
    }

    void Push(T item) {
      items_.Add(item); 
    }

    T Pop() {
      int top_index = items_.Count() - 1;
      T top         = items_[top_index];
      items_.RemoveAt(top_index);

      return top;
    }

    T Peek() {
      int top_index = items_.Count() - 1;
      T top       = items_[top_index];

      return top;
    }

    bool TryPeek(T &item) {
      if (IsEmpty())
        return false;

      item = Peek();

      return true;
    }

    bool TryPop(T &item) {
      if (IsEmpty())
        return false;

      item = Pop();
      
      return true;
    }
};

#endif
