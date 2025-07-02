set terminal pdfcairo font "Helvetica,12"
set output "speedup.pdf"

set title "Speedup"
set xlabel "Número de Threads"
set ylabel "Speedup"
set grid
set key top left
set yrange [0:5]  # Para ver mejor las diferencias
set key right center

# Línea ideal
f(x) = x

plot \
    f(x) title "Ideal" lt -1 lc "gray", \
    "metrics_seq.dat" using 1:2 title "seq" with points pt 7 ps 1 lc rgb "#1f77b4", \
    "metrics_par.dat" using 1:2 title "par" with linespoints lw 2 lc rgb "#2ca02c", \
    "metrics_par_unseq.dat" using 1:2 title "par unseq" with linespoints lw 2 lc rgb "#d62728"
