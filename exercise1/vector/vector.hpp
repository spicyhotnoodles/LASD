#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../container/container.hpp"

namespace lasd {

  template <typename Data>
  class Vector: virtual public LinearContainer<Data>,
                virtual public PreOrderMappableContainer<Data>,
                virtual public PostOrderMappableContainer<Data>,
                virtual public PreOrderFoldableContainer<Data>,
                virtual public PostOrderFoldableContainer<Data>
                { // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

  private:

  protected:

    using LinearContainer<Data>::size;
    Data* Elements = nullptr; // Array pointer

  public:

    // Default constructor
    Vector() = default;

    // Specific constructors
    Vector(unsigned long size); // A vector with a given initial dimension
    Vector(const LinearContainer<Data>&); // A vector obtained from a LinearContainer

    // Copy constructor
    Vector(const Vector<Data>&);

    // Move constructor
    Vector(const Vector<Data>&&) noexcept;

    // Destructor
    virtual ~Vector();

    // Copy assignment
    Vector& operator=(const Vector&); 

    // Move assignment
    Vector& operator=(Vector&&) noexcept;

    // Comparison operators
    inline bool operator==(const Vector&) noexcept;
    inline bool operator!=(const Vector&) noexcept;

    // Specific member functions

    void Resize(const ulong);  // Resize the vector to a given size

    // Specific member functions (inherited from Container)

    void Clear() override; // Override Container member

    // Specific member functions (inherited from LinearContainer)

    Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
    Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)
    Data& operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

    // Specific member functions (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFunctor;

    void Map(MapFunctor, void*) override; // Override MappableContainer member
    void MapPreOrder(MapFunctor, void*) override; // Override PreOrderMappableContainer member
    void MapPostOrder(MapFunctor, void*) override; // Override PostOrderMappableContainer member

    // Specific member functions (inherited from FoldableContainer)

    using typename FoldableContainer<Data>::FoldFunctor;

    void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
    virtual void FoldPreOrder(FoldFunctor, const void*, void*) const override; // Override PreOrderFoldableContainer member
    virtual void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override PostOrderFoldableContainer member

  };
  
}

#include "vector.cpp"

#endif
