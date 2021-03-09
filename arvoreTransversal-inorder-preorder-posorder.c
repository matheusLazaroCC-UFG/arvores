#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no* esquerda;
    struct  no* direita;
};
/*
struct no* criarNo(int valor){
    struct no* no = (struct no*) malloc(sizeof(struct no));

    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}*/

struct no* criarNovoNo(int valor){
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->valor = valor;
    return novoNo;
}

struct no* adicionar(struct no* raiz, struct no* no){
    if(raiz == NULL){
        return no;
    }
    if(no->valor < raiz->valor){
        raiz->esquerda = adicionar(raiz->esquerda, no);
    }else{
        raiz->direita = adicionar(raiz->direita, no);
    }
    return raiz;
}

void imprimirPosOrdem(struct no* no){
    if(no == NULL){
        return;
    }
    imprimirPosOrdem(no->esquerda);
    imprimirPosOrdem(no->direita);
    printf(" %d", no->valor);
}

void imprimirPreOrdem(struct no* no){
    if(no == NULL){
        return;
    }
    printf(" %d", no->valor);
    imprimirPreOrdem(no->esquerda);
    imprimirPreOrdem(no->direita);
}

void imprimirEmOrdem(struct no* no){
    if(no == NULL){
        return;
    }
    imprimirEmOrdem(no->esquerda);
    printf(" %d", no->valor);
    imprimirEmOrdem(no->direita);
}

void exibirArvore(struct no* raiz){
    if(raiz != NULL){
        printf("%d", raiz->valor);
        printf("(");
        exibirArvore(raiz->esquerda);
        exibirArvore(raiz->direita);
        printf(")");
    }
}

int main(){
    int i, j;
    int t, n, valor;
    struct no* r = NULL;

    scanf("%d%*c", &t);

    for(i = 0; i < t; i++){
        scanf("%d%*c", &n);

        r = NULL;
        for(j = 0; j < n; j++){
            scanf("%d%*c", &valor);
            struct no* no = criarNovoNo(valor);
            r = adicionar(r, no);
        }
        //exibirArvore(r);

        printf("Case %d:\n", i + 1);
        printf("Pre.:");
        imprimirPreOrdem(r);
        printf("\n");

        printf("In..:");
        imprimirEmOrdem(r);
        printf("\n");

        printf("Post:");
        imprimirPosOrdem(r);
        printf("\n\n");
    }

    //scanf("%*c");
    return 0;

}
