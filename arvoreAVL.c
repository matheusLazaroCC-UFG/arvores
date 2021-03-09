#include <stdio.h>
#include <stdlib.h>

/**
    Árvore AVL: árvore de busca binária balanceada,
    com relação à altura de suas subárvores.
*/

typedef struct no{
    int valor;
    struct no* esquerda;
    struct no* direita;
    int altura;
} no;

typedef no* ponteiroNo;

void imprimirArvore(ponteiroNo raiz){
    if(raiz != NULL){
        printf("%i", raiz->valor);
        printf("[");
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
        printf("]");
    }
}

int altura(ponteiroNo no){
    if(no == NULL){
        return 0;
    }
    return no->altura;
}

//Obter no max 2 inteiros
int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

ponteiroNo novoNo(int valor){
    ponteiroNo no = (struct no*)malloc(sizeof(struct no));

    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    no->altura = 1;
    return no;
}

ponteiroNo rotacionarDireita(ponteiroNo y){
    ponteiroNo x = y->esquerda;
    ponteiroNo t2 = x->direita;

    x->direita = y;
    y->esquerda = t2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

ponteiroNo rotacionarEsquerda(ponteiroNo x){
    ponteiroNo y = x->direita;
    ponteiroNo t2 = y->esquerda;

    y->esquerda = x;
    x->direita = t2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

int obterBalanco(ponteiroNo no){
    if(no == NULL){
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

ponteiroNo inserir(ponteiroNo no, int valor){
    if(no == NULL){
        return(novoNo(valor));
    }
    if(valor < no->valor){
        no->esquerda = inserir(no->esquerda, valor);
    }else
    if(valor > no->valor){
        no->direita = inserir(no->direita, valor);
    }else{
        return no;
    }

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanco = obterBalanco(no);

    if(balanco > 1 && valor < no->esquerda->valor){
        printf("Balanco: %d\n", balanco);
        printf("RotacionouDireita - %d\n", no->esquerda->valor); imprimirArvore(no);printf("\n");
        return rotacionarDireita(no);
    }

    if(balanco < -1 && valor > no->direita->valor){
        printf("Balanco: %d\n", balanco);

        printf("RotacionouEsquerda  - %d\n", no->direita->valor); imprimirArvore(no);printf("\n");
        return rotacionarEsquerda(no);
    }

    if(balanco > 1 && valor > no->esquerda->valor){
        printf("Balanco: %d\n", balanco);

        printf("RotacionouEsquerdaDireita - %d\n", valor); imprimirArvore(no);printf("\n");

        no->esquerda = rotacionarEsquerda(no->esquerda);
        return rotacionarDireita(no);
    }

    if(balanco < -1 && valor < no->direita->valor){
        printf("Balanco: %d\n", balanco);

        printf("RotacionouDireitaEsquerda - %d\n", valor); imprimirArvore(no); printf("\n");

        no->direita = rotacionarDireita(no->direita);
        return rotacionarEsquerda(no);
    }


    return no;
}

ponteiroNo valorMinimoNo(ponteiroNo no){
    ponteiroNo atual = no;

    while(atual->esquerda != NULL){
        atual = atual->esquerda;
    }

    return atual;
}

ponteiroNo deletarNo(ponteiroNo r, int valor){
    if(r == NULL){
        return r;
    }

    if(valor < r->valor){
        r->esquerda = deletarNo(r->esquerda, valor);
    }else
    if(valor > r->valor){
        r->direita = deletarNo(r->direita, valor);
    }else{
        if((r->esquerda == NULL) || (r->direita == NULL)){
            ponteiroNo temp;
            if(r->esquerda != NULL){
                temp = r->esquerda;
            }else{
                temp = r->direita;
            }

            if(temp == NULL){
                temp = r;
                r = NULL;
            }else{
                *r = *temp;
            }

            free(temp);
        }else{
            ponteiroNo temp = valorMinimoNo(r->direita);

            r->valor = temp->valor;

            r->direita = deletarNo(r->direita, temp->valor);
        }
    }

    if(r == NULL){
        return r;
    }


    r->altura = 1 + max(altura(r->esquerda), altura(r->direita));

    int balanco = obterBalanco(r);

    if(balanco > 1 && obterBalanco(r->esquerda) >= 0){
        return rotacionarDireita(r);
    }

    if(balanco > 1 && obterBalanco(r->esquerda) < 0){
        r->esquerda = rotacionarEsquerda(r->esquerda);
        return rotacionarDireita(r);
    }

    if(balanco < -1 && obterBalanco(r->direita) <= 0){
        return rotacionarEsquerda(r);
    }

    if(balanco < -1 && obterBalanco(r->direita) > 0){
        r->direita = rotacionarDireita(r->direita);
        return rotacionarEsquerda(r);
    }

    return r;
}


void preOrdem(ponteiroNo r){
    if(r != NULL){
        printf("%d ", r->valor);
        preOrdem(r->esquerda);
        preOrdem(r->direita);
    }
}

//Busca: exatamente como na arvore binaria



int main(){
    ponteiroNo r = NULL;

    /** teste inserir
    r = inserir(r, 10);
    r = inserir(r, 20);
    r = inserir(r, 30);
    r = inserir(r, 40);
    r = inserir(r, 50);
    r = inserir(r, 25);
    */

    r = inserir(r, 30);
    r = inserir(r, 23);
    r = inserir(r, 24);
    r = inserir(r, 25);
    r = inserir(r, 35);
    r = inserir(r, 26);


    printf("Travessia da pre-ordem do AVL construida: ");
    preOrdem(r);
    printf("\n");

    r = deletarNo(r, 10);

    printf("Travessia da pre-ordem depois de deletar o 10: ");
    preOrdem(r);
    imprimirArvore(r);
    scanf("%*c");
    return 0;
}