#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 10

// Definição da estrutura do nó da tabela de dispersão
struct Nodo {
    char chave[50];
    int valor;
    struct Nodo* proximo;
};

// Definição da estrutura da tabela de dispersão
struct TabelaHash {
    struct Nodo* tabela[TAMANHO_TABELA];
};

// Função para calcular o índice hash de uma chave
int calcularIndiceHash(char chave[]) {
    int soma = 0;
    for (int i = 0; i < strlen(chave); i++) {
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

// Função para inicializar a tabela de dispersão
void inicializarTabela(struct TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->tabela[i] = NULL;
    }
}

// Função para inserir um elemento na tabela de dispersão
void inserir(struct TabelaHash* tabela, char chave[], int valor) {
    int indice = calcularIndiceHash(chave);

    struct Nodo* novoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    strcpy(novoNodo->chave, chave);
    novoNodo->valor = valor;
    novoNodo->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novoNodo;
}

// Função para buscar um elemento na tabela de dispersão
int buscar(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceHash(chave);

    struct Nodo* atual = tabela->tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->valor;
        }
        atual = atual->proximo;
    }

    return -1; // Valor de sentinela indicando que a chave não foi encontrada
}

// Função para remover um elemento da tabela de dispersão
void remover(struct TabelaHash* tabela, char chave[]) {
    int indice = calcularIndiceHash(chave);

    struct Nodo* atual = tabela->tabela[indice];
    struct Nodo* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                // Remover o primeiro elemento da lista
                tabela->tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

// Função para imprimir a tabela de dispersão
void imprimirTabela(struct TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("Índice %d: ", i);
        struct Nodo* atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("(%s, %d) ", atual->chave, atual->valor);
            atual = atual->proximo;
        }
        printf("\n");
    }
}

int main() {
    // Inicializando a tabela de dispersão
    struct TabelaHash minhaTabela;
    inicializarTabela(&minhaTabela);

    // Inserindo elementos na tabela
    inserir(&minhaTabela, "chave1", 42);
    inserir(&minhaTabela, "chave2", 17);
    inserir(&minhaTabela, "chave3", 99);

    // Imprimindo a tabela
    printf("Tabela de dispersão após inserção:\n");
    imprimirTabela(&minhaTabela);

    // Buscando elementos na tabela
    printf("\nBuscando 'chave2': %d\n", buscar(&minhaTabela, "chave2"));
    printf("Buscando 'chave4': %d\n", buscar(&minhaTabela, "chave4"));

    // Removendo elementos da tabela
    remover(&minhaTabela, "chave1");

    // Imprimindo a tabela após a remoção
    printf("\nTabela de dispersão após remoção:\n");
    imprimirTabela(&minhaTabela);

    return 0;
}
