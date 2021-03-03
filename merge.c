/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>


void imprimiVetor(int vet[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

// Merge os dois subvetores do vet[].
// Primeiro subvetor é igual vet[inicio..meio]
// Segundo subvetor é igual vet[meio+1..fim]
void merge(int vet[], int inicio, int meio, int fim, int tamanho)
{
    printf("--------------- Chamada Merge --------------- \n");
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    printf("inicio: %d\n", inicio);
    printf("fim: %d\n", fim);
    printf("n1: %d n2: %d\n", n1, n2);

    // Cria vetores auxiliares de tamanho n1 e n2 respectivamente
    int L[n1], R[n2];

    // Preenchendo os vetores auxiliares L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vet[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[meio + 1 + j];

    printf("vetor L: ");
    imprimiVetor(L, n1);
    printf("vetor R: ");
    imprimiVetor(R, n2);

    /* Merge dos subvetores no vetor a ser ordenado - vet[inicio..fim]*/
    i = 0; // Index inicial do vetor L
    j = 0; // Index inicial do vetor R
    k = inicio; // Index inicial do vetor a ser ordenado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vet[k] = L[i];
            i++;
        }
        else {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    printf("vet apos troca: ");
    imprimiVetor(vet, tamanho);

    // Copia dos elementos restantes do subvetor L, se existir
    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    // Copia dos elementos restantes do subvetor R, se existir
    while (j < n2) {
        vet[k] = R[j];
        j++;
        k++;
    }

    printf("vet fim do merge: ");
    imprimiVetor(vet, tamanho);

    printf("--------------- Fim Merge --------------- \n");
}

void mergeSort(int vet[], int inicio, int fim, int tamanho)
{
    printf("--------------- Chamada MergeSort --------------- \n");

    printf("tamanho: %d\n", tamanho);
    printf("vetor: ");
    imprimiVetor(vet, tamanho);

    printf("inicio: %d\n", inicio);
    printf("fim: %d\n", fim);
    if (inicio < fim) {
        // int meio = inicio + (fim - inicio) / 2;
        int meio = (inicio+fim)/2;
        printf("meio: %d\n", meio);

        // MergeSort para as duas metades do vetor
        mergeSort(vet, inicio, meio, tamanho);
        mergeSort(vet, meio + 1, fim, tamanho);

        merge(vet, inicio, meio, fim, tamanho);
    }
    printf("--------------- Fim MergeSort --------------- \n");
}



int main()
{
    int tamanho, i;
  	printf("Digite o tamanho do vetor: ");
  	scanf("%d", &tamanho);
  	int *vetor = (int*) malloc(tamanho*sizeof(int));
  	printf("Preencha o vetor: ");
  	for(i=0; i<tamanho; i++)
  		scanf("%d", &vetor[i]);

    printf("Vetor original: \n");
    imprimiVetor(vetor, tamanho);

    mergeSort(vetor, 0, tamanho - 1, tamanho);

    printf("\nVetor ordenado: \n");
    imprimiVetor(vetor, tamanho);
    return 0;
}
