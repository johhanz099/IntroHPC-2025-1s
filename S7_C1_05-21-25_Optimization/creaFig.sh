for val in 0 1 2 3 fast; do
    echo "Optimization level: $val";
    gcc -O$val matriz_3d_transposeBloc.c; OPT=$val; MSIZE=512;
    for ((csize=1; csize <= $MSIZE; csize *= 2)); do
        echo -n $MSIZE $csize; ./a.out $MSIZE $csize " ";
        done > data_$OPT.txt; 
done;
gnuplot script.gp
