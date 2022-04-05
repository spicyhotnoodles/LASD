#include "test.hpp"
#include <iostream>
#include <random>

/* void mytest() {
    int choice = -1;
    std::cout << "Scegli la struttura dati" << std::endl;
    std::cout << "1) Vettore" << std::endl;
    std::cout << "2) Lista" << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1: {
        int selectedType = selectType();
        int size = -1;
        std::cout << "Inserisci la dimensione (l'array verrà popolato randomicamente): ";
        std::cin >> size;
        switch (selectedType)
        {
        case 1: {
            if (size != 0) {
                lasd::Vector<int> vec(size);
                vectorInt(vec);
            }
            else
                lasd::Vector<int> vec;   
            break;
        }
        case 2: {
            if (size != 0)
                lasd::Vector<double> vec(size);
            else
                lasd::Vector<double> vec;
        }
        case 3: {
            if (size != 0)
                lasd::Vector<std::string> vec(size);
            else
                lasd::Vector<std::string> vec;
        }
        default:
            break;
        }                     
        vectorTest();
        break;
    }
    case 2:
        listTest();
        break;
    default:
        std::cout << "Scelta non valida!" << std::endl;
        break;
    }
}

template<typename Data>
void vectorTest(lasd::Vector<Data>& vec) {
    int input = -1;
    std::cout << "---------- Vettore ----------" << std::endl;
    std::cout << "1) Stampa vettore" << std::endl;
    std::cout << "2) Stampa elemento" << std::endl;
    std::cout << "3) Ripopola vettore" << std::endl;
    std::cout << "4) Ricerca elemento" << std::endl;
    std::cout << "5) Ridimensiona vettore" << std::endl;
    std::cout << "6) Applica fold function" << std::endl;

    switch (input)
    {
    case 1:
        vec.MapPreOrder(&printValue<Data>, nullptr);
        break;
    case 2:
        if (vec.size != 0)
            printValueAt(vec);
        else
            std::cout << "Il vettore è vuoto" << std::endl;
        break;
    case 3:
        // Ripulisci vettore e rigenere casualmente i valori dello stesso tipo definito dall'utente.
        break;
    case 4:
        Data element;
        std::cout << "Inserisci l'elemento da ricercare: ";
        std::cin >> element;
        if (vec.Exists(element))
            std::cout << "L'elemento è presente nel vettore" << std::endl;
        else
            std::cout << "L'elemento non è presente nel vettore" << std::endl;
        
    default:
        break;
    }
    std::cout << std::endl;
}

void vectorInt(lasd::Vector<int>& vec) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,100);
    for (ulong index = 0; index < vec.Size(); index++) {
        vec.operator[](index) = dist(gen);
    }
    std::cout << "Array popolato" << std::endl;
}

int selectType() {
    int input = 0;
    std::cout << "Scegli il tipo di dati" << std::endl;
    std::cout << "1) Int" << std::endl;
    std::cout << "2) Double" << std::endl;
    std::cout << "3) String" << std::endl;
    std::cin >> input;   
    return input;
}

template<typename Data>
void printValue(Data& value, void*) {
    std::cout << value << std::endl;
}

template<typename Data>
void printValueAt(lasd::Vector<Data>& vec) {
    std::cout << "Seleziona quale elemento vuoi mostrare:" << std::endl;
    std::cout << "1) Front element" << std::endl;
    std::cout << "2) Back element" << std::endl;
    std::cout << "3) Index element" << std::endl;
    int input = -1;
    switch (input)
    {
        case 1:
            std::cout << vec.Front() << std::endl;
            break;
        case 2:
            std::cout << vec.Back() << std::endl;
        case 3: {
            int index = -1;
            std::cout << "Inserisci l'indice: ";
            std::cin >> index;
            std::cout << vec.operator[](index) << std::endl;
        } 
        default:
            std::cout << "Scelta non valida!" << std::endl;
            break;
    }
}

void listTest() {

} */

void mytest() {
    std::cout << "--------- Test Studente ----------" << std::endl;
    int selectedStruct = selectStruct();
    int selectedType = selectType();
    int selectedSize = selectSize();
    if (selectedStruct == 1) {
        if (selectedType == 1) {
            if (selectedSize != 0) {
                lasd::Vector<int> vec(selectedSize); // Specific constructor
                vectorMenu(vec);
            }
            else
                lasd::Vector<int> vec;  // Default constructor
        }
        else if (selectedType == 2) {
            if (selectedSize != 0)
                lasd::Vector<double> vec(selectedSize);
            else
                lasd::Vector<double> vec;
        }
        else if (selectedType == 3) {
            if (selectedSize != 0)
                lasd::Vector<std::string> vec(selectedSize);
            else
                lasd::Vector<std::string> vec;
        }
    }
}

int selectStruct() {
    int choice = -1;
    std::cout << "Scegli la struttura dati" << std::endl;
    std::cout << "1) Vettore" << std::endl;
    std::cout << "2) Lista" << std::endl;
    std::cin >> choice;
    return choice;
}

int selectType() {
    int choice = -1;
    std::cout << "Scegli il tipo per definire la struttura" << std::endl;
    std::cout << "1) Int" << std::endl;
    std::cout << "2) Double" << std::endl;
    std::cout << "3) String" << std::endl;
    std::cin >> choice;
    return choice;
}

int selectSize() {
    int size = 0;
    std::cout << "Inserisci la dimensione della struttura: ";
    std::cin >> size;
    return size;
}

template <typename Data>
void vectorMenu(lasd::Vector<Data>& vec) {
    std::cout << "---------- Vector Menu ----------" << std::endl;
    std::cout << "1) Stampa vettore" << std::endl;
    std::cout << "2) Stampa elemento" << std::endl;
    std::cout << "3) Ripopola vettore" << std::endl;
    std::cout << "4) Ricerca elemento" << std::endl;
    std::cout << "5) Ridimensiona vettore" << std::endl;
    std::cout << "6) Applica fold function" << std::endl;
}