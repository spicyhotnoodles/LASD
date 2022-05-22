#include "test.hpp"
#include <iostream>
#include <random>
#include <cmath>

void mytest() {
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Test Studente -----------" << std::endl;
        int selectedLinearContainer = selectLinearContainer();
        if (selectedLinearContainer == 0) {
            exit = true;
            break;
        }
        int selectedType = selectType();
        int size = -1;
        std::cout << "Inserire il numero di nodi per la costruzione dell'albero: ";
        std::cin >> size;
        switch (selectedLinearContainer) {
            case 1: {
                    if (selectedType == 1) {
                        lasd::Vector<int> vector(size);
                        randomVecGen(vector);
                        lasd::BST<int> bst(vector);
                        bstMenu(bst);
                    }
                    else if (selectedType == 2) {
                        lasd::Vector<float> vector(size);
                        randomVecGen(vector);
                        lasd::BST<float> bst(vector);
                        bstMenu(bst);
                    }
                    else if (selectedType == 3) {
                        lasd::Vector<std::string> vector(size);
                        randomVecGen(vector);
                        lasd::BST<std::string> bst(vector);
                        bstMenu(bst);
                    }
                    break;
            }
            case 2: {
                    if (selectedType == 1) {
                        lasd::List<int> list;
                        randomListGen(list, size);
                        lasd::BST<int> bst(list);
                        bstMenu(bst);
                    }
                    else if (selectedType == 2) {
                        lasd::List<float> list;
                        randomListGen(list, size);
                        lasd::BST<float> bst(list);
                        bstMenu(bst);
                    }
                    else if (selectedType == 3) {
                        lasd::List<std::string> list;
                        randomListGen(list, size);
                        lasd::BST<std::string> bst(list);
                        bstMenu(bst);
                    }
                    break;
            }
            default: {
                std::cout << "Scelta non valida" << std::endl;
                break;
            }
        }
    } while(!exit);
}

int selectLinearContainer() {
    int choice = -1;
    std::cout << "Scegli il tipo di container" << std::endl;
    std::cout << "1) Vettore" << std::endl;
    std::cout << "2) Lista" << std::endl;
    std::cout << "0) Esci" << std::endl;
    std::cin >> choice;
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
void bstMenu(lasd::BinaryTree<Data>& bst) {
    int choice = -1;
    bool exit = false;
    std::string aString = "";
    do {
        std::cout << std::endl;
        std::cout << "---------- Binary Search Tree Menu ----------" << std::endl;
        std::cout << "\nRandom generated tree:\n" << std::endl;
        bst.printTree(aString, &(bst.Root()), false);
        std::cout << "\n Leggenda: " << std::endl;
        std::cout << "1) Il simbolo '├──' corrisponde al figlio sinistro" << std::endl;
        std::cout << "\n2) Il simbolo '└──' corrisponde al figlio destro" << std::endl;
        std::cout << "\nNB: Il figlio sinistro viene stampato prima del figlio destro" << std::endl;    
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "1) Effettua visita sull'albero" << std::endl;
        std::cout << "2) Controllo di esistenza di un dato" << std::endl;
        std::cout << "3) Calcola fold function" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            treeTraversal(bst);
            break;
        }
        case 2: {
            Data value;
            std::cout << "Inserisci l'elemento da ricercare: ";
            std::cin >> value;
            if (bst.Exists(value)) 
                std::cout << "Il valore è presente nell'albero" << std::endl;
            else
                std::cout << "Il valore non è presente nell'albero" << std::endl;
            break;
        }
        case 3: {
            int n = -1;
            int type = -1;
            std::cout << "Inserisci il valore di n, il calcolo varia in base al tipo di struttura dichiarata: ";
            std::cin >> n;
            struct lasd::BinaryTree<Data>::Node* node = &(bst.Root());
            Data value = node->Element();
            type = checkType(value);
            if (type == 1) {
                int result = 1;
                bst.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
            else if (type == 2) {
                float result = 0.0;
                bst.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
            else if (type == 3) {
                std::string result = "";
                bst.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
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
void printNode(const Data& value, void* opt) {
    std::cout << value << " ";
}

template<typename Data>
void treeTraversal(lasd::BinaryTree<Data>& binaryTree) {
    int traversal = -1;
    std::cout << "Scegliere la visita da effettuare" << std::endl;
    std::cout << "1) Preorder" << std::endl;
    std::cout << "2) Inorder" << std::endl;
    std::cout << "3) Postorder" << std::endl;
    std::cout << "4) Levelorder (Breadth)" << std::endl;
    std::cin >> traversal;
    int option = -1;
    std::cout << "Scegliere il metodo di visita per l'albero:" << std::endl;
    std::cout << "1) Utilizzando la funzione ricorsiva" << std::endl;
    std::cout << "2) Utilizzando l'iteratore" << std::endl;
    std::cin >> option;
    switch (traversal)
    {
    case 1: {
        if (option == 1) {
            std::cout << "Preorder traversal using recursion: " << std::endl;
            binaryTree.MapPreOrder(&printNode<Data>, nullptr);
            break;
        }
        else if (option == 2) {
            lasd::BTPreOrderIterator<Data> it(binaryTree);
            std::cout << "Preorder traversal using iterator: " << std::endl;
            while (!it.Terminated()) {
                std::cout << it.operator*() << " ";
                it.operator++();
            }
        break;
        }
    }
    case 2: {
        if (option == 1) {
            std::cout << "Inorder traversal using recursion: " << std::endl;
            binaryTree.MapInOrder(&printNode<Data>, nullptr);
            break;
        }
        else if (option == 2) {
            lasd::BTInOrderIterator<Data> it(binaryTree);
            std::cout << "Inorder traversal using iterator: " << std::endl;
            while (!it.Terminated()) {
                std::cout << it.operator*() << " ";
                it.operator++();
            }
            break;
        }
    }
    case 3: {
        if (option == 1) {
            std::cout << "Postorder traversal using recursion: " << std::endl;
            binaryTree.MapPostOrder(&printNode<Data>, nullptr);
            break;
        }
        else if (option == 2) {
            lasd::BTPostOrderIterator<Data> it(binaryTree);
            std::cout << "Postorder traversal using iterator: " << std::endl;
            while (!it.Terminated()) {
                std::cout << it.operator*() << " ";
                it.operator++();
            }
            break;
        }
    }
    case 4: {
        if (option == 1) {
            std::cout << "Levelorder (Breadth) traversal using recursion: " << std::endl;
            binaryTree.MapBreadth(&printNode<Data>, nullptr);
            break;
        }
        else if (option == 2) {
            lasd::BTBreadthIterator<Data> it(binaryTree);
            std::cout << "Levelorder (Breadth) traversal using iterator: " << std::endl;
            while (!it.Terminated()) {
                std::cout << it.operator*() << " ";
                it.operator++();
            }
            break;
        }
    }
    default:
        break;
    }
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
void randomListGen(lasd::List<float>& list, int size) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(1.0,100);
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
void applyFold(const Data& value, const void* par, void* acc);

// multiply all the elements
template<>
void applyFold(const int& value, const void* par, void* acc) { //par should be n input from the user (sum all integers less than n)
    if (value < *((int*) par))
        *((int*)acc) = *((int*)acc) * value;
    //*acc = *acc + value;
}

// sum all the elements
template<> 
void applyFold(const float& value, const void* par, void* acc) { //par should be n input from the user (multiply all float greater than n)
    if (value > *((float*) par))
        *((float*)acc) = *((float*)acc) + value;
}

// concat all the elements
template<>
void applyFold(const std::string& value, const void* par, void* acc) { //par should be n input from the user (sum all strings with length less or equal than n)
    if (value.length() <= *((int*) par))
        *((std::string*)acc) = *((std::string*)acc) + value;
}