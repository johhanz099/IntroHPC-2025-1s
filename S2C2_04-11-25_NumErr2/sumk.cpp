#include <iostream>
#include <cmath>

typedef float REAL;

// Decalaration
REAL sumk(int k);

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 1000; k++)
    {
        std::cout << k << "\t" << sumk(k) << std::endl;
    }
    

    //std::cout << sumk(1) << std::endl;
    return 0;
}

// Implementation
REAL sumk(int k){

    REAL sum = 0.0;
    for (int ii = 1; ii <= k; ii++)
    {
        sum += 0.1; 
    }
    REAL aux = k/10.0; // k/n.0 
    return std::fabs(aux - sum);

}