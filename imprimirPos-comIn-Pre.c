#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int k = 0;
int procurar(char v[], int inicio, int fim, char valor){
    int i;
    for(i = inicio; i < fim; i++){
        if(v[i] == valor){
            return i;
        }
    }
    return i;
}

void imprimirPosOrdem(char* emOrdem, char* preOrdem, int inicio, int fim){
    k++;
    if(inicio > fim){
        return;
    }

    int i = procurar(emOrdem, inicio, fim, preOrdem[k]);

    imprimirPosOrdem(emOrdem, preOrdem, inicio, i - 1);
    imprimirPosOrdem(emOrdem, preOrdem, i + 1, fim);
    printf("%c", emOrdem[i]);
}

void imprimirPosOrdem(char* emOrdem, char* preOrdem, int inicio, int fim){
    k++;
    if(inicio > fim){
        return;
    }

    int i = procurar(emOrdem, inicio, fim, preOrdem[k]);

    imprimirPosOrdem(emOrdem, preOrdem, inicio, i - 1);
    imprimirPosOrdem(emOrdem, preOrdem, i + 1, fim);
    printf("%c", emOrdem[i]);
}

int main(){
    char emOrdem[100], preOrdem[100];
    scanf("%s%*c%s%*c", emOrdem, preOrdem);
    int t = strlen(emOrdem);
    imprimirPosOrdem(emOrdem, preOrdem, 0, t - 1);
    //scanf("%*c");
}