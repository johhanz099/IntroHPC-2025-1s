parallel 'g++ -O{} matmul_block.cpp -o {}.x' ::: 0 1 2 3 fast
parallel --progress './{1}.x 1024 {2} 10 >> {1}.txt' ::: 0 1 2 3 fast ::: 2 4 8 16 32 64 128 256 512 1024