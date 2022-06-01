#include "test.hpp"
#include <iostream>
#include <random>
#include <cmath>

void mytest() {
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Test Studente -----------" << std::endl;
        int selectedImpl = selectImplementation();
        if (selectedImpl == 0) {
            exit = true;
            break;
        }
        int selectedLinearContainer = selectLinearContainer();
        int selectedType = selectType();
        int size = -1;
        std::cout << "Inserire il numero di elementi del container: ";
        std::cin >> size;
        switch (selectedImpl) {
            case 1: {
                // Closed Addressing
                switch (selectedLinearContainer) {
                    case 1: {
                        // Vector
                        if (selectedType == 1) {
                            lasd::Vector<int> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableClsAdr<int> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 2) {
                            lasd::Vector<double> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableClsAdr<double> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 3) {
                            lasd::Vector<std::string> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableClsAdr<std::string> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        break;
                    }
                    case 2: {
                        // List
                        if (selectedType == 1) {
                            lasd::List<int> list;
                            randomListGen(list, size);
                            lasd::HashTableClsAdr<int> hash(list);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 2) {
                            lasd::List<double> list;
                            randomListGen(list, size);
                            lasd::HashTableClsAdr<double> hash(list);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 3) {
                            lasd::List<std::string> list;
                            randomListGen(list, size);
                            lasd::HashTableClsAdr<std::string> hash(list);
                            hashMenu(hash);
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            case 2: {
                // Open Addressing
                switch (selectedLinearContainer) {
                    case 1: {
                        // Vector
                        if (selectedType == 1) {
                            lasd::Vector<int> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableOpnAdr<int> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 2) {
                            lasd::Vector<double> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableOpnAdr<double> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 3) {
                            lasd::Vector<std::string> vector(size);
                            randomVecGen(vector);
                            lasd::HashTableOpnAdr<std::string> hash(vector);
                            hashMenu(hash);
                            break;
                        }
                        break;
                    }
                    case 2: {
                        // List
                        if (selectedType == 1) {
                            lasd::List<int> list;
                            randomListGen(list, size);
                            lasd::HashTableOpnAdr<int> hash(list);
                            hashMenu(hash);
                            break;
                        }
                    else if (selectedType == 2) {
                            lasd::List<double> list;
                            randomListGen(list, size);
                            lasd::HashTableOpnAdr<double> hash(list);
                            hashMenu(hash);
                            break;
                        }
                        else if (selectedType == 3) {
                            lasd::List<std::string> list;
                            randomListGen(list, size);
                            lasd::HashTableOpnAdr<std::string> hash(list);
                            hashMenu(hash);
                            break;
                        }
                        break;
                    }
                }
                break;
            }
        }
    } while(!exit);
}

int selectImplementation() {
    int choice = -1;
    std::cout << "Scegli una implementazione:" << std::endl;
    std::cout << "1) Closed Addressing" << std::endl;
    std::cout << "2) Open Addressing" << std::endl;
    std::cout << "0) Termina" << std::endl;
    std::cin >> choice;
    return choice;
}

int selectLinearContainer() {
    int choice = -1;
    std::cout << "Scegli il tipo di container" << std::endl;
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

template<typename Data>
void hashMenu(lasd::HashTable<Data>& hash) {
    int choice = -1;
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Hash Table Menu ----------" << std::endl;
        std::cout << "1) Visualizza tutti gli elementi" << std::endl;
        std::cout << "2) Controllo di esistenza di un dato" << std::endl;
        std::cout << "3) Calcola fold function" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            hash.Map(&printValue<Data>, nullptr);
            break;
        }
        case 2: {
            Data value;
            std::cout << "Inserisci l'elemento da ricercare: ";
            std::cin >> value;
            if (hash.Exists(value)) 
                std::cout << "Il valore è presente nella hash table" << std::endl;
            else
                std::cout << "Il valore non è presente nella hash table" << std::endl;
            break;
        }
        case 3: {
            compute(hash);
            break;
        }
        case 0: {
            exit = true;
            break;
        }        
        default:
            break;
        }
    } while(!exit);
}

template<typename Data>
void printValue(const Data& value, void* opt) {
    std::cout << value << " ";
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

// Random double generation
template<>
void randomVecGen(lasd::Vector<double>& vec) {
    // Generate random double
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0,100.0);
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
void randomListGen(lasd::List<Data>& list, int size);

template<>
void randomListGen(lasd::List<int>& list, int size) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,100);
    for (ulong index = 0; index < size; index++) {
        list.InsertAtBack(dist(gen));
    }
    std::cout << "Lista popolata" << std::endl;
}

template<>
void randomListGen(lasd::List<double>& list, int size) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1.0,100);
    for (ulong index = 0; index < size; index++) {
        list.InsertAtBack(dist(gen));
    }
    std::cout << "Lista popolata" << std::endl;
}

template<>
void randomListGen(lasd::List<std::string>& list, int size) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string random_string;
    for (ulong index = 0; index < size; index++) {
        random_string = "";
        int length = getRandomInt();
        for (ulong i = 0; i < length; ++i)
            random_string += characters[distribution(generator)];
        list.InsertAtBack(random_string);
    }
    std::cout << "Lista popolata" << std::endl;
}

template<typename Data>
void compute(const lasd::HashTable<Data>& hash);

template<>
void compute(const lasd::HashTable<int>& hash) {
    ulong result = 1;
    int n = -1;
    std::cout << "Inserisci il valore di n, il calcolo varia in base al tipo di struttura dichiarata: ";
    std::cin >> n;
    hash.Fold(&applyFold<int>, &n, &result);
    std::cout << "Risultato: " << result << std::endl;
}

template<>
void compute(const lasd::HashTable<double>& hash) {
    double result = 0;
    int n = -1;
    std::cout << "Inserisci il valore di n, il calcolo varia in base al tipo di struttura dichiarata: ";
    std::cin >> n;
    hash.Fold(&applyFold<double>, &n, &result);
    std::cout << "Risultato: " << result << std::endl;
}

template<>
void compute(const lasd::HashTable<std::string>& hash) {
    std::string result = "";
    int n = -1;
    std::cout << "Inserisci il valore di n, il calcolo varia in base al tipo di struttura dichiarata: ";
    std::cin >> n;
    hash.Fold(&applyFold<std::string>, &n, &result);
    std::cout << "Risultato: " << result << std::endl;
}

template<typename Data>
void applyFold(const Data& value, const void* par, void* acc);

// multiply all the elements
template<>
void applyFold(const int& value, const void* par, void* acc) { //par should be n input from the user (sum all integers less than n)
    if (value < *((int*) par))
        *((ulong*)acc) = *((ulong*)acc) * value;
}

// sum all the elements
template<> 
void applyFold(const double& value, const void* par, void* acc) { //par should be n input from the user (multiply all float greater than n)
    if (value > *((double*) par))
        *((double*)acc) = *((double*)acc) + value;
}

// concat all the elements
template<>
void applyFold(const std::string& value, const void* par, void* acc) { //par should be n input from the user (sum all strings with length less or equal than n)
    if (value.length() <= *((int*) par))
        *((std::string*)acc) = *((std::string*)acc) + value;
}
