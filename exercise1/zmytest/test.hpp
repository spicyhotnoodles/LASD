#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../vector/vector.hpp"

/* template<typename Data>
void vectorInt(lasd::Vector<Data>&);
void vectorTest();
template<typename Data>
void printValue(lasd::Vector<Data>& vec);
template<typename Data>
void printValueAt(lasd::Vector<Data>& vec);
void listTest();
int selectType();
void mytest(); */
void mytest();
template<typename Data>
void vectorMenu(lasd::Vector<Data>&);
int selectStruct();
int selectType();
int selectSize();

#endif
