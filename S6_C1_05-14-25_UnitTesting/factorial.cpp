#include "factorial.h"

long factorial(long number)
{
    if (number  == 0) return 1;
    if (number < 0){
        std::cerr << "Negative numbers not allowed. Returning -1\n";
        return -1;
    }
    return number <= 1 ? number : factorial(number-1)*number;
}