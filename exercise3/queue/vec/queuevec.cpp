
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template<typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& queue) {
    size = queue.size;
    front = queue.front;
    rear = queue.rear;
    queueSize = queue.queueSize;
    Elements = new Data[queue.size];
    for (int index = 0; index < size; index++)
        Elements[index] = queue[index];
}

// Move constructor
template<typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queue) noexcept {
    Elements = new Data[queue.size];
    std::swap(Elements, queue.Elements);
    std::swap(size, queue.size);
    std::swap(front, queue.front);
    std::swap(rear, queue.rear);
    std::swap(queueSize, queue.queueSize);
}

// Copy assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queue) {
    QueueVec<Data>* tmpqueue = new QueueVec<Data>(queue); // Copy constructor
    std::swap(*tmpqueue, *this);
    delete tmpqueue;
    return *this;
}

// Move assignment
template<typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queue) noexcept {
    std::swap(Elements, queue.Elements);
    std::swap(size, queue.size);
    std::swap(front, queue.front);
    std::swap(rear, queue.rear);
    std::swap(queueSize, queue.queueSize);
    return *this;
}

// Comparison operators
template<typename Data>
bool QueueVec<Data>::operator==(const QueueVec& queue) const noexcept {
    return (Vector<Data>::operator==(queue));
}

template<typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& queue) const noexcept {
    return (Vector<Data>::operator!=(queue));
}

template<typename Data>
const Data& QueueVec<Data>::Head() const {
    if (Empty())
        throw std::length_error("Queue is empty!");
    else {
        return Elements[front];
    }
}

template<typename Data>
Data QueueVec<Data>::Head() {
    if (Empty())
        throw std::length_error("Queue is empty!");
    else {
        return Elements[front];
    }
}

template<typename Data>
void QueueVec<Data>::Dequeue() {
    if (Empty())
        throw std::length_error("Queue is empty!");
    else {
        if (queueSize <= (size/4) && size > 5) {// if number of the elements is 1/4 of the size
            //std::cout << "La coda può essere ridotta" << std::endl;
            Reduce();
            front = (front + 1) % size;
        }
        else 
            front = (front + 1) % size;
        queueSize--;
    }
}

template<typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if (Empty())
        throw std::length_error("Queue is empty!");
    else {
        Data tmp = Head();
        Dequeue();
        return tmp;
        queueSize--;
    }
}

template<typename Data>
void QueueVec<Data>::Enqueue(const Data& dat) {
    if (((rear + 1) % size) == front) { // if the next circular index is front the queue need to be expanded
        Expand();
        rear = (rear + 1) % size; // circular increment
        Elements[rear] = dat;
        queueSize++;
    }
    else {
        rear = (rear + 1) % size; // circular increment
        Elements[rear] = dat;
        queueSize++;
    }
}

template<typename Data>
void QueueVec<Data>::Enqueue(Data&& dat) {
    if (((rear + 1) % size) == front) { // if the next circular index is front the queue need to be expanded
        Expand();
        rear = (rear + 1) % size; // circular increment
        Elements[rear] = dat;
        queueSize++;
    }
    else {
        rear = (rear + 1) % size; // circular increment
        Elements[rear] = dat;
        queueSize++;
    }
}

template<typename Data>
void QueueVec<Data>::printQueue() const noexcept {
    std::cout << "Queue: " << std::endl;
    std::cout << "Front <-- ";
    for (int index = front; index <= rear; index++) {
        std::cout << Elements[index];
        std::cout << "<-- ";
    }
    std::cout << "Rear" << std::endl;
    //std::cout << "Front value: " << front << std::endl;
    //std::cout << "Rear value: " << rear << std::endl;
}

template<typename Data>
void QueueVec<Data>::Clear() {
    //Vector<Data>::Clear();
    front = 1;
    rear = 0;
    queueSize = 0;
}

template<typename Data>
void QueueVec<Data>::Expand() noexcept {
    size *= 2;
    Data* temp = new Data[size];
    for (int i = front; i <= rear; i++)
        temp[i] = Elements[i];
    delete[] Elements;
    Elements = temp;
}

template<typename Data>
void QueueVec<Data>::Reduce() noexcept {
    size /= 2;
    Data* temp = new Data[size];
    for (int i = front; i <= rear; i++)
        temp[i] = Elements[i];
    delete[] Elements;
    Elements = temp;
}

template<typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    if (queueSize == 0)
        return true;
    else
        return false;
}

/* ************************************************************************** */

}
