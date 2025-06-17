#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função pra criar o vetor com números aleatórios
int* criarVetor(int tamanho) {
    int *v;
    v = malloc(tamanho * sizeof(int));

    if (v == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        v[i] = rand() % 100; // número de 0 até 99
    }

    return v;
}

// função pra mostrar os valores
void mostrar(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// ordenar do menor pro maior
void ordenarCrescente(int *v, int t) {
    int i, j, aux;
    for (i = 0; i < t - 1; i++) {
        for (j = 0; j < t - 1 - i; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

// ordenar do maior pro menor
void ordenarDecrescente(int *v, int t) {
    int i, j, aux;
    for (i = 0; i < t - 1; i++) {
        for (j = 0; j < t - 1 - i; j++) {
            if (v[j] < v[j+1]) {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main() {
    int tam;
    int *vet;

    srand(time(NULL)); // pra gerar números diferentes

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    vet = criarVetor(tam);

    printf("\nVetor aleatorio:\n");
    mostrar(vet, tam);

    ordenarCrescente(vet, tam);
    printf("\nVetor em ordem crescente:\n");
    mostrar(vet, tam);

    ordenarDecrescente(vet, tam);
    printf("\nVetor em ordem decrescente:\n");
    mostrar(vet, tam);

    free(vet); // liberar a memória
    return 0;
}
