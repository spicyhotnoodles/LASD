
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stack) {
    size = stack.size;
    top = stack.top;
    Elements = new Data[stack.size];
    for (int index = 0; index < size; index++)
        Elements[index] = stack[index];
}

/* template<typename Data>
  StackVec<Data>::StackVec(const LinearContainer<Data> & copyContainer){
        DataVector = new Data[copyContainer.Size()];
        size = copyContainer.Size();
        for(ulong i = 0;i<size; i++){
            Push(copyContainer[i]);
        }
    } */

// Move constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stack) noexcept {
    Elements = new Data[stack.size];
    std::swap(Elements, stack.Elements);
    std::swap(size, stack.size);
    std::swap(top, stack.top);
}

// Copy assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& stack) {
    StackVec<Data>* tmpstack = new StackVec<Data>(stack); // Copy constructor
    std::swap(*tmpstack, *this);
    delete tmpstack;
    return *this;
}

// Move assignement
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& stack) noexcept {
    std::swap(Elements, stack.Elements);
    std::swap(size, stack.size);
    std::swap(top, stack.top);
    return *this;
}

// Specific member functions (inherited from Stack)

// Top const version
template<typename Data>
const Data& StackVec<Data>::Top() const {
    if (top == 0)
        throw std::out_of_range("Stack is empty");
    else
        return Elements[top-1];
}

// Top
template<typename Data>
Data StackVec<Data>::Top() {
    if (top == 0)
        throw std::length_error("Stack is empty!");
    else 
        return Elements[top-1];
}

template<typename Data>
void StackVec<Data>::Pop() {
    if (top <= (size/4)) {
        std::cout << "Lo stack può essere ridotto" << std::endl;
        Reduce();
        top--;
    }
    else
        top--;
}

template<typename Data>
Data StackVec<Data>::TopNPop() {
    if (top == 0)
        throw std::length_error("Stack is empty!");
    else {
        Data temp = Top();
        Pop();
        return temp;
    }
}

template<typename Data>
void StackVec<Data>::Push(const Data& dat) {
    if (top >= size) {
        std::cout << "Lo stack deve essere espanso" << std::endl;
        Expand();
        Elements[top] = dat;
        top++;
    }
    else {
        Elements[top] = dat;
        top++;
    }
}

template<typename Data>
void StackVec<Data>::Push(Data&& dat) {
    if (top >= size) {
        Expand();
        Elements[top] = dat;
        top++;        
    }
    else {
        Elements[top] = dat;
        top++;
    }
}

template<typename Data>
void StackVec<Data>::Expand() noexcept {
    size *= 2;
    Data* temp = new Data[size];
    for (int i = 0; i < top; i++)
        temp[i] = Elements[i];
    delete[] Elements;
    Elements = temp;
}

template<typename Data>
void StackVec<Data>::Reduce() noexcept {
    size /= 2;
    Data* temp = new Data[size];
    for (int i = 0; i < top; i++)
        temp[i] = Elements[i];
    delete[] Elements;
    Elements = temp;
}

template<typename Data>
void StackVec<Data>::Clear() {
    lasd::Vector<Data>::Clear();
    top = 0;
}

template<typename Data>
bool StackVec<Data>::Empty() const noexcept {
    if (top == 0)
        return true;
    else
        return false;
}

// DA RIMUOVERE!!!
template<typename Data>
void StackVec<Data>::printStack() const noexcept { 
    std::cout << "Stack: " << std::endl;
    for (int index = top - 1; index >= 0; index--)
        std::cout << Elements[index] << std::endl;
    std::cout << "Top value: " << top << std::endl;
}

}
