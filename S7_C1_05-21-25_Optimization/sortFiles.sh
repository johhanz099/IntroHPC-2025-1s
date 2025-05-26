for val in 0 1 2 3 fast; do
    echo "Ordenando data_$val.txt"
    sort -k 2n ${val}.txt > data_${val}.txt
done
