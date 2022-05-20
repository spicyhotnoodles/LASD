
namespace lasd {

/* ************************************************************************** */

// Specific constructor
template<typename Data>
BST<Data>::BST(LinearContainer<Data>& lc) {
    for (int i = 0; i < lc.Size(); i++) {
        Insert(lc[i]);
    }
}

// Copy constructor
template<typename Data>
/*BST<Data>::BST(const BST<Data>& bst) {
    typename BinaryTreeLnk<Data>::BinaryTreeLnk(bst);
}*/
BST<Data>::BST(const BST<Data>& bst) : BinaryTreeLnk<Data>::BinaryTreeLnk(bst) {}

// Move constructor
template<typename Data>
/*BST<Data>::BST(BST<Data>&& bst) noexcept {
    typename BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst));
}*/
BST<Data>::BST(BST<Data>&& bst) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)) {}

// Copy assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst) {
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}

// Move assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bst) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}

// Comparison operators

template<typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
    if (size != bst.size)
        return false;
    else {
        BTInOrderIterator<Data> thisIterator(*this);
        BTInOrderIterator<Data> hisIterator(bst);
        while (!thisIterator.Terminated()) {
            if (thisIterator.operator*() != hisIterator.operator*())
                return false;
            else {
                thisIterator.operator++();
                hisIterator.operator++();
            }
        }
        return true;
    }
}

template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

// Specific member functions

template<typename Data>
const Data& BST<Data>::Min() const {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        return FindPointerToMin(root)->value;
}

template<typename Data>
Data BST<Data>::MinNRemove() {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        return DataNDelete(DetachMin(root));
}

template<typename Data>
void BST<Data>::RemoveMin() {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        delete DetachMin(root);
}

template<typename Data>
const Data& BST<Data>::Max() const {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        return FindPointerToMax(root)->value;
}

template<typename Data>
Data BST<Data>::MaxNRemove() {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        return DataNDelete(DetachMax(root));
}

template<typename Data>
void BST<Data>::RemoveMax() {
    if (root == nullptr)
        throw std::length_error("Tree is empty");
    else
        delete DetachMax(root);
}

template<typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const {
    struct BST<Data>::NodeLnk* const* ptr = &FindPointerToPredecessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Predecessor not found");
    else
        return (*ptr)->value;
}

template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerToPredecessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Predecessor not found");
    else
        return DataNDelete(Detach(ptr));
}

template<typename Data>
void BST<Data>::RemovePredecessor(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerToPredecessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Predecessor not found");
    else
        delete Detach(ptr);
}

template<typename Data>
const Data& BST<Data>::Successor(const Data& dat) const {
    struct BST<Data>::NodeLnk* const* ptr = &FindPointerToSuccessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Successor not found");
    else
        return (*ptr)->value;
}

template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerToSuccessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Successor not found");
    else
        return DataNDelete(Detach(ptr));
}

template<typename Data>
Data BST<Data>::RemoveSuccessor(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerToSuccessor(root, dat);
    if (ptr == nullptr)
        throw std::length_error("Successor not found");
    else
        delete Detach(ptr);
}


// Specific member functions (inherited from TestableContainer)

template<typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept {
    return (FindPointerTo(root, dat) != nullptr);
}

// Specific member functions (inherited from DictionaryContainer)

template<typename Data>
void BST<Data>::Insert(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerTo(root, dat);
    if(ptr == nullptr){
        ptr = new struct BST<Data>::NodeLnk(dat);
        size++;
    }
}

template<typename Data>
void BST<Data>::Insert(Data&& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerTo(root, dat);
    if(ptr == nullptr){
        ptr = new struct BST<Data>::NodeLnk(std::move(dat));
        size++;
    }
}

template<typename Data>
void BST<Data>::Remove(const Data& dat) {
    struct BST<Data>::NodeLnk*& ptr = FindPointerTo(root, dat);
    if (ptr == nullptr)
        return;
    else
        delete Detach(ptr);
}

// Auxiliary functions

template<typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data dat = node->value;
    delete node;
    return dat;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if (node->leftChild == nullptr)
        return Skip2Right(node);
    else if (node->rightChild == nullptr)
        return Skip2Left(node);
    else {
        NodeLnk* min = DetachMin(node->rightChild);
        std::swap(node->value, min->value);
        return min;
    }
    return nullptr;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    struct BST<Data>::NodeLnk* left = nullptr;
    if (node != nullptr) {
        std::swap(left, node->leftChild);
        std::swap(left, node);
        size--;
    }
    return left;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    struct BST<Data>::NodeLnk* right = nullptr;
    if (node != nullptr) {
        std::swap(right, node->rightChild);
        std::swap(right, node);
        size--;
    }
    return right;
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& node, const Data& dat) const noexcept {
    NodeLnk* const* ptr = &node; // pointer to pointer (reference to pointer)
    NodeLnk* current = node; // pointer equals pointer
    while (current != nullptr) {
        if (current->value < dat) {
            ptr = &current->rightChild;
            current = current->rightChild;
        }
        else if (current->value > dat) {
            ptr = &current->leftChild;
            current = current->leftChild;
        }
        else
            break;
        }
    return *ptr;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& dat) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, dat));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept {
    NodeLnk* const* ptr = &node;
    NodeLnk* current = node;
    if (current != nullptr) {
        while (current->HasLeftChild()) {
            ptr = &current->leftChild;
            current = current->leftChild;
        }
    }
    return *ptr;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept {
    NodeLnk* const* ptr = &node;
    NodeLnk* current = node;
    while (current->HasRightChild()) {
        ptr = &current->rightChild;
        current = current->rightChild;
    }
    return *ptr;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
}


template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, const Data& dat) const noexcept {
    NodeLnk* const* ext = nullptr;
    NodeLnk* const* current = &node;
    while (*current != nullptr) {
        if (dat == (*current)->value) {
            if ((*current)->rightChild == nullptr)
                break;
            else
                return FindPointerToMin((*current)->rightChild);
        }
        else if (dat > (*current)->value)
            current = &((*current)->rightChild);
        else if (dat < (*current)->value) {
            ext = current;
            current = &((*current)->leftChild);
        }
    }
    return *ext;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& dat) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, dat));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& node, const Data& dat) const noexcept {
    NodeLnk* const* ext = nullptr;
    NodeLnk* const* current = &node;
    while (*current != nullptr) {
        if (dat == (*current)->value) {
            if ((*current)->leftChild == nullptr)
                break;
            else
                return FindPointerToMax((*current)->leftChild);
        }
        else if (dat > (*current)->value) {
            ext = current;
            current = &((*current)->rightChild);
        }
        else if (dat < (*current)->value)
            current = &((*current)->leftChild);
    }
    return *ext;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node, const Data& dat) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, dat));
}

/* ************************************************************************** */

}
