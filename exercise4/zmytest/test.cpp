#include "test.hpp"
#include <iostream>
#include <random>
#include <cmath>

void mytest() {
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Test Studente -----------" << std::endl;
        /* lasd::Vector<std::string> vector(29);
        vector.operator[](0) = "A";
        vector.operator[](1) = "B";
        vector.operator[](2) = "L";
        vector.operator[](3) = "D";
        vector.operator[](4) = "C";
        vector.operator[](5) = "H";
        vector.operator[](6) = "I";
        vector.operator[](7) = "[...]";
        vector.operator[](8) = "M";
        vector.operator[](9) = "E";
        vector.operator[](10) = "F";
        vector.operator[](11) = "J";
        vector.operator[](12) = "[...]";
        vector.operator[](13) = "K";
        vector.operator[](14) = "[...]";
        vector.operator[](15) = "[...]";
        vector.operator[](16) = "[...]";
        vector.operator[](17) = "[...]";
        vector.operator[](18) = "[...]";
        vector.operator[](19) = "[...]";
        vector.operator[](20) = "[...]";
        vector.operator[](21) = "[...]";
        vector.operator[](22) = "G";
        vector.operator[](23) = "[...]";
        vector.operator[](24) = "[...]";
        vector.operator[](25) = "[...]";
        vector.operator[](26) = "[...]";
        vector.operator[](27) = "[...]";
        vector.operator[](28) = "[...]"; */
        int selectedImple = selectImple();
        if (selectedImple == 0) {
            exit = true;
            break;
        }
        int selectedLinearContainer = selectLinearContainer();
        int selectedType = selectType();
        int size = -1;
        std::cout << "Inserire il numero di nodi per la costruzione dell'albero: ";
        std::cin >> size;
        switch (selectedImple) {
            case 1: {
                if (selectedLinearContainer == 1) {
                    if (selectedType == 1) {
                        lasd::Vector<int> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeVec<int> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 2) {
                        lasd::Vector<float> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeVec<float> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 3) {
                        lasd::Vector<std::string> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeVec<std::string> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    break;
                }
                else {
                    if (selectedType == 1) {
                        lasd::List<int> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeVec<int> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 2) {
                        lasd::List<float> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeVec<float> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 3) {
                        lasd::List<std::string> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeVec<std::string> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    break;
                }
            }
            case 2: {
                if (selectedLinearContainer == 1) {
                    if (selectedType == 1) {
                        lasd::Vector<int> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeLnk<int> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 2) {
                        lasd::Vector<float> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeLnk<float> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 3) {
                        lasd::Vector<std::string> vector(size);
                        randomVecGen(vector);
                        lasd::BinaryTreeLnk<std::string> binaryTree(vector);
                        binaryTreeMenu(binaryTree);
                    }
                    break;
                }
                else {
                    if (selectedType == 1) {
                        lasd::List<int> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeLnk<int> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 2) {
                        lasd::List<float> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeLnk<float> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    else if (selectedType == 3) {
                        lasd::List<std::string> list;
                        randomListGen(list, size);
                        lasd::BinaryTreeLnk<std::string> binaryTree(list);
                        binaryTreeMenu(binaryTree);
                    }
                    break;
                }
            }
            default: {
                std::cout << "Scelta non valida" << std::endl;
                break;
            }
        }
    } while(!exit);
}

int selectImple() {
    int choice = -1;
    std::cout << "Scegli l'implementazione" << std::endl;
    std::cout << "1) BinaryTreeVec" << std::endl;
    std::cout << "2) BinaryTreeLnk" << std::endl;
    std::cout << "0) Esci" << std::endl;
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
void binaryTreeMenu(lasd::BinaryTree<Data>& binaryTree) {
    int choice = -1;
    bool exit = false;
    std::string aString = "";
    do {
        std::cout << std::endl;
        std::cout << "---------- Binary Tree Menu ----------" << std::endl;
        std::cout << "\nRandom generated tree:\n" << std::endl;
        binaryTree.printTree(aString, &(binaryTree.Root()), false);
        std::cout << "\nNB: Il figlio sinistro viene stampato prima del figlio destro" << std::endl;    
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "1) Effettua visita sull'albero" << std::endl;
        std::cout << "2) Controllo di esistenza di un dato" << std::endl;
        std::cout << "3) Calcola fold function" << std::endl;
        std::cout << "4) Applica map function (3n per gli interi, n^3 per i float, concatenzaione in testa di una stringa str)" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            treeTraversal(binaryTree);
            break;
        }
        case 2: {
            Data value;
            std::cout << "Inserisci l'elemento da ricercare: ";
            std::cin >> value;
            if (binaryTree.Exists(value)) 
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
            struct lasd::BinaryTree<Data>::Node* node = &(binaryTree.Root());
            Data value = node->Element();
            type = checkType(value);
            if (type == 1) {
                int result = 1;
                binaryTree.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
            else if (type == 2) {
                float result = 0.0;
                binaryTree.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
            else if (type == 3) {
                std::string result = "";
                binaryTree.FoldPreOrder(&applyFold<Data>, &n, &result);
                std::cout << "Risultato: " << result << std::endl;
            }
            break;
        }
        case 4: {
            struct lasd::BinaryTree<Data>::Node* node = &(binaryTree.Root());
            Data value = node->Element();
            int type = -1;
            type = checkType(value);
            if (type == 3) {
                std::string aString = "";
                std::cout << "Inserire la stringa da concatenare in testa: ";
                std::cin >> aString;
                binaryTree.Map(&applyMap<Data>, &aString);
            }
            else 
                binaryTree.Map(&applyMap<Data>, nullptr);
            std::cout << "Il valore dei nodi è stato modificato correttamente" << std::endl;
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

// sum all the elements
template<>
void applyFold(const int& value, const void* par, void* acc) { //par should be n input from the user (sum all integers less than n)
    if (value < *((int*) par))
        *((int*)acc) = *((int*)acc) * value;
    //*acc = *acc + value;
}

// multiply all the elements
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

template<typename Data>
void applyMap(Data& value, void* opt);

template<>
void applyMap(int& value, void* opt) {
    value *= 3;
}

template<>
void applyMap(float& value, void* opt) {
    value = pow(value, 3);
}

template<>
void applyMap(std::string& value, void* opt) {
    value = *((std::string*)opt) + value;
}