
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public virtual Queue<Data>,
                protected virtual Vector<Data> {
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  int queueSize = 0; // elements in the queue
  int front = 1;
  int rear = 0;

  // ...

public:

  // Default constructor
  QueueVec() : Vector<Data>(5) {};

  // Specific constructor
  QueueVec(const LinearContainer<Data>& lc) : Vector<Data>(lc) {}; // A queue obtained from a LinearContainer

  // Copy constructor
  QueueVec(const QueueVec<Data>&);

  // Move constructor
  QueueVec(QueueVec<Data>&&) noexcept;

  // Destructor
  virtual ~QueueVec() = default;

  // Copy assignment
  QueueVec& operator=(const QueueVec<Data>&);

  // Move assignment
  QueueVec& operator=(QueueVec<Data>&&) noexcept;

  // Comparison operators
  bool operator==(const QueueVec<Data>&) const noexcept;
  bool operator!=(const QueueVec<Data>&) const noexcept;

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  Data Head() override; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) override; // Override Queue member (move of the value)

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  inline virtual ulong Size() const noexcept override { // Override Container member
    if (queueSize == 0) {
      return 0;
    } else {
      return queueSize;
    }
  }

  void Clear() override; // Override Container member

  void printQueue() const noexcept override; // DA RIMUOVERE!!!

protected:

  // Auxiliary member functions

  void Expand() noexcept;
  void Reduce() noexcept;
  // type SwapVectors(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
