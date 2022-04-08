//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo que define as funcoes da arvore
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


No* criar_no(char x, No *l, No *r) {
    No *no = (No*) malloc(sizeof(No));
    no->dado = x;
    no->esq = l;
    no->dir = r;
    return no;
}

void destruir_arvore(No **raiz){
    if (*raiz == NULL) return;
    destruir_arvore(&((*raiz)->esq));
    destruir_arvore(&((*raiz)->dir));
    free(*raiz);
    *raiz = NULL;
}

void pos_ordem(No *raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%c", raiz->dado); 
    }
}