#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    char cor;
    struct no *esquerda, *direita, *pai;
} NO;
typedef NO* ponteiroNO;

void rotacionarEsquerda(ponteiroNO* r, ponteiroNO x){
    ponteiroNO y = x->direita;

    x->direita = y->esquerda;

    if(x->direita != NULL){
        x->direita->pai = x;
    }

    y->pai = x->pai;

    if(x->pai == NULL){
        *r = y;
    }else
    if(x == x->pai->esquerda){
        x->pai->esquerda = y;
    }else{
        x->pai->direita = y;
    }

    y->esquerda = x;
    x->pai = y;
}

void rotacionarDireita(ponteiroNO *r, ponteiroNO y){
    ponteiroNO x = y->esquerda;
    y->esquerda = x->direita;
    if(x->direita != NULL){
        x->direita->pai = y;
    }
    x->pai = y->pai;
    if(x->pai == NULL){
        *r = x;
    }else
    if(y == y->pai->esquerda){
        y->pai->esquerda = x;
    }else{
        y->pai->direita = x;
    }

    x->direita = y;
    y->pai = x;
}

void inserirFixarCima(ponteiroNO *r, ponteiroNO z){
    while(z != *r && z->pai->cor == 'V'){
        ponteiroNO y;
        
        if(z->pai = z->pai->pai->esquerda){
            y = z->pai->pai->direita;
        }else{
            y = z->pai->pai->esquerda;
        }
        
        if(y->cor == 'V'){
            y->cor = 'P';
            z->pai->cor = 'P';
            z->pai->pai->cor = 'V';
            z = z->pai->pai;
        }else{
            if(z->pai == z->pai->pai->esquerda && z == z->pai->esquerda){
                char cor = z->pai->cor;
                z->pai->cor = z->pai->pai->cor;
                z->pai->pai->cor = cor;
                rotacionarDireita(r, z->pai->pai);
            }
            
            if(z->pai == z->pai->pai->esquerda && z == z->pai->direita){
                char cor = z->cor;
                z->cor = z->pai->pai->cor;
                z->pai->pai->cor = cor;
                rotacionarEsquerda(r, z->pai);
                rotacionarDireita(r, z->pai->pai);
            }
            
            if(z->pai == z->pai->pai->direita && z == z->pai->direita){
                char cor = z->pai->cor;
                z->pai->cor = z->pai->pai->cor;
                z->pai->pai->cor = cor;
                rotacionarEsquerda(r, z->pai->pai);
            }

            if(z->pai == z->pai->pai->direita && z == z->pai->esquerda){
                char cor = z->cor;
                z->cor = z->pai->pai->cor;
                z->pai->pai->cor = cor;
                rotacionarDireita(r, z->pai);
                rotacionarEsquerda(r, z->pai->pai);
            }
        }
    }
    *r->cor = 'P';
}

void inserir(ponteiroNO *r, int valor){
    ponteiroNO z = (ponteiroNO)malloc(sizeof(NO));
    z->valor = valor;
    z->esquerda = NULL;
    z->direita = NULL;
    z->pai = NULL;

    if(*r == NULL){
        z->cor = 'P';
        *r = z;
    }else{
        ponteiroNO y = NULL;
        ponteiroNO x = *r;

        while(x != NULL){
            y = x;
            if(z->valor < x->valor){
                x = x->esquerda;
            }
        }
    }
}