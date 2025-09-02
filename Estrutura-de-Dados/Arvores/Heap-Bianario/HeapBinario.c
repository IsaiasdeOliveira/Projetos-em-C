#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pai(int i) {
    return (i - 1) / 2; // Retorna o Ã­ndice do pai do nÃ³ i
}

int esq(int i) {
    return 2*i + 1; // Retorna o Ã­ndice do filho Ã  esquerda de i
}

int dir(int i) {
    return 2*i + 2; // Retorna o Ã­ndice do filho Ã  direita de i
}

void subir(int *heap, int i) {
     int aux;
     int p = pai(i); // Calcula o Ã­ndice do pai
     if (p >= 1) { // Se pai(i) pertence ao heap
        if (heap[i] > heap[p]) { // Se o filho for maior que o pai (max-heap)
           // Troca pai e filho
           aux = heap[i];
           heap[i] = heap[p];
           heap[p] = aux;
          subir(heap, p); // Continua subindo recursivamente
        }
     }
}

void inserir(int *heap, int *n, int novoItem) {
     *n = *n + 1; // Aumenta o nÃºmero de elementos no heap
     heap[*n] = novoItem; // Insere o novo elemento no final
     subir(heap, *n); // Sobe o Ãºltimo elemento do heap
}

void imprimirHeap(int *heap, int n, int i, int b) {
     int j;
     if (i > n) { // NÃ³ nulo (alÃ©m do tamanho do heap), imprime "NULL"
        for (j = 0; j < b; j++) printf("-----");
        printf("NULL\n");
        return;
     }
     imprimirHeap(heap, n, dir(i), b + 1); // Imprime subÃ¡rvore direita
     for (j = 0; j < b; j++) printf("-----"); // IndentaÃ§Ã£o
     printf("%i\n", heap[i]); // Imprime o valor do nÃ³ com Ã­ndice i
     imprimirHeap(heap, n, esq(i), b + 1); // Imprime subÃ¡rvore esquerda
}

void construirHeapSubindo(int *heap, int n) {
     int i;  
     for (i = 2; i <= n; i++) // ComeÃ§a no filho Ã  esquerdo da raiz
         subir(heap, i); // Sobe o elemento
}

int ehHeapMaximo(int v[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int filhoEsq = esq(i);
        int filhoDir = dir(i);

        if (filhoEsq < n && v[i] < v[filhoEsq]) {
            return 0; // pai menor que filho esquerdo
        }

        if (filhoDir < n && v[i] < v[filhoDir]) {
            return 0; // pai menor que filho direito
        }
    }

    return 1; // É um heap de máximo
}

int main(void) {
    int heap[]= { 100, 50, 80, 20, 30, 70, 60}; // Vamos considerar um heap de inteiros
    int n = sizeof(heap) / sizeof(heap[0]); // Heap inicia com 0 elementos
    int i, m;
    
    // Exibe o vetor linear do heap
    for (i = 0; i < n; i++) printf("heap[%d] = %d\n", i, heap[i]);
    printf("\n");
  
    // Exibe o heap em formato de Ã¡rvore (bidimensional)
    imprimirHeap(heap, n, 0, 0);
    
    if (ehHeapMaximo(heap, n)) {
        printf("É um heap de máximo.\n");
    } else {
        printf("Não é um heap de máximo.\n");
    }
    
  return 0;
}
