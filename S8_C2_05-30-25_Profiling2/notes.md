1. PERF -> viene del kernel de Linux (también .py - activando ciertas cosas)

cómo usamos perf?
Compilar con bandera

    gcc -g -fno-omit-frame-pointer code.cpp -o name.x
    perf.stat ./name.x > profile_sumary

Para ver la info:

    perf record ./name.x
    perf report

El uso más chévere es crear las flame graphs para visualizar mejor los tiempos. Hay que instalar ciertos scripts. Lo primero crea el .data y lo segundo lo pasa a texto plano

    perf record --call-graph dwarf -F 99 -g -- ./a.out arg1 arg2 ...
    perf script > out.perf

Para descargar scripts. Vamos a downloads, clonamos github FlameGraph. Ejecutamos algo de ahí para generarla.

Editar formatos vectoriales con Inkscape

2. Speedscope: Usa el .perf para ver la info de una forma sencilla y más completa (online)

3. Hotspot -> descargar AppImage -> volverla ejecutable -> usar sin instalar
chmod -x name.AppImages

4. Valgrind - cachegrind and callgrind. 
Cache misses -> ? Saltos de memoria -> lento







AppImage HUB
Audacity: Fourier Transf

Tips: formas de dejar corriendo con ciertos nproc : parallel -jnproc. Comando independiente del padre

    nohup {command} &

Otra forma con t-mux, más útil

    tmux command

Luego buscar forma de salir y volver a entrar