Notas para Intro a HPC
Paralelización en CPU - Progamar directamente en paralelo

Curso para usar un cluster

Métricas:
Speedup - parallel effiency (min 0.6)

Herramientas:
Math gpt - video/resumen cierto tema
Paraview: Visualización de los programas en paralelo

#pragma -> compilar en paralelo con la bandera -fopenmp con nproc la cantidad máxima disponible (con `#include <omp.h>`)

    #pragma omp parallel
    {
        Todo paralelo
    }
    continúa serial

Así, compilamos 

    g++ -fopenmp -std=c++17 -O3 -fsanitize=address,leak,undefined file.cpp
    OMP_NUM_THREADS=nproc ./a.out

los santizers son importantes para evitar corrupción de memoria ya que varios threads pueden interferir.

Variables privadas: dentro del #pragma. Para cada thread
Variables públicas: fuera del ...

std::cout -> estamos diciendo que cout está en el alcance de std

## MPI
Comunicación entre threads. Todo está en paralelo. Cuidado con la duplicación. No garantías del orden de ejecución

    CXX=mpic++
    $(CXX) $(FLAGS) file.cpp # Compila
    mpirun -np nproc ./a.out # Todos son procesos diferentes (dif memoria)






phind.com LLM