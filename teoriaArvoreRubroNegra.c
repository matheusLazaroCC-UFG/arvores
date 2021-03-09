/**
Árvore Rubro negra
            Seja bem vindos à aula de Algoritmos e estruturas de dados 2
            Este trabalho foi desenvolvido por alunos do instituto de informática
            da universidade federal de goiás, semestre letivo 2020 1
            Ao longo deste vídeo, será apresentada a teoria e o algoritmo referentes
            à árvore rubro negra em linguagem C, com destaque para o procedimento
            de remoção de nós.
            A árvore Rubro negra foi inventada em 1972 por Rudolf Bayer, e
        é um tipo de árvore de busca binária balanceada, em que cada nó tem
        um bit extra reservado à definição de sua cor (vermelho ou preto).2
            As cores são usadas para garantir que a árvore permaneça equilibrada
        durante as inserções e remoções de nós, diferentemente da árvore AVL, que
        utiliza o cálculo do fato de balanceamente para tal. Isso implica que, ao
        se utilizar de mecanismos de balanceamento por meio de rotações locais, o
        equilíbrio da árvore rubro negra não fica perfeito, embora garanta maior
        velocidade em inserções e remoções. As árvores AVL são mais equilibradas, em comparação com ás árvores
        rubro negras, mas podem causar mais rotações durante a inserção e remoção.
            Desta forma, a implementação de um determinado tipo de árvore vair
        depender da aplicação e suas exigências.

            Quanto à estrutura da árvore rubro negra, cabe evidenciar as seguintes
        regras:
            1 -Cada nó tem uma cor vermelha ou preta.

            2 - A raiz da árvore é sempre preta.

            3 - Não há dois nós vermelhos adjacentes, ou seja: um nó vermelho
            não pode ter um pai vermelho ou filho vermelho.

            4 - Cada caminho de um nó (incluindo a raiz) para qualquer um de
            seu nó NULL descendente tem o mesmo número de nós pretos.

            Além disso, cabe destacar alguns pontos interessantes:
                1 - A altura preta da árvore vermelho-preta é o número de nós
                pretos em um caminho do nó raiz até um nó folha. Os nós de
                folha também são contados como nós pretos. Portanto, uma árvore
                vermelho-preta de altura h tem altura preta >= h / 2.

                2 - A altura de uma árvore vermelho-preta com n nós é
                h <= 2 log 2 (n + 1).

                3 - Todas as folhas (NULL) são pretas.

                4 - A profundidade de preto de um nó é definida como o número de
                nós pretos da raiz até aquele nó, ou seja, o número de
                ancestrais pretos.

                5 - Cada árvore rubro-negra é um caso especial de árvore binária.

            MOSTRAR A ESTRUTURA DO ALGORITMO
                Este é o algorimo que desenvolvemos. Ele foi desenvolvido utilizando
            linguagem de programação C. Foram implementados os principais mecanismos
            da estrutura de dados para o funcionamento da árvore rubro negra.
                Para vizualização completa, sugerimos que acesse o link em anexo.
                (1)Aqui definimos três variáveis do tipo de dado enum,
                que em linguagem C é um conjunto de valores inteiros representados por
                identicadores. Elas são usadas para definir a cor dos nós da árvore.
                (2)Definimos aqui uma struct que é o corpo de cada nó da árvore, com
                seus principais elementos como a valor, o nó pai, o nó da esquerda, o nó
                da direita, a cor do nó, a quantidade de nos da subárvore, e a quantidade
                de nós vermelhos na subárvore.

                Ler o que faz cada função, até imprimirArvore.

                Aqui estão as principais funções do algoritmo:
                Cabe destacar que dividimos o processo de inserção em 2 subcasos, sendo
                que no caso 1, recolorimos e rotacionamos, caso o nó tio seja NULL ou a cor do nó tio
                seja preto.
                No caso 2, recolorimos e repetimos o ciclo até obtermos o equilíbrio.

                Conforme estabelecido, não detalheremos a respeito da estrutura
                das demais funções deste algoritmo, senão do mecanismo de remoção.

                //Mostrando a função removerNo
                MECANISMO DE REMOÇÃO
                    A função removerNo, recebe como referência um nó, e realiza
                as seguintes operações:
                    Se o nó for NULL, retorna falha(=0)
                    Se o nó à esquerda e o nó à direita forem diferentes de NULL,
                pegamos o nó sucessor, fazemos a substituição do valor do nó
                sucessor no valor do no, e removemos o nó sucessor.
                    caso contrário
                    se o nó à esquerda ou o nó à direite forem diferentes de NULL,
                    verificamos:
                    se o nó à esquerda for diferente de NULL, assumimos o proximo nó
                como o nó à esquerda.
                    caso contrário, assumimos o proximo no como o nó à direita.

                    se o nó pai for diferente de NULL
                    verificamos:
                    se o nó à esquerda do nó pai for igual ao nó, assumimos este
                como o proximo no
                    caso contrário, assumimos o nó à direita do nó pai como o próximo
                nó.
                    Desta forma, assumimos o nó pai do proximo nó como o nó pai,
                e atualizamos a contagem do no na sua subárvore.

                Caso o nó pai for igual a NULL, assumimos o no raiz como o proximo no,
                e o nó pai do proximo no como NULL;

                se a cor do nó for preto, assumimos a cor do próximo nó como preto;

                desta forma, atualizamos a contagem de nós na subárvore vermelha,
                assumimos o nó pai como NULL e esvaziamos a memória.

                Utilizando a álgebra booleana, deduzimos que , se o nó à esquerda for
                NULL ou o nó à direita for NULL, verificamos:

                se a cor do nó for vermelho, verificamos:
                se o nó à esquerda do nó pai for igual ao nó, o assumimos como NULL.
                caso contrario, assumimos o nó à direita do nó pai como NULL;
                desta forma, atualizamos a contagem de nós da subárvore, a contagem de
                nós vermelhos da subárvore, assumimos o nó pai como NULL e liberamos
                a memória.

                caso a cor do nó for preto, verificamos:
                se o nó raiz for igual ao nó, assumimos este como NULL, liberamos a
                memória e retornamos sucesso.

                se o nó à esquerda do nó pai for igual ao nó, assumimos este como NULL,
                e assumimos o nó irmão como o nó à direita do nó pai.
                caso contrário (o nó à esquerda do nó pai for diferente do nó, assumimos
                o nó à direita do no pai como NULL, e o irmão como o nó à esquerda do
                nó pai.

                com isso, atualizamos a contegem da subárvore, assumimos o nó pai como NULL,
                liberamos a memória e partimos para os possíveis casos de remoção,
                passando como referência o nó pai e o nó irmão.


                    Nesta etapa, verificamos a cor do nó irmão,  para decidir o caso apropriado.
                    A propriedade violada ao se remover um nó de uma árvore rubro negra
                é a alteração da altura dos nós vermelhos nas subárvores.
                A remoção de um nó vermelho causa redução da altura da subárvore vermelha, de
                uma raiz à caminho do nó folha.

                    Na função removerCasos, destrinchamos 6 subcasos:

                    se a cor do nó pai for vermelho, verificamos:
                    se o nó irmão for NULL ou
                    o nó à esquerda do irmão for NULL ou a cor do nó à esquerda do
                    irmão for pretto e o nó à direita do irmão for NULL ou a cor
                    do nó à direita do nó irmão for preto, partimos para o caso12
                    de remoção, passando por referência o nó pai e o nó irmão.
                    //mostrar função removerCaso1_2
                    Nele, verificamos:
                        se o nó irmão for diferente de NULL, então assumimos a cor do
                        irmão como vermelho, e atualizamos a contegem da subárvore
                        vermelha;

                        com isso, assumimos a cor do nó pai como preto e novamente
                        atualizamos a contagem da subárvore vermelha.

                        //retornar à linha 767
                    Utilizando algebra booleana, verificamos:
                    se o irmão for falsa que se o nó irmão for NULL ou
                    o nó à esquerda do irmão for NULL ou a cor do nó à esquerda do
                    irmão for pretto e o nó à direita do irmão for NULL ou a cor
                    do nó à direita do nó irmão for preto, então partimos para
                    o subcaso 11

                    Neste subcaso, aplicamos o conceito de recoloração, atualizando
                    a contagem de nós sucessivamente, a aplicamos o mecanismo de rotação
                    local, sendo que verificamos:
                    se o nó à esquerda do nó pai for  igual ao irmão, verificamos:
                    se o nó à esquerda for diferente de NULL e a cor do nó à esquerda do
                    irmão for vermelho, recolorimos e aplicamos rotação esquerda esquerda.

                    caso contrário, recolorimos e aplicamos a rotação esquerda direta.
                    caso o nó à esquerda do nó pai por diferente do nó irmão, então
                    verificamos:
                    se o nó à direita do nó irmão for diferente do NULL e a cor do nó à
                    direita do nó irmão for vermelho, então recolorimos e aplicamos
                    a rotação direita direita
                    caso contrário, recolorimos e aplicamos a rotação direita esquerda.

                    //voltar à linha 771
                    voltando àos casos, se a cor do nó pai for preta, então verificamos:
                    se o nó à esquerda do irmão for NULL ou a cor do no à esquerda do irmao for preto
                    e
                    o nó à direita do rimão for NULL ou a cor do nó à direita do irmão for preto,
                    então partimos para o caso 2 1 2

                    //Mostrar função removerCaso2_1_2
                    Neste caso, verificamos:
                    se o nó pai for igual ao nó raiz, assumimos que o no raiz é igual ao irmao

                    se o nó à esquerda do no pai for igual ao irmão, então recolorimos e aplicamos
                    a rotação esquerda esquerda.

                    caso contrário, recolorimos e aplicamos a rotação direita direita

                    caso seja falso que se o nó à esquerda do irmão for NULL ou a cor do no à esquerda do irmao for preto
                    e
                    o nó à direita do rimão for NULL ou a cor do nó à direita do irmão for preto
                    então aplicamos o  caso de remoção 2 1 1
                    Neste caso, se o irmao for igual ao no à esquerda do no pai, assumimos o neto
                    igual ao no à direita do irmao, e verificamos:
                    se o no à esquerda do neto for diferente de NULL e a cor do no à esquerda do neto
                    for vermelho, então recolorimos, recolocamos os nós e aplicamos a rotação esquerda
                    esquerda;
                    caso seja falso que o no à esquerda do neto é NULL e a cor do no à esquerda do neto
                    seja vermelho, então recolorimos, recolocamos os nós e aplicamos a rotação esquerda esquerda

                    caso o irmão seja diferente do no à esquerda do no pai, então
                    assummos o neto como o no à esquerda do irmão e verificamos:
                    se o no à direita do neto for diferente de NULL e a cor do no à direita do neto
                    for vermelho, então recolorimo, recolocamos os nós e aplicamos a rotação direita direta;

                    caso contrario, recolorimos, recolocamos os nós e a aplicamos a rotação direita direita.

                    //voltar à linha 784

                    Voltando aos subcasos, se for falso que o nó irmão é diferente de NULL e a cor
                    do irmão é vermelho, então verificamos:
                    se o irmão for NULL, retornamos;
                    se ...
                    aplicamos o subcaso de remoção 2 2 2
                    //mostrar a função removerCaso2_2_2
                    neste subcaso, verificamos, se o nó pai for diferente de NULL e o nó pai do nó pai
                    for diferente de NULL, então assumimos o no pai igual ao nó pai do no pai, e
                    se o no pai anterior for igual ao no à esquerda do no pai, assumimos o irmao igual
                    ao no à direita do no pai
                    caso contrario, o assumimos como o no à esquerdado no pai.
                    desta forma, retornamos por recursão indireta à função dos casos de remoção

                    caso seja falso que ...
                    então finalmente aplicamos o subcaso de remoção 2 2 1

                    neste caso, verificamos:
                    //mostrar função removerCaso2_2_1
                    se o irmão for igual ao no à esquerda do no pai, verificamos:
                    se o no à esquerda do irmao for diferente de NULL ...
                    aplicamos a recoloração, e a rotação esquerda esquerda.
                    caso contrario, aplicamos a recolorção e a rotação esquerda direita;

                    caso o irmão seja diferente do no à esquerda do no pai, verificamos:
                    se o no à direita do irmão for diferente de NULL ...
                    então recolorimos e aplicamos a rotação direita dereita.
                    caso contrario, recolorimos e aplicamos a rotação direita esquerda.

                    Com isso, cobrimos todos os possíveis casos de remoção na árvore rubro negra.

                    //mostrar um exemplo de inserção e remoção
                    inserir: 7 3 18 10 22 8 11 26 2 6 13
                    remover: 18 11 3 10 22
                    resultado: 10 7 18 3 8 11 22 2 6 13 26






















                ler sobre cada função.

            MECANISMO DE INSERÇÃO
                Na árvore rubro negra, utilizamos duas ferramentas para realizar o
            balanceamento:
                1- recolorir
                2- rotação

                Tentamos recolorir primeiro, se recolorir não funcionar,
            então vamos para a rotação.

            //Mostrando o algoritmo
                O algoritmo de inserção tem 2 principais casos, que dependem
            da cor do nó tio.
                - Caso 1: Se o nó tio for NULL ou a cor do nó tio for preto,
                recolorimos e rotacionamos.
                - Caso 2: Caso contrário, recolorimos e repetimos o ciclo até obtermos
                o equilíbrio.

                Mostrar o código
