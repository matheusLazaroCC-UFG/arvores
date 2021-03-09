/**                                             Árvores
 * Árvores
        Estrutura de dados composta de um nó chamado raiz, abaixo
    do qual estão as subárvores que compõem essa árvore.
    Cada nó possui um nó pai, exceto o nó raiz que não possui pai.
        O número de subárvores de cada nó (analogamente, o número
    de filhos de um nó) é chamado de grau desse nó.
        O grau máximo permitido para uma árvore identifica o tipo de
    árvore (binária, ternária, etc).
    Nós que não possuem filhos são chamados de folhas.
    Nós abaixo de um determinado nó são seus descendentes
        O nível do nó raiz é 0.
        A altura h de um nó é o comprimento do caminho mais longo
    entre ele e uma folha.
        A altura de uma árvore é a altura do nó raiz.
        A altura de um nó pode ser calculada como sendo 1 mais o
    máximo entre a altura de seus filhos.

Árvores Binárias
        Uma árvore binária é uma árvore em que, abaixo de cada nó,
    existem no máximo duas subárvores (cada nó terá, no
    máximo, dois filhos).
 */


/**             Árvores Binárias de Pesquisa
 *
 *
 *  Uma árvore binária de pesquisa é uma árvore binária
        em que, a cada nó, todos os registros com chaves
        menores que a deste nó estão na subárvore
        da esquerda, enquanto
        que os registros com
        chaves maiores estão na
        subárvore da direita.
    Para nossa árvore binária de pesquisa, veremos as
        seguintes funções:
        Inicialização da árvore
        Inserção de um elemento
        Busca de um elemento
        Contagem do número de elementos
        Leitura da árvore
        Remoção de um elemento
 *
 * */
/**	Iniciação da árvore*/
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
    TIPOCHAVE chave;
    /* Dados armazenados vão aqui */
    struct aux *esq, *dir;
} NO;
typedef NO* PONT;
/**     Para representarmos nossa árvore, precisaremos tão
            somente do endereço do nó raiz.
            E para inicializarmos a
            árvore basta tornarmos
            esse endereço null
 */
PONT inicializa() {
    return(NULL);
}
int main() {
    PONT r = inicializa();
}

/**	Inserção de um elemento
 *  Vamos supor que não permitimos duplicação de chaves.
        Caso permitamos, basta definir uma política.
        Por exemplo: chaves ≤ à de um determinado nó
        ficam na subárvore à esquerda deste.
        Como então inserimos um elemento (um nó) na árvore?

    Se a raiz for null, inserimos lá
    Senão:
    Se a chave do elemento a ser inserido for menor que
    a da raiz:
    Insere na subárvore da esquerda
    Senão:
    Insere na subárvore da direita

    Note que essa versão é recursiva
        Se a raiz for null, inserimos lá
        Senão:
        Se a chave do elemento a ser
        inserido for menor que a da raiz:
        Insere na subárvore da
        esquerda
        Senão:
        Insere na subárvore da
        direita
 */
PONT adiciona(PONT raiz, PONT no){
    if (raiz == NULL)
        return(no);
    if (no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);
    //ignoro chave igual
    return(raiz);
}
PONT criaNovoNo(TIPOCHAVE ch) {
    PONT novoNo = (PONT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}
/** Usando no código:*/
int main() {
    PONT r = inicializa();
    PONT no = criaNovoNo(23);
    r = adiciona(r,no);
}

/**	Busca de um elemento
 *  Em uma Árvore de Busca Binária, agimos como na
busca binária em um arranjo. Ex: contem(12)
    Primeiro olhamos a raiz:
Se for 12, achamos
Se for > 12 olhamos na
subárvore da esquerda
Senão olhamos na da
direita
 E como fica o código para isso?

 * */
PONT contem(TIPOCHAVE ch, PONT raiz){
    if (raiz == NULL)
        return(NULL);
    if (raiz->chave == ch)
        return(raiz);
    if (raiz->chave>ch)
        return(contem(ch,raiz->esq));
    return(contem(ch,raiz->dir));
}
...
int main(){
    ...
    PONT p = contem(12,r);
}


/**	Contagem do número de elementos
 * Existem várias maneiras de se percorrer uma árvore
        binária, em geral envolvendo 3 elementos:
        O nó raiz
        A subárvore à esquerda de cada nó
        A subárvore à direita de cada nó
    Algumas possibilidades são
        Subárvore esquerda – raiz – subárvore direita
        Subárvore direita – raiz – subárvore esquerda
        Raiz – subárvore esquerda – subárvore direita
        ...
    Em relação a árvores binárias de pesquisa, uma ordem
        bastante útil é subárvore esquerda – raiz – subárvore
        direita
        Também chamada de inorder traversal, varredura
        infixa, ou varredura central
        Nessa varredura, os nós são visitados na ordem
        crescente das chaves de busca
 * */
int numeroNos(PONT raiz){
    if (!raiz )
        return 0;
    return(numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}
...
int main(){
    PONT r = inicializa();
    //...Colocar alguns elementos
    printf("%d\n",numeroNos(r));
}



/**	Leitura da árvore
 * Para imprimir a árvore, pode ser conveniente usarmos a
    ordem raiz – subárvore esquerda – subárvore direita
 * */
void exibirArvore(PONT raiz){
    if (raiz != NULL) {
        printf("%i",raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}
/**	Remoção de um elemento
 * Problemas na remoção de um nó:
        Temos que lidar com as subárvores desse nó
    A árvore resultante deve continuar sendo de busca
    Nós da subárvore da esquerda têm chave menor
    que a do nó raiz
    Nós da subárvore da direita têm chave maior que a
    do nó raiz

    Como fazer?
        Se o nó a ser retirado possui no máximo um
    descendente, substitua-o por este
    Se o nó possuir 2 descendentes, substituímos o nó a
    ser retirado pelo nó mais à direita da subárvore da
    esquerda
    Alternativamente, substituímos o nó a ser retirado
    pelo nó mais à esquerda da subárvore da direita

    Vamos então fazer um método auxiliar:
        Busca binária não recursiva.
            Devolve o ponteiro do nó buscado.
            Abastece pai com o ponteiro para o nó pai deste
*/
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai){
    PONT atual = raiz;
    *pai = NULL;
    while (atual) {
        if(atual->chave == ch) return(atual);
        *pai = atual;
        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return(NULL);
}

PONT removeNo(PONT raiz, TIPOCHAVE ch){
    PONT pai, no, p, q;
    no = buscaNo(raiz,ch,&pai);
    if (no==NULL)
        return(raiz);
    if (!no->esq || !no->dir ) {
        if (!no->esq)
            q = no->dir;
        else
            q = no->esq;
    }
    else {
        p = no;
        q = no->esq;
        while (q->dir) {
            p = q;
            q = q->dir;
        }
        if (p != no) {
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai) {
        free(no);
        return(q);
    }
    if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;
    free(no);
    return(raiz);
}

















