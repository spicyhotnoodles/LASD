
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

#include "../binarytree.hpp"

namespace lasd {

template <typename Data>
class BinaryTreeLnk: virtual public BinaryTree<Data> {
                      // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  // ...

  struct NodeLnk: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:

    Data value;
    NodeLnk* leftChild = nullptr;
    NodeLnk* rightChild = nullptr;
    List<NodeLnk*>* listPtr = nullptr; // Can be used to access List methods

    NodeLnk() = default; // create an empty node
    NodeLnk(const Data&); // create a node with a value

    virtual ~NodeLnk(); // * destroy a node

    Data& Element() noexcept override;
    const Data& Element() const noexcept override;

    bool IsLeaf() const noexcept override {
      return (HasLeftChild() && HasRightChild());
    }

    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  // Specific constructors
  BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  // Auxiliary constructor function
  void createTreeLnk(int, struct BinaryTreeLnk<Data>::NodeLnk*, const LinearContainer<Data>&);

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Auxiliary copy constructor function
  struct BinaryTreeLnk<Data>::NodeLnk* copyTreeLnk(struct BinaryTreeLnk<Data>::NodeLnk*);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  // Destructor
  virtual ~BinaryTreeLnk();

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  // Specific member functions (inherited from BinaryTree)

  NodeLnk& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

};

}

#include "binarytreelnk.cpp"

#endif
