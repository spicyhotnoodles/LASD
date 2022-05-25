#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../bst/bst.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

// The complete student test
void mytest();

// Menu for binary tree testing
template<typename Data>
void bstMenu(lasd::BinaryTree<Data>&);

// Will return the selected struct, type and implementation for declaration
int selectLinearContainer();
int selectType();

// Print tree traversal
template<typename Data>
void treeTraversal(lasd::BinaryTree<Data>&);

// Printing node value function
template<typename Data>
void printNode(const Data&, void*);

// Random list fill function
template<typename Data>
void randomListGen(lasd::List<Data>&, int);
template<>
void randomListGen(lasd::List<int>&, int);
template<>
void randomListGen(lasd::List<float>&, int);
template<>
void randomListGen(lasd::List<std::string>&, int);

// Random vector fill function
template<typename Data>
void randomVecGen(lasd::Vector<Data>&);
template<>
void randomVecGen(lasd::Vector<int>&);
template<>
void randomVecGen(lasd::Vector<float>&);
template<>
void randomVecGen(lasd::Vector<std::string>&);

// Functions calculated with fold function
template<typename Data>
void applyFold(const Data&, const void*, void*);
template<>
void applyFold(const int&, const void*, void*);
template<>
void applyFold(const float&, const void*, void*);
template<>
void applyFold(const std::string&, const void*, void*);

#endif
