#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
typedef struct node {
    int item;
    struct node *esq, *dir;
} *link;

link novoNo(int item) {
    link n = (link)malloc(sizeof(struct node));
    n->item = item;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// ------------------ Fila com ponteiros ------------------

typedef struct celula {
    link no;
    struct celula *prox;
} *Celula;

typedef struct {
    Celula ini, fim;
} FILA;

void inicializaFila(FILA *f) {
    f->ini = f->fim = NULL;
}

int filaVazia(FILA *f) {
    return f->ini == NULL;
}

void enfileira(FILA *f, link no) {
    Celula nova = (Celula)malloc(sizeof(struct celula));
    nova->no = no;
    nova->prox = NULL;

    if (filaVazia(f)) {
        f->ini = f->fim = nova;
    } else {
        f->fim->prox = nova;
        f->fim = nova;
    }
}

link desenfileira(FILA *f) {
    if (filaVazia(f)) return NULL;

    Celula tmp = f->ini;
    link no = tmp->no;
    f->ini = tmp->prox;
    if (f->ini == NULL) f->fim = NULL;
    free(tmp);
    return no;
}
void percursoPorNivel(link raiz){
    if(raiz== NULL);
    FILA fila;
    inicializaFila(&fila);
    enfileira(&fila, raiz);

    while(!filaVazia(&fila)){
         link atual = desenfileira(&fila);
        printf("%d ", atual->item);

        if(atual->esq !=NULL){
            enfileira(&fila, atual->esq);
        }
        if(atual->dir !=NULL){
            enfileira(&fila, atual->dir);
        }
        
        }
    
}

int main() {
    /*
            Árvore exemplo:
                   10
                 /    \
                5      15
               / \    /  \
              3   7  12  18
    */
    link raiz = novoNo(10);
    raiz->esq = novoNo(5);
    raiz->dir = novoNo(15);
    raiz->esq->esq = novoNo(3);
    raiz->esq->dir = novoNo(7);
    raiz->dir->esq = novoNo(12);
    raiz->dir->dir = novoNo(18);

    printf("Percurso por nível (em largura): ");
    percursoPorNivel(raiz);
    printf("\n");

    return 0;
}