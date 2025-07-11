#include <stdio.h>
#include <stdlib.h>

struct no{
    char conteudo;
    struct no *sae;
    struct no *sad;
};
typedef struct no No;

// Árvore: Funções
// Criar:
No *criar(char c, No *e, No *d){
    No *Arv = malloc(sizeof(No));
    Arv -> conteudo = c;
    Arv -> sae = e;
    Arv -> sad = d;
    return Arv;
}

int buscar(No *a, char c){
    if (a == NULL){
        return 0;
    } else {
        return a -> conteudo == c || buscar(a -> sae, c) || buscar(a -> sad, c);
    }
}

int altura(No *a){
    if (a == NULL){
        return -1;
    } else{
        int esq = altura(a -> sae);
        int dir = altura(a -> sad);
        if (esq > dir){
            return esq + 1;
        } else {
            return dir + 1;
        }
    }
}

// Liberar(Excluir):
// Não Copiei no dia:

int main(){
    printf("Olá Mundo!");
}
