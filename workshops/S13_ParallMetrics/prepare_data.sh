rm -f *.dat
echo "Preparando datos para gnuplot"

# Extrae los tiempos
awk 'NR>1 {print $3, $2}' output_seq.txt > data_seq.dat
awk 'NR>1 {print $3, $2}' output_par.txt > data_par.dat
awk 'NR>1 {print $3, $2}' output_par_unseq.txt > data_par_unseq.dat

# Tiempo base secuencial
TSEQ=$(awk 'NR==2 {print $2}' output_seq.txt)

# Calcula Speedup y Eficiencia
echo "1 1.000000 1.000000" > metrics_seq.dat
awk -v tseq=$TSEQ '{printf "%d %.6f %.6f\n", $1, tseq/$2, (tseq/$2)/$1}' data_par.dat > metrics_par.dat
awk -v tseq=$TSEQ '{printf "%d %.6f %.6f\n", $1, tseq/$2, (tseq/$2)/$1}' data_par_unseq.dat > metrics_par_unseq.dat