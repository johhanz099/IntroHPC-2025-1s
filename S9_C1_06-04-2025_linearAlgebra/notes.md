# Notas para la clase

## Operaciones (opt) con matrices
Usamos la librería `eigen`

    #include <eigen3/Eigen/Dense>
    using Eigen::MatrixX{d,f} // con d:double, f:float

para manipular matrices (y sus operaciones) de forma eficiente. Para correr con parallel hay que colocar ciertas banderas de ejecución y compilación (con ciertas operaciones -> ver manual)

    OMP_NUM_THREADS=nproc /usr/bin/time ./a.out [args]

Para usar cierto número de procesadores. Hay una relación óptima para ciertos threads -> IMP

### Tarea
LLenar aleatoriamente y:
1. crono. Recordar uso de steadyclock para **no** medir el tiempo del CPU sino otro reloj monótono (intervalos). Pero necesitamos medir ambos tiempos para sacar estadísticas
imprimir primer elemento en x para que se ejecute

2. 

















### Tips
#### Firefox
Si no abre, entonces podemos cambiar el nombre de un directorio

    mv .mozilla .m

Esto cambia el directorio peo