#include <iostream>
#include <cmath>

typedef float REAL;

// Decalaration
REAL sumOne(int k);
REAL sumTwo(int k);
REAL sumThree(int k);

int main(void){
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for (int k = 1; k <= 500; k++)
    {
        std::cout << k << "\t" << (std::fabs(sumOne(k) - sumThree(k)))/(sumThree(k))
                       << "\t" << (std::fabs(sumTwo(k) - sumThree(k)))/(sumThree(k))
                       << "\t" << sumThree(k)
                       << std::endl;
    }
    

    //std::cout << sumk(1) << std::endl;
    return 0;
}

// Implementation
REAL sumOne(int k){

    REAL sum = 0.0;
    for (int ii = 1; ii <= 2*k; ii++)
    { 
        sum += std::pow(-1,ii) * 1.0 * ii/(ii+1); 
    }
    return sum;

}

REAL sumTwo(int N){
    REAL suma_pos = 0.0;
    REAL suma_neg = 0.0;
    REAL n2;
    
    for (int n = 1; n <= N; n++){
        n2 = 2.0*n;

        suma_pos += n2 / (n2 + 1.0);
        suma_neg += (n2 - 1.0) / n2 ;
    }
    return suma_pos - suma_neg;
}

REAL sumThree(int N){
        REAL suma = 0.0;
    REAL aux = 0.0;
    for(int ii = 1; ii <= N; ii++) {
        aux = 1/(2*ii*(2*ii+1)*1.0);
        suma += aux;
    }
    return suma;
}