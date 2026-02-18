#include <stdio.h>
#include <time.h>

#define MAX 10000

// Preenche vetor em ordem decrescente (pior caso)
void preencherDecrescente(int v[], int n){
    for(int i = 0; i < n; i++){
        v[i] = n - i;
    }
}

// Bubble Sort
void bubbleSort(int v[], int n, long long *comp, long long *mov){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            (*comp)++;
            if(v[j] > v[j + 1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                (*mov)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int v[], int n, long long *comp, long long *mov){
    int temp;
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            (*comp)++;
            if(v[j] < v[min]){
                min = j;
            }
        }
        if(min != i){
            temp = v[i];
            v[i] = v[min];
            v[min] = temp;
            (*mov)++;
        }
    }
}

int main(){
    int tamanhos[] = {100, 1000, 10000};
    int v[MAX];

    printf("Algoritmo\tTamanho\tTempo(ms)\tComparacoes\tMovimentacoes\n");

    for(int t = 0; t < 3; t++){
        int n = tamanhos[t];
        clock_t inicio, fim;
        double tempo;
        long long comp, mov;

        // Bubble Sort
        preencherDecrescente(v, n);
        comp = mov = 0;

        inicio = clock();
        bubbleSort(v, n, &comp, &mov);
        fim = clock();

        tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
        printf("Bubble\t\t%d\t%.2f\t\t%lld\t\t%lld\n", n, tempo, comp, mov);

        // Selection Sort
        preencherDecrescente(v, n);
        comp = mov = 0;

        inicio = clock();
        selectionSort(v, n, &comp, &mov);
        fim = clock();

        tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
        printf("Selection\t%d\t%.2f\t\t%lld\t\t%lld\n", n, tempo, comp, mov);
    }

    return 0;
}
