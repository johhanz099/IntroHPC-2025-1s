set terminal pdfcairo font "Helvetica,12"
set output "eficiencia_paralela.pdf"

set title "Eficiencia Paralela"
set xlabel "Número de Threads"
set ylabel "Eficiencia"
set grid
set key top right
set yrange [0.0:1.05]
set key right center

f(x) = 1

plot \
    f(x) title "Ideal" lt -1 lc "gray", \
    "metrics_seq.dat" using 1:3 title "seq" with points pt 7 ps 1 lc rgb "#1f77b4", \
    "metrics_par.dat" using 1:3 title "par" with linespoints lw 2 lc rgb "#2ca02c", \
    "metrics_par_unseq.dat" using 1:3 title "par unseq" with linespoints lw 2 lc rgb "#d62728"
