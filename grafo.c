// Criado por: Diogo Bruno
// Data: 12/07/2025
// Comentado por: Diogo Bruno

#include <stdio.h>
#include <stdlib.h>

typedef struct aresta {
    int conteudo; 
    struct aresta *proximo;
} Aresta;

typedef struct vertice {
    int cont; 
    Aresta *adj; 
    struct vertice *prox; 
} Vertice;

// Função para criar um novo vértice
Aresta *criarAresta(int conteudo, Aresta *proximo) {
    Aresta *nova; 
    nova = malloc(sizeof(Aresta)); 
    nova->conteudo = conteudo;
    nova->proximo = proximo; 
    return nova;
}

// Função para criar um novo grafo
Vertice *criarVertice(int conteudo, Aresta *adj, Vertice *prox) {
    Vertice *novo; 
    novo = malloc(sizeof(Vertice));
    novo->cont = conteudo; //1
    novo->adj = adj; // NULL
    novo->prox = prox; // 
    return novo; 
}

// Função para adicionar uma aresta ao grafo
void adicionarAresta(Vertice *grafo, int origem, int destino) {
    Vertice *atual = grafo;

    while (atual != NULL && atual->cont != origem) {
        atual = atual->prox; 
    }
    if (atual == NULL) {
        printf("Vertice %d não encontrado.\n", origem); 
        return;
    }
    Aresta *nova = atual->adj; 
    atual->adj = criarAresta(destino, nova); 
}

// Buscar por vertice no grafo
int buscarAresta(Vertice *grafo, int conteudo) {
    while (grafo != NULL) {
        if (grafo->cont == conteudo ) { 
            printf("Vertice %d", conteudo); 
            Aresta *adj = grafo->adj;
            printf(" tem adjacentes:");
            if (adj == NULL) {
                printf(" Nenhum\n");
                return 0;
            }
            while (adj != NULL) { 
                printf(" -> %d", adj->conteudo); 
                adj = adj->proximo; 
            }
            printf("\n");
            return 1;
        }
        grafo = grafo->prox;
    }
    return 0;
}


int main(){
    Vertice *grafo = NULL;
    grafo = criarVertice(2, NULL, grafo);
    grafo = criarVertice(1, NULL, grafo);

    adicionarAresta(grafo, 1, 2);
    adicionarAresta(grafo, 1, 3);

    buscarAresta(grafo, 1);
    buscarAresta(grafo, 2);
}
