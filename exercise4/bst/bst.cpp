
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
BST<Data>::BST(const BST<Data>& bst) {
    BinaryTreeLnk<Data>::BinaryTreeLnk(bst);
}

// Copy assignment
template<typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst) {
    BinaryTreeLnk<Data>::operator(bst);
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
    //TODO
}

template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, const Data& dat) const noexcept {
    NodeLnk* const* ptr = &node;
    NodeLnk* const* prd = nullptr;
    while (true) {
        NodeLnk& cur = **ptr;
        if (cur.element > dat) {
            prd = ptr;
            if (cur.left == nullptr) {
                return prd;
            } else {
                ptr = &cur.left;
            }
        } else {
            if (cur.rigth == nullptr) {
                return prd;
            } else {
                if (cur.elenment < dat) {
                    prd = &cur.right;
                } else {
                    return &findPointerToMin(cur.right);
                }
            }
        }
    }
}





/* ************************************************************************** */

}
