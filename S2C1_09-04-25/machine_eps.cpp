#include <iostream>
#include <cstdlib>

typedef float REAL;

int main(int argc, char **argv)
{   
    std::cout.precision(20);
    std::cout.setf(std::ios::scientific);
    REAL eps = 1.0;
    int N = std::atoi(argv[1]);
    REAL one = 1;
    for (int ii = 0; ii < N; ii++)
    {
        eps /= 2;
        one = 1.0 + eps;
        std::cout << ii << "    Eps:" << eps << "; One:" << one << std::endl;
    }


    // TODO
    

}