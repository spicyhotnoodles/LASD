
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr: virtual public HashTable<Data> { // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::size; // num of elements
  using HashTable<Data>::m;
  using HashTable<Data>::p;
  using HashTable<Data>::HashKey;
  Vector<Data> buckets;
  Vector<char> flags; // 'd' for deleted, 'u' for used, 'e' for empty


  // ...

public:

  // Default constructor
  HashTableOpnAdr();

  // Specific constructors
  HashTableOpnAdr(ulong&); // A hash table of a given size
  HashTableOpnAdr(const LinearContainer<Data>&); // A hash table obtained from a LinearContainer
  HashTableOpnAdr(const ulong size, const LinearContainer<Data>&); // A hash table of a given size obtained from a LinearContainer

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr&);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr&);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;

  // Comparison operators
  bool operator==(const HashTableOpnAdr&) const noexcept;
  bool operator!=(const HashTableOpnAdr&) const noexcept;

  // Specific member functions (inherited from HashTable)

  void Resize(ulong) override; // Resize the hashtable to a given size

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor, void*) override; // Override MappableContainer member

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  void resetFlags(); // Reset flags status
  ulong HashKey(ulong, ulong) const; // Probing function
  ulong Find(const Data&); // Find the index of the given value
  ulong FindEmpty(ulong); // Find the index of the first empty bucket
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
