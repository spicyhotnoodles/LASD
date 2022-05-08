
// #include "..."

namespace lasd {

/* ************************************************************************** */

/* ********** Node implementations ********** */

// Comparison operators
template<typename Data>
bool BinaryTree<Data>::Node::operator==(const struct BinaryTree<Data>::Node& node) const {
    if (node.Element() == this->Element()){ 
        bool thisDX = this->HasRightChild();
        bool thisSX = this->HasLeftChild(); 

        bool hisDX = node.HasRightChild();
        bool hisSX = node.HasLeftChild(); 

        bool right = (thisDX == hisDX);
        bool left = (thisSX == hisSX); 

        if (left && right) { 
            if (thisSX && thisDX){
                return ((node.LeftChild() == LeftChild()) && (node.RightChild() == RightChild()));
            } 
            else if (thisSX) {
                return (node.LeftChild() == LeftChild());
            } 
            else if (thisDX) {
                return (node.RightChild() == RightChild());
            } 
            else {
                return true;
            }
        }
  }
  return false;
}

template<typename Data>
bool BinaryTree<Data>::Node::operator!=(const struct BinaryTree<Data>::Node& node) const {
    return !(*this == node);
}

/* ********* Binary tree implementations ********* */

// Comparison operators
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if (this->size != bt.size)
        return false;
    else {
        if (size == 0)
            return true;
        else
            return (this->Root().operator==(bt.Root()));
    }
}

template<typename Data>
void BinaryTree<Data>::printTree(const std::string& prefix, struct BinaryTree<Data>::Node* root, bool isLeft) {
    if (root != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        // print the value of the node
        std::cout << root->Element() << std::endl;
        // enter the next tree level - left and right branch
        if (root->HasLeftChild())
            printTree(prefix + (isLeft ? "│   " : "    "), &(root->LeftChild()), true);
        if (root->HasRightChild())
            printTree(prefix + (isLeft ? "│   " : "    "), &(root->RightChild()), false);
    }
}

template<typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bt) const noexcept {
    return !(*this == bt);
}

template<typename Data>
void BinaryTree<Data>::Map(MapFunctor fun, void* par) {
    if (size != 0)
        MapPreOrder(fun, par, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
    if (size != 0)
        FoldPreOrder(fun, par, acc, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void* par) {
    if (size != 0)
        MapPreOrder(fun, par, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const {
    if (size != 0)
        FoldPreOrder(fun, par, acc, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor fun, void* par) {
    if (size != 0)
        MapPostOrder(fun, par, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const {
    if (size != 0)
        FoldPostOrder(fun, par, acc, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor fun, void* par) {
    if (size != 0)
        MapInOrder(fun, par, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor fun, const void* par, void* acc) const {
    if (size != 0)
        FoldInOrder(fun, par, acc, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor fun, void* par) {
    if (size != 0)
        MapBreadth(fun, par, &(Root()));
}

template<typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor fun, const void* par, void* acc) const {
    if (size != 0)
        FoldBreadth(fun, par, acc, &(Root()));
}

/* ********** Auxiliary functions implementations  ********** */

template<typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void* par, Node* node) {
    if (node != nullptr) {
        fun(node->Element(), par);
        if (node->HasLeftChild())
            MapPreOrder(fun, par, &(node->LeftChild()));
        if (node->HasRightChild())
            MapPreOrder(fun, par, &(node->RightChild()));
    }
}

template<typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* node) const {
    if (node != nullptr) {
        fun(node->Element(), par, acc);
        if (node->HasLeftChild())
            FoldPreOrder(fun, par, acc, &(node->LeftChild()));
        if (node->HasRightChild())
            FoldPreOrder(fun, par, acc, &(node->RightChild()));
    }
}

template<typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor fun, void* par, Node* node) {
    if (node != nullptr) {
        if (node->HasLeftChild())
            MapPostOrder(fun, par, &(node->LeftChild()));
        if (node->HasRightChild())
            MapPostOrder(fun, par, &(node->RightChild()));
        fun(node->Element(), par);
    }
}

template<typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* node) const {
    if (node != nullptr) {
        if (node->HasLeftChild())
            FoldPostOrder(fun, par, acc, &(node->LeftChild()));
        if (node->HasRightChild())
            FoldPostOrder(fun, par, acc, &(node->RightChild()));
        fun(node->Element(), par, acc);
    }
}

template<typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor fun, void* par, Node* node) {
    if (node != nullptr) {
        if (node->HasLeftChild())
            MapInOrder(fun, par, &(node->LeftChild()));
        fun(node->Element(), par);
        if (node->HasRightChild())
            MapInOrder(fun, par, &(node->RightChild()));
    }
}

template<typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor fun, const void* par, void* acc, Node* node) const {
    if (node != nullptr) {
        if (node->HasLeftChild())
            FoldInOrder(fun, par, acc, &(node->LeftChild()));
        fun(node->Element(), par, acc);
        if (node->HasRightChild())
            FoldInOrder(fun, par, acc, &(node->RightChild()));
    }
}

template<typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor fun, void* par, Node* node) {
    QueueLst<struct BinaryTree<Data>::Node*> queue;
    queue.Enqueue(node);
    while (!queue.Empty()) {
        Node* temp = queue.HeadNDequeue();
        fun(temp->Element(), par);
        if (temp->HasLeftChild())
            queue.Enqueue(&(temp->LeftChild()));
        if (temp->HasRightChild())
            queue.Enqueue(&(temp->RightChild()));
    }    
}

template<typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor fun, const void* par, void* acc, Node* node) const {
    QueueLst<struct BinaryTree<Data>::Node*> queue;
    queue.Enqueue(node);
    while (!queue.Empty()) {
        Node* temp = queue.HeadNDequeue();
        fun(temp->Element(), par, acc);
        if (temp->HasLeftChild())
            queue.Enqueue(&(temp->LeftChild()));
        if (temp->HasRightChild())
            queue.Enqueue(&(temp->RightChild()));
    }
}

/* ********** BTPreOrderIterator implementations ********** */

// Specific constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty())
        current = nullptr;
    else {
        current = &(bt.Root());
        resetRoot = &(bt.Root());
    }
}

// Copy constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator) {
    current = iterator.current;
    resetRoot = iterator.resetRoot;
    stack = iterator.stack;
}

// Move constructor
template<typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
}

// Destructor
template<typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator() {
    stack.Clear();
    /* delete current;
    delete resetRoot; */
    current = nullptr;
    resetRoot = nullptr;
}

// Copy assignment 
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& iterator) {
    BTPreOrderIterator<Data>* temp = new BTPreOrderIterator<Data>(iterator);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

// Move assignment
template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
    return *this;
}

// Comparison operators
template<typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator) const noexcept {
    if (current != iterator.current)
        return false;
    else if (stack.Size() != iterator.stack.Size())
        return false;
    else if (resetRoot != iterator.resetRoot)
        return false;
    else {
        for (int i = 0; i < stack.Size(); i++) { 
            if (stack[i] != iterator.stack[i])
                return false;
        }
        return true;
    }
}

template<typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);   
}

// Specific memeber functions (inherited from Iterator)

template<typename Data>
Data& BTPreOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else 
        return current->Element();
}

template<typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return current == nullptr;
}

// Specific member functions (inherited from Iterator)

template<typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else {
        if (current->HasLeftChild() && current->HasRightChild()) {
            stack.Push(&(current->RightChild()));
            current = &(current->LeftChild());
        }
        else if (current->HasLeftChild() && !current->HasRightChild())
            current = &(current->LeftChild());
        else if (!current->HasLeftChild() && current->HasRightChild())
            current = &(current->RightChild());
        else if (!current->HasLeftChild() && !current->HasRightChild()) {
            if (stack.Empty())
                current = nullptr;
            else {
                current = stack.TopNPop();
            }
        }
        return *this;
    }
}

// Specific member functions (inherited from ResettableIterator)

template<typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    current = resetRoot;
    stack.Clear();
}

/* ********** BTPostOrderIterator implementations ********** */

// Specific constructor

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty())
        current = nullptr;
    else {
        setMinLeaf(&(bt.Root()));
        resetRoot = last = current;
    }
}

// Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iterator) noexcept {
    current = iterator.current;
    resetRoot = iterator.resetRoot;
    stack = iterator.stack;
    last = iterator.last;
}

// Move constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
    std::swap(last, iterator.last);
}

// Destructor
template<typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator() {
    stack.Clear();
    /* delete current;
    delete resetRoot;
    delete last; */
    current = nullptr;
    resetRoot = nullptr;
    last = nullptr;
}

// Copy assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& iterator) {
    BTPostOrderIterator<Data>* temp = new BTPostOrderIterator<Data>(iterator);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

//Move assignment
template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
    std::swap(last, iterator.last);
    return *this;
}

// Comparison operators
template<typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iterator) const noexcept {
    if (current != iterator.current)
        return false;
    else if (stack.Size() != iterator.stack.Size())
        return false;
    else if (resetRoot != iterator.resetRoot)
        return false;
    else {
        for (int i = 0; i < stack.Size(); i++) { 
            if (stack[i] != iterator.stack[i])
                return false;
        }
        return true;
    }
}

template<typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);   
}

// Auxiliary function
template<typename Data>
void BTPostOrderIterator<Data>::setMinLeaf(struct BinaryTree<Data>::Node* node) {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else {
        current = node;
        while (current->HasLeftChild()) {
            stack.Push(current);
            current = &(current->LeftChild());
        }
        if (current->HasRightChild()) {
            stack.Push(current);
            setMinLeaf(&(current->RightChild()));
        }
    }
}

// Specific memeber functions (inherited from Iterator)

template<typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else 
        return current->Element();
}

template<typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return current == nullptr;
}

// Specific member functions (inherited from ForwardIterator)

template<typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    if (stack.Empty()) 
        current = last = nullptr;
    else {
        current = stack.TopNPop();
        if (current->HasRightChild() && (&(current->RightChild()))!=last) {
            stack.Push(current);
            setMinLeaf(&(current->RightChild()));
        }
    }
    last = current;
    return *this;
}

// Specific memeber functions (Inherited from ResettableIterator)

template<typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    current = resetRoot;
    stack.Clear();
}

/* ********** BTInOrderIterator implementations ********** */

// Specific constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty())
        current = nullptr;
    else {
        setMinLeaf(&(bt.Root()));
        resetRoot = current;
    }
}

// Copy constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator) {
    current = iterator.current;
    resetRoot = iterator.resetRoot;
    stack = iterator.stack;
}

// Move constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
}

// Destructor
template<typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator() {
    current = nullptr;
    resetRoot = nullptr;
    stack.Clear();
}

// Copy assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& iterator) {
    BTInOrderIterator<Data>* temp = new BTInOrderIterator<Data>(iterator);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

// Move assignment
template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(stack, iterator.stack);
    return *this;
}

// Comparison operators
template<typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept {
    if (current != iterator.current)
        return false;
    if (stack.Size() != iterator.stack.Size())
        return false;
    else if (resetRoot != iterator.resetRoot)
        return false;
    else {
        for (int i = 0; i < stack.Size(); i++) { 
            if (stack[i] != iterator.stack[i])
                return false;
        }
        return true;
    }
}

template<typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept {
    return !(*this == iterator);
}

// Auxiliary function
template<typename Data>
void BTInOrderIterator<Data>::setMinLeaf(struct BinaryTree<Data>::Node* node) {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else {
        current = node;
        while (current->HasLeftChild()) {
            stack.Push(current);
            current = &(current->LeftChild());
        }
    }
}

// Specific member functions (inherited from Iterator)

template<typename Data>
Data& BTInOrderIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else 
        return current->Element();
}

template<typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return current == nullptr;
}

// Specific member functions (inherited from ForwardIterator)

template<typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else {
        if (current->HasRightChild()) {
            current = &(current->RightChild());
            if (current->HasLeftChild()) {
                stack.Push(current);
                setMinLeaf(&(current->LeftChild()));
            }
        }
        else {
            if (stack.Empty())
                current = nullptr;
            else
                current = stack.TopNPop();
        }   
    }
    return *this;
}

// Specific member functions (Inherited from ResettableIterator)

template<typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    current = resetRoot;
    stack.Clear();
}

/* ********** BTBreadthIterator implementations ********** */

// Specific constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty())
        current = nullptr;
    else {
        //current = typename BinaryTree<Data>::Node*(&(bt.Root()));
        //resetRoot = typename BinaryTree<Data>::Node*(&(bt.Root()));
        current = &(bt.Root());
        resetRoot = &(bt.Root());
    }
}

// Copy constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator) {
    current = iterator.current;
    resetRoot = iterator.resetRoot;
    queue = iterator.queue;
}

// Move constructor
template<typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(queue, iterator.queue);
}

// Destructor
template<typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator() {
    queue.Clear();
    /* delete current;
    delete resetRoot; */
    current = nullptr;
    resetRoot = nullptr;
}

// Comparison operators
template<typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& iterator) const noexcept {
    if (current != iterator.current)
        return false;
    else if (resetRoot != iterator.resetRoot)
        return false;
    else if (queue.Size() != iterator.queue.Size())
        return false;
    else {
        for (int i = 0; i < queue.Size(); i++) {
            if (queue[i] != iterator.queue[i])
                return false;
        }
        return true;
    }
}

template<typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& iterator) const noexcept {
    return !(*this == iterator);
}

// Copy assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator) {
    BTBreadthIterator<Data>* temp = new BTBreadthIterator<Data>(iterator);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

// Move assignment
template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator) noexcept {
    std::swap(current, iterator.current);
    std::swap(resetRoot, iterator.resetRoot);
    std::swap(queue, iterator.queue);
    return *this;
}

// Specific member functions (inherited from Iterator)

template<typename Data>
Data& BTBreadthIterator<Data>::operator*() const {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else
        return current->Element();
}

template<typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return current == nullptr;
}

// Specific member functions (inherited from ForwardIterator)

template<typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (Terminated())
        throw std::out_of_range("Iterator out of range");
    else {
        if (current->HasLeftChild())
            queue.Enqueue(&(current->LeftChild()));
        if (current->HasRightChild())
            queue.Enqueue(&(current->RightChild()));
        if (!queue.Empty())
            current = queue.HeadNDequeue();
        else
            current = nullptr;
        return *this;
    }
}

// Specific member functions (inherited from ResettableIterator)

template<typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    current = resetRoot;
    queue.Clear();
}

/* ************************************************************************** */

}
