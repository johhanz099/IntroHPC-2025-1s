# Notas para la clase

## Operaciones (opt) con matrices
Usamos la librería `eigen`

    #include <eigen3/Eigen/Dense>
    using Eigen::MatrixX{d,f} // con d:double, f:float

para manipular matrices (y sus operaciones) de forma eficiente. Para correr con parallel hay que colocar ciertas banderas de ejecución y compilación (con ciertas operaciones -> ver manual)

    OMP_NUM_THREADS=16 /usr/bin/time ./a.out 1000 4  2>/dev/null 1 >> data_nproc
 
Para usar cierto número de procesadores. Hay una relación óptima para ciertos threads -> IMP

### Tarea
LLenar aleatoriamente y:
1. crono. Recordar uso de steadyclock para **no** medir el tiempo del CPU sino otro reloj monótono (intervalos). Pero necesitamos medir ambos tiempos para sacar estadísticas
imprimir primer elemento en x para que se ejecute

2. 


## Clase 2
Con `srand` controlamos el cambio de la semilla.

Creamos figura del tiempo promedio con barras de error -> desvest.p en función de el tamaño de la matriz para 1,2,4,5,16 threads


## métricas paralelas
Speedup, eficiencia paralela


















### Tips
#### Firefox
Si no abre, entonces podemos cambiar el nombre de un directorio

    mv .mozilla .m

Esto cambia el directorio peo