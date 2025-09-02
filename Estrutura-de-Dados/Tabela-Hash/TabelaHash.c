#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Aluno *link;

struct Aluno {
    int matricula; // NÃºmero de matrÃ­cula do aluno
    float cr; // Coeficiente de Rendimento
};

typedef struct Aluno *Hash; // Hash Ã© um vetor de ponteiros para structs do tipo Aluno

void inicializar(Hash *tab, int m) {
    int i;
    for (i = 0; i < m; i++) {
        tab[i] = NULL; // tab[i] Ã© um ponteiro para um struct Aluno
    }
}

int hash_linha(int mat, int m) {
    return mat % m; // MÃ©todo da divisÃ£o
}

int hash_duplo(int mat, int m){
    double c = (sqrt(5) - 1) / 2.0; // Constante de ouro
    return floor(m * (mat * c - floor(mat * c)));
}

int hash(int mat, int m, int k) {
    return (hash_linha(mat, m) + k * hash_duplo(mat,m)) % m; // Dispersão dupla
}

// FunÃ§Ã£o que busca uma matrÃ­cula em uma tabela hash com sondagem
// tab: tabela hash (vetor de ponteiros)
// m: tamanho da tabela hash
// mat: matrÃ­cula (chave) a ser buscada
// achou: ponteiro para inteiro que serÃ¡ alterado para 1 se a chave for encontrada, ou 0 caso contrÃ¡rio
// Retorna o Ã­ndice onde a chave foi encontrada ou, se nÃ£o foi encontrada, a primeira posiÃ§Ã£o livre
int buscar(Hash *tab, int m, int mat, int *achou) {
    *achou = 0; // Inicialmente assume que a chave nÃ£o foi encontrada
    int endereco = -1; // VariÃ¡vel para armazenar o endereÃ§o atual da sondagem
    int posicao_livre = -1; // Guarda a primeira posiÃ§Ã£o livre encontrada
    int k = 0; // Contador de tentativas de sondagem
    // Loop de sondagem com no mÃ¡ximo m tentativas (tabela cheia)
    while (k < m) {
        endereco = hash(mat, m, k); // Aplica a funÃ§Ã£o de hash com sondagem (k define a tentativa)
        if (tab[endereco] != NULL && tab[endereco]->matricula == mat) {
            *achou = 1; // Marca que encontrou a chave
            k = m; // ForÃ§aa saÃ­da do loop
        }
        else {
            if (tab[endereco] == NULL) {
                // Encontrou endereco livre
                // Registra a posiÃ§Ã£o livre se for a primeira encontrada
                if (posicao_livre == -1) {
                    posicao_livre = endereco;
                }
            }
            k = k + 1; // Incrementa k para tentar prÃ³xima posiÃ§Ã£o (sondagem)
        }
    }
    // Se a chave foi encontrada, retorna seu endereÃ§o
    // Caso contrÃ¡rio, retorna a primeira posiÃ§Ã£o livre encontrada (ou -1 se nÃ£o houver)
    if (*achou)
        return endereco;
    else 
        return posicao_livre;
}

/*
 * FunÃ§Ã£o inserir adiciona um novo aluno na tabela hash, caso a matrÃ­cula ainda nÃ£o exista.
 * Utiliza a funÃ§Ã£o buscar para encontrar uma posiÃ§Ã£o livre ou detectar duplicatas.
 * Em caso de duplicata ou tabela cheia, exibe mensagem e nÃ£o realiza a inserÃ§Ã£o.
 */
void inserir(Hash *tab, int m, int mat, float cr) {
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (!achou) {
        if (endereco != -1) {
            // NÃ£o encontrou a chave, mas encontrou posiÃ§Ã£o livre
            // InserÃ§Ã£o serÃ¡ realizada nessa posiÃ§Ã£o livre encontrada pela busca
            // tab[endereco] = alocar(mat, cr);
            tab[endereco] = (link) malloc(sizeof(struct Aluno));
            tab[endereco]->matricula = mat;
            tab[endereco]->cr = cr;            
        } else {
            // NÃ£o foi encontrada posiÃ§Ã£o livre durante a busca: overflow
            printf("A tabela estÃ¡ cheia. Ocorreu overflow. InsercÃ£o nÃ£o realizada! \n");
        }
    } else {
        printf("MatrÃ­cula jÃ¡ existe. InsercÃ£o invÃ¡lida! \n");
    }
}

/*
 * FunÃ§Ã£o remover assume que a busca retornarÃ¡ o endereÃ§o da chave a ser removida,
 * caso ela exista na tabela. A remoÃ§Ã£o Ã© feita liberando a memÃ³ria e marcando
 * a posiÃ§Ã£o como NULL. Caso a matrÃ­cula nÃ£o seja encontrada, nada Ã© feito.
 *
 */
void remover(Hash *tab, int m, int mat) {
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (achou) {
        // Remove
        free(tab[endereco]);
        tab[endereco] = NULL;
    } else {
        printf("MatrÃ­cula nÃ£o encontrada - RemoÃ§Ã£o nÃ£o realizada!\n");
    }
}

void imprimir(Hash *tab, int m) {
    int i, h;
    for (i = 0; i < m; i++) {
        h = i;
        if (tab[h] != NULL) {
            link p = tab[h];
            printf("tab[%d]:\tmat:%d\tcr:%.2f\n", h, p->matricula, p->cr);
        } else
          printf("tab[%d]:\n", h);
    }
}

int main(void) {
    int n, m;
    printf("Digite o valor de m (tamanho da tabela hash): ");
    scanf("%d", &m);
    printf("Digite o valor de n (quantidade de matriculas): ");
    scanf("%d", &n);

    Hash tab[m];
    inicializar(tab, m);
    imprimir(tab, m);

    int i, mat;
    float cr;
    for (i = 0; i < n; i++) {
        printf("Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &mat);
        printf("Digite o CR do aluno %d: ", i+1);
        scanf("%f", &cr);
        inserir(tab, m, mat, cr);
        imprimir(tab, m);
    }

    char resposta;

  do {
    printf("Digite a matricula que deseja procurar: ");
    scanf("%d", &mat);
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (achou == 0) printf("MatrÃ­cula nÃ£o encontrada!\n");
    else {
        link p = tab[endereco];
        printf("Encontrou mat = %d , cr = %.1f\n", p->matricula, p->cr);
    }
    printf("Quer procurar outra matrÃ­cula? (s/n) ");
    scanf(" %c", &resposta);
  } while ((resposta != 'N') && (resposta != 'n'));

  imprimir(tab, m);
  
    do {
        printf("Digite a matricula que deseja remover: ");
        scanf("%d", &mat);
        remover(tab, m, mat);
        imprimir(tab, m);
        printf("Quer remover outra matrÃ­cula? (s/n) ");
        scanf(" %c", &resposta);
    } while ((resposta != 'N') && (resposta != 'n'));

    return 0;
}