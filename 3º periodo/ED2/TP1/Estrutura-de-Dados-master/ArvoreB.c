#include "./headers/ArvoreB.h"
#include <stdio.h>
#include <stdlib.h>

struct TRegister
{
    TKey key;
    long dado1;
    char dado2[500];
};

struct TPage
{
    short n;
    TRegister reg[2 * ORDEM_M];
    TPointer pointer[(2 * ORDEM_M) + 1];
};

/* Inicia uma árvore a partir de um apontador
        Nenhuma chave ainda inicializada*/
void inicializa(TPointer Arvore)
{
    /* Inicia uma árvore a partir de um apontador
        Nenhuma chave ainda inicializada*/
    Arvore = NULL;
}

int pesquisaArvoreB(TRegister *x, TPointer ap)
{
    long i = 0;

    if (ap == NULL)
        return 0;

    /*Pesquisa por todas as chaves em uma folha e salva
        a posição i, caso encontre um valor maior ou igual
        ao desejado ou o fim da página atual.*/
    while (i < ap->n && x->key > ap->reg[i - 1].key)
        i++;

    /*Confere se i representa um registro dentro da página
        atual*/
    if (x->key == ap->reg[i - 1].key)
    {
        //O registro encontrado é retornado através de x
        *x = ap->reg[i - 1];
        return 1;
    }
    /*Quando o registro não é encontrado é necessário que
        seja feita a verificação para qual página seguir
        com a pesquisa.*/
    if (x->key < ap->reg[i - 1].key)
        //Segue a pesquisa pela esquerda
        return pesquisaArvoreB(x, ap->pointer[i - 1]);
    else
        //Segue a Pesquisa pela direita
        return pesquisaArvoreB(x, ap->pointer[i]);
}

void imprime(TPointer arvore)
{
    int i = 0;

    //Arvore vazia
    if (arvore == NULL)
        return;
    //Chamada recursiva para impressão dos nodos descendentes
    while (i <= arvore->n)
    {
        //imprime os registros menores
        imprime(arvore->pointer[i]);
        if (i != arvore->n)
        {
            //imprime o registro atual
            printf("%ld ", arvore->reg[i].key);
        }
        //repete os passos anteriores com o próximos registros
        i++;
    }
}

void encerra(TPointer arvore)
{
    int i = 0;

    //Arvore vazia
    if (arvore == NULL)
        return;
    //Chamada recursiva para remoção dos nodos descendentes
    while (i <= arvore->n)
    {
        //imprime os registros menores
        encerra(arvore->pointer[i]);
        if (i != arvore->n)
        {
            //imprime o registro atual
            free(arvore);
        }
        //repete os passos anteriores com o próximos registros
        i++;
    }
}

/*  FUNÇÕES REFERENTES À INSERÇÃO NA ARVORE B
*/

void insereNaPagina(TPointer ap, TRegister regist, TPointer apDir)
{
    //Página encontrada, essa função realiza a inserção do registro

    /*A posição do registro na página é representada pela variavel k
        a verificação começa no último registro da pagina*/
    int k = ap->n;

    //Enquanto a verificação não chegar ao ínicio da página.
    while (k > 0)
    {
        /*os registros são comparados para garantir que o novo
            registro seja colocado a frente apenas de registros
            com chave menor.*/
        if (regist.key >= ap->reg[k - 1].key)
            break;

        /*Enquanto a posição não é encontrado os registro são relocados
            para a direita.*/
        ap->reg[k] = ap->reg[k - 1];
        ap->pointer[k + 1] = ap->pointer[k];
        k--;
    }
    //Encontrada a posição, o registro é inserido e n ap->n incrementado.
    ap->reg[k] = regist;
    ap->pointer[k + 1] = apDir;
    ap->n++;
}

void ins(TRegister regist, TPointer ap, short *cresceu,
         TRegister *regRetorno, TPointer *apRetorno)
{
    long j, i = 1;
    TPointer apTemp = NULL;

    //Página vazia
    if (ap == NULL)
    {
        *cresceu = 1;           //indica que a inserção exige crescimento da arvore
        (*regRetorno) = regist; //retorna o registro a ser inserido
        (*apRetorno) = NULL;    //ponteiro a direita
        return;
    }

    //Encontra de forma linear o lugar de inserção na página
    while (i < ap->n && regist.key > ap->reg[i - 1].key)
        i++;
    //Se um registro igual já estiver presente
    if (regist.key == ap->reg[i - 1].key)
    {
        //Inserção chega ao fim sem alterações na arvore
        *cresceu = 0;
        return;
    }
    /*Se o registro atual for maior que o registro a ser inserido,   a inserção
        acontece no ponteiro a esquerda*/
    if (regist.key < ap->reg[i - 1].key)
        i--;
    //Verifica a inserção na próxima página.
    ins(regist, ap->pointer[i], cresceu, regRetorno, apRetorno);

    /* Se a inserção aconteceu e mais nenhuma alteração é necessária
    , a função termina aqui.*/
    if (!(*cresceu))
        return;

    //Página tem espaço
    if (ap->n < (2 * ORDEM_M))
    {
        insereNaPagina(ap, *regRetorno, *apRetorno); //Inserção acontece
        *cresceu = 0;                                //mais nenhuma alteração é necessária
        return;
    }

    /* Página cheia, precisa ser dividida
        Registro do meio será o pai das duas novas páginas.
        Nova página será o ponteiro a direita do novo registro pai.
    */

    //nova página é criada
    apTemp = (TPointer)malloc(sizeof(TPage));
    apTemp->n = 0;
    apTemp->pointer[0] = NULL;

    //Posição de inserção encontrado antes da metade da página.
    if (i < ORDEM_M + 1)
    {
        //Libera espaço na página, passando o último registro para a página recem criada
        insereNaPagina(apTemp, ap->reg[(2 * ORDEM_M) - 1], ap->pointer[2 * ORDEM_M]);
        ap->n--;
        //Insere o registro
        insereNaPagina(ap, *regRetorno, *apRetorno);
    }
    //Insere o registro na nova página.
    else
        insereNaPagina(apTemp, *regRetorno, *apRetorno);

    //Insere metade dos registros da página atual, na nova página
    for (j = ORDEM_M + 2; j <= (2 * ORDEM_M); j++)
        insereNaPagina(apTemp, ap->reg[j - 1], ap->pointer[j]);

    //Atualiza a quantidade de itens na página atual
    ap->n = ORDEM_M;
    //O primeiro apontador da nova página recebe o último apontador à direita restante
    apTemp->pointer[0] = ap->pointer[ORDEM_M + 1];
    //Retorna o registro do meio para ser inserido na página pai
    *regRetorno = ap->reg[ORDEM_M];
    //Nova página será o ponteiro a direita do novo registro pai.
    *apRetorno = apTemp;
}

void insereArvoreB(TRegister regist, TPointer *ap)
{
    short cresceu;        /*Valor booleano que controla se alguma alteração deve ser realizada 
                            devido ao crescimento da árvore.*/
    TRegister regRetorno; //Guarda os registros movidos de para um nível superior da árvore.
    TPage *apRetorno;     //Ponteiro a direita do registro retornado.
    TPage *apTemp;        /*usada na criação de uma nova raiz a partir de um regRetorno e apRetorno
                            caso necessário.*/

    /*Chamada do método recursivo que insere na árvore e garante o crescimento
        balanceado da mesma, mantendo suas propriedades.*/
    
    ins(regist, *ap, &cresceu, &regRetorno, &apRetorno);

    //Árvore cresce na altura da raíz
    if (cresceu)
    {
        //Criação da nova raiz.
        apTemp = (TPage *)malloc(sizeof(TPage));
        apTemp->n = 1;
        apTemp->reg[0] = regRetorno;
        apTemp->pointer[1] = apRetorno;
    }
}

/*  FUNÇÕES REFERENTES À REMOÇÃO NA ARVORE B
*/

void reconstitui(TPointer apPag, TPointer apPai, int posPai, short *diminuiu)
{
    TPage *aux;
    long dispAux, j;

    if (posPai < apPai->n)
    {
        //aux = TPage a direita de apPag
        aux = apPai->pointer[posPai + 1];
        dispAux = (aux->n - ORDEM_M + 1) / 2;
        apPag->reg[apPag->n] = apPai->reg[posPai];
        apPag->pointer[apPag->n + 1] = aux->pointer[0];
        apPag->n++;

        if (dispAux > 0)
        {
            //Existe folga: transfere de aux para apPag
            for (j = 1; j < dispAux; j++)
                insereNaPagina(apPag, aux->reg[j - 1], aux->pointer[j]);

            apPai->reg[posPai] = aux->reg[dispAux - 1];
            aux->n -= dispAux;

            for (j = 0; j < aux->n; j++)
                aux->reg[j] = aux->reg[j + dispAux];
            for (j = 0; j <= aux->n; j++)
                aux->pointer[j] = aux->pointer[j + dispAux];

            *diminuiu = 0;
        }
        else
        {
            //Fusão: intercala aux em apPag e libera aux
            for (j = 1; j <= ORDEM_M; j++)
                insereNaPagina(apPag, aux->reg[j - 1], aux->pointer[j]);

            free(aux);

            for (j = posPai; j < apPai->n; j++)
            {
                apPai->reg[j - 1] = apPai->reg[j];
                apPai->pointer[j] = apPai->pointer[j + 1];
            }

            apPai->n--;

            if (apPai->n >= ORDEM_M)
                *diminuiu = 0;
        }
    }
    else //Aux = TPage a esquerda de apPag
    {
        aux = apPai->pointer[posPai - 1];
        dispAux = (aux->n - ORDEM_M - 1) / 2;

        for (j = apPag->n; j >= 1; j--)
            apPag->reg[j] = apPag->reg[j - 1];

        apPag->reg[0] = apPai->reg[posPai - 1];

        for (j = apPag->n; j >= 0; j--)
            apPag->pointer[j + 1] = apPag->pointer[j];

        apPag++;

        if (dispAux > 0)
        {
            //Existe folga: transfere de aux para apPag
            for (j = 1; j < dispAux; j++)
                insereNaPagina(apPag, aux->reg[aux->n - j], aux->pointer[aux->n - j + 1]);

            apPag->pointer[0] = aux->pointer[aux->n - dispAux + 1];
            apPai->reg[posPai - 1] = aux->reg[aux->n - dispAux];
            aux->n -= dispAux;
            *diminuiu = 0;
        }
        else
        {
            //Fusão: intercala apPag em aux e libera apPag
            for (j = 1; j <= ORDEM_M; j++)
                insereNaPagina(aux, apPag->reg[j - 1], apPag->pointer[j]);

            free(apPag);
            apPai->n--;

            if (apPai->n >= ORDEM_M)
                *diminuiu = 0;
        }
    }
}

void antecessor(TPointer ap, int ind, TPointer apPai, short *diminuiu)
{
    if (apPai->pointer[apPai->n] != NULL)
    {
        antecessor(ap, ind, apPai->pointer[apPai->n], diminuiu);

        if (*diminuiu)
        {
            reconstitui(apPai->pointer[apPai->n], apPai, (long)apPai->n, diminuiu);
            return;
        }
        ap->reg[ind - 1] = apPai->reg[apPai->n - 1];
        apPai->n--;
        *diminuiu = (apPai->n < ORDEM_M);
    }
}

void ret(TKey chave, TPointer *ap, short *diminuiu)
{
    long j, ind = 1;
    TPointer pag;

    if (*ap == NULL)
    {
        *diminuiu = 0;
        return;
    }

    pag = *ap;

    while (ind < pag->n && chave > pag->reg[ind - 1].key)
        ind++;

    if (chave == pag->reg[ind - 1].key)
    {
        if (pag->pointer[ind - 1] == NULL)
        {
            //Pagina folha encontrada
            pag--;
            *diminuiu = (pag->n < ORDEM_M);

            for (j = ind; j <= pag->n; j++)
            {
                pag->reg[j - 1] = pag->reg[j];
                pag->pointer[j] = pag->pointer[j + 1];
            }

            return;
        }
        /*TPage não é folha: Trocar com o antecessor*/
        antecessor(*ap, ind, pag->pointer[ind - 1], diminuiu);
        if (*diminuiu)
            reconstitui(pag->pointer[ind - 1], *ap, ind - 1, diminuiu);

        return;
    }

    if (chave > pag->reg[ind - 1].key)
        ind++;

    ret(chave, &pag->pointer[ind - 1], diminuiu);

    if (*diminuiu)
        reconstitui(pag->pointer[ind - 1], *ap, ind - 1, diminuiu);
}

void retiraArvoreB(TKey chave, TPointer *ap)
{
    short diminuiu; //Valor booleano que indica se a quantidade de itens na página é menor que ORDEM_M
    TPointer aux;   //Auxilia na redução da árvore neste nível.

    ret(chave, ap, &diminuiu);

    //Árvore diminui em altura
    if (diminuiu && (*ap)->n == 0)
    {
        aux = *ap;
        *ap = aux->pointer[0];
        free(aux);
    }
}

/*  FUNÇÕES ESPECÍFICAS DO TP
*/

void insercaoTP(TPointer *arvore, FILE *registros)
{
    TRegister *reg = NULL;

    registros = fopen("registros.bin", "rb");
    while (!feof(registros))
    {   
        fread(reg, sizeof(TRegister), 1, registros);
        insereArvoreB(*reg, arvore);
    }
    fclose(registros);
}

void pesquisaTP(long chave, TPointer *arvore)
{
    TRegister registro;
    registro.key = chave;

    if (pesquisaArvoreB(&registro, *arvore))
    {
        printf("A chave: %ld foi encontrada\n", chave);
        printf("Dado 1: %ld \t | \tDado 2: %s\n", registro.dado1, registro.dado2);
    }
    else
        printf("A chave: %ld não foi encontrada", chave);
}
