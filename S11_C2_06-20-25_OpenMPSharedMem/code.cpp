#include <iostream>
#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int thread_id;
    int n_thread;
  std::cout << "BEFORE\n";
#pragma omp parallel
  {
    thread_id = omp_get_thread_num();
    n_thread = omp_get_num_threads();
    //std::cout << "Hola mundo, desde el hilo" << thread_id << "from" << n_thread << std::endl;
    printf("Hola mundo, desde el hilo: %d, from: %d\n", thread_id, n_thread);
    //printf("Hola mundo, desde el hilo: %d\n", thread_id);
  }
  std::cout << "AFTER\n";

  return 0;
}