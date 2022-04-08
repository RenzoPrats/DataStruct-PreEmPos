//aluno: Renzo Prats Silva Souza   matricula: 11921ECP004
//arquivo com a funcao main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

// declarando prototipo da funcao criar_arvore que vai receber o vetor in-ordem,
//o vetor pre-ordem, o indice de inicio(0) e o indice de fim(tamanho-1) e o ponteiro k
// que ira apontar para um inteiro(0) e vai ser acrescentado toda vez que a funcao for chamada
No *criar_arvore(char in[], char pre[], int comeco, int fim, int *k);

int main() {
    // declarando as variaveis c que representa o tanto de caso de testes, e n o numero de nos da arvore
    int c, n;
    //declarando o ponteiro k e atribuindo o valor de z a k
    int *k;
    int z = 0;
    k = &z;

    //recebe a quantidade de casos de teste
    scanf("%d", &c);

    //para cada caso de teste
    for(int i = 0; i < c; i++){
        
        //recebe a quantidade de nos
        scanf("%d", &n);
        //declarando dinamicamente os vetores pre e in
        char *pre = (char *) malloc(n * sizeof(char));
        char *in = (char *) malloc(n * sizeof(char));
        //atribuindo valores aos vetores pre e in
        scanf("%s", pre);
        scanf("%s", in);

        //criando a arvore usando a funcao criar_arvore
        No *T = criar_arvore(in, pre, 0, n-1, k);
        
        //imprimindo pos-ordem da arvore criada
        pos_ordem(T);
        printf("\n");
        
        //destruindo a arvore
        destruir_arvore(&T);
        
        //limpando a memoria alocada dinamicamente
        free(pre);
        free(in);
        
        //redefinindo o valor de k para 0
        *k = 0;
    }
    return 0;
}

//a ideia de funcao e que o percurso pre-ordem sempre tem inicio na raiz da arvore
//podemos entao adicionar essa raiz na arvore e utilizando o percurso in-ordem
//encontrar onde esta essa raiz e fazer essa mesma chamada para parte esquerda e direita utilizando recursao
No *criar_arvore(char in[], char pre[], int comeco, int fim, int *k){
    //se o indice de inicio for maior que o indice de fim, nao ha mais como continuar retorna null
    //e termina a recursao atual
    if (comeco > fim)
        return NULL;

    //pega o valor da raiz utilizando o percurso pre ordem
    char no_raiz = pre[*k];

    //adiciona o valor de k, que serve como indice para pegar a raiz do percurso pre ordem
    (*k)++;

    //cria um novo no que contem o valor da raiz do atual no_raiz
    No *novo_no = criar_no(no_raiz, NULL, NULL);

    //nao ha nenhum filho(e uma folha), nao continua a recursao e retorna o no atual
    if(comeco == fim){
        return novo_no;
    }

    //percorre o vetor in ordem e procura a posicao da raiz do no atual
    int index = 0;
    for(int y = comeco; y <= fim; y++){
        if(in[y] == no_raiz){
            index = y;
        }
    }
    
    //chama recursivamente a parte esquerda passando o atual subvetor da in-ordem
    novo_no->esq = criar_arvore(in, pre, comeco, index-1, k);
    //chama recursivamente a parte direita passando o atual subvetor da in-ordem
    novo_no->dir = criar_arvore(in, pre, index+1, fim, k);

    //retorna o atual no criado para a chamada da funcao
    return novo_no;
}