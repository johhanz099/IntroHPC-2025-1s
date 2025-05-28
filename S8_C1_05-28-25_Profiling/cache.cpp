#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <chrono>

/*
  Tests cache misses.
*/

void option1(long * data, int m, int n);
void option2(long * data, int m, int n);
void option3(long * data, int m, int n);

int main(int argc, char **argv)
{
    if (argc < 3){
        printf("Usage: cacheTest sizeI sizeJ\nIn first input.\n");
        return 1;
    }
    long sI = atoi(argv[1]);
    long sJ = atoi(argv[2]);

    printf("Operating on matrix of size %ld by %ld\n", sI, sJ);
    
    // Create diff var (seeconds)
    std::chrono::duration<double> diff;

    // Time creating array
    auto start_arr = std::chrono::steady_clock::now();
    long *arr = new long[sI*sJ]; // double array.
    auto end_arr = std::chrono::steady_clock::now();
    diff = end_arr - start_arr;
    std::cout << "Tiempo_arr (s): " << (diff).count() << "\n";
    
    // option 1
    auto start1 = std::chrono::steady_clock::now();
    option1(arr, sI, sJ);
    auto end1 = std::chrono::steady_clock::now();
    diff = end1 - start1;
    std::cout << "Tiempo_opt1 (s): " << (diff).count() << "\n";  

    // option 2
    auto start2 = std::chrono::steady_clock::now();
    option2(arr, sI, sJ);
    auto end2 = std::chrono::steady_clock::now();
    diff = end2 - start2;
    std::cout << "Tiempo_opt2 (s): " << (diff).count() << "\n";
  
    // option 3
    auto start3 = std::chrono::steady_clock::now();
    option3(arr, sI, sJ);
    auto end3 = std::chrono::steady_clock::now();
    diff = end3 - start3;
    std::cout << "Tiempo_opt3 (s): " << (diff).count() << "\n"; 

    // why this?
    printf("%ld\n", arr[0]);

    // free memory
    auto start_f = std::chrono::steady_clock::now();
    delete [] arr; 
    auto end_f = std::chrono::steady_clock::now();
    diff = end_f - start_f;
    std::cout << "Tiempo_lib_mem (s): " << (diff).count() << "\n"; 

    return 0;
}

void option1(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(i * (n)) + j ] = i;
}

void option2(long * data, int m, int n)
{
  for (long i=0; i < m; ++i)
    for (long j=0; j < n; ++j)
      data[(j * (m)) + i ] = i;
}

void option3(long * data, int m, int n)
{
  for (int i=0; i < m*n; ++i) data[i] = i;
}