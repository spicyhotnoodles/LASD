
namespace lasd {

/* ************************************************************************** */
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr() {
    buckets = Vector<BST<Data>>(m);
    /* for (ulong i = 0; i < m; i++) {
        BST<int> bst;
        buckets.operator[](i) = bst;
    } */
}

// Specific constructors
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong& size) {
    m = size;
    buckets = Vector<BST<Data>>(m);
    /* for (ulong i = 0; i < m; i++) {
        BST<int> bst;
        buckets.operator[](i) = bst;
    } */
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const LinearContainer<Data>& lc) {
    m = lc.Size();
    buckets = Vector<BST<Data>>(m);
    /* for (ulong i = 0; i < m; i++) {
        BST<int> bst;
        buckets.operator[](i) = bst;
    } */
    DictionaryContainer<Data>::Insert(lc);
}

template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size, const LinearContainer<Data>& lc) {
    m = size;
    buckets = Vector<BST<Data>>(m);
    DictionaryContainer<Data>::Insert(lc);
}

// Copy constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr& table) : HashTable<Data>::HashTable(table) {
    buckets = Vector<BST<Data>>(table.buckets.Size());
    m = table.buckets.Size();
    buckets = table.buckets;
    size = table.size;
}

// Move constructor
template<typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr&& table) noexcept : HashTable<Data>::HashTable(table) {
    std::swap(m, table.m);
    std::swap(buckets, table.buckets);
    std::swap(size, table.size);
}

/* // Destructor
template<typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr() {

} */

// Copy assignment
template<typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr& table) {
    HashTableClsAdr* tmp = new HashTableClsAdr(table);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr&& table) noexcept {
    HashTable<Data>::operator=(table);
    std::swap(m, table.m);
    std::swap(buckets, table.buckets);
    std::swap(size, table.size);
    return *this;
}

// Comparison operators
/* template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr& table) const noexcept {
    if (size != table.size)
        return false;
    else {
        for (ulong i = 0; i < m; i++) {
            BTInOrderIterator<Data> it(buckets.operator[](i));
            while (!it.Terminated()) {
                if (table.Exists(it.operator*()))
                    it.operator++();
                else
                    return false;
            }
        }
        return true;
    }
} */

template<typename Data>
void AuxEqualOperator(const Data& data, const void* table, void* check) noexcept {
    if (!static_cast<const HashTableClsAdr<Data>*>(table)->Exists(data))
        *((bool*)check) = false;
}

template<typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr& table) const noexcept {
    if (size != table.size) // num of elements
        return false;
    else {
        bool check = true;
        for (ulong i = 0; i < m; i++) {
            buckets.operator[](i).Fold(&AuxEqualOperator<Data>, &table, &check);
            if (!check)
                return false;
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
    HashTableClsAdr<Data>* newTable = new HashTableClsAdr<Data>(newSize);
    for (ulong i = 0; i < m; i++) {
        if (buckets.operator[](i).Size() > 0) {
            BTBreadthIterator<Data> it(buckets.operator[](i));
            while (!it.Terminated()) {
                newTable->Insert(it.operator*());
                it.operator++();
            }
        }
    }
    std::swap(*this, *newTable);
    delete newTable;
}

// Specific member functions (inherited from DictionaryContainer)

template<typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) {
    bool tmp = buckets.operator[](HashTable<Data>::HashKey(data)).Insert(data);
    if (tmp) {
        size++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) {
    bool tmp = buckets.operator[](HashTable<Data>::HashKey(data)).Insert(std::move(data));
    if (tmp) {
        size++;
        return true;
    }
    else
        return false;
}

template<typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) {
    bool tmp = buckets.operator[](HashTable<Data>::HashKey(data)).Remove(data);
    if (tmp) {
        size--;
        return true;
    }
    else
        return false;
}

// Specific memeber functions (inherited from TestableContainer)

/* template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    for (ulong i = 0; i < m; i++) {
        BTInOrderIterator<Data> it(buckets.operator[](i));
        while (!it.Terminated()) {
            if (it.operator*() == HashTable<Data>::hash(data))
                return true;
            else
                it.operator++();
        }
    }
    return false;
} */

/* template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    bool check = false;
    for (ulong i = 0; i < m; i++) {
        buckets.operator[](i).Fold(&AuxFoldExists<Data>, &data, &check);
        if (check)
            return true;
    }
    return false;
} */

template<typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    return buckets.operator[](HashTable<Data>::HashKey(data)).Exists(data);
}

// Specific member functions (inherited from MappableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Map(MapFunctor fun, void* opt) {
    for (ulong i = 0; i < m; i++)
        buckets.operator[](i).Map(fun, opt);
}

// Specific member functions (inherited from FoldableContainer)

template<typename Data>
void HashTableClsAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
    for (ulong i = 0; i < m; i++)
        buckets.operator[](i).Fold(fun, par, acc);
}

// Specific member functions (inherited from Container)

template<typename Data>
void HashTableClsAdr<Data>::Clear() {
    for (ulong i = 0; i < m; i++)
        buckets.operator[](i).Clear();
    size = 0;
}

/* ************************************************************************** */

}
