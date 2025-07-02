#!/bin/bash

echo "Limpiando output_*.txt"
rm output_*.txt

VECTOR_SIZE=200000000
echo "Compilando"
g++ -std=c++20 -O2 parallel_metrics_algs.cpp -ltbb -o parallel_metrics_algs.x


for POLICY in 0 1 2; do
    case $POLICY in
        0) OUT_FILE="output_seq.txt" ;;
        1) OUT_FILE="output_par.txt" ;;
        2) OUT_FILE="output_par_unseq.txt" ;;
    esac

    echo "# Suma\tTiempo(s)\tThreads" > "$OUT_FILE"

    for THREADS in $(seq 1 16); do
        ./parallel_metrics_algs.x $VECTOR_SIZE $THREADS $POLICY >> "$OUT_FILE"
    done
done

echo "Ejecución exitosa"
