
#ifndef LIST_HPP
#define LIST_HPP

#include "../container/container.hpp"

namespace lasd {

template <typename Data>
class List: virtual public LinearContainer<Data>,
            virtual public PreOrderMappableContainer<Data>,
            virtual public PostOrderMappableContainer<Data>,
            virtual public PreOrderFoldableContainer<Data>,
            virtual public PostOrderFoldableContainer<Data>
{
              // Must extend LinearContainer<Data>,
              //             PreOrderMappableContainer<Data>,
              //             PostOrderMappableContainer<Data>,
              //             PreOrderFoldableContainer<Data>,
              //             PostOrderFoldableContainer<Data>

private:

protected:

  using LinearContainer<Data>::size; // numbers of node?

  struct Node {

    Data value;
    Node* next = nullptr;

    // Default constructor
    Node() = default;
    
    // Specific constructors
    Node(const Data& data) : value(data) {};

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&) noexcept;

    // Destructor
    ~Node() = default;

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    // Specific member functions

    // ...

  };

  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  // Specific constructor
  List(const LinearContainer<Data>&); // A list obtained from a LinearContainer

  // Copy constructor
  List(const List<Data>&);

  // Move constructor
  List(List<Data>&&) noexcept;

  // Destructor
  ~List() = default;

  // Copy assignment
  List& operator=(const List<Data>&);

  // Move assignment
  List& operator=(List<Data>&&) noexcept;

  // Comparison operators
  bool operator==(const List<Data>&) const noexcept;
  bool operator!=(const List<Data>&) const noexcept;

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&); // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&); // Move of the value

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  Data& operator[](const ulong) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void Map(MapFunctor, void*) override; // Override MappableContainer member

  // Specific member functions (inherited from PreOrderMappableContainer)

  void MapPreOrder(MapFunctor, void*) override; // Override PreOrderMappableContainer member

  // Specific member functions (inherited from PostOrderMappableContainer)

  void MapPostOrder(MapFunctor, void*) override; // Override PostOrderMappableContainer member

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void Fold(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  // Specific member functions (inherited from PreOrderFoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  // Specific member functions (inherited from PostOrderFoldableContainer)

  void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  void printList() const;
  
protected:

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  void MapPreOrder(MapFunctor, void*, Node*); // Accessory function executing from one point of the list onwards
  void MapPostOrder(MapFunctor, void*, Node*); // Accessory function executing from one point of the list onwards

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one point of the list onwards
  void FoldPostOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one point of the list onwards

};

}

#include "list.cpp"

#endif
