#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../vector/vector.hpp"

void mytest();
template<typename Data>
void vectorMenu(lasd::Vector<Data>&);
int selectStruct();
int selectType();
int selectSize();

template<typename Data>
int checkType(const Data&);

template<typename Data>
void randomVecGen(lasd::Vector<Data>&);
template<>
void randomVecGen(lasd::Vector<int>&);
template<>
void randomVecGen(lasd::Vector<float>&);
template<>
void randomVecGen(lasd::Vector<std::string>&);


template<typename Data>
void printValue(const Data&, void*);
template<typename Data>
void printIndex(const lasd::Vector<Data>&);


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
