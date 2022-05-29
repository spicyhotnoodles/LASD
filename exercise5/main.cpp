#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include "hashtable/clsadr/htclsadr.hpp"
#include "hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
/*   int input = 0;
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
  } while (flag); */
  lasd::HashTableOpnAdr<int> ht;
  ht.Insert(1);
  ht.Insert(2);
  ht.Insert(3);
  if (ht.Exists(1))
    std::cout << "1 esiste" << std::endl;
  else
    std::cout << "1 non esiste" << std::endl;
  if (ht.Exists(2))
    std::cout << "2 esiste" << std::endl;
  else
    std::cout << "2 non esiste" << std::endl;
  if (ht.Exists(3))
    std::cout << "3 esiste" << std::endl;
  else
    std::cout << "3 non esiste" << std::endl;
  if (ht.Exists(4))
    std::cout << "4 esiste" << std::endl;
  else
    std::cout << "4 non esiste" << std::endl;
  std::cout << "Numero di elementi: " << ht.Size() << std::endl;
  ht.Resize(500);
  std::cout << "Numero di elementi: " << ht.Size() << std::endl;
  return 0;
}