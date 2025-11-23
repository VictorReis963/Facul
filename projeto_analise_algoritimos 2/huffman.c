#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

// Estrutura de um nó 
typedef struct Node {
    unsigned char caractere;
    int freq;
    struct Node *esq, *dir;
} Node;

// Heap mínimo 
typedef struct {
    int tamanho;
    Node *dados[TAM];
} MinHeap;

// Função auxiliar 
Node* novo_node(unsigned char caractere, int freq) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->caractere = caractere;
    node->freq = freq;
    node->esq = node->dir = NULL;
    return node;
}

// Funções para manipular o heap
void trocar(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(MinHeap *heap, int i) {
    int menor = i, esq = 2*i + 1, dir = 2*i + 2;

    if (esq < heap->tamanho && heap->dados[esq]->freq < heap->dados[menor]->freq)
        menor = esq;
    if (dir < heap->tamanho && heap->dados[dir]->freq < heap->dados[menor]->freq)
        menor = dir;
    if (menor != i) {
        trocar(&heap->dados[i], &heap->dados[menor]);
        min_heapify(heap, menor);
    }
}

Node* extrair_min(MinHeap *heap) {
    Node* temp = heap->dados[0];
    heap->dados[0] = heap->dados[--heap->tamanho];
    min_heapify(heap, 0);
    return temp;
}

void inserir_heap(MinHeap *heap, Node *node) {
    int i = heap->tamanho++;
    heap->dados[i] = node;
    while (i && node->freq < heap->dados[(i-1)/2]->freq) {
        heap->dados[i] = heap->dados[(i-1)/2];
        i = (i-1)/2;
    }
    heap->dados[i] = node;
}

// Criação da arvore
Node* construir_arvore(int freq[]) {
    MinHeap heap = {0};

    for (int i = 0; i < TAM; i++) {
        if (freq[i])
            inserir_heap(&heap, novo_node(i, freq[i]));
    }

    while (heap.tamanho > 1) {
        Node *esq = extrair_min(&heap);
        Node *dir = extrair_min(&heap);
        Node *novo = novo_node('\0', esq->freq + dir->freq);
        novo->esq = esq;
        novo->dir = dir;
        inserir_heap(&heap, novo);
    }

    return extrair_min(&heap);
}

// Gerar binários
void gerar_codigos(Node *raiz, char *codigo, int nivel, char *tabela[TAM]) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
        codigo[nivel] = '\0';
        tabela[raiz->caractere] = strdup(codigo);
        return;
    }

    if (raiz->esq) {
        codigo[nivel] = '0';
        gerar_codigos(raiz->esq, codigo, nivel+1, tabela);
    }
    if (raiz->dir) {
        codigo[nivel] = '1';
        gerar_codigos(raiz->dir, codigo, nivel+1, tabela);
    }
}

// Compactador
void compactar(const char *texto) {
    int freq[TAM] = {0};
    for (int i = 0; texto[i]; i++)
        freq[(unsigned char)texto[i]]++;

    Node *raiz = construir_arvore(freq);

    char *tabela[TAM] = {0};
    char codigo[100];
    gerar_codigos(raiz, codigo, 0, tabela);

    printf("Texto compactado em Huffman:\n");
    for (int i = 0; texto[i]; i++)
        printf("%s", tabela[(unsigned char)texto[i]]);
    printf("\n");

    printf("\nTabela de códigos:\n");
    for (int i = 0; i < TAM; i++) {
        if (tabela[i])
            printf("'%c': %s\n", i, tabela[i]);
    }
}

// Descompactador
void descompactar(const char *codigo, Node *raiz) {
    printf("\nTexto descompactado:\n");
    Node *atual = raiz;
    for (int i = 0; codigo[i]; i++) {
        if (codigo[i] == '0')
            atual = atual->esq;
        else
            atual = atual->dir;

        if (!atual->esq && !atual->dir) {
            printf("%c", atual->caractere);
            atual = raiz;
        }
    }
    printf("\n");
}


int main() {
    const char *texto = "banana";

    printf("Texto original: %s\n", texto);
    compactar(texto);

    return 0;
}
