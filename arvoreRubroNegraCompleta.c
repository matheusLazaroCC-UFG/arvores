#include <stdio.h>
#include <stdlib.h>

#define sucesso 0
#define falha 1
#define elementoDuplicado 2

//(1)
typedef enum {
    vermelho,
    preto,
    invalido
}cor;

//(2)
typedef struct no {
    int valor;
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    cor cor;
    int nosNaSub;
    int nosNaSubVermelho;
} structNo;


/**
** Cria e retorna o nó
**/
int criarstructNoNo(structNo** noCriado, int valor);

/**
** Pesquisar a chave na arvore
** Se um no com mesmo valor for encontrado, o retorna.
** Senão, retorna o último no visitado
**/
structNo* buscarNoValor(structNo* no, int chave);

/**
** Insere o novo no na posição apropriada
** Retorna sucesso ou falha
 * O algoritmo de inserção tem 2 principais casos, que dependem
    da cor do nó tio.
**/
int inserirNo(structNo* no, structNo* novoNo);

/**
    - Caso 1: Se o nó tio for NULL ou a cor do nó tio for preto,
    recolorimos e rotacionamos.
 */
void inserirCaso1 (structNo* avo, structNo* noPai, structNo* chaveNo);

/**
 * - Caso 2: Caso contrário, recolorimos e repetimos o ciclo até obtermos
    o equilíbrio.
 */
void inserirCaso2 (structNo* avo, structNo* tio, structNo* noPai, structNo* chaveNo);


/**
** Retorna a altura do no fornecido
**/
int alturaNo(structNo* no);


/**
** Retorna a altura preta da arvore
**/
int alturaPreto(structNo* no);

/**
** Retorna o no anterior, se existente
**/
structNo* noAnterior(structNo* no);

/**
** Retorna o no sucessor, se existente
**/
structNo* noSucessor(structNo* no);

/**
** Rotações da arvore: utiliza o mecanismo de rotação local
 * da árvore rubro negra
**/
void rotacionarDireita (structNo* raiz, structNo* pivo);

void rotacionarEsquerda (structNo* raiz, structNo* pivo);

/**
** Casos de Rotação
**/
void casoEsquerdaEsquerda(structNo* raiz, structNo* pivo);

void casoDireitaDireita(structNo* raiz, structNo* pivo);

void casoEsquerdaDireita(structNo* raiz, structNo* pivo);

void casoDireitaEsquerda(structNo* raiz, structNo* pivo);




/**
** Retorna o valor maximo, dado dois valores
**/
int max(int valor1, int valor2);

/**
 * Atualiza a quantidade de nós da subárvore do nó passado por referência,
 * com o valor a ser atualizado.
 */
void atualizarContagemNo(structNo* no, int valorAtualizar);

/**
 * Atualiza a quantidade de nós varmelhos da subárvore do nó passado
 * por referência, com o valor a ser atualizado.
 */
void atualizarContagemNoVermelho(structNo* no, int valorAtualizar);

/**
** Imprimir a arvore transversal
** 1. Inorder
** 2. Preorder
** 3. Postorder
**/
void imprimirEmOrdem(structNo* no);
void imprimirPreOrdem(structNo* no);
void imprimirPosOrdem(structNo* no);

void imprimirArvore(structNo* no);


/**
** Recebe como entrada o no a ser excluido
** Dividido em subcasos
**/
int removerNo(structNo* no);

void removerCasos(structNo* noPai, structNo* irmao);

void removerCaso1_1(structNo* noPai, structNo* irmao);

void removerCaso1_2(structNo* noPai, structNo* irmao);

void removerCaso2_1_1(structNo* noPai, structNo* irmao);

void removerCaso2_1_2(structNo* noPai, structNo* irmao);

void removerCaso2_2_1(structNo* noPai, structNo* irmao);

void removerCaso2_2_2(structNo* noPai, structNo* irmao);


structNo* noRaiz;

int main() {
    int opType, valor;
    structNo* result;
    int status;
    noRaiz = NULL;

    while(1) {
        printf("########## ARVORE RUBRO-NEGRA ##########\n");
        printf("0: procurar valor\n");
        printf("1: inserir\n");
        printf("2: remover\n");
        printf("3: imprimir arvore\n");
        printf("4: imprimir inorder\n");
        printf("5: imprimir preorder\n");
        printf("6: imprimir postorder\n");
        printf("-1: Sair\n");
        scanf("%d", &opType);
        if(opType == -1){
            break;
        }
        switch(opType) {

            case 0:
                printf("Digite um valor para procurar na arvore: ");
                scanf("%d", &valor);

                result = buscarNoValor(noRaiz, valor);

                if (result == NULL)
                    printf("%d valor nao valido\n", valor);

                else if (result->valor != valor)
                    printf("%d valor nao encontrado\n", valor);
                else
                    printf("%d valor encontrado\n", valor);

                break;

            case 1:
                printf("Digite um valor para inserir na arvore: ");
                scanf("%d",&valor);
                status = criarstructNoNo (&result, valor);
                if (status == falha) {
                    printf("Nao foi possivel criar o no\n");
                    continue;
                }
                status = inserirNo(noRaiz, result);

                if (status == elementoDuplicado || status == falha) {
                    printf("Valores duplicados não permitidos %d\n", valor);
                    continue;
                }
                printf("%d no inserido\n", valor);
                break;

            case 2:
                printf("Digite um valor para remover na arvore: ");
                scanf("%d", &valor);

                result = buscarNoValor(noRaiz, valor);

                if (result == NULL || result->valor != valor)
                    printf("%d este no nao existe na arvore\n", valor);

                else {

                    status = removerNo(result);

                    if(status == sucesso)
                        printf("%d excluido\n", valor);
                    else
                        printf("Erro ao excluir %d\n", valor);

                }
                break;
            case 3:
                printf("Representacao da arvore: \n");
                imprimirArvore(noRaiz);
                printf("\n");
                break;
            case 4:
                printf("Representacao inorder: \n");
                imprimirEmOrdem(noRaiz);
                printf("\n");
                break;
            case 5:
                printf("Representacao preorder: \n");
                imprimirPreOrdem(noRaiz);
                printf("\n");
                break;
            case 6:
                printf("Representacao postorder: \n");
                imprimirPosOrdem(noRaiz);
                printf("\n");
                break;
        }
        printf("\n\n\n");
    }

    //printf("In-order\n");
    //inOrder(noRaiz);
    //printf("Pre-order\n");
    //preOrder(noRaiz);
    //printf("Numero de nos: %d\n", noRaiz->nosNaSub);
    //printf("Altura da arvore: %d \n", alturaNo(noRaiz));
    //imprimirArvore(noRaiz);

    //scanf("%*c");
    //scanf("%*c");
    return sucesso;
}








int criarstructNoNo(structNo** noCriado, int valor) {
    structNo* temp = (structNo*)calloc(sizeof(structNo), 1);

    if (temp == NULL) {
        printf("Erro ao criar no\n");
        return falha;
    }

    temp->valor = valor;
    temp->pai = NULL;
    temp->esquerda = NULL;
    temp->direita = NULL;

    temp->cor = invalido;
    temp->nosNaSub = 1;
    temp->nosNaSubVermelho = 1;
    (*noCriado) = temp;

    return sucesso;
}

structNo* buscarNoValor(structNo* no, int chave) {
    if (no == NULL){
        return NULL;
    }
    if (no->valor == chave){
        return no;
    }else
    if(no->valor < chave && no->direita != NULL){
        return buscarNoValor(no->direita, chave);
    }else
    if (no->valor > chave && no->esquerda != NULL){
        return buscarNoValor(no->esquerda, chave);
    }else{
        return no;
    }

    return NULL;
}

int max(int valor1, int valor2) {
    if(valor1 > valor2){
        return valor1;
    }else{
        return valor2;
    }
}

int alturaNo(structNo* no) {
    if (no == NULL){
        return 0;
    }

    if (no->esquerda == NULL && no->direita == NULL){
        return 0;
    }

    return (1 + max(alturaNo(no->esquerda), alturaNo(no->direita)));
}

int alturaPreto(structNo* no) {
    int altura = 0;

    if (no == NULL){
        return altura;
    }

    if (no->cor == preto) {
        altura = 1;
    }else{
        altura = 0;
    }

    if (no->esquerda != NULL){
        return altura + alturaPreto(no->esquerda);
    }else
    if (no->direita != NULL){
        return altura + alturaPreto(no->direita);
    }else{
        return altura;
    }
}

structNo* noAnterior(structNo* no) {
    if(no->esquerda != NULL) {
        no = no->esquerda;

        while ( no->direita != NULL) {
            no = no->direita;
        }

        return no;
    }else
    if ( no->pai != NULL) {
        if (no->pai->direita == no){
            no = no->pai;
        }else{
            while (no->pai->esquerda == no) {
                no = no->pai;
            }

            no = no->pai;
        }

        return no;
    }

    return NULL;
}

structNo* noSucessor(structNo* no) {
    if (no->direita != NULL) {
        no = no->direita;

        while (no->esquerda != NULL) {
            no = no->esquerda;
        }

        return no;
    }else
    if ( no->pai != NULL) {
        if (no->pai->esquerda == no) {
            no = no->pai;
        }else {
            while (no->pai->direita == no) {
                no = no->pai;
            }

            no = no->pai;
        }

        return no;
    }

    return NULL;
}

void atualizarContagemNo(structNo* no, int valorAtualizar) {
    no->nosNaSub = no->nosNaSub + valorAtualizar;

    if (no->pai != NULL){
        atualizarContagemNo(no->pai, valorAtualizar);
    }
}

void atualizarContagemNoVermelho(structNo* no, int valorAtualizar) {
    no->nosNaSubVermelho += valorAtualizar;

    if (no->pai != NULL){
        atualizarContagemNoVermelho(no->pai, valorAtualizar);
    }
}


void rotacionarDireita (structNo* raiz, structNo* pivo) {
    structNo* subB = pivo->direita;

    pivo->pai = raiz->pai;
    if(pivo->pai != NULL) {
        if (raiz->pai->esquerda == raiz){
            raiz->pai->esquerda = pivo;
        }else{
            raiz->pai->direita = pivo;
        }
    }

    raiz->pai = pivo;
    pivo->direita = raiz;

    raiz->esquerda = subB;
    if(raiz->esquerda != NULL){
        raiz->esquerda->pai = raiz;
    }
}

void rotacionarEsquerda(structNo* raiz, structNo* pivo) {
    structNo* raizpai = raiz->pai;
    structNo* subB = pivo->esquerda;

    pivo->pai = raizpai;
    if (pivo->pai != NULL) {
        if (raizpai->esquerda == raiz){
            raizpai->esquerda = pivo;
        }else{
            raizpai->direita = pivo;
        }
    }

    raiz->pai = pivo;
    pivo->esquerda = raiz;

    raiz->direita = subB;
    if (raiz->direita != NULL){
        raiz->direita->pai = raiz;
    }
}

void casoEsquerdaEsquerda(structNo* raiz, structNo* pivo) {
    rotacionarDireita (raiz, pivo);
}

void casoDireitaDireita(structNo* raiz, structNo* pivo) {
    rotacionarEsquerda(raiz, pivo);
}

void casoEsquerdaDireita(structNo* raiz, structNo* pivo) {
    rotacionarEsquerda(pivo, pivo->direita);
    rotacionarDireita(raiz, raiz->esquerda);
}

void casoDireitaEsquerda(structNo* raiz, structNo* pivo) {
    rotacionarDireita(pivo, pivo->esquerda);
    rotacionarEsquerda(raiz, raiz->direita);
}

int inserirNo(structNo* no, structNo* novoNo) {
    structNo* avo;
    structNo* tio;
    structNo* noPai = NULL;

    if (no != NULL){
        noPai = buscarNoValor(no, novoNo->valor);
    }
    if (noPai == NULL) {
        noRaiz = novoNo;
        novoNo->cor = preto;
        atualizarContagemNoVermelho(novoNo, -1);
        return sucesso;
    }

    if (noPai->valor == novoNo->valor) {
        return elementoDuplicado;
    }

    if (noPai->valor < novoNo->valor){
        noPai->direita = novoNo;
    } else{
        noPai->esquerda = novoNo;
    }

    novoNo->pai = noPai;
    novoNo->cor = vermelho;

    atualizarContagemNo(noPai, 1);
    atualizarContagemNoVermelho(noPai, 1);

    if (noPai->cor == vermelho) {
        avo = noPai->pai;

        if (avo != NULL && avo->esquerda == noPai){
            tio = avo->direita;
        }else{
            tio = avo != NULL ? avo->esquerda : NULL;
        }

        if (tio == NULL || tio->cor == preto) {
            //Caso 1
            inserirCaso1 (avo, noPai, novoNo);
        }else {
            //Caso 2
            inserirCaso2 (avo, tio, noPai, novoNo);
        }
    }

    return sucesso;
}

void inserirCaso1 (structNo* avo, structNo* noPai, structNo* chaveNo) {
    if (avo->direita == noPai) {
        if (noPai->direita == chaveNo) {
            avo->cor = vermelho;
            noPai->cor = preto;

            atualizarContagemNoVermelho(avo, 1);
            atualizarContagemNoVermelho(noPai, -1);

            avo->nosNaSub -= noPai->nosNaSub;
            avo->nosNaSubVermelho -= noPai->nosNaSubVermelho;

            if (noPai->esquerda != NULL) {
                noPai->nosNaSub -= noPai->esquerda->nosNaSub;
                avo->nosNaSub += noPai->esquerda->nosNaSub;

                noPai->nosNaSubVermelho -= noPai->esquerda->nosNaSubVermelho;
                avo->nosNaSubVermelho += noPai->esquerda->nosNaSubVermelho;
            }

            noPai->nosNaSub += avo->nosNaSub;
            noPai->nosNaSubVermelho += avo->nosNaSubVermelho;

            if (avo == noRaiz){
                noRaiz = noPai;
            }

            casoDireitaDireita (avo, noPai);
        }else {
            avo->cor = vermelho;
            chaveNo->cor = preto;

            atualizarContagemNoVermelho(avo, 1);
            atualizarContagemNoVermelho(chaveNo, -1);

            avo->nosNaSub = avo->nosNaSub - noPai->nosNaSub + (chaveNo->esquerda != NULL ? chaveNo->esquerda->nosNaSub: 0);
            noPai->nosNaSub += ((chaveNo->direita != NULL ? chaveNo->direita->nosNaSub : 0) - chaveNo->nosNaSub);
            chaveNo->nosNaSub = avo->nosNaSub + noPai->nosNaSub + 1;

            avo->nosNaSubVermelho = avo->nosNaSubVermelho - noPai->nosNaSubVermelho + (chaveNo->esquerda != NULL ? chaveNo->esquerda->nosNaSubVermelho: 0);
            noPai->nosNaSubVermelho += ((chaveNo->direita != NULL ? chaveNo->direita->nosNaSubVermelho : 0) - chaveNo->nosNaSubVermelho);
            chaveNo->nosNaSubVermelho = avo->nosNaSubVermelho + noPai->nosNaSubVermelho + 1;
            if (avo == noRaiz){
                noRaiz = chaveNo;
            }

            casoDireitaEsquerda(avo, noPai);
        }
    }else {
        if (noPai->esquerda == chaveNo) {
            avo->cor = vermelho;
            noPai->cor = preto;

            atualizarContagemNoVermelho(noPai, -1);
            atualizarContagemNoVermelho(avo, 1);

            avo->nosNaSub += ((noPai->direita != NULL ? noPai->direita->nosNaSub : 0) - noPai->nosNaSub);
            noPai->nosNaSub += (avo->nosNaSub - (noPai->direita != NULL ? noPai->direita->nosNaSub : 0));

            avo->nosNaSubVermelho += ((noPai->direita != NULL ? noPai->direita->nosNaSubVermelho : 0) - noPai->nosNaSubVermelho);
            noPai->nosNaSubVermelho += (avo->nosNaSubVermelho - (noPai->direita != NULL ? noPai->direita->nosNaSubVermelho : 0));

            if (avo == noRaiz){
                noRaiz = noPai;
            }

            casoEsquerdaEsquerda(avo, noPai);
        }else {
            avo->cor = vermelho;
            chaveNo->cor = preto;

            atualizarContagemNoVermelho(chaveNo, -1);
            atualizarContagemNoVermelho(avo, 1);

            avo->nosNaSub += ((chaveNo->direita != NULL ? chaveNo->direita->nosNaSub : 0) - noPai->nosNaSub);
            noPai->nosNaSub += ((chaveNo->esquerda != NULL ? chaveNo->esquerda->nosNaSub : 0) - chaveNo->nosNaSub);
            chaveNo->nosNaSub = noPai->nosNaSub + avo->nosNaSub + 1;

            avo->nosNaSubVermelho += ((chaveNo->direita != NULL ? chaveNo->direita->nosNaSubVermelho : 0) - noPai->nosNaSubVermelho);
            noPai->nosNaSubVermelho += ((chaveNo->esquerda != NULL ? chaveNo->esquerda->nosNaSubVermelho : 0) - chaveNo->nosNaSubVermelho);
            chaveNo->nosNaSubVermelho = noPai->nosNaSubVermelho + avo->nosNaSubVermelho + 1;
            if (avo == noRaiz){
                noRaiz = chaveNo;
            }

            casoEsquerdaDireita(avo, noPai);
        }
    }
}

void inserirCaso2 (structNo* avo, structNo* tio, structNo* noPai, structNo* chaveNo) {
    avo->cor = vermelho;
    tio->cor = preto;
    noPai->cor = preto;

    atualizarContagemNoVermelho(noPai, -1);
    atualizarContagemNoVermelho(tio, -1);
    atualizarContagemNoVermelho(avo, 1);

    if (avo->pai == NULL) {
        noRaiz = avo;
        avo->cor = preto;
        atualizarContagemNoVermelho(avo, -1);
        return;
    }

    if (avo->pai->cor == preto) {
        return;
    }

    chaveNo = avo;
    noPai = avo->pai;
    avo = noPai->pai;

    if (avo->esquerda == noPai){
        tio = avo->direita;
    }else{
        tio = avo->esquerda;
    }

    if (tio == NULL || tio->cor == preto) {
        //Caso 1
        inserirCaso1 (avo, noPai, chaveNo);
    }else {
        //Caso 2
        inserirCaso2 (avo, tio, noPai, chaveNo);
    }
}

int removerNo(structNo* no) {
    structNo* sucessor;
    structNo* proximoNo;
    structNo* irmao;
    structNo* noPai;
    int temp;

    if(no == NULL) {
        return falha;
    }
    if (no->esquerda != NULL && no->direita != NULL) {
        sucessor = noSucessor(no);
        temp = sucessor->valor;
        no->valor = temp;
        removerNo(sucessor);
    }else
    if (no->esquerda != NULL || no->direita != NULL) {
        if (no->esquerda != NULL){
            proximoNo = no->esquerda;
        }else{
            proximoNo = no->direita;
        }

        if (no->pai != NULL) {
            if (no->pai->esquerda == no) {
                no->pai->esquerda = proximoNo;
            }else {
                no->pai->direita = proximoNo;
            }

            proximoNo->pai = no->pai;
            atualizarContagemNo(no->pai, -1);
        }else {
            noRaiz = proximoNo;
            proximoNo->pai = NULL;
        }

        if (no->cor == preto){
            proximoNo->cor = preto;
        }

        atualizarContagemNoVermelho(proximoNo, -1);
        no->pai = NULL;
        free(no);
    }else {
        if (no->cor == vermelho) {
            if (no->pai->esquerda == no){
                no->pai->esquerda = NULL;
            }else{
                no->pai->direita = NULL;
            }

            atualizarContagemNo(no->pai, -1);
            atualizarContagemNoVermelho(no->pai, -1);
            no->pai = NULL;
            free(no);
        }else {
            if (noRaiz == no) {
                noRaiz = NULL;
                free(no);
                return sucesso;
            }

            noPai = no->pai;
            if (noPai->esquerda == no) {
                noPai->esquerda = NULL;
                irmao = noPai->direita;
            }else {
                noPai->direita = NULL;
                irmao = noPai->esquerda;
            }

            atualizarContagemNo (noPai, -1);
            no->pai = NULL;
            free(no);
            removerCasos(noPai, irmao);
        }
    }

    return sucesso;
}

void removerCasos(structNo* noPai, structNo* irmao) {
    //Nó pai vermelho
    if (noPai->cor == vermelho) {
        //Caso 1
        if (
            (irmao == NULL) ||
            (
                (irmao->esquerda == NULL ||irmao->esquerda->cor == preto) &&
                (irmao->direita == NULL || irmao->direita->cor == preto)
            )
        ) {
            //No pai vermelho caso 1_2
            removerCaso1_2(noPai, irmao);
        }else {
            //No pai vermelho caso1_1
            removerCaso1_1(noPai, irmao);
        }
    }else
    //No irmao vermelho
    if (irmao != NULL && irmao->cor == vermelho) {
        //Caso 2_1
        if (
                (irmao->esquerda == NULL || irmao->esquerda->cor == preto) &&
                (irmao->direita == NULL || irmao->direita->cor == preto)
        ) {
            //Caso 2_1_2
            removerCaso2_1_2 (noPai, irmao);
        }else {
            //Caso 2_1_1
            removerCaso2_1_1(noPai, irmao);
        }
    }else {
        //No irmao preto ou nulo
        //Caso 2_2
        if (irmao == NULL) {
            return;
        }

        //Irmaos nulos, irmao direito preto, irmao esquerdo preto ou irmaos pretos
        if (
            (irmao->esquerda == NULL || irmao->esquerda->cor == preto) &&
            (irmao->direita == NULL || irmao->direita->cor == preto)
        ) {
            //Caso 2_2_2
            removerCaso2_2_2(noPai, irmao);
        }else {
            //
            //Caso 2_2_1
            removerCaso2_2_1(noPai, irmao);
        }
    }
}

void removerCaso1_1(structNo* noPai, structNo* irmao) {
    structNo* neto;

    if (noPai->esquerda == irmao) {
        if (irmao->esquerda != NULL && irmao->esquerda->cor == vermelho) {
            irmao->cor = vermelho;
            irmao->esquerda->cor = preto;
            noPai->cor = preto;

            atualizarContagemNoVermelho(irmao->esquerda, -1);
            atualizarContagemNoVermelho(noPai, -1);
            atualizarContagemNoVermelho(irmao, 1);

            noPai->nosNaSub += ((irmao->direita != NULL ? irmao->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (noPai->nosNaSub - (irmao->direita != NULL ? irmao->direita->nosNaSub : 0));

            noPai->nosNaSubVermelho += ((irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0));


            if(noPai == noRaiz){
                noRaiz = irmao;
            }

            casoEsquerdaEsquerda(noPai, irmao);
        }else {
            neto = irmao->direita;
            noPai->cor = preto;

            atualizarContagemNoVermelho(noPai, -1);

            noPai->nosNaSub += ((neto->direita != NULL ? neto->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += ((neto->esquerda != NULL ? neto->esquerda->nosNaSub : 0) - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->direita != NULL ? neto->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += ((neto->esquerda != NULL ? neto->esquerda->nosNaSubVermelho : 0) - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;


            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoEsquerdaDireita(noPai, irmao);
        }
    }else {
        if (irmao->direita != NULL && irmao->direita->cor == vermelho) {
            noPai->cor = preto;
            irmao->direita->cor = preto;
            irmao->cor = vermelho;

            atualizarContagemNoVermelho(noPai, -1);
            atualizarContagemNoVermelho(irmao->direita, -1);
            atualizarContagemNoVermelho(irmao, 1);

            noPai->nosNaSub += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (noPai->nosNaSub - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0));

            noPai->nosNaSubVermelho += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0));
            if(noPai == noRaiz){
                noRaiz = irmao;
            }

            casoDireitaDireita(noPai, irmao);
        }else {
            neto = irmao->esquerda;
            noPai->cor = preto;

            atualizarContagemNoVermelho(noPai, -1);

            noPai->nosNaSub += ((neto->esquerda != NULL ? neto->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += ((neto->direita != NULL ? neto->direita->nosNaSub : 0) - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->esquerda != NULL ? neto->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += ((neto->direita != NULL ? neto->direita->nosNaSubVermelho : 0) - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;
            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoDireitaEsquerda(noPai, irmao);
        }
    }
}

void removerCaso1_2(structNo* noPai, structNo* irmao) {
    if(irmao != NULL){
        irmao->cor = vermelho;
        atualizarContagemNoVermelho(irmao, 1);
    }

    noPai->cor = preto;
    atualizarContagemNoVermelho(noPai, -1);
}

void removerCaso2_1_1(structNo* noPai, structNo* irmao) {
    structNo* neto;
    structNo* bisneto;

    if (irmao == noPai->esquerda) {
        neto = irmao->direita;
        if (neto->esquerda != NULL && neto->esquerda->cor == vermelho) {
            bisneto = neto->esquerda;
            bisneto->cor = preto;

            atualizarContagemNoVermelho(bisneto, -1);

            noPai->nosNaSub += ((neto->direita != NULL ? neto->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (bisneto->nosNaSub - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->direita != NULL ? neto->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (bisneto->nosNaSubVermelho - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;

            noPai->esquerda = neto;
            neto->pai = noPai;
            irmao->pai = neto;
            irmao->direita = bisneto;
            bisneto->pai = irmao;
            neto->esquerda = irmao;
            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoEsquerdaEsquerda(noPai, neto);
        }else {
            bisneto = neto->direita;
            bisneto->cor = preto;

            atualizarContagemNoVermelho(bisneto, -1);

            noPai->nosNaSub += ((bisneto->direita != NULL ? bisneto->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub -= neto->nosNaSub;
            neto->nosNaSub += ((bisneto->esquerda != NULL ? bisneto->esquerda->nosNaSub : 0) - bisneto->nosNaSub);
            irmao->nosNaSub += neto->nosNaSub;
            bisneto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((bisneto->direita != NULL ? bisneto->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho -= neto->nosNaSubVermelho;
            neto->nosNaSubVermelho += ((bisneto->esquerda != NULL ? bisneto->esquerda->nosNaSubVermelho : 0) - bisneto->nosNaSubVermelho);
            irmao->nosNaSubVermelho += neto->nosNaSubVermelho;
            bisneto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;

            neto->direita = bisneto->esquerda;
            bisneto->esquerda->pai = neto;

            noPai->esquerda = bisneto;
            bisneto->pai = noPai;

            bisneto->esquerda = irmao;
            irmao->pai = bisneto;

            if(noPai == noRaiz){
                noRaiz = bisneto;
            }

            casoEsquerdaEsquerda(noPai, bisneto);
        }
    }else {
        neto = irmao->esquerda;
        if (neto->direita != NULL && neto->direita->cor == vermelho) {
            bisneto = neto->direita;
            bisneto->cor = preto;

            atualizarContagemNoVermelho(bisneto, -1);

            noPai->nosNaSub += ((neto->esquerda != NULL ? neto->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (bisneto->nosNaSub - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->esquerda != NULL ? neto->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (bisneto->nosNaSubVermelho - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;

            noPai->direita = neto;
            neto->pai = noPai;
            irmao->pai = neto;
            irmao->esquerda = bisneto;
            bisneto->pai = irmao;
            neto->direita = irmao;
            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoDireitaDireita(noPai, neto);
        }else {
            bisneto = neto->esquerda;
            bisneto->cor = preto;

            atualizarContagemNoVermelho(bisneto, -1);

            noPai->nosNaSub += ((bisneto->esquerda != NULL ? bisneto->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub -= neto->nosNaSub;
            neto->nosNaSub += ((bisneto->direita != NULL ? bisneto->direita->nosNaSub : 0) - bisneto->nosNaSub);
            irmao->nosNaSub += neto->nosNaSub;
            bisneto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((bisneto->esquerda != NULL ? bisneto->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho -= neto->nosNaSubVermelho;
            neto->nosNaSubVermelho += ((bisneto->direita != NULL ? bisneto->direita->nosNaSubVermelho : 0) - bisneto->nosNaSubVermelho);
            irmao->nosNaSubVermelho += neto->nosNaSubVermelho;
            bisneto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;

            neto->esquerda = bisneto->direita;
            bisneto->direita->pai = neto;

            noPai->direita = bisneto;
            bisneto->pai = noPai;

            bisneto->direita = irmao;
            irmao->pai = bisneto;
            if(noPai == noRaiz){
                noRaiz = bisneto;
            }

            casoDireitaDireita(noPai, bisneto);
        }
    }
}

void removerCaso2_1_2(structNo* noPai, structNo* irmao) {
    if(noPai == noRaiz){
        noRaiz = irmao;
    }

    if (noPai->esquerda == irmao) {
        irmao->cor = preto;
        irmao->direita->cor = vermelho;

        atualizarContagemNoVermelho(irmao, -1);
        atualizarContagemNoVermelho(irmao->direita, 1);

        /* Atualiza a contagem*/
        noPai->nosNaSub += ((irmao->direita != NULL ? irmao->direita->nosNaSub : 0) - irmao->nosNaSub);
        irmao->nosNaSub += (noPai->nosNaSub - (irmao->direita != NULL ? irmao->direita->nosNaSub : 0));

        noPai->nosNaSubVermelho += ((irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
        irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0));

        casoEsquerdaEsquerda(noPai, irmao);
    }else {
        irmao->cor = preto;
        irmao->esquerda->cor = vermelho;

        atualizarContagemNoVermelho(irmao, -1);
        atualizarContagemNoVermelho(irmao->esquerda, 1);

        /* Atualiza a contagem*/
        noPai->nosNaSub += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0) - irmao->nosNaSub);
        irmao->nosNaSub += (noPai->nosNaSub - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0));

        noPai->nosNaSubVermelho += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
        irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0));

        casoDireitaDireita(noPai, irmao);
    }
}

void removerCaso2_2_1(structNo* noPai, structNo* irmao) {
    structNo* neto;
    if(irmao == noPai->esquerda) {
        if (irmao->esquerda != NULL && irmao->esquerda->cor == vermelho) {
            neto = irmao->esquerda;
            neto->cor = preto;

            atualizarContagemNoVermelho(neto, -1);

            noPai->nosNaSub += ((irmao->direita != NULL ? irmao->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (noPai->nosNaSub - (irmao->direita != NULL ? irmao->direita->nosNaSub : 0));

            noPai->nosNaSubVermelho += ((irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->direita != NULL ? irmao->direita->nosNaSubVermelho : 0));
            if(noPai == noRaiz){
                noRaiz = irmao;
            }

            casoEsquerdaEsquerda(noPai, irmao);
        }else {
            neto = irmao->direita;
            neto->cor = preto;

            atualizarContagemNoVermelho(neto, -1);

            noPai->nosNaSub += ((neto->direita != NULL ? neto->direita->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += ((neto->esquerda != NULL ? neto->esquerda->nosNaSub : 0) - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->direita != NULL ? neto->direita->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += ((neto->esquerda != NULL ? neto->esquerda->nosNaSubVermelho : 0) - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;
            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoEsquerdaDireita(noPai, irmao);
        }
    }else {
        if (irmao->direita != NULL && irmao->direita->cor == vermelho) {
            neto = irmao->direita;
            neto->cor = preto;

            atualizarContagemNoVermelho(neto, -1);

            noPai->nosNaSub += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += (noPai->nosNaSub - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSub : 0));

            noPai->nosNaSubVermelho += ((irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += (noPai->nosNaSubVermelho - (irmao->esquerda != NULL ? irmao->esquerda->nosNaSubVermelho : 0));
            if(noPai == noRaiz){
                noRaiz = irmao;
            }

            casoDireitaDireita(noPai, irmao);
        }else {
            neto = irmao->esquerda;
            neto->cor = preto;

            atualizarContagemNoVermelho(neto, -1);

            noPai->nosNaSub += ((neto->esquerda != NULL ? neto->esquerda->nosNaSub : 0) - irmao->nosNaSub);
            irmao->nosNaSub += ((neto->direita != NULL ? neto->direita->nosNaSub : 0) - neto->nosNaSub);
            neto->nosNaSub = noPai->nosNaSub + irmao->nosNaSub + 1;

            noPai->nosNaSubVermelho += ((neto->esquerda != NULL ? neto->esquerda->nosNaSubVermelho : 0) - irmao->nosNaSubVermelho);
            irmao->nosNaSubVermelho += ((neto->direita != NULL ? neto->direita->nosNaSubVermelho : 0) - neto->nosNaSubVermelho);
            neto->nosNaSubVermelho = noPai->nosNaSubVermelho + irmao->nosNaSubVermelho + 1;
            if(noPai == noRaiz){
                noRaiz = neto;
            }

            casoDireitaEsquerda(noPai, irmao);
        }
    }
}

void removerCaso2_2_2(structNo* noPai, structNo* irmao) {
    structNo* temp;
    irmao->cor = vermelho;

    atualizarContagemNoVermelho(irmao, 1);
    if (noPai != NULL && noPai->pai != NULL) {
        temp = noPai;
        noPai = noPai->pai;
        if(temp == noPai->esquerda){
            irmao = noPai->direita;
        }else{
            irmao = noPai->esquerda;
        }

        removerCasos(noPai, irmao);
    }
}

void imprimirPosOrdem(structNo* no){
    if(no == NULL){
        return;
    }
    imprimirPosOrdem(no->esquerda);
    imprimirPosOrdem(no->direita);
    printf(" %d", no->valor);
}

void imprimirPreOrdem(structNo* no){
    if(no == NULL){
        return;
    }
    printf(" %d", no->valor);
    imprimirPreOrdem(no->esquerda);
    imprimirPreOrdem(no->direita);
}

void imprimirEmOrdem(structNo* no){
    if(no == NULL){
        return;
    }
    imprimirEmOrdem(no->esquerda);
    printf(" %d", no->valor);
    imprimirEmOrdem(no->direita);
}

void imprimirArvore(structNo* no){
    if(no != NULL){
        printf("%i", no->valor);
        printf("[");
        imprimirArvore(no->esquerda);
        imprimirArvore(no->direita);
        printf("]");
    }
}