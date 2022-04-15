
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

#include "../stack.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class StackVec: public virtual Stack<Data>,
                protected virtual Vector<Data> {
                  // Must extend public Stack<Data> (every function should be available to a StackVec object),
                  //             protected Vector<Data> (all Vector functions can't be used on a StackVec object)

private:

  // ...

protected:

  using Vector<Data>::size; // Total number of cells in the stack
  using Vector<Data>::Elements; // Array holding stack elements
  int top = 0; // Index of the top element in the stack. Top points to the first free cell in the array.
  // ...

public:

  // Default constructor
  StackVec() : Vector<Data>(5) {};

  // Specific constructor
  StackVec(const LinearContainer<Data>& lc) : Vector<Data>(lc) {}; // A stack obtained from a LinearContainer


  //StackVec(const LinearContainer<Data> &);

  // Copy constructor
  StackVec(const StackVec<Data>&);

  // Move constructor
  StackVec(StackVec<Data>&&) noexcept;

  // Destructor
  virtual ~StackVec() = default;

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&) noexcept;

  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  bool operator!=(const StackVec&) const noexcept;

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (constant version; must throw std::length_error when empty)
  Data Top() override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) override; // Override Stack member (move of the value)

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  inline virtual ulong Size() const noexcept override { // Override Container member
    return top-1; // return the number of values in the stack (not the stack size!)
  }

  void Clear() override; // Override Container member

  void printStack() const noexcept override; // DA RIMUOVERE!!!

protected:

  // Auxiliary member functions

  void Expand() noexcept;
  void Reduce() noexcept;

};

}

#include "stackvec.cpp"

#endif
