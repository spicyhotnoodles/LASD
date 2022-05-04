
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP


#include "../container/container.hpp"
#include "../iterator/iterator.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"


namespace lasd {

template <typename Data>
class BinaryTree: virtual public PreOrderMappableContainer<Data>,
                  virtual public PostOrderMappableContainer<Data>,
                  virtual public InOrderMappableContainer<Data>,
                  virtual public BreadthMappableContainer<Data>,
                  virtual public PreOrderFoldableContainer<Data>,
                  virtual public PostOrderFoldableContainer<Data>,
                  virtual public InOrderFoldableContainer<Data>,
                  virtual public BreadthFoldableContainer<Data> {
                   // Must extend PreOrderMappableContainer<Data>,
                   //             PostOrderMappableContainer<Data>,
                   //             InOrderMappableContainer<Data>,
                   //             BreadthMappableContainer<Data>,
                   //             PreOrderFoldableContainer<Data>,
                   //             PostOrderFoldableContainer<Data>,
                   //             InOrderFoldableContainer<Data>,
                   //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  using BreadthMappableContainer<Data>::size;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:

    // Comparison operators
    bool operator==(const Node&) const;
    bool operator!=(const Node&) const;

  public:

    friend class BinaryTree<Data>;

    // Destructor
    ~Node() = default;

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types should not be possible.


    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.


    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)
    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  // Destructor
  virtual ~BinaryTree() = default;

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  // Specific member functions

  virtual Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor, void*) override; // Override MappableContainer member

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  // Specific member functions (inherited from PreOrderMappableContainer)

  void MapPreOrder(MapFunctor, void*) override; // Override PreOrderMappableContainer member

  // Specific member functions (inherited from PreOrderFoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*) const override; // Override PreOrderFoldableContainer member

  // Specific member functions (inherited from PostOrderMappableContainer)

  void MapPostOrder(MapFunctor, void*) override; // Override PostOrderMappableContainer member

  // Specific member functions (inherited from PostOrderFoldableContainer)

  void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override PostOrderFoldableContainer member

  // Specific member functions (inherited from InOrderMappableContainer)

  void MapInOrder(MapFunctor, void*) override; // Override InOrderMappableContainer member

  // Specific member functions (inherited from InOrderFoldableContainer)

  void FoldInOrder(FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member

  // Specific member functions (inherited from BreadthMappableContainer)

  void MapBreadth(MapFunctor, void*) override; // Override BreadthMappableContainer member

  // Specific member functions (inherited from BreadthFoldableContainer)

  void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member

protected:

  // Order functions starting from specific node

  // Auxiliary member functions (for PreOrderMappableContainer)

  void MapPreOrder(MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  // Auxiliary member functions (for PreOrderFoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

  // Auxiliary member functions (for PostOrderMappableContainer)

  void MapPostOrder(MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  // Auxiliary member functions (for PostOrderFoldableContainer)

  void FoldPostOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

  // Auxiliary member functions (for InOrderMappableContainer)

  void MapInOrder(MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  // Auxiliary member functions (for InOrderFoldableContainer)

  void FoldInOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

  // Auxiliary member functions (for BreadthMappableContainer)

  void MapBreadth(MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  // Auxiliary member functions (for BreadthFoldableContainer)

  void FoldBreadth(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:

  StackLst<struct BinaryTree<Data>::Node*> stack;
  struct BinaryTree<Data>::Node* current;
  struct BinaryTree<Data>::Node* resetRoot;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator&);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

  // Destructor
  virtual ~BTPreOrderIterator();

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  // Comparison operators
  bool operator==(const BTPreOrderIterator&) const noexcept;
  bool operator!=(const BTPreOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:

  StackLst<struct BinaryTree<Data>::Node*> stack;
  struct BinaryTree<Data>::Node* current;
  struct BinaryTree<Data>::Node* resetRoot;
  struct BinaryTree<Data>::Node* last;

  // Auxiliary function
  void setMinLeaf(struct BinaryTree<Data>::Node*);

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator&) noexcept;

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  // Destructor
  virtual ~BTPostOrderIterator();

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept;
  bool operator!=(const BTPostOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data>,
                         virtual public ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  StackLst<struct BinaryTree<Data>::Node*> stack;
  struct BinaryTree<Data>::Node* current;
  struct BinaryTree<Data>::Node* resetRoot;

  // Auxiliary function
  void setMinLeaf(struct BinaryTree<Data>::Node*);

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  // Destructor
  virtual ~BTInOrderIterator();

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept;
  bool operator!=(const BTInOrderIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data>,
                         virtual public ResettableIterator<Data> {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  QueueLst<struct BinaryTree<Data>::Node*> queue;
  struct BinaryTree<Data>::Node* current;
  struct BinaryTree<Data>::Node* resetRoot;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&&) noexcept;

  // Destructor
  virtual ~BTBreadthIterator();

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator);

  // Move assignment
  BTBreadthIterator operator=(BTBreadthIterator&&) noexcept;

  // Comparison operators
  bool operator==(const BTBreadthIterator&) const noexcept;
  bool operator!=(const BTBreadthIterator&) const noexcept;

  // Specific member functions (inherited from Iterator)

  Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

}

#include "binarytree.cpp"

#endif
