
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queue) {
    Node* tmp = queue.head;
    while (tmp != nullptr) {
        List<Data>::InsertAtBack(tmp->value);
        tmp = tmp->next;
    }
}

// Move constructor
template<typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queue) noexcept {
    std::swap(head, queue.head);
    std::swap(size, queue.size);
}

// Copy assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queue) {
    QueueLst<Data>* tmpQueue = new QueueLst<Data>(queue);
    std::swap(*tmpQueue, *this);
    delete tmpQueue;
    return *this;
}

// Move assignment
template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queue) noexcept {
    std::swap(head, queue.head);
    std::swap(size, queue.size);
    return *this;
}

// Comparison operators
template<typename Data>
bool QueueLst<Data>::operator==(const QueueLst<Data>& queue) const noexcept {
    return (List<Data>::operator==(queue));
}

template<typename Data>
bool QueueLst<Data>::operator!=(const QueueLst<Data>& queue) const noexcept {
    return (List<Data>::operator!=(queue));
}

template<typename Data>
const Data& QueueLst<Data>::Head() const {
    if (size == 0)
        throw std::length_error("Queue is empty");
    else
        return head->value;
}

template<typename Data>
Data QueueLst<Data>::Head() {
    if (size == 0)
        throw std::length_error("Queue is empty");
    else
        return head->value;
}

template<typename Data>
void QueueLst<Data>::Dequeue() {
    if (size == 0)
        throw std::length_error("Queue is empty");
    else {
        List<Data>::RemoveFromFront();
    }
}

template<typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    if (size == 0)
        throw std::length_error("Queue is empty");
    else {
        Data tmp = Head();
        List<Data>::RemoveFromFront();
        return tmp;
    }
}

template<typename Data>
void QueueLst<Data>::Enqueue(const Data& dat) {
    List<Data>::InsertAtBack(dat);
}

template<typename Data>
void QueueLst<Data>::Enqueue(Data&& dat) {
    List<Data>::InsertAtBack(dat);
}

template<typename Data>
void QueueLst<Data>::Clear() {
    List<Data>::Clear();
}

template<typename Data>
void QueueLst<Data>::printQueue() const noexcept {
    if (size != 0) {
            Node* curr = head;
            std::cout << "Front <-- "; 
            while(curr != nullptr) {
                std::cout << curr->value;
                std::cout << " <-- ";
                curr = curr->next;
            }
            std::cout << "Rear" << std::endl;
        }
        else {
            std::cout << "Queue is empty" << std::endl;
        }
}

/* ************************************************************************** */

}
