
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

template <typename Data>
class Hash {

public:

  ulong operator()(const Data&) noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable: virtual public DictionaryContainer<Data>,
                 virtual public MappableContainer<Data>,
                 virtual public FoldableContainer<Data> { // Must extend DictionaryContainer<Data>,
                  //             MappableContainer<Data>,
                  //             FoldableContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size; // num of elements
  ulong a = 0;
  ulong b = 0;
  ulong m = 2209; // size of the table (num of buckets)
  ulong p = 134217989; // prime number
  Hash<Data> hash;

public:

  // Constructor
  HashTable() {
    //get a random unsigned long
    a = getRandomUlong(1);
    b = getRandomUlong(0);
  }

  // Destructor
  virtual ~HashTable() = default;

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract binary tree is possible.
  bool operator!=(const HashTable&) const noexcept = delete; // Comparison of abstract binary tree is possible.

  // Specific member function

  virtual void Resize(ulong newSize) = 0; // Resize the hashtable to a given size

protected:

  // Auxiliary member functions

  ulong HashKey(const Data&);
  ulong getRandomUlong(ulong min);

  // Copy assignment
  HashTable& operator=(const HashTable&); // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&&) noexcept; // Move assignment of abstract types should not be possible.

  // Copy constructor
  HashTable(const HashTable&);

  // Move constructor
  HashTable(HashTable&&) noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
