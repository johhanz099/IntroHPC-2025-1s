set terminal pdfcairo enhanced color font 'Helvetica,10'
set output 'error_vs_N.pdf'

set title '|1 - sum1/sum2| en función de N'
set xlabel 'N'
set ylabel '|1 - sum1/sum2|'
set grid

set logscale y   # escala logarítmica en y (muy útil para ver errores pequeños)
set format y '10^{%T}'  # notación científica en el eje y

plot 'datos.txt' using 1:4 with lines title '|1 - sum1/sum2|'