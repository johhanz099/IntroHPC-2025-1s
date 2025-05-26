set terminal pdfcairo enhanced color font 'Arial,12'
set output "t_vs_nFibonacci.pdf"

set title "Distintos niveles de optimización"
set xlabel "n-ésimo término de la secuencia de Fibonacci"
set ylabel "Tiempo (s)"
set logscale y
set format y "%.1e"
set grid

# Leyenda
set key outside right top


# Estilos de líneas
# Estilos para "Naive"
set style line 1 lc rgb '#1f77b4' lt 1 lw 2  # azul
set style line 2 lc rgb '#ff7f0e' lt 1 lw 2  # naranja
set style line 3 lc rgb '#2ca02c' lt 1 lw 2  # verde
set style line 4 lc rgb '#d62728' lt 1 lw 2  # rojo
set style line 5 lc rgb '#9467bd' lt 1 lw 2  # morado

# Estilos para "Fast" con líneas punteadas explícitas
set style line 6 lc rgb '#1f77b4' dt (5,5) lw 2  # azul punteada
set style line 7 lc rgb '#ff7f0e' dt (5,5) lw 2  # naranja punteada
set style line 8 lc rgb '#2ca02c' dt (5,5) lw 2  # verde punteada
set style line 9 lc rgb '#d62728' dt (5,5) lw 2  # rojo punteada
set style line 10 lc rgb '#9467bd' dt (5,5) lw 2  # morado punteada


# Gráfica
plot \
    "data_0.txt" using 1:2 with lines ls 1 title "FibNaive OPT=0", \
    "data_1.txt" using 1:2 with lines ls 2 title "FibNaive OPT=1", \
    "data_2.txt" using 1:2 with lines ls 3 title "FibNaive OPT=2", \
    "data_3.txt" using 1:2 with lines ls 4 title "FibNaive OPT=3", \
    "data_fast.txt" using 1:2 with lines ls 5 title "vNaive OPT=fast", \
    "data_0.txt" using 1:3 with lines ls 6 title "FibFast OPT=0", \
    "data_1.txt" using 1:3 with lines ls 7 title "FibFast OPT=1", \
    "data_2.txt" using 1:3 with lines ls 8 title "FibFast OPT=2", \
    "data_3.txt" using 1:3 with lines ls 9 title "FibFast OPT=3", \
    "data_fast.txt" using 1:3 with lines ls 10 title "FibFast OPT=fast"