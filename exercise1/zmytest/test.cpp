#include "test.hpp"
#include <iostream>
#include <random>
#include <cmath> // to evaluate n^2
#include <cctype> // to use toupper
#include <string>
#include <algorithm>

void mytest() {
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "--------- Test Studente ----------" << std::endl;
        int selectedStruct = selectStruct();
        if (selectedStruct == 0)
            exit = true;
        else {
            int selectedType = selectType();
            int selectedSize = selectSize();
            if (selectedStruct == 1) {
                if (selectedType == 1) {
                    if (selectedSize != 0) {
                        lasd::Vector<int> vec(selectedSize); // Specific constructor
                        randomVecGen(vec);
                        vectorMenu(vec);
                    }
                    else {
                        lasd::Vector<int> vec;  // Default constructor
                        vectorMenu(vec);
                    }
                }
                else if (selectedType == 2) {
                    if (selectedSize != 0) {
                        lasd::Vector<float> vec(selectedSize);
                        randomVecGen(vec);
                        vectorMenu(vec);
                    }
                    else {
                        lasd::Vector<float> vec;
                        vectorMenu(vec);
                    }
                }
                else if (selectedType == 3) {
                    if (selectedSize != 0) {
                        lasd::Vector<std::string> vec(selectedSize);
                        randomVecGen(vec);
                        vectorMenu(vec);
                    }
                    else {
                        lasd::Vector<std::string> vec;
                        vectorMenu(vec);
                    }
                }
            }
            else if (selectedStruct == 2) {
                lasd::List<int> list;
                list.InsertAtFront(5);
                int value = 10;
                list.InsertAtFront(value);
                lasd::List<int> anotherList;
                anotherList.InsertAtFront(5);
                if (list.operator!=(anotherList))
                    std::cout << "Le liste sono diverse" << std::endl;
                else
                    std::cout << "Le liste sono uguali" << std::endl;
                list.InsertAtBack(7);
                //list.InsertAtFront(8);
                list.printList();
                break;
            }
        }
    } while(!exit);
}

int selectStruct() {
    int choice = -1;
    std::cout << "Scegli la struttura dati" << std::endl;
    std::cout << "1) Vettore" << std::endl;
    std::cout << "2) Lista" << std::endl;
    std::cout << "0) Per terminare" << std::endl;
    std::cin >> choice;
    std::cout << choice << std::endl;
    return choice;
}

int selectType() {
    int choice = -1;
    std::cout << "Scegli il tipo per definire la struttura" << std::endl;
    std::cout << "1) Int" << std::endl;
    std::cout << "2) Float" << std::endl;
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
    int choice = -1;
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Vector Menu ----------" << std::endl;
        std::cout << "1) Stampa vettore" << std::endl;
        std::cout << "2) Stampa elemento" << std::endl;
        std::cout << "3) Ripopola vettore" << std::endl;
        std::cout << "4) Ricerca elemento" << std::endl;
        std::cout << "5) Ridimensiona vettore" << std::endl;
        std::cout << "6) Applica fold function" << std::endl;
        std::cout << "7) Applica map function (2n per gli interi, n^2 per i float, uppercase per le stringhe)" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
            case 1: {
                if (vec.Size() != 0)
                    vec.MapPreOrder(&printValue<Data>, nullptr); // why <Data>?
                else
                    std::cout << "Il vettore è vuoto.\nSuggerimento: estendere la dimensione del vettore e ripopolarlo." << std::endl;
                break;
            }
            case 2: {
                if (vec.Size() != 0)
                    printIndex(vec);
                else
                    std::cout << "Il vettore è vuoto.\nSuggerimento: estendere la dimensione del vettore e ripopolarlo." << std::endl;
                break;
            }
            case 3: {
                int copySize = vec.Size();
                vec.Clear(); // At the end of the process, vector's size will be 0, so Resize is called.
                vec.Resize(copySize);
                randomVecGen(vec);
                break;
            }
            case 4: {
                Data value;
                std::cout << "Inserire l'elemento da ricercare: ";
                std::cin >> value;
                if(vec.Exists(value))
                    std::cout << "L'elemento è presente nel vettore" << std::endl;
                else
                    std::cout << "L'elemento non è presente nel vettore" << std::endl;
                break;
            }
            case 5: {
                int newsize = -1;
                std::cout << "Inserisci la nuova dimensione del vettore *NOTA se la dimensione risulta inferiore a quella attuale (" << vec.Size() << ") alcuni elementi andranno persi!*: " << std::endl;
                std::cin >> newsize;
                vec.Resize(newsize);
                std::cout << "Vettore ridimensionato, eseguire una stampa per visualizzare i dettagli" << std::endl; 
                break;
            }
            case 6: {
                int n = -1;
                int type = -1;
                std::cout << "Inserisci il valore di n, il calcolo varia in base al tipo di struttura dichiarata: ";
                std::cin >> n;
                type = checkType(vec.operator[](0));
                if (type == 1) {
                    int result = 0;
                    vec.FoldPreOrder(&applyFold<Data>, &n, &result);
                    std::cout << "Risultato: " << result << std::endl;
                }
                else if (type == 2) {
                    float result = 1.0;
                    vec.FoldPreOrder(&applyFold<Data>, &n, &result);
                    std::cout << "Risultato: " << result << std::endl;
                }
                else if (type == 3) {
                    std::string result = "";
                    vec.FoldPreOrder(&applyFold<Data>, &n, &result);
                    std::cout << "Risultato: " << result << std::endl;
                } 
                break;
            }
            case 7: {
                vec.MapPreOrder(&applyFunction<Data>, nullptr);
                std::cout << "Funzione applicata, i valori sono stati modificati. Effettua una stampa per visualizzare i dettagli" << std::endl;
                break;
            }
            case 0:
                exit = true;
                break;
            default: {
                std::cout << "Scelta non valida, riprovare!" << std::endl;
                break;
            }
        }
    } while(!exit);
}


template<typename Data>
void randomVecGen(lasd::Vector<Data>& vec);

// Random integer generation
template<>
void randomVecGen(lasd::Vector<int>& vec) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,100);
    for (ulong index = 0; index < vec.Size(); index++) {
        vec.operator[](index) = dist(gen);
    }
    std::cout << "Array popolato" << std::endl;
}

// Random float generation
template<>
void randomVecGen(lasd::Vector<float>& vec) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(1.0,100.0);
    for (ulong index = 0; index < vec.Size(); index++) {
        vec.operator[](index) = dist(gen);
    }
    std::cout << "Array popolato" << std::endl;
}

int getRandomInt() {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,25);
    return dist(gen);
}

// Random string generation
template<>
void randomVecGen(lasd::Vector<std::string>& vec) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string random_string;
    for (ulong index = 0; index < vec.Size(); index++) {
        random_string = "";
        int length = getRandomInt();
        for (ulong i = 0; i < length; ++i)
        {
            random_string += characters[distribution(generator)];
        }
        vec.operator[](index) = random_string;
        std::cout << "Array popolato" << std::endl;
    }
}

template<typename Data>
int checkType(const Data& value) {
    int i = 0;
    float f = 1.0;
    std::string s = "";
    int type = -1;
    if (typeid(value) == typeid(i))
        type = 1;
    else if (typeid(value) == typeid(f))
        type = 2;
    else if (typeid(value) == typeid(s))
        type = 3;
    return type;
}

template<typename Data>
void printValue(const Data& value, void* opt) {
    std::cout << value << " ";
}

template<typename Data>
void printIndex(const lasd::Vector<Data>& vec) {
    int choice = -1;
    std::cout << "Selezionare l'elemento da visualizzare:" << std::endl;
    std::cout << "1) Front" << std::endl;
    std::cout << "2) Back" << std::endl;
    std::cout << "3) Index" << std::endl;
    std::cin >> choice;
    if(choice == 1)
        std::cout << "Front: " << vec.Front() << std::endl;
    else if (choice == 2)
        std::cout << "Back: " << vec.Back() << std::endl;
    else if (choice == 3) {
        int index = -1;
        std::cout << "Inserisci l'indice dell'elemento da visualizzare (da 0 a " << vec.Size() - 1 << "): ";
        std::cin >> index;
        if (index < 0 || index > vec.Size() - 1)
            throw std::out_of_range("Out of vector range!");
        else
            std::cout << vec.operator[](index) << std::endl;
    }
}

template<typename Data>
void applyFunction(Data& value, void* opt);
// multiply by 2 function
template<>
void applyFunction(int& value, void* opt) {
    value *= 2;
}
// squared function
template<>
void applyFunction(float& value, void* opt) {
    value = pow(value, 2);
}
// uppercase function
template<>
void applyFunction(std::string& value, void* opt) {
    for (ulong index = 0; index < value.size(); index++) {
        value[index] = toupper(value[index]);
    }
}

template<typename Data>
void applyFold(const Data& value, const void* par, void* acc);
// sum all the elements
template<>
void applyFold(const int& value, const void* par, void* acc) { //par should be n input from the user (sum all integers less than n)
    if (value < *((int*) par))
        *((int*)acc) = *((int*)acc) + value;
    //*acc = *acc + value;
}
// multiply all the elements
template<> 
void applyFold(const float& value, const void* par, void* acc) { //par should be n input from the user (multiply all float greater than n)
    if (value > *((float*) par))
        *((float*)acc) = *((float*)acc) * value;
}
// concat all the elements
template<>
void applyFold(const std::string& value, const void* par, void* acc) { //par should be n input from the user (sum all strings with length less or equal than n)
    if (value.length() <= *((int*) par))
        *((std::string*)acc) = *((std::string*)acc) + value;
}