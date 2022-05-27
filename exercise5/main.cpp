#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include "hashtable/clsadr/htclsadr.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  int input = 0;
  bool flag = true;
  std::cout << "---------- Menu ----------" << std::endl;
  do {
    std::cout << "Digita la scelta corrispondente:" << std::endl;
    std::cout << "1. Test del docente." << std::endl << "2. Test dello studente." << std::endl << "3. Termina" << std::endl;
    std::cin >> input;
    switch (input)
    {
    case 1:
      lasdtest(); // To call in the menu of your library test!
      break;   
    case 2:
      mytest();
      break;
    case 3:
      std::cout << "Terminazione" << std::endl;
      flag = false;
      break;
    default:
      std::cout << "Scelta non valida, riprovare!" << std::endl;
      break;
    }
  } while (flag);
  /* lasd::HashTableClsAdr<int> ht1;
  lasd::HashTableClsAdr<int> ht2;
  lasd::HashTableClsAdr<int> ht3;
  ht.print();
  ht1.Insert(1);
  ht2.Insert(1);
  ht3.Insert(0);
  if (ht1.Exists(1))
    std::cout << "Il valore esiste" << std::endl;
  else
    std::cout << "Il valore non esiste" << std::endl;
  if (ht2.Exists(2))
    std::cout << "Il valore esiste" << std::endl;
  else
    std::cout << "Il valore non esiste" << std::endl;
  std::cout << ht.Size() << std::endl;
  ht.Insert(1);
  std::cout << ht.Size() << std::endl;
  ht.Clear();
  std::cout << ht.Size() << std::endl;
  if (ht1 == ht2)
    std::cout << "Le due hash table sono uguali" << std::endl;
  else
    std::cout << "Le due hash table non sono uguali" << std::endl;
  if (ht1 == ht3)
    std::cout << "Le due hash table sono uguali" << std::endl;
  else
    std::cout << "Le due hash table non sono uguali" << std::endl; */
  /* lasd::Vector<int> vector(5);
  for (int i = 0; i < vector.Size(); i++)
    vector[i] = i;
  lasd::List<int> list;
  for (int i = 0; i < 5; i++)
    list.InsertAtBack(i);
  lasd::HashTableClsAdr<int> ht(list);
  if (ht.Exists(4))
    std::cout << "Il valore esiste" << std::endl;
  else
    std::cout << "Il valore non esiste" << std::endl;
  std::cout << "Dimension: " << ht.Size() << std::endl;
  ht.Remove(4);
  if (ht.Exists(4))
    std::cout << "Il valore esiste" << std::endl;
  else
    std::cout << "Il valore non esiste" << std::endl;
  std::cout << "Dimension: " << ht.Size() << std::endl;*/
  return 0;
}