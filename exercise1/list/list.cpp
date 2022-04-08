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
        }
    }

    // Copy constructor
    template<typename Data>
    List<Data>::List(const List& list) {
        // Todo

    }

    // Move constructor
    template<typename Data>
    List<Data>::List(List&& list) noexcept {
        // Todo
    }

    // Copy assignment
    template<typename Data>
    List<Data>& List<Data>::operator=(const List&) {
        // Todo
    }

    // Move assignment
    template<typename Data>
    List<Data>& List<Data>::operator=(List&&) noexcept {
        // Todo
    }

    // Comparison operators
    template<typename Data>
    bool List<Data>::operator==(const List& list) const noexcept {
        if (size != list.size)
            return false;
        else {
            ulong index = size;
            while (index < size)
            {
                if ((*this).operator[](index) != list.operator[](index))
                    return false;
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
    void List<Data>::InsertAtFront(Data& dat) {
        Node* n = new Node;
        n->value = dat;
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            n->next = tail;
            head = n;
            tail = n;
        }
        else {
            std::cout << "The list is not empty" << std::endl;
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
            std::cout << "The list is empty!" << std::endl;
            n->next = tail;
            head = n;
            tail = n;
        }
        else {
            std::cout << "The list is not empty" << std::endl;
            n->next = head;
            head = n;
        }
        size++;
    }

    template<typename Data>
    void List<Data>::RemoveFromFront() {
        if (size != 0) {
            // Todo
        }
        else
            throw std::length_error("The list is empty!");
    }

    template<typename Data>
    Data List<Data>::FrontNRemove() {
        if (size != 0) {
            // Todo
        }
        else
            throw std::length_error("The list is empty!");
    }

    // Copy of the value
    template<typename Data>
    void List<Data>::InsertAtBack(Data& dat) {
        Node* n = new Node;
        n->value = dat;
        if (head == nullptr) {
            std::cout << "The list is empty!" << std::endl;
            n->next = tail;
            head = n;
            tail = n;
        }
        else {
            std::cout << "The list is not empty" << std::endl;
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
            std::cout << "The list is empty!" << std::endl;
            n->next = tail;
            head = n;
            tail = n;
        }
        else {
            std::cout << "The list is not empty" << std::endl;
            Node* temp = new Node;
            temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = n;
            n->next = nullptr;
            tail = n;
        }
    }

    template<typename Data>
    void List<Data>::Clear() {
        // Todo
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
        Node* curr = head;
        std::cout << "Head --> ";
        while(curr != nullptr) {
            std::cout << curr->value;
            std::cout << "--> ";
            curr = curr->next;
        }
        std::cout << "NULL" << std::endl;
    }

/* ************************************************************************** */

}
