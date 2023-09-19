/* ------------  Funcionalidades  ------------ */

void mostrarArvoreSimplificada(Nodo *nodo, short altura);

void mostrarArvoreDetalhada(Nodo *nodo, short altura);

/* ------------------------------------------- */

// mostrarArvoreSimplificada: Implime a arvore ao usuario mostrando os nodos e seus fatores.

void mostrarArvoreSimplificada(Nodo *nodo, short altura)
{
    short i;
    if (nodo == NULL)
    {

        int linhas = pow(2, altura);
        linhas = (linhas + (linhas - 2)) / 2;

        for (i = 0; i < linhas; i++)
        {
            printf("\n\n");
        }
    }
    else
    {

        mostrarArvoreSimplificada(nodo->filhoDireita, (altura - 1));

        for (i = 0; i < nodo->nivelNodo; i++)
        {
            printf("           ");
        }

        printf(" (%5d)%2hd \n\n", nodo->numeroNodo, nodo->fatorBalanceamento);

        mostrarArvoreSimplificada(nodo->filhoEsquerda, (altura - 1));
    }

    return;
};

// mostrarArvoreDetalhada: Implime a arvore em barras mostrando os dados dos nodos.

void mostrarArvoreDetalhada(Nodo *nodo, short altura)
{

    if (nodo != NULL)
    {

        printf("|  %5d |   %2hd  |   %2hd   |   %hd  |   %2hd  |     %hd    |    %hd    | ", nodo->numeroNodo, nodo->nivelNodo, nodo->alturaNodo, nodo->grauNodo, nodo->fatorBalanceamento, nodo->alturaEsquerda, nodo->alturaDireita);

        short i;
        for (i = 1; i < nodo->nivelNodo; i++)
        {
            printf("       ");
        }

        printf(" %5d ", nodo->numeroNodo);

        for (i = nodo->nivelNodo; i < altura; i++)
        {
            printf("-------");
        }
        printf("|\n");

        printf("                                                                ");
        for (i = 1; i < (altura + 1); i++)
        {
            printf("       ");
        }
        printf("|\n");

        mostrarArvoreDetalhada(nodo->filhoEsquerda, altura);
        mostrarArvoreDetalhada(nodo->filhoDireita, altura);
    }

    return;
};