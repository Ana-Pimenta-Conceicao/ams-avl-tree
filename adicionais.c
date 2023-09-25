/* ------------ Funcionalidades ------------- */

void menu(short *opcao);

void opcaoInexistente();

short max(short a, short b);

void limparMemoria(Nodo *nodo);

void encerrarPrograma();

/* -------------------------------------------- */

// menu: Imprime as funcionalidades ao usuario.

void menu(short *opcao)
{

    while (1)
    {

        printf("\n-------------  MENU  -------------\n\n");
        printf("    [1] Inserir   Nodo\n");
        printf("    [2] Remover   Nodo\n");
        printf("    [3] Visitar   Arvore\n");
        printf("    [4] Mostrar   Arvore\n");
        printf("    [0] Encerrar  Software\n\n");
        printf("----------------------------------\n\n");

        printf(" </> Informe o numero da opcao: ");
        scanf("%hd", opcao);
        printf("\n");

        if (*opcao >= 0 && *opcao < 4)
            break;

        else if (*opcao == 4)
        {

            printf("----------------------------------\n\n");
            printf("    [5] Convencional  Simplificada\n");
            printf("    [6] Em Barras     Detalhada\n");
            printf("    [0] Voltar\n\n");
            printf("----------------------------------\n\n");

            printf(" </> Informe o numero da opcao: ");
            scanf("%hd", opcao);
            printf("\n");

            if (*opcao >= 5 && *opcao < 8)
                break;

            else if (*opcao == 0)
                continue;
        }

        opcaoInexistente();
    }

    return;
};

// opcaoInexistente: Alerta que a opcao informada nao existe.

void opcaoInexistente()
{

    printf(" </> A opcao informada nao existe!\n\n\n");

    return;
};

// verificarTamanhoNumero: Verifica se o número passado por parâmetro está dentro do requisito.

short verificarTamanhoNumero(short numero)
{
    if (numero > -9999 && numero < 9999)
        return 1;
    else
        return 0;
};

// max: Encontra o maior valor passado por parametro.

short max(short a, short b)
{
    return (a > b) ? a : b;
};

// limparMemoria: Libera os espacos de memoria reservados para os nodos da arvore.

void limparMemoria(Nodo *nodo)
{

    if (nodo)
    {
        limparMemoria(nodo->filhoEsquerda);
        limparMemoria(nodo->filhoDireita);
        free(nodo);
    }

    return;
};

// encerrarPrograma: Despedida.

void encerrarPrograma()
{

    printf(" </> Agradecemos por utilizar nosso software.\n\n");

    return;
};