#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <stdexcept>
#include <functional>

namespace lasd {

class Container {

// A container is a base class for all the kind of containers.

private:

protected:

  unsigned long size = 0; 

public:

  // Destructor
  virtual ~Container() = default; 

  // Copy assignment
  Container& operator=(const Container&) = delete;


  // Move assignment
  Container& operator=(Container&&) noexcept = delete;

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete;
  bool operator!=(const Container&) const noexcept = delete;

  // Specific member functions

  inline virtual bool Empty() const noexcept {
    return (size == 0);
  } 

  inline virtual ulong Size() const noexcept {
    return size;
  }

  virtual void Clear() = 0; // should be implemented appropriately from the derived classes

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public Container { // Must extend Container

// A linear container is a container  where datas are sequence of elements 

private:

protected:

public:

  // Destructor
  virtual ~LinearContainer() = default;

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) = delete;

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) noexcept = delete;

  // Comparison operators
  inline bool operator==(const LinearContainer&) const noexcept;
  inline bool operator!=(const LinearContainer&) const noexcept;

  // Specific member functions

  inline virtual Data& Front() const;
  inline virtual Data& Back() const; 

  // type operator[](argument) specifiers; // (concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](const ulong) const = 0;

};

/* ************************************************************************** */

template <typename Data>

class TestableContainer: virtual public Container { // Must extend Container

// A testable container is a container on which searching for an element is possible --> Exists()

private:

protected:

public:

  // Destructor
  virtual ~TestableContainer() = default;
  
  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) = delete;

  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete;

  // Comparison operators
  inline bool operator==(const TestableContainer&) const noexcept = delete;
  inline bool operator!=(const TestableContainer&) const noexcept = delete;

  // Specific member functions

  virtual inline bool Exists(const Data&) const noexcept = 0;  // should be implemented appropriately from the derived classes

};

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public Container { // Must extend Container

// A mappable container is a container whom datas can be modified by passing a function to the map() function 

private:

protected:

public:

  // Destructor
  virtual ~MappableContainer() = default;

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete;

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  // Comparison operators

  bool operator==(const MappableContainer&) const noexcept = delete;
  bool operator!=(const MappableContainer&) const noexcept = delete;

  // Specific member functions

  typedef std::function<void(Data&, void*)> MapFunctor; // void (*MapFunctor) (Data&, void*) this is the function that modifies the datas

  virtual void Map(MapFunctor, void*) = 0; // should be implemented from MapPreOrder and MapPostOrder 

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer

  private: 
    
  protected:
  
  public:

    // Destructor
    virtual ~PreOrderMappableContainer() = default;

    // Copy assignment
    PreOrderMappableContainer& operator=(const PreOrderMappableContainer&) = delete;

    // Move assignment
    PreOrderMappableContainer& operator=(PreOrderMappableContainer&&) noexcept = delete;

    // Comparison operators
    bool operator==(const PreOrderMappableContainer&) const noexcept = delete;
    bool operator!=(const PreOrderMappableContainer&) const noexcept = delete;

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPreOrder(MapFunctor, void*) = 0; //should be implemented appropriately from derived classes MapInOrder

    // Specific member functions (inherited from MappableContainer)
    
    inline virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer

private:

protected:

public:

    // Destructor
    virtual ~PostOrderMappableContainer() = default;

    // Copy assignment
    PostOrderMappableContainer& operator=(const PostOrderMappableContainer&) = delete;

    // Move assignment
    PostOrderMappableContainer& operator=(PostOrderMappableContainer&&) noexcept = delete;

    // Comparison operators
    bool operator==(const PostOrderMappableContainer&) const noexcept = delete;
    bool operator!=(const PostOrderMappableContainer&) const noexcept = delete;

    // Specific member functions

    using typename MappableContainer<Data>::MapFunctor;

    virtual void MapPostOrder(MapFunctor, void*) = 0; //should be implemented appropriately from derived classes 

    // Specific member functions (inherited from MappableContainer)
    inline virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer: virtual public TestableContainer<Data> { // Must extend TestableContainer

// A foldable container is a container whom datas can be read (and folded into an accumulator)

private:

protected:

public:

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete;

  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const FoldableContainer&) const noexcept = delete;
  inline bool operator!=(const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(const Data&, const void*, void*)> FoldFunctor;
  virtual void Fold(FoldFunctor, const void*, void*) const = 0;

  // The fold functions must apply the FoldFunctor function to each element of the container in the proper way: PreOrder and PostOrder

  // type Exists(argument) specifiers; // Override TestableContainer member
  inline virtual bool Exists(const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldaleContainer

private:

protected:

public:

  // Destructor
  ~PreOrderFoldableContainer() = default;

  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer&) = delete;
  
  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&&) const = delete;

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer&) const noexcept = delete;
  bool operator!=(const PreOrderFoldableContainer&) const noexcept = delete;

  // Specific member functions
  
  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldPreOrder(FoldFunctor, const void*, void*) const = 0; // should be implemented appropriately from derived classes. 
  // const void* is the accumulator (initial value), void* is the result. The functions is const because no changes is done to the container

  // Specific member functions (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

template<typename Data>
class PostOrderFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer

private:

protected:

public:

  // Destructor
  ~PostOrderFoldableContainer() = default;

  // Copy assignment
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer&) = delete;

  // Move assignement
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&&) noexcept = delete;

  // Comparison operators
  bool operator==(const PostOrderFoldableContainer&) const noexcept = delete;
  bool operator!=(const PostOrderFoldableContainer&) const noexcept = delete;

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldPostOrder(FoldFunctor, const void*, void*) const = 0; // should be implemented appropriately from derived classes
  // const void* is the accumulator (initial value), void* is the result. The functions is const because no changes is done to the container


  // Specific member functions (inherited from FoldableContainer)

  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer { // Must extend MappableContainer

private:

  // 

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer { // Must extend FoldableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
