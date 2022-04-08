
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include "list/list.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
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
  return 0;
}



