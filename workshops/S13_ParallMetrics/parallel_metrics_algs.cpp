#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <execution>
#include <chrono>
#include <tbb/global_control.h>

int main(int argc, char* argv[]) {
    
    // Parámetros
    const long ARRAY_SIZE = atoi(argv[1]);
    const int NUM_THREADS = atoi(argv[2]);
    const int EX_POLICY   = atoi(argv[3]);

    // Forzar cantidad de threads
    tbb::global_control control(tbb::global_control::max_allowed_parallelism, NUM_THREADS);


    // Crear y llenar vector
    std::vector<double> array(ARRAY_SIZE);
    std::iota(array.begin(), array.end(), 0); // Llena el arreglo con 0,1,2,...

    // EX_POLICYs
    // seq
    if (EX_POLICY == 0)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        auto sum = std::reduce(std::execution::seq, array.begin(), array.end());
        auto tf = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dt = tf - t0;
        printf("%.2e\t  %.6f\t  %d\n", sum, dt.count(), NUM_THREADS);
    } 
    // par
    else if (EX_POLICY == 1)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        auto sum = std::reduce(std::execution::par, array.begin(), array.end());
        auto tf = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dt = tf - t0;
        printf("%.2e\t  %.6f\t  %d\n", sum, dt.count(), NUM_THREADS);
    }
    // par_unseq
    else if (EX_POLICY == 2)
    {
        auto t0 = std::chrono::high_resolution_clock::now();
        auto sum = std::reduce(std::execution::par_unseq, array.begin(), array.end());
        auto tf = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> dt = tf - t0;
        printf("%.2e\t  %.6f\t  %d\n", sum, dt.count(), NUM_THREADS);
    }
    // Error de política
    else {
        std::cerr << "Política no válida (sólo 0=seq, 1=par, 2=par_unseq): " << "\n";
        return 0;
    }
    
    return 0;
}