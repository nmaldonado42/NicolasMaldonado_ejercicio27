#include <stdio.h>
#include "mph.h"

int main (int argc, char *argv[]){
    int rank, size;
    /* starts MPI */
    MPI_Init (&argc, &argv);
    /* get current process rank */
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    /* get number of processes */
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    /* print the rank and number of processes */
    printf("Hello world from process %d of %d\n", rank, size );
    /* ends MPI */
    MPI_Finalize();
    return 0;
}