set terminal pdfcairo enhanced color font 'Arial,12'
set output "random_pdf.pdf"

set title "Distribución Normal para Diferentes Semillas"
set title "Normal distribution of different seeds"
set xlabel "Bin Center"
set ylabel "PDF"
set grid

plot \
    "data1.txt" using 1:2 with lines title "Seed 1", \
    "data2.txt" using 1:2 with lines title "Seed 2", \
    "data5.txt" using 1:2 with lines title "Seed 5"

