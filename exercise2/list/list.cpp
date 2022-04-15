#include <iostream>
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

    // Specific constructor 
    template<typename Data>
    List<Data>::List(const LinearContainer<Data>& lc) { // A list obtained from a LinearContainer
        unsigned long index = 0;
        while (index < lc.Size()) {
            InsertAtBack(lc[index]);
            index++;
        }
    }

    // Copy constructor
    template<typename Data>
    List<Data>::List(const List& list) {
        Node* tmp = list.head;
        while (tmp != nullptr) {
            InsertAtBack(tmp->value);
            tmp = tmp->next;
        }
    }

    // Move constructor
    template<typename Data>
    List<Data>::List(List&& list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);        
    }

    // Copy assignment
    template<typename Data>
    List<Data>& List<Data>::operator=(const List& list) {
        List<Data>* tempList = new List<Data>(list);
        std::swap(*tempList, *this);
        delete tempList;
        return *this;
    }

    // Move assignment
    template<typename Data>
    List<Data>& List<Data>::operator=(List&& list) noexcept {
        std::swap(head, list.head);
        std::swap(tail, list.tail);
        std::swap(size, list.size);
        return *this;
    }

    // Comparison operators
    template<typename Data>
    bool List<Data>::operator==(const List& list) const noexcept {
        if (size != list.size)
            return false;
        else {
            Node* tmp1 = head;
            Node* tmp2 = list.head;
            while (tmp1 != nullptr && tmp2 != nullptr) {
                if (tmp1->value != tmp2->value)
                    return false;
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            return true;
        }
    }

    template<typename Data>
    bool List<Data>::operator!=(const List& list) const noexcept {
        if (size != list.size)
            return false;
        else
            return !(*this == list);
    }

    // Copy of the value
    template<typename Data>
    void List<Data>::InsertAtFront(const Data& dat) {
        Node* n = new Node;
        n->value = dat;
        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else {
            n->next = head;
            head = n;
        }
        size++;
    }

    // Move of the value
    template<typename Data>
    void List<Data>::InsertAtFront(Data&& dat) {
        Node* n = new Node;
        n->value = std::move(dat);
        if (head == nullptr) { // There are no elements
            head = n;
            tail = n;
        }
        else {
            n->next = head;
            head = n;
        }
        size++;
    }

    template<typename Data>
    void List<Data>::RemoveFromFront() {
        if (size != 0) {
            Node* temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }
        else
            throw std::length_error("The list is empty!");
    }

    template<typename Data>
    Data List<Data>::FrontNRemove() {
        if (size != 0) {
            Data value = head->value;
            RemoveFromFront();
            return value;
        }
        else
            throw std::length_error("The list is empty!");
    }

    // Copy of the value
    template<typename Data>
    void List<Data>::InsertAtBack(const Data& dat) {
        Node* n = new Node;
        n->value = dat;
        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            n->next = nullptr;
            tail = n;
        }
        size++;
    }

    // Move of the value
    template<typename Data>
    void List<Data>::InsertAtBack(Data&& dat) {
        Node* n = new Node;
        n->value = std::move(dat);
        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else {
            tail->next = n;
            n->next = nullptr;
            tail = n;
        }
        size++;
    }

    template<typename Data>
    void List<Data>::Clear() {
        if (size > 0) {
            Node* curr = head;
            Node* tmp = nullptr;
            while (curr != nullptr) {
                tmp = curr;
                curr = curr->next;
                delete tmp;
            }
            size = 0;
        }
        head = nullptr;
        tail = nullptr;
    }

    template<typename Data>
    Data& List<Data>::Front() const {
        if (size != 0) {
            return head->value;
        }
        else {
            throw std::length_error("The list is empty!");
        }
    }

    template<typename Data>
    Data& List<Data>::Back() const {
        if (size != 0)
            return tail->value;
        else
            throw std::length_error("The list is empty!");
    }

    template<typename Data>
    Data& List<Data>::operator[](ulong index) const {
        if (index < size) {
            unsigned long i = 0;
            Node* curr = head;
            while (i < index) {
                curr = curr->next;
                i++;
            }
            return curr->value;
        }
        else
            throw std::out_of_range("Out of range!");
    }

    template<typename Data>
    void List<Data>::printList() const {
        if (size != 0) {
            Node* curr = head;
            std::cout << "Head --> ";
            while(curr != nullptr) {
                std::cout << curr->value;
                std::cout << "--> ";
                curr = curr->next;
            }
            std::cout << "NULL" << std::endl;
        }
        else {
            throw std::length_error("List is empty!");
        }
    }

    template<typename Data>
    void List<Data>::Map(MapFunctor fun, void* par) {
        MapPreOrder(fun, par, head);
    }

    template<typename Data>
    void List<Data>::MapPreOrder(MapFunctor fun, void* par) {
        MapPreOrder(fun, par, head);
    }

    template<typename Data>
    void List<Data>::MapPostOrder(MapFunctor fun, void* par) {
        MapPostOrder(fun, par, head);
    }

    template<typename Data>
    void List<Data>::Fold(FoldFunctor fun, const void* par, void* acc) const {
        FoldPreOrder(fun, par, acc);
    }

    template<typename Data>
    void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const {
        FoldPreOrder(fun, par, acc, head);
    }

    template<typename Data>
    void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const {
        FoldPostOrder(fun, par, acc, head);
    }

    // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

    template<typename Data>
    void List<Data>::MapPreOrder(MapFunctor fun, void* par, Node* curr) {
        for (; curr != nullptr; curr = curr->next)
            fun(curr->value, par);
    }

    template<typename Data>
    void List<Data>::MapPostOrder(MapFunctor fun, void* par, Node* curr) {
        if (curr != nullptr) {
            MapPostOrder(fun, par, curr->next);
            fun(curr->value, par);
        }
    }

    // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

    template<typename Data>
    void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const {
        for(; curr != nullptr; curr = curr->next) {
            fun(curr->value, par, acc);
        }
    }

    template<typename Data>
    void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const {
        if (curr != nullptr) {
            FoldPostOrder(fun, par, acc, curr->next);
            fun(curr->value, par, acc);
        }
    }

}
