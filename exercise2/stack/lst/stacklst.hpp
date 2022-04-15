
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

template <typename Data>
class StackLst: virtual public Stack<Data>,
                virtual protected List<Data> {
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;
  using List<Data>::head;
  using typename List<Data>::Node;
  Node* top = head;
  //typename List<Data>::Node* top = head;

  // ...

public:

  // Default constructor
  StackLst() : List<Data>() {};

  // Specific constructor
  StackLst(LinearContainer<Data>& lc) : List<Data>(lc) {}; // A stack obtained from a LinearContainer

  // Copy constructor
  StackLst(const StackLst<Data>&);

  // Move constructor
  StackLst(StackLst<Data>&&) noexcept;

  // Destructor
  virtual ~StackLst() = default;

  // Copy assignment
  StackLst& operator=(const StackLst<Data>&);

  // Move assignment
  StackLst& operator=(StackLst<Data>&&) noexcept;

  // Comparison operators
  bool operator==(const StackLst<Data>&) const noexcept;
  bool operator!=(const StackLst<Data>&) const noexcept;

  // Specific member functions (inherited from Stack)

  Data& Top() const override; // Override Stack member (constant version; must throw std::length_error when empty)
  Data Top() override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) override; // Override Stack member (move of the value)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  void printStack() const noexcept override;

};

}

#include "stacklst.cpp"

#endif
