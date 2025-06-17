#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* gerarVetor(int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 100; 
    }

    return vetor;
}


void imprimirVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));
    }
    printf("\n");
}


void ordenarCrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (*(vetor + j) > *(vetor + j + 1)) {
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
        }
    }
}


void ordenarDecrescente(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (*(vetor + j) < *(vetor + j + 1)) {
                int temp = *(vetor + j);
                *(vetor + j) = *(vetor + j + 1);
                *(vetor + j + 1) = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL)); 

    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = gerarVetor(tamanho);

    printf("\nVetor gerado:\n");
    imprimirVetor(vetor, tamanho);

    ordenarCrescente(vetor, tamanho);
    printf("\nVetor em ordem crescente:\n");
    imprimirVetor(vetor, tamanho);

    ordenarDecrescente(vetor, tamanho);
    printf("\nVetor em ordem decrescente:\n");
    imprimirVetor(vetor, tamanho);

    free(vetor); // libera a memória
    return 0;
}
