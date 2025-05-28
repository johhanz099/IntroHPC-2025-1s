parallel 'g++ -O{} fibonacci.cpp -o {}.x' ::: 0 1 2 3 fast
parallel --progress './{1}.x {2} >> {1}.txt' ::: 0 1 2 3 fast ::: 5 10 15 20 25 30 35 40 45 50