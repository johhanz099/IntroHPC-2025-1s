#include <iostream>
#include <chrono>

// Naive recursive Fibonacci
long long fib_naive(int n);

// Fast Fibonacci
long long fib_fast(int n);

int main(int argc, char **argv) {

    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    int n = atoi(argv[1]);
    if (n < 0){
       std::cerr << "Debe escoger n mayor que cero" << std::endl;
       return 0;
    }
    
    // Fib_naive calculations
    auto start_n = std::chrono::high_resolution_clock::now();
    long long result_naive = fib_naive(n);
    auto end_n = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_naive = end_n - start_n;
    //std::cout << "fib_naive(" << n << ") = " << result_naive << "\n";
    //std::cout << "Elapsed time: " << elapsed_naive.count() << " seconds\n";

    // Fib_fast calculations
    auto start_f = std::chrono::high_resolution_clock::now();
    long long result_fast = fib_fast(n);
    auto end_f = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_fast = end_f - start_f;
    //std::cout << "fib_fast(" << n << ") = " << result_fast << "\n";
    //std::cout << "Elapsed time: " << elapsed_fast.count() << " seconds\n";

    // Show n   time_naive  time_fast
    std::cout << n << "\t"  << elapsed_naive.count() << "\t" << elapsed_fast.count() << std::endl;

    return 0;
}

// Naive recursive Fibonacci
long long fib_naive(int n)
{
    if (n <= 1) return n;
    return fib_naive(n - 1) + fib_naive(n - 2);
}

// Fast Fibonacci
long long fib_fast(int n)
{
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
    
}