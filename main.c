/* ------------ Include / Import ------------ */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct.h"
#include "adicionais.c"

#include "insercao/insercao.c"
#include "fatorBalanceamento/fatorBalanceamento.c"
#include "balanceamentoEsquerda/rotacaoSimplesEsquerda.c"
#include "balanceamentoDireita/rotacaoSimplesDireita.c"
#include "balanceamentoEsquerda/rotacaoDuplaEsquerda.c"
#include "balanceamentoDireita/rotacaoDuplaDireita.c"
#include "remocao/remocao.c"
#include "visitacao/ordens.c"
#include "apresentacao/apresentacao.c"

/* -------------------------------------------- */

/* ------------ Funcionalidades ------------- */

int main();

short verificarArvoreVazia(Nodo *nodo);

Nodo *alocarNodo();

Nodo *verificarExistenciaNodo(Nodo *nodo, short alvo);

void construirNodo(Nodo **pRaiz, Nodo *nodo);

void alterarDadosNodo(Nodo *nodo, short nivel);

void buscarNodoDesbalanceado(Nodo **alvo, short *rotacao, Nodo *nodo);

void encontrarPaiNodo(Nodo **pai, short *lado, short numero, Nodo *nodo);

void balancearArvore(Nodo **pRaiz);

void removerNodo(Nodo **pRaiz);

/* -------------------------------------------- */

// main: Funcao principal.

int main()
{
    short opcao = -1;
    Nodo *pRaiz = NULL;
    Nodo *novoNodo = NULL;

    while (opcao != 0)
    {

        menu(&opcao);

        switch (opcao)
        {

        case 1:

            printf("--------------  1.1 CONSTRUCAO  -------------\n\n");
            printf(" </> Alocando nodo.\n");
            novoNodo = alocarNodo();

            if (novoNodo)
            {
                printf(" </> Nodo alocado.\n");
                printf(" </> Construindo nodo.\n");
                construirNodo(&pRaiz, novoNodo);
                printf(" </> Nodo construido.\n\n");
                printf("---------------------------------------------\n\n");
                printf("--------------  2.1 ALTERACAO  --------------\n\n");
                printf(" </> Alterando dados do(s) nodo(s).\n");
                alterarDadosNodo(pRaiz, 1);
                printf(" </> Dados alterados.\n\n");
                printf("---------------------------------------------\n\n");
                printf("------------  3.1 BALANCEAMENTO  ------------\n\n");
                printf(" </> Verificando balanceamento.\n");
                balancearArvore(&pRaiz);
                printf(" </> Verificacao concluida.\n\n");
                printf("---------------------------------------------\n\n");
            }
            else
                printf(" </> Nao ha espaco de memoria disponivel!\n");

            break;

        case 2:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A arvore esta vazia!\n");
            else
            {
                printf("---------------  1.1 REMOCAO  ---------------\n\n");
                removerNodo(&pRaiz);
                printf("---------------------------------------------\n\n");

                if (!verificarArvoreVazia(pRaiz))
                {
                    printf("--------------  2.1 ALTERACAO  --------------\n\n");
                    printf(" </> Alterando dados do(s) nodo(s).\n");
                    alterarDadosNodo(pRaiz, 1);
                    printf(" </> Dados alterados.\n\n");
                    printf("-----------------------------------------\n\n");
                    printf("------------  3.1 BALANCEAMENTO  ------------\n\n");
                    printf(" </> Verificando balanceamento.\n");
                    balancearArvore(&pRaiz);
                    printf(" </> Verificacao concluida.\n\n");
                    printf("---------------------------------------------\n\n");
                }
            }

            break;

        case 3:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A arvore esta vazia!\n");
            else
            {
                /* Funcao VISITACAO */
                printf(" </> Pre-ordem: ");
                preOrdem(pRaiz);
                printf("\n");

                printf(" </> Em-ordem.: ");
                emOrdem(pRaiz);
                printf("\n");

                printf(" </> Pos-ordem: ");
                posOrdem(pRaiz);
                printf("\n\n\n");
            }

            break;

        case 5:

            if (verificarArvoreVazia(pRaiz))
                printf(" </> A arvore esta vazia!\n");
            else
                mostrarArvoreSimplificada(pRaiz, pRaiz->alturaNodo);

            break;

        case 6:

            if (verificarArvoreVazia(pRaiz))

                printf(" </> A arvore esta vazia!\n");

            else
            {
                short i;
                printf("----------------------------------------------------------------");
                for (i = 1; i < (pRaiz->alturaNodo + 2); i++)
                    printf("-------");
                printf("-\n");

                printf("| Numero | Nivel | Altura | Grau | Fator | Esquerda | Direita |\n\n");

                mostrarArvoreDetalhada(pRaiz, (pRaiz->alturaNodo + 1));
                printf("\n");

                printf("----------------------------------------------------------------");
                for (i = 1; i < (pRaiz->alturaNodo + 2); i++)
                    printf("-------");
                printf("-\n\n\n");
            }

            break;

        case 0:

            printf("------------  1.1 ENCERRAMENTO  -------------\n\n");
            if (pRaiz)
            {
                printf("--------------  1.2 LIBERACAO  --------------\n\n");
                printf(" </> Liberando espaco de memoria preenchido.\n");
                limparMemoria(pRaiz);
                printf(" </> Espaco liberado.\n\n");
                printf("---------------------------------------------\n\n");
            }
            encerrarPrograma();
            printf("---------------------------------------------\n\n");

            break;
        }
    }

    return 0;
};

// verificarArvoreVazia: Verifica se a arvore esta vazia.

short verificarArvoreVazia(Nodo *nodo)
{

    if (nodo)
        return 0;

    else
        return 1;
};

// alocarNodo: Verifica se ha espaco de memoria e aloca um nodo.

Nodo *alocarNodo()
{

    Nodo *ponteiroNovo = (Nodo *)malloc(sizeof(Nodo));

    return ponteiroNovo;
};

// verificarExistenciaNodo: Verifica se existe um no com o valor passado pela variavel alvo.

Nodo *verificarExistenciaNodo(Nodo *nodo, short alvo)
{

    if (nodo)
    {

        if (nodo->numeroNodo == alvo)
            return nodo;

        else if (nodo->numeroNodo > alvo)
            return verificarExistenciaNodo(nodo->filhoEsquerda, alvo);

        else
            return verificarExistenciaNodo(nodo->filhoDireita, alvo);
    }
    else
        return NULL;
};

// construirNodo: Constroi o nodo colocando dados dentro do mesmo.

void construirNodo(Nodo **pRaiz, Nodo *nodo)
{
    while (1)
    {
        printf(" </> Informe um numero de ate 4 digitos para o nodo: ");
        scanf("%hd", &nodo->numeroNodo);

        if (!verificarTamanhoNumero(nodo->numeroNodo))
        {
            printf("\n");
            printf(" </> O numero deve ser entre -9999 e 9999!\n\n");
            continue;
        }

        if (verificarExistenciaNodo(*pRaiz, nodo->numeroNodo))
        {
            printf("\n");
            printf(" </> Ja existe um nodo com este numero!\n\n");
            continue;
        }
        else
            break;
    }

    printf(" </> Inserindo nodo %d na arvore.\n", nodo->numeroNodo);
    nodo->nivelNodo = inserirNodo(nodo, pRaiz, (*pRaiz)) + 1; /* Funcao INSERCAO */
    printf(" </> Nodo inserido.\n");

    nodo->grauNodo = 0;

    nodo->alturaNodo = 1;

    nodo->filhoDireita = NULL;

    nodo->alturaDireita = 0;

    nodo->filhoEsquerda = NULL;

    nodo->alturaEsquerda = 0;

    nodo->fatorBalanceamento = 0;

    return;
};

// alterarDadosNodo: Vai alterar os dados de cada nodo.

void alterarDadosNodo(Nodo *nodo, short nivel)
{
    if (nodo)
    {
        alterarDadosNodo(nodo->filhoEsquerda, (nivel + 1));
        alterarDadosNodo(nodo->filhoDireita, (nivel + 1));

        nodo->nivelNodo = nivel;

        if (nodo->filhoEsquerda && nodo->filhoDireita)
            nodo->grauNodo = 2;
        else if (nodo->filhoEsquerda || nodo->filhoDireita)
            nodo->grauNodo = 1;
        else
            nodo->grauNodo = 0;

        nodo->fatorBalanceamento = fatorDeBalanceamento(nodo); /* FATORBALANCEAMENTO */

        nodo->alturaNodo = max(nodo->alturaEsquerda, nodo->alturaDireita) + 1;
    }

    return;
};

// buscarNodoDesbalanceado: Procura nodos desbalanceados.

void buscarNodoDesbalanceado(Nodo **alvo, short *rotacao, Nodo *nodo)
{
    if (nodo)
    {
        if (nodo->fatorBalanceamento == -2)
        {
            if (nodo->filhoEsquerda->fatorBalanceamento == -2 || nodo->filhoEsquerda->fatorBalanceamento == 2)
                buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoEsquerda);
            else
            {
                (*alvo) = nodo;
                if (nodo->filhoEsquerda->fatorBalanceamento == -1)
                    *rotacao = 1;
                else
                    *rotacao = 2;

                return;
            }
        }
        else if (nodo->fatorBalanceamento == 2)
        {
            if (nodo->filhoDireita->fatorBalanceamento == -2 || nodo->filhoDireita->fatorBalanceamento == 2)
                buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoDireita);
            else
            {
                (*alvo) = nodo;
                if (nodo->filhoDireita->fatorBalanceamento == -1)
                    *rotacao = -2;
                else
                    *rotacao = -1;

                return;
            }
        }
        else
        {
            buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoEsquerda);
            buscarNodoDesbalanceado(alvo, rotacao, nodo->filhoDireita);
        }
    }

    return;
};

// encontrarPaiNodo: Encontra o pai do nodo.

void encontrarPaiNodo(Nodo **pai, short *lado, short numero, Nodo *nodo)
{
    if (nodo->numeroNodo != numero)
    {
        if (nodo->filhoEsquerda->numeroNodo == numero)
        {
            (*pai) = nodo;
            *lado = -1;
            return;
        }
        else if (nodo->filhoDireita->numeroNodo == numero)
        {
            (*pai) = nodo;
            *lado = 1;
            return;
        }
        else
        {
            if (nodo->numeroNodo > numero)
                return encontrarPaiNodo(pai, lado, numero, nodo->filhoEsquerda);
            else
                return encontrarPaiNodo(pai, lado, numero, nodo->filhoDireita);
        }
    }
    else
    {
        (*pai) = NULL;
        *lado = 0;
        return;
    }
};

// balancearArvore: Vai chamar a rotacao para balancear a arvore.

void balancearArvore(Nodo **pRaiz)
{
    Nodo *pai = NULL;
    Nodo *alvo = NULL;
    short lado;
    short rotacao;

    printf(" </> Buscando nodos desbalanceados.\n");
    buscarNodoDesbalanceado(&alvo, &rotacao, (*pRaiz));

    if (alvo)
    {
        printf(" </> Nodo desbalanceado encontrado.\n");
        printf(" </> Buscando pai do nodo.\n");
        encontrarPaiNodo(&pai, &lado, alvo->numeroNodo, (*pRaiz));

        if ((*pRaiz) != alvo)
        {
            printf(" </> Pai do nodo encontrado.\n\n");
            printf("---------------  3.2 ROTACAO  ---------------\n\n");
            printf(" </> Pai: %d.\n", pai->numeroNodo);
            printf(" </> Alvo: %d.\n", alvo->numeroNodo);

            if (lado == -1)
            {
                if (rotacao == -2)
                {
                    pai->filhoEsquerda = rotacaoDuplaEsquerda(alvo); /* Funcao RDE */
                    printf(" </> RDE para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == -1)
                {
                    pai->filhoEsquerda = rotacaoSimplesEsquerda(alvo); /* Funcao RSE */
                    printf(" </> RSE para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == 1)
                {
                    pai->filhoEsquerda = rotacaoSimplesDireita(alvo); /* Funcao RSD */
                    printf(" </> RSD para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else
                {
                    pai->filhoEsquerda = rotacaoDuplaDireita(alvo); /* Funcao RDD */
                    printf(" </> RDD para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
            }
            else if (lado == 1)
            {
                if (rotacao == -2)
                {
                    pai->filhoDireita = rotacaoDuplaEsquerda(alvo); /* Funcao RDE */
                    printf(" </> RDE para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == -1)
                {
                    pai->filhoDireita = rotacaoSimplesEsquerda(alvo); /* Funcao RSE */
                    printf(" </> RSE para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else if (rotacao == 1)
                {
                    pai->filhoDireita = rotacaoSimplesDireita(alvo); /* Funcao RSD */
                    printf(" </> RSD para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
                else
                {
                    pai->filhoDireita = rotacaoDuplaDireita(alvo); /* Funcao RDD */
                    printf(" </> RDD para %d que e filho de %d.\n\n", alvo->numeroNodo, pai->numeroNodo);
                }
            }
            printf("---------------------------------------------\n\n");
        }
        else
        {

            printf(" </> O nodo desbalanceado e a raiz.\n\n");
            printf("---------------  3.2 ROTACAO  ---------------\n\n");
            printf(" </> Raiz: %d.\n", alvo->numeroNodo);

            if (rotacao == -2)
            {
                (*pRaiz) = rotacaoDuplaEsquerda(alvo); /* Funcao RDE */
                printf(" </> RDE para %d que e a raiz.\n\n", alvo->numeroNodo);
            }
            else if (rotacao == -1)
            {
                (*pRaiz) = rotacaoSimplesEsquerda(alvo); /* Funcao RSE */
                printf(" </> RSE para %d que e a raiz.\n\n", alvo->numeroNodo);
            }
            else if (rotacao == 1)
            {
                (*pRaiz) = rotacaoSimplesDireita(alvo); /* Funcao RSD */
                printf(" </> RSD para %d que e a raiz.\n\n", alvo->numeroNodo);
            }
            else
            {
                (*pRaiz) = rotacaoDuplaDireita(alvo); /* Funcao RDD */
                printf(" </> RDD para %d que e a raiz.\n\n", alvo->numeroNodo);
            }
            printf("---------------------------------------------\n\n");
        }

        printf(" </> Rotacao bem sucedida.\n");
        printf(" </> Balanceamento completo.\n\n");
        printf("--------------  3.3 ALTERACAO  --------------\n\n");
        printf(" </> Alterando dados do(s) nodo(s).\n");
        alterarDadosNodo((*pRaiz), 1);
        printf(" </> Dados alterados.\n\n");
        printf("---------------------------------------------\n\n");
    }
    else
        printf(" </> Nao ha nodo(s) desbalanceado(s).\n");

    return;
};

// removerNodo: Determina o nodo a ser removido.

void removerNodo(Nodo **pRaiz)
{
    mostrarArvoreSimplificada((*pRaiz), (*pRaiz)->alturaNodo);

    Nodo *alvo = NULL;
    short numero;
    while (1)
    {
        printf(" </> Informe o numero do nodo: ");
        scanf("%hd", &numero);
        printf(" </> Buscando nodo.\n");

        if (!verificarTamanhoNumero(numero))
        {
            printf("\n");
            printf(" </> O numero deve ser entre -9999 e 9999!\n\n");
            continue;
        }

        alvo = verificarExistenciaNodo((*pRaiz), numero);

        if (!alvo)
        {
            printf("\n");
            printf(" </> Nao existe um nodo com este numero!\n\n");
        }
        else
            printf(" </> Nodo encontrado.\n");
        break;
    }

    printf(" </> Removendo nodo %d.\n", alvo->numeroNodo);
    (*pRaiz) = remover((*pRaiz), alvo->numeroNodo); /* Funca REMOCAO */
    printf(" </> Nodo removido com sucesso.\n\n");

    return;
};