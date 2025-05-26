for val in 0 1 2 3 fast; do
    echo "Ordenando ${val}.txt"
    sort -k 1n ${val}.txt > data_${val}.txt
done