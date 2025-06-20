#include <mpi.h>
#include <iostream>

int main(int argc, char** argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int np;
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    // Get the rank of the process
    int pid;
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int number = atoi(argv[1]);
    if(pid == 0){
        // Envía el número tipo int al proceso objetivo
        int pid_target = 1;
        MPI_Send(&number,1,MPI_INT,pid_target,0,MPI_COMM_WORLD);
    }else if(pid == 1){
        int pid_ms = 0; // pid del procesos emisor
        MPI_Recv(&number,1,MPI_INT,pid_ms,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Process %d recieved number %d from process %d \n",pid,number,pid_ms);
    }
    MPI_Finalize();
}   