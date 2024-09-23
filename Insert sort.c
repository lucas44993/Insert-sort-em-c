#include <stdio.h>

// Função para ler os números do teclado e armazená-los no vetor
void lerNumeros(float vetor[], int tamanho) {
    printf("Digite os numeros do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%f", &vetor[i]);
    }
}

// Função para imprimir o vetor
void imprimirVetor(float vetor[], int tamanho) {
    printf("Vetor:");
    for (int i = 0; i < tamanho; i++) {
        printf(" %.2f", vetor[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos de posição no vetor
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Função para realizar a ordenação do vetor usando o selection sort
void selectionSort(float vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        printf("\nIteracao %d:\n", i + 1);
        printf("--------------\n");
        printf("Vetor antes da ordenacao:");
        imprimirVetor(vetor, tamanho);

        int menorIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menorIndex]) {
                menorIndex = j;
            }
        }

        // Troca os elementos se necessário
        if (menorIndex != i) {
            printf("Troca %d ( %.2f <--> %.2f ):\n", i + 1, vetor[i], vetor[menorIndex]);
            trocar(&vetor[i], &vetor[menorIndex]);
            imprimirVetor(vetor, tamanho);
        } else {
            printf("Nenhuma troca necessaria.\n");
        }
    }
}

void insertionSort(float arr[], int n)
{
    int i, j;
    float key;
    int SwapCount = 1;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            printf("Troca %d ( %.2f <--> %.2f ):\n",SwapCount, arr[j], arr[j+1] );
            SwapCount += 1;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int start() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    float vetor[tamanho];

    lerNumeros(vetor, tamanho);
    printf("\nVetor inicial:\n");
    imprimirVetor(vetor, tamanho);
    insertionSort(vetor, tamanho);
    printf("\nVetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

int main() {
    start();
    return 0;
}
