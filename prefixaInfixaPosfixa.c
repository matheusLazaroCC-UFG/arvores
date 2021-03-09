#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct no{
    char valor;
    struct no *esquerda;
    struct  no *direita;
} no;

char* adicionar(no** p, char* a){
    if(*a == '\0'){
        return '\0';
    }

    while(1){
        char* q = "null";
        if(*p == NULL){
            no* nox = (no*) malloc(sizeof(no));
            nox->valor = *a;
            nox->esquerda = NULL;
            nox->direita = NULL;
            *p = nox;
        }else{
            if(*a >= 'a' && *a <= 'z' || *a >= 'A' && *a <= 'Z' ){
                return a;
            }

            q = adicionar(&(*p)->esquerda, a+1);
            q = adicionar(&(*p)->direita, q+1);
            return q;fix(p->esquerda);
            posfix(p->direita);
            printf("%c ", p->valor);
        }
    }
        }
    }
}

void infix(no* p){
    if(p == NULL){
        return;
    }else{
        infix(p->direita);
        printf("%c ", p->valor);
        infix(p->direita);
    }
}

void posfix(no* p){
    if(p == NULL){
        return;
    }else{
        pos

int main(){
    int i, j, k;
    int t, numNos;
    char *prefixo, *infixo;


    scanf("%d%*c", &t);

    for(i = 0; i < t; i++){
        scanf("%d%*c", &numNos);


        prefixo = (char*) malloc(sizeof(char*) * numNos);
        infixo = (char*) malloc(sizeof(char*) * numNos);
        scanf("%s%*c", prefixo);
        scanf("%s%*c", infixo);

        no* r = NULL;
        adicionar(&r, prefixo);

        printf("Posfixo: ");
        posfix(r);

    }

    scanf("%*c");
    return 0;
}