#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include "hashtable/clsadr/htclsadr.hpp"
#include "hashtable/opnadr/htopnadr.hpp"

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
  /* lasd::Vector<int> vector(5);
  for (int i = 0; i < 5; i++)
    vector.operator[](i) = i;
  lasd::HashTableOpnAdr<int> ht(87, vector); */
  return 0;
}