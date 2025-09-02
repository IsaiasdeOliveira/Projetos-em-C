#include <stdio.h>
#include <stdlib.h>

//Arvore Balanciada

typedef struct node *link;

struct node{
int chave;
int altura;
link esq;
link dir;
};

int altura(link no) {
    if (no == NULL) return 0;
    return no->altura;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
link novoNo(int chave) {
    link no = (link)malloc(sizeof(struct node));
    no->chave = chave;
    no->esq = no->dir = NULL;
    no->altura = 1;
    return no;
}
int fatorBalanceamento(link no) {
    if (no == NULL) return 0;
    return altura(no->esq) - altura(no->dir);
}

link RotacaoDireita(link p){
    link u;
    u= p->esq;
    p->esq= u->dir;
    u->dir= p;

    p->altura= max(altura(p->esq), altura(p->dir)) +1;
    u->altura= max(altura(p->esq), p->altura) +1;

    return u;
}
link RotacaoEsquerda(link p){
    link z;
    z= p->dir;
    p->dir= z->esq;
    z->esq= p;

    p->altura= max(altura(p->esq), altura(p->dir)) +1;
    z->altura= max(p->altura, altura(p->dir)) +1;

    return z;
}
link RotacaoDireitaEsquerda(link p){
    p->dir= RotacaoDireita(p->dir);
    return RotacaoEsquerda(p);
}
link RotacaoEsquerdaDireita(link p){
    p->esq= RotacaoEsquerda(p->esq);
    return RotacaoDireita(p);
}

link Balanciar (link raiz){
    short fb= fatorBalanceamento(raiz);
    if(fb <-1 ){
        if(fatorBalanceamento(raiz->dir)<=0) 
          raiz= RotacaoEsquerda(raiz);
        else
          raiz= RotacaoDireitaEsquerda(raiz);
    }
    else if(fb >1){
        if(fatorBalanceamento(raiz->esq)>=0) 
          raiz= RotacaoDireita(raiz);
        else
        raiz= RotacaoEsquerdaDireita(raiz);
    } 
    return raiz;
}
link Inserir( link raiz, int x){
    if(raiz== NULL){
        link novoNode= (link) malloc(sizeof(struct node));
        novoNode->chave= x;
        novoNode->esq= NULL;
        novoNode->dir= NULL;
        novoNode->altura= 0;
        return novoNode;
    }
    if(x < raiz->chave){
        raiz->esq= Inserir(raiz->esq, x);
    }
    else{
        raiz->dir= Inserir(raiz->dir, x);
    }
    raiz->altura= max(altura(raiz->esq), altura(raiz->dir)) +1;

    raiz= Balanciar(raiz);
    return raiz;
}

link Remover(link raiz, int valor) {
    if (raiz == NULL) {
        printf("Valor %d nao encontrado!\n", valor);
        return NULL;
    }

    if (valor < raiz->chave)
        raiz->esq = Remover(raiz->esq, valor);
    else if (valor > raiz->chave)
        raiz->dir = Remover(raiz->dir, valor);
    else {
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esq != NULL && raiz->dir != NULL) {
            link aux = raiz->esq;
            while (aux->dir != NULL)
                aux = aux->dir;
            raiz->chave = aux->chave;
            raiz->esq = Remover(raiz->esq, aux->chave);
        }
        else {
            link aux = (raiz->esq != NULL) ? raiz->esq : raiz->dir;
            free(raiz);
            return aux;
        }
    }

    raiz->altura = max(altura(raiz->esq), altura(raiz->dir)) + 1;
    return Balanciar(raiz);
}

void Imprimir(link raiz, int nivel) {
    if (raiz != NULL) {
        Imprimir(raiz->dir, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("   ");
        printf("%d\n", raiz->chave);
        Imprimir(raiz->esq, nivel + 1);
    }
}

int main() {
    link raiz = NULL;

    raiz = Inserir(raiz, 10);
    raiz = Inserir(raiz, 20);
    raiz = Inserir(raiz, 30);
    raiz = Inserir(raiz, 40);
    raiz = Inserir(raiz, 50);
    raiz = Inserir(raiz, 25);

    printf("Árvore AVL:\n");
    Imprimir(raiz, 0);

    raiz = Remover(raiz, 30);
    printf("\nDepois de remover 30:\n");
    Imprimir(raiz, 0);

    return 0;
}
