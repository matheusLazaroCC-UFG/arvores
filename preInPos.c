#include <stdio.h>
#include <stdlib.h>
int k;
typedef struct no{
    char valor;
    struct no* esquerda;
    struct no* direita;
} no;
typedef no* ponteiroNo;


ponteiroNo criarNovoNo(char valor){
    ponteiroNo novoNo = (ponteiroNo)malloc(sizeof(no));
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->valor = valor;
    return novoNo;
}

int buscar(char v[], int inicio, int fim, char valor){
    int i;
    for(i = inicio; i <= fim; i++){
        if(v[i] == valor){
            return i;
        }
    }
    return -1;
}

ponteiroNo f(char* emOrdem, char* preOrdem, int inicio, int fim){
    if(inicio > fim){
        return NULL;
    }

    ponteiroNo novoNo = criarNovoNo(preOrdem[k++]);

    if(inicio == fim){
        return novoNo;
    }

    int indice = buscar(emOrdem, inicio, fim, novoNo->valor);

    novoNo->esquerda = f(emOrdem, preOrdem, inicio, indice - 1);

    novoNo->direita = f(emOrdem, preOrdem, indice + 1, fim);

    return novoNo;
}

void imprimirPosOrdem(ponteiroNo no){
    if(no == NULL){
        return;
    }
    imprimirPosOrdem(no->esquerda);
    imprimirPosOrdem(no->direita);
    printf("%c", no->valor);
}



void imprimirArvore(ponteiroNo raiz){
    if(raiz != NULL){
        printf("%c", raiz->valor);
        printf("[");
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
        printf("]");
    }
}


int main(){
    int i, j;
    int t, numNos;
    char *preOrdem, *emOrdem;

    scanf("%d%*c", &t);

    for(i = 0; i < t; i++){
        scanf("%d%*c", &numNos);
        preOrdem = (char*) malloc(sizeof(char*) * numNos);
        emOrdem = (char*) malloc(sizeof(char*) * numNos);

        scanf("%s%*c", preOrdem);
        scanf("%s%*c", emOrdem);
        k = 0;
        numNos--;
        ponteiroNo r = f(emOrdem, preOrdem, k, numNos);

        //imprimirArvore(r);
        imprimirPosOrdem(r);
        printf("\n");
    }

    //scanf("%*c");
    return 0;
}
