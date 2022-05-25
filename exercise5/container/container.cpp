#include <iostream>

namespace lasd {

    template <typename Data>
    inline bool LinearContainer<Data>::operator==(const LinearContainer<Data>& lc) const noexcept {
        if (size == lc.size) {
            for (int index = 0; index < size; index++)
                if (operator[](index) != lc[index])
                    return false;
            return true;
        }
        else
            return false; //the containers have different sizes
    }

    template <typename Data>
    inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data>& lc) const noexcept {
        return !(this == lc); 
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Front() const {
        if (size == 0)
            throw std::length_error("The linear container is empty!");
        else
            return operator[](0);
    }

    template <typename Data>
    inline Data& LinearContainer<Data>::Back() const {
        if (size == 0)
            throw std::length_error("The linear container is empty!");
        else
            return operator[](size - 1);
    }

    template <typename Data>
    void AuxFoldExists(const Data& dat, const void* val, void* exists) noexcept {
        if (dat == *((Data*) val))
            *((bool*)exists) = true;        
    }

    template<typename Data>
    bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept {
        bool exists = false;
        Fold(&AuxFoldExists<Data>, &dat, &exists);
        return exists;
    }

    template<typename Data>
    void PreOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
        MapPreOrder(fun, par);
    }

    template<typename Data>
    void PostOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
        MapPostOrder(fun, par);
    }

    template<typename Data>
    void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
        FoldPreOrder(fun, par, acc);
    }

    template<typename Data>
    void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* acc, void* res) const {
        FoldPostOrder(fun, acc, res);
    }

    template<typename Data>
    void InOrderMappableContainer<Data>::Map(MapFunctor fun, void* par) {
        MapInOrder(fun, par);
    }

    template<typename Data>
    void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
        FoldInOrder(fun, par, acc);
    }

    template<typename Data>
    void Insert(const LinearContainer<Data>& lc) {
        for (int i = 0; i < lc.Size(); i++)
            Insert(lc[i]);
    }

    template<typename Data>
    void Insert(LinearContainer<Data>&& lc) {
        for (int i = 0; i < lc.Size(); i++)
            Insert(lc[i]);
    }

    template<typename Data>
    void Remove(LinearContainer<Data>& lc) {
        for (int i = 0; i < lc.Size(); i++)
            Remove(lc[i]);
    }

}

/* ************************************************************************** */
