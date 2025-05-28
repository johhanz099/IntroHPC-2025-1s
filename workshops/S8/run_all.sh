#!/usr/bin/env bash

# 1. Compilación
echo "Compilando ..."
parallel 'g++ -O{} fibonacci.cpp -o {}.x' ::: 0 1 2 3 fast

# 2. Obtener tiempo de referencia ejecutando directamente OPT=0 con n=20
echo "Ejecutando referencia (OPT=0, n=20) ..."
ref_time=$(./0.x 20 | awk '{print $2}')
echo "Tiempo de referencia (n=20, OPT=0): $ref_time"

# 3. Ejecución para todos los niveles y pasos de n
echo "Ejecutando casos ..."
parallel --progress './{1}.x {2} >> {1}.txt' ::: 0 1 2 3 fast ::: 5 10 15 20 25 30 35 40 45 50

# 4. Ordenamiento y normalización en un solo paso
echo "Ordenando y normalizando ..."
for val in 0 1 2 3 fast; do
    sort -k 1n ${val}.txt | awk -v ref="$ref_time" '{
        printf "%d %.8e %.8e\n", $1, $2/ref, $3/ref
    }' > data_${val}.txt
done

# 5. Limpieza: eliminar los archivos sin procesar
rm -f 0.txt 1.txt 2.txt 3.txt fast.txt

# 6. Script para graficar datos
# Puede crear un script.gp con las indicaciones al final del documento para crear la gráfica cambiando valores de n
echo "Creando gráfica ..."
gnuplot script.gp

echo "Listo. Datos normalizados y guardados en data_*.txt"


# ------------------------------------------------------------
# Código de Gnuplot sugerido para graficar los datos:
# ------------------------------------------------------------

# set terminal pdfcairo enhanced color font 'Arial,12'
# set output "t_vs_nFibonacci.pdf"

# set title "Tiempos normalizados para dos cómputos de la secuencia de Fibonacci"
# set xlabel "n-ésimo término en la secuencia de Fibonacci"
# set ylabel "Tiempo escalado con n=20, OPT=0 (s)"
# set logscale y
# set format y "10^{%T}"
# set grid

# Leyenda
# set key left top


# Estilos de líneas
# Estilos para "Naive"
# set style line 1 lc rgb '#1f77b4' lt 1 lw 2  # azul
# set style line 2 lc rgb '#ff7f0e' lt 1 lw 2  # naranja
# set style line 3 lc rgb '#2ca02c' lt 1 lw 2  # verde
# set style line 4 lc rgb '#d62728' lt 1 lw 2  # rojo
# set style line 5 lc rgb '#9467bd' lt 1 lw 2  # morado

# Estilos para "Fast" con líneas punteadas explícitas
# set style line 6 lc rgb '#1f77b4' dt (5,5) lw 2  # azul punteada
# set style line 7 lc rgb '#ff7f0e' dt (5,5) lw 2  # naranja punteada
# set style line 8 lc rgb '#2ca02c' dt (5,5) lw 2  # verde punteada
# set style line 9 lc rgb '#d62728' dt (5,5) lw 2  # rojo punteada
# set style line 10 lc rgb '#9467bd' dt (5,5) lw 2  # morado punteada


# Gráfica
#  plot \
#     "data_0.txt" using 1:2 with lines ls 1 title "FibNaive OPT=0", \
#    "data_1.txt" using 1:2 with lines ls 2 title "FibNaive OPT=1", \
#     "data_2.txt" using 1:2 with lines ls 3 title "FibNaive OPT=2", \
#     "data_3.txt" using 1:2 with lines ls 4 title "FibNaive OPT=3", \
#     "data_fast.txt" using 1:2 with lines ls 5 title "FibNaive OPT=fast", \
#     "data_0.txt" using 1:3 with lines ls 6 title "FibFast OPT=0", \
#     "data_1.txt" using 1:3 with lines ls 7 title "FibFast OPT=1", \
#     "data_2.txt" using 1:3 with lines ls 8 title "FibFast OPT=2", \
#     "data_3.txt" using 1:3 with lines ls 9 title "FibFast OPT=3", \
#     "data_fast.txt" using 1:3 with lines ls 10 title "FibFast OPT=fast"