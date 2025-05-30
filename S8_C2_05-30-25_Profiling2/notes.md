PERF -> viene del kernel de Linux

cómo usamos perf?
Compilar con bandera

    gcc -g -fno-omit-frame-pointer
    perf.stat ./name.x > profile_sumary

Para ver la infor:

        perf record ./name.x
        perf report


asd                      