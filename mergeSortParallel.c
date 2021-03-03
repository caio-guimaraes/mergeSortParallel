#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void imprimiVetor(int vet[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);

  int size, myRank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  MPI_Status status;

  int origem, destino;
  int tamanho = 5;
  int vetor[] = {11, 13, 2, 7, 4};

  // Master
  if (myRank == 0){
    printf("Vetor original: \n");
    imprimiVetor(vetor, tamanho);
    // mergeSort(vetor, 0, tamanho - 1, tamanho);
  }

  // MPI_Send(vet, tam, MPI_INT, destino, 0, MPI_COMM_WORLD);
  // MPI_Recv(vet, tam, MPI_INT, origem, 0, MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}
