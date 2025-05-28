Notas

Recordando banderas de opt.
Row major para c++. Primero recorrer filas, luego columnas

PROFILING
quiero optimizar pero... ¿dónde? Debo buscar dónde y es útil conocer el tiempo de ejecución en ciertas partes como método de control de cambios.

1. Saber el tiempo de ejecución total (TODO EL PROGRAMA / no sé detalles):
$ /usr/bin/time ./a.out {data_input}

2. Detalles. Cronómetro antes y después de lo que quiero monitoriear -- #include <crono>. This allows to measure the clock time, not the cpu time (look for the differences …)
    system_clock: referenciado al clock del pc - posibles cambios - NO RECOMENDADO
    steady_clock: monótono - preciso para medir diferencias - OK
        auto start = std::chrono::steady_clock::now(); //auto: retorna con el tipo de variable a la cual está asignada e.g. si es var_typy, se vuelve var_type
        option1(...);
        auto end = std::chrono::steady_clock::now();
        std::cout << (end-start).count() << "\n"; // prints the time diff in seconds // better to print in scientific notatiom

        Tener cuidado con la redeclaración de variables. Para reutilizar en otros lados no vuelvo a declarar.

Primer ejercicio
En el código cache.cpp implementar medidas de tiempo para cada uno de los procesos

 // why this?
    printf("%ld\n", arr[0]);
    Para usarlos y que el compilador obligatoriamente dé el tiempo de ejecución. Puede darse el caso de que dé cero porque no se usa.

La impresión de los tiempos se da en algunas unidades "arbitrarias". Para convertir a segundos usamos
std::chrono::duration<double> diff;
std::cout << diff.count() << std::endl;

