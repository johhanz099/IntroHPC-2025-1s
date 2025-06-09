set terminal pdfcairo enhanced color font 'Arial,12'
set output "t_vs_nproc.pdf"

set title "Tiempos en función de nproc "
set xlabel "nproc"
set ylabel "Tiempos"
set logscale y
set grid

plot \
    "data.txt" using 1:3:($3-$4):($3+$4) with yerrorlines title "wtime", \
    "data.txt" using 1:5 with lines title "ctime", 