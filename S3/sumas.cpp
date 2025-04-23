#include <iostream>
#include <cmath>

typedef float REAL;

// Decalaration
REAL sum_one_to_N(int k);
REAL sum_N_to_one(int k);

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    int step = 1e3;
    for (int N = step; N <= 1e6; N += step)
    {
        REAL sum_one_to_N_value = sum_one_to_N(N);
        REAL sum_N_to_one_value = sum_N_to_one(N);
        REAL delta = std::fabs(1 - sum_one_to_N_value/sum_N_to_one_value);
        std::cout << N << "\t"
                       << sum_one_to_N_value << "\t"
                       << sum_N_to_one_value << "\t"
                       << delta << "\t"
                       << std::endl;
    }
    return 0;
}

// Implementation
REAL sum_one_to_N(int N){

    REAL sum = 0.0;
    for (int ii = 1; ii <= N; ii++)
    {
        sum += 1.0/ii; 
    }
    return sum;

}

REAL sum_N_to_one(int N){

    REAL sum = 0.0;
    for (int ii = N; ii >= 1; ii--)
    {
        sum += 1.0/ii; 
    }
    return sum;

}