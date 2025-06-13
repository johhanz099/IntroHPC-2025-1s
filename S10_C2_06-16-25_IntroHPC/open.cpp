#include <iostream>
#include <omp.h>

int i = 1699994; // Global scope

int main(int argc, char *argv[]) {
  std::cout << "BEFORE\n";
  int i = 9; // public scope?
#pragma omp parallel
  {
    int i = 9; // private scope
    std::cout << "Hola mundo" << "\n";
    std::cout << &i << "\t" << ::i << "\n";
  }
  std::cout << "AFTER\n";

  return 0;
}