#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

// The complete student test
void mytest();

// Menu for vector testing
template<typename Data>
void vectorMenu(lasd::Vector<Data>&);

// Menu for list testing
template<typename Data>
void listMenu(lasd::List<Data>&);

// Menu for stack testing
template<typename Data>
void stackMenu(lasd::Stack<Data>&); // Should work for both stack implementations

// Menu for queue testing
template<typename Data>
void queueMenu(lasd::Queue<Data>&);

// Will return the selected struct, type and size for declaration
int selectStruct();
int selectType();
int selectSize();
int selectImple();

// Will return the Data type
template<typename Data>
int checkType(const Data&);

// Random vector fill function
template<typename Data>
void randomVecGen(lasd::Vector<Data>&);
template<>
void randomVecGen(lasd::Vector<int>&);
template<>
void randomVecGen(lasd::Vector<float>&);
template<>
void randomVecGen(lasd::Vector<std::string>&);

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

// Printing value function
template<typename Data>
void printValue(const Data&, void*);

// Print value of container with given index
template<typename Data>
void printIndex(const lasd::LinearContainer<Data>&); // works with both vector and list

// Point number 7
template<typename Data>
void applyFunction(Data&, void*);
template<>
void applyFunction(int&, void*);
template<>
void applyFunction(double&, void*);

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
