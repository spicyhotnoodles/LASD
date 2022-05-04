
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class BinaryTreeVec: virtual public BinaryTree<Data> {
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  struct NodeVec: virtual public BinaryTree<Data>::Node { // Must extend Node

    private:

      // ...

    protected:

      // ...

    public:

      Data value;
      int index = 0;
      lasd::Vector<NodeVec*>* vecPtr = nullptr; // Can be used to access Vector methods 

      NodeVec() = default; // create an empty node
      NodeVec(const Data&, const int, lasd::Vector<NodeVec*>*); // create a node with a value

      virtual ~NodeVec() = default; // * destroy a node

      Data& Element() noexcept override;
      const Data& Element() const noexcept override;

      bool IsLeaf() const noexcept override {
        return (HasLeftChild() && HasRightChild());
      }
      
      bool HasLeftChild() const noexcept override;
      bool HasRightChild() const noexcept override;

      NodeVec& LeftChild() const override;
      NodeVec& RightChild() const override;

  };

  Vector<NodeVec*>* treePtr = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default; // create an empty binary tree

  // Specific constructors
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  // Destructor
  virtual ~BinaryTreeVec();

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  // Comparison operators
  bool operator==(const BinaryTreeVec&) const noexcept;
  bool operator!=(const BinaryTreeVec&) const noexcept;

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  // Specific member functions (inherited from BreadthMappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void MapBreadth(MapFunctor, void*) override; // Override BreadthMappableContainer member

  // Specific member functions (inherited from BreadthFoldableContainer)
  
  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member

};

}

#include "binarytreevec.cpp"

#endif
