## Memoria compartida
Recordemos lo de la memoria compartida.

Master thread --> parallel region (n threads con `#pragma ...` y especificando 3 threads con `OMP_NUM_THREADS=n`) --> serial region --> ...

En cada parallel region los threads tienen accesos a la memoria. Con memoria compartida se crean threads != procesos. Deben cominucarse entre ellos en el caso de necesitarlo con una **Librería de comunicación**

## Memoria distribuida - MPI
Lanzo procesos (no threads), no se hablan y tienen su propia memoria. Para compilar y ejecutar

    mpic++ file.cpp
    mpirun -np 4 ./a.out

### Tarea
Dos **procesos** (-np 2)

p1 -> manda número (int) ->p2 (imprime). Usando MPI_Send, MPI_Recv

MPI_Send(
    buffer = dirección de memoria de lo que quiero enviar
    int count = cuánto envío
    MPI_DataType = e.g. MPI_INT, ...
    int rank_destination = int con el pid
    int tag = identificador ()
    MPI_COMM_WORLD : Grupo lógico de mis procesadores que agrupa a todo el mundo
    )

declaramos dentro del else un `int buf;` interno para evitar sobreescritura
MPI_Recv(
    buffer = &buf;
    ...
    MPI_STATUS_IGNORE: ignora errores (por ahora)

)