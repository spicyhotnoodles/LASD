#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

// The complete student test
void mytest();

// Menu for stack testing
template<typename Data>
void stackMenu(lasd::Stack<Data>&); // Should work for both stack implementations

// Menu for queue testing
template<typename Data>
void queueMenu(lasd::Queue<Data>&);

// Will return the selected struct, type and implementation for declaration
int selectStruct();
int selectType();
int selectImple();

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
