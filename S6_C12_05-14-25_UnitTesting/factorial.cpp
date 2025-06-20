#include "factorial.h"

int factorial(int number)
{
    if (number  == 0) return 1;
    if (number < 0){
        std::cerr << "Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number <= 1 ? number : factorial(number-1)*number;
}

int factorial_test(int mensaje)
{
    // función que imprime el número
    std::cout << "Este es su número: " << mensaje << std::endl;
    return 0;
}