
namespace lasd {

// Copy constructor
template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack) {
    Node* tmp = stack.head;
    Node* top = stack.top;
    while (tmp != nullptr) {
        List<Data>::InsertAtBack(tmp->value);
        tmp = tmp->next;
    }
}

// Move costructor
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept {
    std::swap(head, stack.head);
    std::swap(top, stack.top);
    std::swap(size, stack.size);
}

// Copy assignment
template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stack) {
    StackLst<Data>* tmpStack = new StackLst<Data>(stack);
    std::swap(*tmpStack, *this);
    delete tmpStack;
    return *this;
}

//Move assignment
template<typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stack) noexcept {
    std::swap(head, stack.head);
    std::swap(top, stack.top);
    std::swap(size, stack.size);
    return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
    List<Data>::operator==(stack);
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept {
    List<Data>::operator!=(stack);
}

template<typename Data>
Data& StackLst<Data>::Top() const {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else
        return top->value;
}

template<typename Data>
Data StackLst<Data>::Top() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else
        return top->value;
}

template<typename Data>
void StackLst<Data>::Pop() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
}

template<typename Data>
Data StackLst<Data>::TopNPop() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else {
        Node* temp = top; // ragionaci
        Pop();
        return temp->value;
    }
}

template<typename Data>
void StackLst<Data>::Push(const Data& dat) {
    List<Data>::InsertAtFront(dat);
}

template<typename Data>
void StackLst<Data>::Push(Data&& dat) {
    List<Data>::InsertAtFront(dat);
}

template<typename Data>
void StackLst<Data>::Clear() {
    List<Data>::Clear();
}

template<typename Data>
void StackLst<Data>::printStack() const noexcept {
    List<Data>::printList();
}


}
