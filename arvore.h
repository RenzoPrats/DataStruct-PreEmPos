//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo que define o prototipo das funcoes da arvore
# ifndef ARVORE_BINARIA_H
# define ARVORE_BINARIA_H

typedef struct no {
    char dado;
    struct no *esq, *dir;
} No;

//Funcoes
//cria um no na arvore
No* criar_no(char x, No *l, No *r);
//destroi a arvore
void destruir_arvore(No **raiz);
//imprime seguindo a regra de pos_ordem
void pos_ordem(No *raiz);

#endif