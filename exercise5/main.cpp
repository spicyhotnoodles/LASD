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
  // Generate random double numbers
  /* std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0, 1);
  lasd::Vector<double> v(100);
  for (int i = 0; i < 100; i++) {
    v[i] = dis(gen);
  }
  lasd::HashTableOpnAdr<double> ht(5, v);
  for (int i = 0; i < v.Size(); i+17) {
    std::cout << "Checking " << v[i] << ": ";
    if (ht.Exists(v[i]))
      std::cout << "Elemento esistente" << std::endl;
    else
      std::cout << "Elemento non esistente" << std::endl;
  }*/
  return 0;
}