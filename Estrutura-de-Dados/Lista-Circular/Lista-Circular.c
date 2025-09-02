// Exercicio 5 ADO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição do tipo link como ponteiro para struct node
typedef struct node *link;

// Definição da estrutura node
struct node {
  int item;
  link next;
  link prev;
};

// Função para inserir um item na lista circular com cabeça
void inserir(link lista, int novoItem) {
  link novoNode = (link)malloc(sizeof(struct node));
  novoNode->item = novoItem;

  link ultimo = lista->prev;

  // Inserção sempre após a cabeça
  novoNode->next = lista;
  novoNode->prev = ultimo;
  ultimo->next = novoNode;
  lista->prev = novoNode;
}

// Função para buscar um item na lista circular com cabeça
link buscar(link lista, int chave) {
  link p = lista->next; // Começa após o nó cabeça

  while (p != lista) { // Enquanto não voltar para a cabeça
    if (p->item == chave)
      return p; // Elemento encontrado
    p = p->next;
  }
  return NULL; // Elemento não encontrado
}

void alterar(link lista, int antigo, int novo) {
  link encontrado = buscar(lista, antigo);
  if (encontrado) {
    encontrado->item = novo;
    printf("Elemento %d alterado para %d.\n", antigo, novo);
  } else
    printf("Elemento %d não encontrado!\n", antigo);
}

// Função para remover um item da lista circular com cabeça
void remover(link lista, int chave) {
  link p = buscar(lista, chave);

  if (p) {
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
    printf("Elemento %d removido.\n", chave);
  } else
    printf("Elemento %d não encontrado!\n", chave);
}

// Função para imprimir a lista circular com cabeça
void imprimir(link lista) {
  if (lista->next == lista) { // Lista vazia
    printf("Lista Vazia\n");
    return;
  }

  link p = lista->next; // Começa após o nó cabeça
  printf("Lista: ");

  while (p != lista) { // Enquanto não voltar para a cabeça
    printf("%d <-> ", p->item);
    p = p->next;
  }
  printf("(circular)\n"); // Indica que é circular
}

int main(void) {
  int i, n, chave, chaveNova;
  link lista = (link)malloc(sizeof(struct node)); // Criar a cabeça da lista
  lista->next = lista;
  lista->prev = lista;

  printf("Quantidade de nós da lista: ");
  scanf("%d", &n);
  printf("\n");

  // Inserir n elementos (pseudo)aleatórios na lista
  srand((unsigned)time(NULL));

  for (i = 0; i < n; i++)
    inserir(lista, 1 + (rand() % 100));

  // Exibir os elementos da lista
  imprimir(lista);

  // Solicitar ao usuário um valor para buscar na lista
  printf("\nDigite o valor do elemento que deseja buscar: ");
  scanf("%d", &chave);

  // Buscar o elemento na lista ligada
  if (buscar(lista, chave) != NULL)
    printf("\nO elemento %d foi encontrado na lista!\n", chave);
  else
    printf("\nO elemento %d não foi encontrado na lista!\n", chave);

  // Solicitar ao usuário um valor para alterar na lista
  printf("\nDigite o valor do elemento que deseja alterar: ");
  scanf("%d", &chave);

  printf("\nDigite o novo valor do elemento que quer alterar: ");
  scanf("%d", &chaveNova);

  alterar(lista, chave, chaveNova);

  // Exibir os elementos da lista depois da alteração
  printf("\nLista depois da alteração:\n");
  imprimir(lista);

  // Solicitar ao usuário um valor para remover na lista
  printf("\nDigite o valor do elemento que deseja remover: ");
  scanf("%d", &chave);

  remover(lista, chave);

  // Exibir os elementos da lista depois da remoção
  printf("\nLista depois da remoção:\n");
  imprimir(lista);

  return 0;
}
