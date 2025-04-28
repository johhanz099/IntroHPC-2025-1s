set title "PDF"
set xlabel "Bin Center"
set ylabel "PDF"
set grid
plot "data.txt" using 1:2 with linespoints pt 7 lc rgb "blue" title "PDF"
