
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: public virtual Queue<Data>,
                protected virtual List<Data> {
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;
  using List<Data>::head;
  using typename List<Data>::Node;

  // ...

public:

  // Default constructor
  QueueLst() : List<Data>() {};

  // Specific constructor
  QueueLst(const LinearContainer<Data>& lc) : List<Data>(lc) {}; // A queue obtained from a LinearContainer

  // Copy constructor
  QueueLst(const QueueLst<Data>&);

  // Move constructor
  QueueLst(QueueLst<Data>&&) noexcept;

  // Destructor
  virtual ~QueueLst() = default;

  // Copy assignment
  QueueLst& operator=(const QueueLst<Data>&);

  // Move assignment
  QueueLst& operator=(QueueLst<Data>&&) noexcept;

  // Comparison operators
  bool operator==(const QueueLst<Data>&) const noexcept;
  bool operator!=(const QueueLst<Data>&) const noexcept;

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (constant version; must throw std::length_error when empty)
  Data Head() override; // Override Queue member (must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  void Enqueue(Data&&) override; // Override Queue member (move of the value)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  void printQueue() const noexcept override;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
