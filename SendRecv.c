#include <stdio.h>
#include "mph.h"

int main (int argc, char *argv[]){
    int rank, number;
    number =0;
    /* starts MPI */
    MPI_Init (&argc, &argv);
    /* get current process rank */
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        number = 123;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        printf("Number = %d\n", number);
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    /* get number of processes */
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    /* print the rank and number of processes */
    printf("Hello world from process %d of %d\n", rank, size );
    /* ends MPI */
    MPI_Finalize();
    return 0;
}