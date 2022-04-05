//#include "vector.hpp"
#include <stdexcept>

namespace lasd {

    // Constructor for a vector with given initial dimension 
    template<typename Data>
    Vector<Data>::Vector(const ulong newsize) {
        Elements = new Data[newsize] {};
        size = newsize;
    }

    // Constructor for a vector obtained from a LinearContainer
    template<typename Data>
    Vector<Data>::Vector(const LinearContainer<Data>& lc) {
        size = lc.Size();
        Elements = new Data[size];
        for (ulong index = 0; index < size; index++)
            Elements[index] = lc[index];
    }

    // Copy constructor
    template<typename Data>
    Vector<Data>::Vector(const Vector<Data>& vec) {
        Elements = new Data[vec.size];
        size = vec.size;
        std::copy(vec.Elements, vec.Elements + vec.size, Elements); // copy(first, last, destination)
        // vec.Elements + vec.size = first element out of range of the array. Elements is a pointer! 
    }

    // Move constructor 
    template<typename Data>
    Vector<Data>::Vector(const Vector<Data>&& vec) noexcept {
        Elements = new Data[vec.size];
        size = vec.size;
        std::swap(Elements, vec.Elements);
        std:swap(size, vec.size);
    }

    // Destructor
    template<typename Data>
    Vector<Data>::~Vector() {
        delete[] Elements;
    }

    // Copy assignment
    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector& vec) {
        Vector<Data>* tmpvec = new Vector<Data>(vec); // copy constructor
        std::swap(*tmpvec, *this);
        delete tmpvec;
        return *this;
    }

    // Move assignment
    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector && vec) noexcept {
        std::swap(Elements, vec.Elements);
        std::swap(size, vec.size);
        return *this;
    } 

    // Comparison operators
    template<typename Data>
    inline bool Vector<Data>::operator==(const Vector& vec) noexcept {
        if (size != vec.size)
            return false;
        else {
            for (int index = 0; index < size; index++) {
                if (Elements[index] != vec[index])
                    return false;
            }
                return true;
        }
    }

    template<typename Data>
    inline bool Vector<Data>::operator!=(const Vector& vec) noexcept {
        return !(*this == vec);
    }

    // Random access operator
    template<typename Data>
    Data& Vector<Data>::operator[](const ulong index) const {
        if (index < size) {
            return Elements[index];
        }
        else
            throw std::out_of_range("Index out of range!");
    }


    //Resize function
    template<typename Data>
    void Vector<Data>::Resize(const ulong newsize) {
        if (newsize == 0)
            Clear();
        else if (size != newsize) {
            ulong limit = (size < newsize) ? size : newsize; // The array can only be reduced?
            Data* TmpElements = new Data[newsize] {};
            for (int index = 0; index < limit; index++)
                std::swap(Elements[index], TmpElements[index]);
            std::swap(Elements, TmpElements);
            size = newsize; // Shouldn't be limit?
            delete[] TmpElements;
        }
    }

    template<typename Data>
    void Vector<Data>::Clear() {
        delete[] Elements;
        Elements = nullptr;
        size = 0;
    }

    template<typename Data>
    Data& Vector<Data>::Back() const {
        if (size != 0)
            return Elements[size - 1];
        else
            throw std::length_error("The vector is empty!");
    }

    template<typename Data>
    Data& Vector<Data>::Front() const {
        if (size != 0)
            return Elements[0];
        else   
            throw std::length_error("The vector is empty!");
    }

    template<typename Data>
    void Vector<Data>::Map(MapFunctor fun, void* par) {
        MapPreOrder(fun, par);
    }

    template<typename Data>
    void Vector<Data>::MapPreOrder(MapFunctor fun, void* par) {
        for(ulong index = 0; index < size; index++)
            fun(Elements[index], par); 
    }

    template<typename Data>
    void Vector<Data>::MapPostOrder(MapFunctor fun, void* par) {
        for(ulong index = (size - 1); index >= 0; index--)
            fun(Elements[index], par);
    }

    template<typename Data>
    void Vector<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
        FoldPreOrder(fun, par, acc);
    }

    template<typename Data>
    void Vector<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const {
        for (ulong index = 0; index < size; index++)
            fun(Elements[index], par, acc); 
    }

    template<typename Data>
    void Vector<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const {
        for(ulong index = (size - 1); index >= 0; index--)
            fun(Elements[index], par, acc);
    }
}
