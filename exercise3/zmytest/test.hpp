#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../vector/vector.hpp"

// The complete student test
void mytest();

// Menu for stack testing
template<typename Data>
void stackMenu(lasd::Stack<Data>&); // Should work for both stack implementations

// Menu for queue testing
template<typename Data>
void queueMenu(lasd::Queue<Data>&);

// Menu for binary tree testing
template<typename Data>
void binaryTreeMenu(lasd::BinaryTree<Data>&);

// Will return the selected struct, type and implementation for declaration
int selectStruct();
int selectType();
int selectImple();

// Print tree traversal
template<typename Data>
void treeTraversal(lasd::BinaryTree<Data>&);

// Printing node value function
template<typename Data>
void printNode(const Data&, void*);

// Print tree
template<typename Data>
void printTree(std::string&, struct lasd::BinaryTree<Data>::Node* node, bool);

// Random list fill function
template<typename Data>
void randomListGen(lasd::List<Data>&, int);
template<>
void randomListGen(lasd::List<int>&, int);
template<>
void randomListGen(lasd::List<float>&, int);
template<>
void randomListGen(lasd::List<std::string>&, int);

// Random stack fill function
template<typename Data>
void randomStackGen(lasd::Stack<Data>&);
template<>
void randomStackGen(lasd::Stack<int>&);
template<>
void randomStackGen(lasd::Stack<float>&);
template<>
void randomStackGen(lasd::Stack<std::string>&);

// Random queue fill function
template<typename Data>
void randomQueueGen(lasd::Queue<Data>&);
template<>
void randomQueueGen(lasd::Queue<int>&);
template<>
void randomQueueGen(lasd::Queue<float>&);
template<>
void randomQueueGen(lasd::Queue<std::string>&);

#endif
