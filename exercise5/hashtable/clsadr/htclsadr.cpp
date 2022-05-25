
namespace lasd {

/* ************************************************************************** */

// Specific constructors
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong& size) {

}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& lc) {

}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& lc, const ulong size) {

}

// Copy constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr& table) {

}

// Move constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr&& table) noexcept {

}

// Destructor
template<typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {

}

// Copy assignment
template<typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr& table) {

}

// Move assignment
template<typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr&& table) noexcept {

}

// Comparison operators
template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr& table) const noexcept {
    if (size != table.size)
        return false;
    else {
        for (ulong i = 0; i < m; i++) {
            BTInOrderIterator<unsigned long> it(buckets.operator[](i));
            while (!it.Terminated()) {
                if (table.Exists(it.operator*()))
                    it.operator++();
                else
                    return false;
            }
        }
        return true;
    }
}

template<typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr& table) const noexcept {
    return !(*this == table);
}

// Specific member functions (inherited from HashTable)

// Resize the hashtable to a given size
template<typename Data>
void HashTableClsAdr<Data>::Resize(ulong newSize) {

}

// Specific member functions (inherited from DictionaryContainer)

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) {
    bool tmp = buckets.operator[](this->HashKey(data)).Insert(data);
    if (tmp) {
        size++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) {
    bool tmp = buckets.operator[](this->HashKey(data)).Insert(std::move(data));
    if (tmp) {
        size++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) {
    bool tmp = buckets.operator[](this->HashKey(data)).Remove(data);
    if (tmp) {
        size--;
        return true;
    }
    else
        return false;
}

// Specific memeber functions (inherited from TestableContainer)

template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    for (ulong i = 0; i < m; i++) {
        BTInOrderIterator<unsigned long> it(buckets.operator[](i));
        while (!it.Terminated()) {
            if (it.operator*() == data)
                return true;
            else
                it.operator++();
        }
    }
    return false;
}

//? Serve davvero?
template<typename Data>
bool HashTableClsAdr<Data>::AuxExists(const ulong& key) const noexcept {
    BTInOrderIterator<unsigned long> it(buckets.operator[](key));
    while (!it.Terminated()) {
        if (it.operator*() == key)
            return true;
        else
            it.operator++();
    }
    return false;
}

// Specific member functions (inherited from MappableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* opt) {

}

// Specific member functions (inherited from FoldableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {

}

// Specific member functions (inherited from Container)

template<typename Data>
void HashTableClsAdr<Data>::Clear() {

}

/* ************************************************************************** */

}
