#include <iostream>
#include "factorial.h"

int main(void)
{
    std::cout << factorial(-1.5) << std::endl;
    std::cout << factorial(0.5) << std::endl;
    //std::cout << factorial(15) << std::endl;
    //std::cout << factorial(20) << std::endl;
    std::cout << factorial_test(9) << std::endl;
    return 0;
}