## Slurm
HPC resource manager

### Sintaxis
`scontrol`: administrar y obtener información de trabajos
`squeue`: ver trabajos
`scancel`: cancela algunos trabajos

### Conectarnos al ip interno del servidor

    ssh -p 443 192.168.10.1

Con `sinfo` vemos la disponibilidad de recursos. `sinfo -l` da un poco más de info.

#### Ejercicio 1
cómo especificar partición? `srun -p` o `srun --partition`

    srun -p 12threads -n 18 hostname

con `-n` especifico tareas, con `-N` especifico nodos. Pero lo hace a su conveniencia. Cómo lo obligo a que sean tres tareas por nodo -> con la bandera

    --ntasks-per-node=<ntasks>

Quiero estresar la máquina cierto tiempo (colocarlo después del comando que quiero mandar) `-t nsecs -c 1`. En las lectures se puede revisar más detalles sobre los comandos.

#### Ejercicio 2
Run 24 stress processes on 3 nodes , running 8 processes per node. At the same time, check with htop the system utilization on at least one of the nodes. Do you see your command running?

    srun -p 12threads -n 24 -N 3 --ntasks-per-node=8  stress -t 10 -c 1

La bandera `-c` especifica la cantidad de cpus pero es necesario especificar `tasks-per-cpu`.


### Continuando
Podemos contruir scripts para lanzar en slurm y lo corro con `sbatch *.sh`









IP externo fuera de la U
168.176.35.111