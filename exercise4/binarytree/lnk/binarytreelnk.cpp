
namespace lasd {

/* ************************************************************************** */

/* ********** Node implementations ********** */

// Specific constructor
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& value) {
    this->value = value;
    leftChild = nullptr;
    rightChild = nullptr;
}

// Destructor
template<typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete leftChild;
    delete rightChild;
}

// Mutable access to node's key
template<typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return value;
}

// Immutable access to node's key
template<typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return value;
}

// Check if node has left child
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (leftChild != nullptr);
}

// Check if node has right child
template<typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (rightChild != nullptr);
}

// Access to node's left child
template<typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if (HasLeftChild()) {
        return *leftChild;
    }
    else {
        throw std::out_of_range("Left child does not exist");
    }
}

// Access to node's right child
template<typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if (HasRightChild()) {
        return *rightChild;
    }
    else {
        throw std::out_of_range("Right child does not exist");
    }
}

/* ********** BinaryTreeLnk implementations ********** */

// Specific constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& lc) {
    size = lc.Size();
    root = new NodeLnk(lc[0]);
    createTreeLnk(0, root, lc);
}

// Auxiliary constructor function
template<typename Data>
void BinaryTreeLnk<Data>::createTreeLnk(int index, struct BinaryTreeLnk<Data>::NodeLnk* root, const LinearContainer<Data>& lc) {
    if ((index * 2) + 1 < lc.Size()) {
        root->leftChild = new NodeLnk(lc[(index * 2) + 1]);
        createTreeLnk((index * 2) + 1, root->leftChild, lc);
    }
    if ((index * 2) + 2 < lc.Size()) {
        root->rightChild = new NodeLnk(lc[(index * 2) + 2]);
        createTreeLnk((index * 2) + 2, root->rightChild, lc);
    }
}

// Copy constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& binaryTree) {
    if (binaryTree.size > 0) {
        size = binaryTree.size;
        root = copyTreeLnk(binaryTree.root);
    }
}

// Auxiliary copy constructor function
template<typename Data>
struct BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::copyTreeLnk(struct BinaryTreeLnk<Data>::NodeLnk* copyNode) {
    struct BinaryTreeLnk<Data>::NodeLnk* tmp = nullptr;
    if (copyNode != nullptr) {
        tmp = new struct BinaryTreeLnk<Data>::NodeLnk(copyNode->value);
        if (copyNode->leftChild != nullptr) {
            tmp->leftChild = copyTreeLnk(copyNode->leftChild);
        }
        if (copyNode->rightChild != nullptr) {
            tmp->rightChild = copyTreeLnk(copyNode->rightChild);
        }
    }
    return tmp;
}

// Move constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& binaryTree) noexcept {
    std::swap(size, binaryTree.size);
    std::swap(root, binaryTree.root);
}

// Destructor
template<typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

// Copy assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& binaryTree) {
    BinaryTreeLnk<Data>* tmp = new BinaryTreeLnk<Data>(binaryTree);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& binaryTree) noexcept {
    std::swap(size, binaryTree.size);
    std::swap(root, binaryTree.root);
    return *this;
}

// Comparison operators
template<typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& binaryTree) const noexcept {
    return BinaryTree<Data>::operator==(binaryTree);
}

template<typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& binaryTree) const noexcept {
    return !(*this == binaryTree);
}

// Specific member functions (inherited from BinaryTree)

template<typename Data>
struct BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
    if (size > 0)
        return *root;
    else 
        throw std::length_error("Tree is empty");
}

// Specific member functions (inherited from Container)

template<typename Data>
void BinaryTreeLnk<Data>::Clear() {
    delete root;
    root = nullptr;
    size = 0;
}

/* ************************************************************************** */

}
