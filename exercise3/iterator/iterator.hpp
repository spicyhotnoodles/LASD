

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace lasd {

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~Iterator() = default;

  // Copy assignment
  virtual Iterator& operator=(const Iterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual Iterator& operator=(Iterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual Data& operator*() const = 0; // (concrete function must throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept = 0; // (concrete function should not throw exceptions)

};

template <typename Data>
class ForwardIterator: virtual public Iterator<Data> { // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ForwardIterator() = default;

  // Copy assignment
  virtual ForwardIterator& operator=(const ForwardIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual ForwardIterator& operator=(ForwardIterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const ForwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ForwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual ForwardIterator& operator++() = 0; // (concrete function must throw std::out_of_range when terminated)

};

template <typename Data>
class BackwardIterator: virtual public Iterator<Data> { // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~BackwardIterator() = default;

  // Copy assignment
  virtual BackwardIterator& operator=(const BackwardIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BackwardIterator& operator=(BackwardIterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const BackwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BackwardIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual BackwardIterator& operator--() = 0; // (concrete function must throw std::out_of_range when terminated)

};


template <typename Data>
class BidirectionalIterator:  virtual public ForwardIterator<Data>,
                              virtual public BackwardIterator<Data> {
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~BidirectionalIterator() = default;

  // Copy assignment
  virtual BidirectionalIterator& operator=(const BidirectionalIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BidirectionalIterator& operator=(BidirectionalIterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const BidirectionalIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BidirectionalIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual bool Terminated() const noexcept override = 0; // Override Iterator member

  virtual bool ForwardTerminated() const noexcept = 0; // (concrete function should not throw exceptions)

  virtual bool BackwardTerminated() const noexcept = 0; // (concrete function should not throw exceptions)

};


template <typename Data>
class ResettableIterator: virtual public Iterator<Data> { // Must extend Iterator<Data>

private:

protected:

public:

  // Destructor
  ~ResettableIterator() = default;

  // Copy assignment
  virtual ResettableIterator& operator=(const ResettableIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual ResettableIterator& operator=(ResettableIterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const ResettableIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const ResettableIterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual void Reset() noexcept = 0; // (concrete function should not throw exceptions)

};

}

#endif
