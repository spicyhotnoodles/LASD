
namespace lasd {

// Copy constructor
template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stack) {
    Node* tmp = stack.head;
    while (tmp != nullptr) {
        List<Data>::InsertAtBack(tmp->value);
        tmp = tmp->next;
    }
}

// Move costructor
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stack) noexcept {
    std::swap(head, stack.head);
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
    std::swap(size, stack.size);
    return *this;
}

template<typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stack) const noexcept {
    return (List<Data>::operator==(stack));
}

template<typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stack) const noexcept {
    return (List<Data>::operator!=(stack));
}

template<typename Data>
const Data& StackLst<Data>::Top() const {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else
        return head->value;
}

template<typename Data>
Data StackLst<Data>::Top() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else {
        //std::cout << head->value << std::endl;
        return head->value;
    }
}

template<typename Data>
void StackLst<Data>::Pop() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}

template<typename Data>
Data StackLst<Data>::TopNPop() {
    if (size == 0)
        throw std::length_error("Stack is empty");
    else {
        Data tmp = Top();
        Pop();
        return tmp;
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
    if (size != 0) {
            Node* curr = head;
            while(curr != nullptr) {
                std::cout << curr->value << std::endl;
                curr = curr->next;
            }
        }
        else {
            std::cout << "Lo stack è vuoto!" << std::endl;
        }
}


}
