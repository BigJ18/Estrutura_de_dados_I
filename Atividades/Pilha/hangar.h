#ifndef HANGAR_H
#define HANGAR_H

// Definindo a estrutura do avião
typedef struct {
    char nome[50];
    int identificador;
    // Adicione outras características conforme necessário
} Aviao;

// Definindo a estrutura do hangar
typedef struct {
    Aviao *avioes;  // Array dinâmico para armazenar os aviões
    int capacidade; // Capacidade máxima do hangar
    int topo;       // Índice do topo da pilha
} Hangar;

// Inicializa o hangar com a capacidade especificada
void inicializarHangar(Hangar *hangar, int capacidade);

// Libera a memória alocada para o hangar
void destruirHangar(Hangar *hangar);

// Adiciona um avião ao hangar
void adicionarAviao(Hangar *hangar, Aviao aviao);

// Remove um avião do topo do hangar
void removerAviao(Hangar *hangar);

// Lista todos os aviões no hangar
void listarAvioes(Hangar *hangar);

// Lista as características do primeiro avião no hangar
void listarPrimeiroAviao(Hangar *hangar);

// Lista o número de aviões no hangar
int contarAvioes(Hangar *hangar);

// Remove um avião do hangar pela posição
void removerAviaoPorPosicao(Hangar *hangar, int posicao);

#endif // HANGAR_H
