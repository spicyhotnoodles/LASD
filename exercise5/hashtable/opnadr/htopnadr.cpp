
namespace lasd {

/* ************************************************************************** */

// Specific constructors

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr() {
    buckets = Vector<Data>(m);
    flags = Vector<char>(m);
    resetFlags();
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong& size) {
    m = size;
    buckets = Vector<Data>(m);
    flags = Vector<char>(m);
    resetFlags();
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const LinearContainer<Data>& lc) {
    buckets = Vector<Data>(m);
    flags = Vector<char>(m);
    resetFlags();
    DictionaryContainer<Data>::Insert(lc);
}

template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong size, const LinearContainer<Data>& lc) {
    m = size;
    buckets = Vector<Data>(m);
    flags = Vector<char>(m);
    resetFlags();
    DictionaryContainer<Data>::Insert(lc);
}

// Copy constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr& table) : HashTable<Data>::HashTable(table) {
    buckets = Vector<Data>(table.buckets.Size());
    // flags = Vector<char>(table.flags.Size());
    m = table.buckets.Size();
    buckets = table.buckets;
    size = table.size;
    flags = table.flags;
}

// Move constructor
template<typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr&& table) noexcept : HashTable<Data>::HashTable(table) {
    std::swap(m, table.m);
    std::swap(buckets, table.buckets);
    std::swap(flags, table.flags);
    std::swap(size, table.size);
}

// Copy assignment
template<typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr& table) {
    HashTableOpnAdr* tmp = new HashTableOpnAdr(table);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr&& table) noexcept {
    HashTable<Data>::operator=(table);
    std::swap(m, table.m);
    std::swap(buckets, table.buckets);
    std::swap(size, table.size);
    std::swap(flags, table.flags);
    return *this;
}

// Comparison operators
/* template<typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr& table) const noexcept {
    if (size == table.size) {
        for (ulong i = 0; i < m; i++) {
            if (!table.buckets.Exists(buckets.operator[](i)))
                return false;
        }
    }
    return false;
} */

template<typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr& table) const noexcept {
    if (size != table.size)
        return false;
    else {
        for (ulong i = 0; i < m; i++) {
            if (!table.buckets.Exists(buckets.operator[](i)))
                return false;
        }
    }
    return true;
}

template<typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr& table) const noexcept {
    return !(*this == table);
}

// Specific member function (inherited from HashTable)
template<typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newSize) {
    HashTableOpnAdr<Data>* newTable = new HashTableOpnAdr<Data>(newSize);
    //DictionaryContainer<Data>::Insert(buckets);
    for (ulong i = 0; i < m; i++) {
        if (flags.operator[](i) == 'u')
            newTable->Insert(buckets.operator[](i));
    }
    std::swap(*this, *newTable);
}

// Specific member functions (inherited from DictionaryContainer)
/* template<typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) {
    if (!Exists(data)) {
        ulong addr = HashKey(data);
        if (flags.operator[](addr) == 'e' or \
        flags.operator[](addr) == 'd') { // if the bucket is empty or deleted
            buckets.operator[](addr) = data;
            flags.operator[](addr) = 'u';
        }
        else if (flags.operator[](addr) == 'u') { // collision
            addr = FindEmpty(addr);
            buckets.operator[](addr) = data;
            flags.operator[](addr) = 'u';
        }
        size++;
        return true;
    }
    return false;
} */

template<typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) {
    if (!Exists(data)) {
        ulong addr = FindEmpty(HashKey(data));
        if (addr != -1) {
        buckets.operator[](addr) = data;
        flags.operator[](addr) = 'u';
        size++;
        return true;
        }
    }
    return false;
}

template<typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) {
    if (!Exists(data)) {
        ulong addr = FindEmpty(HashKey(std::move(data)));
        if (addr != -1) {
        buckets.operator[](addr) = std::move(data);
        flags.operator[](addr) = 'u';
        size++;
        return true;
        }
    }
    return false;
}

/* template<typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) {
    if (!Exists(data)) {
        ulong addr = HashKey(data);
        if (flags.operator[](addr) == 'e' or \
        flags.operator[](addr) == 'd') { // if the bucket is empty or deleted
            buckets.operator[](addr) = std::move(data);
            flags.operator[](addr) = 'u';
        }
        else if (flags.operator[](addr) == 'u') { // collision
            addr = FindEmpty(addr);
            buckets.operator[](addr) = std::move(data);
            flags.operator[](addr) = 'u';
        }
        size++;
        return true;
    }
    return false;
}
 */
template<typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) {
    if (Exists(data)) {
        ulong addr = Find(data);
        flags.operator[](addr) = 'd';
        buckets.operator[](addr) = Data();
        size--;
        return true;
    }
    return false;
}

// Specific member function (inherited from TestableContainer)
template<typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept {
    ulong addr = HashKey(data);
    ulong i = 0;
    while (flags.operator[](addr) != 'e') { // If an empty bucket is found, the element does not exist for sure
        if (buckets.operator[](addr) == data)
            return true;
        i++;
        if (i == m) // All the buckets are checked and the data was not found
            break;
        addr = HashKey(addr, i);
    }
    return false;
}

// Specific member function (inherited from MappableContainer)
template<typename Data>
void HashTableOpnAdr<Data>::Map(MapFunctor fun, void* par) {
    buckets.Map(fun, par);
}

// Specific member function (inherited from FoldableContainer)
template<typename Data>
void HashTableOpnAdr<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
    buckets.Fold(fun, par, acc);
}

// Specific member function (inherited from Container) 
template<typename Data>
void HashTableOpnAdr<Data>::Clear() {
    buckets.Clear();
    buckets = Vector<Data>(m);
    resetFlags();
    size = 0;
}

template<typename Data>
void HashTableOpnAdr<Data>::resetFlags() {
    for (ulong i = 0; i < m; i++)
        flags.operator[](i) = 'e';
}

template<typename Data>
ulong HashTableOpnAdr<Data>::HashKey(ulong addr, ulong index) const {
    return (addr + index) % m;
}

template<typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(ulong addr) {
    ulong i = 0;
    addr = HashKey(addr, i);
    while (flags.operator[](addr) == 'u') {
        i++;
        if (i == m)
            Resize(m * 2);
        else
            addr = HashKey(addr, i);
    }
    return addr;
}

template<typename Data>
ulong HashTableOpnAdr<Data>::Find(const Data& data) {
    ulong addr = HashKey(data);
    ulong i = 0;
    while (flags.operator[](addr) != 'e') {
        if (buckets.operator[](addr) == data)
            break;
        i++;
        addr = HashKey(addr, i);
    }
    return addr;
}

/* ************************************************************************** */

}
