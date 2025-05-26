HPC
Programas eficientes

9. Optimización (profiling -> dónde optimizar):

9.1 Banderas de compilación
3 Niveles (-Ox, con x en {1,2,3}):
    1: básico
    2: estándar
    3: más rápido pero de cuidado, puede hacer cosas raras.

Programación por bloques (caché CPU) (tamaño bloque ?)


¿cómo puedo sacar el índice 1d para (i,j) con m filas y n columnas. Para el caso de RowMajor tenemos en cuenta el número de columnas
    Estrategia: recordar conversion de binario a decimal.
    1d = id = id(i,j) = i*n^1 + j*n^0
                      = i*n + j
Para calcular la función inversa hago uso del módulo y del truncamiento para int / int
    i = id / n
    j = id % n

////////////////////////////////// C2
 
librerías - flags >>> bien usadas


GNU parallel (exit -> ctrl + D)
>> parallel 'instrucción {arg: n.x}' ::: 1.x 2.x 3.x 4.x            Ejecuta la instrucción con todos los argumentos al tiempo

Cuidados:
Escribir datos separados -> evitar re escritura

Ejemplos:
parallel 'stress -c {}' ::: 1 1 1 1 1 1 1 (stres corriendo 1*n veces -> cpus)
parallel 'echo {}' ::: 1 2 3 4 ::: A B C D (corre dos argumentos a la vez)
>>  1 A 
    2 B  ...

Revisar flags para "parallel"    

Tarea:
Tiempo en función de block size. Fijo argumento de tamaño matriz N = 2048

Instrucción parallel

parallel 'g++ -O{} matmul_block.cpp -o matmul_block_{}.x' ::: 0 1 2 3 fast
parallel './matmul_block_{1}.x 256 {2} >> data_{1}.txt ' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024

parallel 'g++ -O{} matmul_block.cpp -o matmul_block_{}.x' ::: 0 1 2 3 fast; 
parallel --progress './matmul_block_{1}.x 1024 {2} 10 >> data_{1}.txt' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024 

sort -nk col .txt : ordena el txt por la columna col


GNU parallel: > eficiencia




Detalles / trucos:
1. Cosas viejas
2. Lenguaje prog consola
    >> for val in 0 1 2 3 fast; do echo "Optim level: $val"; gcc -O$val file_name; ./a.out; done




Refs:
Donald Knuth