#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INFINITO INT_MAX
#define NULO     -1

typedef struct node *link;

struct node {
    int destino;
    int peso;
    link next;
};

typedef struct {
    int numVertices;
    link *listaAdj;
} Grafo;

Grafo *criarGrafo(int numVertices) {
     Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
     grafo->numVertices = numVertices;
     grafo->listaAdj = (link*)malloc(numVertices * sizeof(link));
     for (int i = 0; i < numVertices; i++) 
         grafo->listaAdj[i] = NULL;
     return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
    link novo = (link)malloc(sizeof(struct node));
    novo->destino = destino;
    novo->peso = peso;
    novo->next = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novo;
}

void imprimirGrafo(Grafo *grafo) {
    printf("Grafo orientado (Vértices adjacentes):\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("Vértice %d: ", i);
        bool primeiro = true;
        link p = grafo->listaAdj[i];
        while (p != NULL) {
            if (!primeiro) printf(", ");
            printf("%d (peso %d)", p->destino, p->peso);
            primeiro = false;
            p = p->next;
        }
        printf("\n");
    }
}

void imprimeArvore(Grafo *grafo, int *pai) {
    printf("\nÁrvore de distâncias:\n");
    for (int i = 0; i < grafo->numVertices; i++) 
        if (pai[i] != NULO) 
            printf("Pai de %d é %d\n", i, pai[i]);
        else 
            printf("Pai de %d é ninguém\n", i);
} 

void inicializar(Grafo *grafo, int origem, int *distancia, int *pai, bool *visitado) {
    for (int i = 0; i < grafo->numVertices; i++) {
        distancia[i] = INFINITO;
        pai[i] = NULO; 
        visitado[i] = false;
    }
    distancia[origem] = 0;
}

void relaxa(int u, int v, int peso, int *distancia, int *pai) {
    if (distancia[u] != INFINITO && distancia[v] > distancia[u] + peso) {
       distancia[v] = distancia[u] + peso;
       pai[v] = u;
    }
}

typedef struct celula {
    int vertice;
    int distancia;
    struct celula *prox;
} Celula;

typedef Celula* FilaPrioridade;

FilaPrioridade inserirOrdenado(FilaPrioridade fila, int vertice, int distancia) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->vertice = vertice;
    nova->distancia = distancia;
    nova->prox = NULL;

    if (fila == NULL || distancia < fila->distancia) {
        nova->prox = fila;
        return nova;
    }

    Celula *atual = fila;
    while (atual->prox != NULL && atual->prox->distancia <= distancia) {
        atual = atual->prox;
    }

    nova->prox = atual->prox;
    atual->prox = nova;
    return fila;
}

FilaPrioridade removerMinimo(FilaPrioridade *fila) {
    if (*fila == NULL) return NULL;
    Celula *removido = *fila;
    *fila = (*fila)->prox;
    return removido;
}

void Dijkstra(Grafo *grafo, int origem) {
    int distancia[grafo->numVertices];
    int pai[grafo->numVertices];
    bool visitado[grafo->numVertices];
    FilaPrioridade fila = NULL;

    inicializar(grafo, origem, distancia, pai, visitado);
    fila = inserirOrdenado(fila, origem, 0);

    while (fila != NULL) {
        Celula *atual = removerMinimo(&fila);
        int u = atual->vertice;
        free(atual);

        if (visitado[u]) continue;

        visitado[u] = true;

        link p = grafo->listaAdj[u];
        while (p != NULL) {
            int v = p->destino;
            int peso = p->peso;

            if (distancia[v] > distancia[u] + peso) {
                distancia[v] = distancia[u] + peso;
                pai[v] = u;
                fila = inserirOrdenado(fila, v, distancia[v]);
            }

            p = p->next;
        }
    }

    printf("\nDistâncias a partir do vértice %d:\n", origem);
    for (int i = 0; i < grafo->numVertices; i++)
        printf("Distância do vértice %d até o vértice %d: %d\n", origem, i, distancia[i]);

    imprimeArvore(grafo, pai);
}

int main(void) {
    int numVertices = 5;

    Grafo* grafo = criarGrafo(numVertices);

    adicionarAresta(grafo, 0, 1, 10);    
    adicionarAresta(grafo, 0, 2, 5);
    adicionarAresta(grafo, 1, 2, 2);  
    adicionarAresta(grafo, 1, 3, 1);  
    adicionarAresta(grafo, 2, 1, 3);  
    adicionarAresta(grafo, 2, 3, 9);  
    adicionarAresta(grafo, 2, 4, 2);  
    adicionarAresta(grafo, 3, 4, 4);  
    adicionarAresta(grafo, 4, 0, 7);  
    adicionarAresta(grafo, 4, 3, 6);

    imprimirGrafo(grafo);

    Dijkstra(grafo, 0);

    return 0;
}
