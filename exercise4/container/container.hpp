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
class DictionaryContainer: virtual public TestableContainer<Data> { // Must extend TestableContainer<Data>

private:

protected:

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&&) = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const DictionaryContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  virtual void Insert(const Data&) = 0; // Copy of the value
  virtual void Insert(Data&&) = 0; // Move of the value
  virtual void Remove(const Data&) = 0;

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
class InOrderMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;
 
  // Copy assignment
  InOrderMappableContainer& operator=(const InOrderMappableContainer&) = delete;
  
  // Move assignment
  InOrderMappableContainer& operator=(InOrderMappableContainer&&) noexcept = delete;
 
  // Comparison operators
  bool operator==(const InOrderMappableContainer&) const noexcept = delete;
  bool operator!=(const InOrderMappableContainer&) const noexcept = delete;
 
  // Specific member functions
 
 using typename MappableContainer<Data>::MapFunctor;
 
  virtual void MapInOrder(MapFunctor, void*) = 0;
 
  // Specific member functions (inherited from MappableContainer)
 
  virtual void Map(MapFunctor, void*) override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;
  
  // Copy assignment
  InOrderFoldableContainer& operator=(const InOrderFoldableContainer&) = delete;
  
  // Move assignment
  InOrderFoldableContainer& operator=(InOrderFoldableContainer&&) noexcept = delete;
  
  // Comparison operators
  bool operator==(const InOrderFoldableContainer&) const noexcept = delete;
  bool operator!=(const InOrderFoldableContainer&) const noexcept = delete;
  
  // Specific member functions
  
  using typename FoldableContainer<Data>::FoldFunctor;
  
  virtual void FoldInOrder(FoldFunctor, const void*, void*) const = 0;
  
  // Specific member functions (inherited from FoldableContainer)
  
  virtual void Fold(FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer: public virtual MappableContainer<Data> { // Must extend MappableContainer

private:

  // 

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;

  // Copy assignment
  BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BreadthMappableContainer& operator=(BreadthMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  virtual bool operator==(const BreadthMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const BreadthMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapBreadth(MapFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer: virtual public FoldableContainer<Data> { // Must extend FoldableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  // Copy assignment
  virtual BreadthFoldableContainer& operator=(const BreadthFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BreadthFoldableContainer& operator=(BreadthFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  virtual bool operator==(const BreadthFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const BreadthFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  // Specific member functions

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void FoldBreadth(FoldFunctor, const void*, void*) const = 0;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
