#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../hashtable/hashtable.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"

// The complete student test
void mytest();

// Menu for binary tree testing
template<typename Data>
void hashMenu(lasd::HashTable<Data>&);

// Will return the selected struct, type and implementation for declaration
int selectImplementation();
int selectLinearContainer();
int selectType();

// Printing node value function
template<typename Data>
void printValue(const Data&, void*);

// Random list fill function
template<typename Data>
void randomListGen(lasd::List<Data>&, int);
template<>
void randomListGen(lasd::List<int>&, int);
template<>
void randomListGen(lasd::List<double>&, int);
template<>
void randomListGen(lasd::List<std::string>&, int);

// Random vector fill function
template<typename Data>
void randomVecGen(lasd::Vector<Data>&);
template<>
void randomVecGen(lasd::Vector<int>&);
template<>
void randomVecGen(lasd::Vector<double>&);
template<>
void randomVecGen(lasd::Vector<std::string>&);

template<typename Data>
void compute(const lasd::HashTable<Data>&);
template<>
void compute(const lasd::HashTable<int>&);
template<>
void compute(const lasd::HashTable<double>&);
template<>
void compute(const lasd::HashTable<std::string>&);

// Functions calculated with fold function
template<typename Data>
void applyFold(const Data&, const void*, void*);
template<>
void applyFold(const int&, const void*, void*);
template<>
void applyFold(const double&, const void*, void*);
template<>
void applyFold(const std::string&, const void*, void*);

#endif
