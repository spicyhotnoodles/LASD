
namespace lasd {

/* ************************************************************************** */

/* ********** Node implementations ********** */

// Specific constructor
template<typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value, const int index, Vector<NodeVec*>* vecPtr) {
    this->value = value;
    this->index = index;
    this->vecPtr = vecPtr;
}

// Mutable access to node's key
template<typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return value;
}

// Immutable access to node's key
template<typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return value;
}

// Check if node has left child
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return (index * 2 + 1 < vecPtr->Size());
}

// Check if node has right child
template<typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return (index * 2 + 2 < vecPtr->Size());
}

// Access to node's left child
template<typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (HasLeftChild()) {
        return *(vecPtr->operator[](index * 2 + 1));
    }
    else {
        throw std::out_of_range("Left child does not exist");
    }
}

// Access to node's right child
template<typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (HasRightChild()) {
        return *(vecPtr->operator[](index * 2 + 2));
    }
    else {
        throw std::out_of_range("Right child does not exist");
    }
}

/* ********** BinaryTreeVec implementations ********** */

// A binary tree obtained from a LinearContainer
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lc) {
    if (lc.Size() > 0) {
        size = lc.Size();
        treePtr = new Vector<NodeVec*>(size);
        for (int i = 0; i < size; i++) {
            treePtr->operator[](i) = new NodeVec(lc[i], i, treePtr);
        }
    }
}

// Copy constructor
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btvec) {
    size = btvec.size;
    treePtr = new Vector<NodeVec*>(size);
    for (int i = 0; i < size; i++) {
        treePtr->operator[](i) = new NodeVec(btvec.treePtr->operator[](i)->value, i, treePtr);
    }
}

// Move constructor
// ! Verificare che funzioni
template<typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btvec) noexcept {
    std::swap(size, btvec.size);
    treePtr = new Vector<NodeVec*>(size);
    std::swap(treePtr, btvec.treePtr); 
}

// Destructor
// ! Verificare che funzioni (probabile double free)
template<typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    for (int i = 0; i < size; i++) {
        delete treePtr->operator[](i);
    }
    delete treePtr;
}

// Copy assignement
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& btvec) {
    BinaryTreeVec* tmp = new BinaryTreeVec(btvec);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

// Move assignement
// ! Verificare che funzioni
template<typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec&& btvec) noexcept {
    std::swap(size, btvec.size);
    treePtr = new Vector<NodeVec*>(size);
    std::swap(treePtr, btvec.treePtr); 
    return *this;
}

// Comparison operators
// ! Verificare che funzioni
template<typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec& btvec) const noexcept {
    /* if (size != btvec.size)
        return false;
    else {
        for (int i = 0; i < size; i++) {
            if (treePtr->operator[](i)->value != btvec.treePtr->operator[](i)->value)
                return false;
        }
        return true;
    } */
    return BinaryTree<Data>::operator==(btvec);
}

template<typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec& btvec) const noexcept {
    return !(*this == btvec);
}

// Specific member functions

template<typename Data>
struct BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const { // Override BinaryTree member function
    if (size > 0) {
        return *(treePtr->operator[](0));
    }
    else {
        throw std::length_error("Binary tree is empty");
    }
}

template<typename Data>
void BinaryTreeVec<Data>::Clear() { // Override Container member
    for (int i = 0; i < size; i++) {
        delete treePtr->operator[](i);
    }
    delete treePtr;
    size = 0;
}

template<typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor fun, void* par) {
    // ? Call MapBreadth(fun, par, Root())
    //MapBreadth(fun, par, &(Root()));
    BinaryTree<Data>::MapBreadth(fun, par, &(Root())); // to call in parent class method
}

template<typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor fun, const void* par, void* acc) const {
    // ? Call FoldBreadth(fun, par, acc, Root())
    //MapBreadth(fun, par, acc, &(Root()));
    BinaryTree<Data>::FoldBreadth(fun, par, acc, &(Root())); // to call in parent class method
}

/* ************************************************************************** */

}