#include "test.hpp"
#include <iostream>
#include <random>

void mytest() {
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Test Studente -----------" << std::endl;
        lasd::Vector<int> vector(5);
        for (int i = 0; i < 5; i++) {
            vector.operator[](i) = i + 1;
        }
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
        lasd::BinaryTreeVec<int> binaryTree(vector);
        //lasd::BinaryTreeVec<std::string> binaryTree(vector);
        binaryTreeMenu(binaryTree);
        exit = true;
        int selectedStruct = selectStruct();
        if (selectedStruct == 0)
            exit = true;
        else {
            if (selectedStruct == 1) {
                int selectedStack = selectImple();
                if (selectedStack == 1) {
                    int selectedType = selectType();
                    if (selectedType == 1) {
                        lasd::StackVec<int> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }
                    else if (selectedType == 2) {
                        lasd::StackVec<float> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }
                    else if (selectedType == 3) {
                        lasd::StackVec<std::string> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }                    
                }
                else if (selectedStack == 2) {
                    int selectedType = selectType();
                    if (selectedType == 1) {
                        lasd::StackLst<int> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }
                    else if (selectedType == 2) {
                        lasd::StackLst<float> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }
                    else if (selectedType == 3) {
                        lasd::StackLst<std::string> stack;
                        randomStackGen(stack);
                        stackMenu(stack);
                    }
                }
            }
            else if (selectedStruct == 2) {
                int selectedQueue = selectImple();
                if (selectedQueue == 1) {
                    int selectedType = selectType();
                    if (selectedType == 1) {
                        lasd::QueueVec<int> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                    else if (selectedType == 2) {
                        lasd::QueueVec<float> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                    else if (selectedType == 3) {
                        lasd::QueueVec<std::string> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                }
                else if (selectedQueue == 2) {
                    int selectedType = selectType();
                    if (selectedType == 1) {
                        lasd::QueueLst<int> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                    else if (selectedType == 2) {
                        lasd::QueueLst<float> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                    else if (selectedType == 3) {
                        lasd::QueueLst<std::string> queue;
                        randomQueueGen(queue);
                        queueMenu(queue);
                    }
                }
            }
        }
    } while(!exit);
}

int selectStruct() {
    int choice = -1;
    std::cout << "Scegli la struttura dati" << std::endl;
    std::cout << "1) Stack" << std::endl;
    std::cout << "2) Queue" << std::endl;
    std::cout << "0) Per terminare" << std::endl;
    std::cin >> choice;
    return choice;
}

int selectImple() {
    int choice = -1;
    std::cout << "Scegli l'implementazione" << std::endl;
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
void stackMenu(lasd::Stack<Data>& stack) {
    int choice = -1;
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Stack Menu ----------" << std::endl;
        std::cout << "1) Push di un elemento nello stack" << std::endl;
        std::cout << "2) Pop di un elemento dallo stack" << std::endl;
        std::cout << "3) Top dello stack" << std::endl;
        std::cout << "4) TopNPop dello stack" << std::endl;
        std::cout << "5) Stampa stack" << std::endl;
        std::cout << "6) Controllo di vuotezza" << std::endl;
        std::cout << "7) Stampa numero di elementi contenuti" << std::endl;
        std::cout << "8) Svuota stack" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                Data value;
                std::cout << "Inserisci il valore da inserire nello stack: ";
                std::cin >> value;
                stack.Push(value);
                std::cout << "Elemento aggiunto correttamente" << std::endl;
                break;
            }
            case 2: {
                try {
                    stack.Pop();
                    std::cout << "Elemento rimosso correttamente" << std::endl;
                } catch(std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                try {
                    std::cout << "Top dello stack: " << stack.Top() << std::endl;
                } catch(std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                try {
                    std::cout << "Top dello stack: " << stack.TopNPop() << std::endl;
                    std::cout << "Elemento rimosso correttamente" << std::endl;
                } catch(std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                if (stack.Size() == 0) {
                    std::cout << "Lo stack è vuoto" << std::endl;
                }
                else {
                    stack.printStack();
                }
                break;
            }
            case 6: {
                if (stack.Empty())
                    std::cout << "Lo stack è vuoto" << std::endl;
                else
                    std::cout << "Lo stack non è vuoto" << std::endl;
                break;
            }
            case 7: {
                std::cout << "Numero di elementi contenuti: " << stack.Size() << std::endl;
                break;
            }
            case 8: {
                stack.Clear();
                std::cout << "Stack svuotato" << std::endl;
                break;
            }
            case 0: {
                exit = true;
                break;
            }
            default: {
                std::cout << "Scelta non valida, riprovare!" << std::endl;
                break;
            }
        }
    } while (!exit);
}

template<typename Data>
void binaryTreeMenu(lasd::BinaryTree<Data>& binaryTree) {
    int choice = -1;
    bool exit = false;
    std::string aString = "";
    do {
        std::cout << std::endl;
        std::cout << "---------- Binary Tree Menu ----------" << std::endl;
        std::cout << "Random generated tree: " << std::endl;
        binaryTree.printTree(aString, &(binaryTree.Root()), false);
        std::cout << "NB: Il figlio sinistro viene stampato prima del figlio destro" << std::endl;    
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "1) Effettua visita sull'albero" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1: {
            treeTraversal(binaryTree);
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
void queueMenu(lasd::Queue<Data>& queue) {
    int choice = -1;
    bool exit = false;
    do {
        std::cout << std::endl;
        std::cout << "---------- Queue Menu ----------" << std::endl;
        std::cout << "1) Enqueue di un elemento nella queue" << std::endl;
        std::cout << "2) Dequeue di un elemento dalla queue" << std::endl;
        std::cout << "3) Head della queue" << std::endl;
        std::cout << "4) HeadNDequeue della queue" << std::endl;
        std::cout << "5) Controllo di vuotezza" << std::endl;
        std::cout << "6) Stampa queue" << std::endl;
        std::cout << "7) Stampa numero di elementi contenuti " << std::endl;
        std::cout << "8) Svuota queue" << std::endl;
        std::cout << "0) Per terminare" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                Data element;
                std::cout << "Inserisci il valore da accodare: " << std::endl;
                std::cin >> element;
                queue.Enqueue(element);
                std::cout << "Elemento aggiunto correttamente" << std::endl;
                break;
            }
            case 2: {
                try {
                    queue.Dequeue();
                    std::cout << "Elemento rimosso correttamente" << std::endl;
                } catch (std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 3: {
                try {
                std::cout << "Head della coda: " << queue.Head() << std::endl;
                } catch (std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                try {
                    std::cout << "Head della coda: " << queue.HeadNDequeue() << std::endl;
                    std::cout << "Elemento rimosso correttamente" << std::endl;
                } catch (std::length_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 5: {
                if (queue.Empty())
                    std::cout << "La coda è vuota" << std::endl;
                else
                    std::cout << "La coda non è vuota" << std::endl;
                break;
            }
            case 6: {
                if (queue.Size() == 0) {
                    std::cout << "La coda è vuota" << std::endl;
                }
                else {
                    queue.printQueue();
                }
                break;
            }
            case 7: {
                std::cout << "Numero di elementi contenuti: " << queue.Size() << std::endl;
                break;
            }
            case 8: {
                queue.Clear();
                std::cout << "Coda svuotata" << std::endl;
                break;
            }
            case 0: {
                exit = true;
                break;
            }
            default : {
                std::cout << "Scelta non valida, riprovare!" << std::endl;
                break;
            }
        }
    } while (!exit);
}

int getRandomInt() {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,25);
    return dist(gen);
}

template<typename Data>
void randomStackGen(lasd::Stack<Data>& stack);

template<>
void randomStackGen(lasd::Stack<int>& stack) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,100);
    for (ulong index = 0; index < 5; index++) {
        stack.Push(dist(gen));
    }
    std::cout << "Stack popolato" << std::endl;
}

template<>
void randomStackGen(lasd::Stack<float>& stack) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(1.0,100.0);
    for (ulong index = 0; index < 5; index++) {
        stack.Push(dist(gen));
    }
    std::cout << "Stack popolato" << std::endl;
}

template<>
void randomStackGen(lasd::Stack<std::string>& stack) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string random_string;
    for (ulong index = 0; index < 5; index++) {
        random_string = "";
        int length = getRandomInt();
        for (ulong i = 0; i < length; ++i)
            random_string += characters[distribution(generator)];
        stack.Push(random_string);
    }
    std::cout << "Stack popolato" << std::endl;
}

template<typename Data>
void randomQueueGen(lasd::Queue<Data>& queue);

template<>
void randomQueueGen(lasd::Queue<int>& queue) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,100);
    for (ulong index = 0; index < 5; index++) {
        queue.Enqueue(dist(gen));
    }
    std::cout << "Queue popolata" << std::endl;
}

template<>
void randomQueueGen(lasd::Queue<float>& queue) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(1.0,100.0);
    for (ulong index = 0; index < 5; index++) {
        queue.Enqueue(dist(gen));
    }
    std::cout << "Queue popolata" << std::endl;
}

template<>
void randomQueueGen(lasd::Queue<std::string>& queue) {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);
    std::string random_string;
    for (ulong index = 0; index < 5; index++) {
        random_string = "";
        int length = getRandomInt();
        for (ulong i = 0; i < length; ++i)
            random_string += characters[distribution(generator)];
        queue.Enqueue(random_string);
    }
    std::cout << "Queue popolata" << std::endl;
}