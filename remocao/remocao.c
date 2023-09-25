Nodo *remover(Nodo *pRaiz, short chave)
{

    if (pRaiz == NULL)
    {

        printf(" </> Elemento não encontrado\n");

        return pRaiz;
    }
    else
    {

        if (pRaiz->numeroNodo == chave)
        {

            if (pRaiz->filhoEsquerda == NULL && pRaiz->filhoDireita == NULL)
            {

                free(pRaiz);

                printf(" </> Elemento folha removido %d!\n", chave);

                return NULL;
            }

            else
            {

                if (pRaiz->filhoEsquerda != NULL && pRaiz->filhoDireita != NULL)
                {

                    Nodo *aux = pRaiz->filhoEsquerda;

                    while (aux->filhoDireita != NULL)

                        aux = aux->filhoDireita;

                    Nodo *paiAux = pRaiz->filhoEsquerda;
                    if (pRaiz->filhoEsquerda != aux)
                    {
                        while (paiAux->filhoDireita != aux)

                            paiAux = paiAux->filhoDireita;

                        paiAux->filhoDireita = aux->filhoEsquerda;
                    }
                    else
                    {
                        pRaiz->filhoEsquerda = aux->filhoEsquerda;
                    }

                    pRaiz->numeroNodo = aux->numeroNodo;

                    aux->numeroNodo = chave;

                    printf(" </> Elemento trocado: %d !\n", chave);

                    free(aux);

                    return pRaiz;
                }

                else
                {

                    Nodo *aux;

                    if (pRaiz->filhoEsquerda != NULL)

                        aux = pRaiz->filhoEsquerda;

                    else

                        aux = pRaiz->filhoDireita;

                    free(pRaiz);

                    printf(" </> Elemento com 1 filho removido %d !\n", chave);

                    return aux;
                }
            }
        }
        else
        {

            if (chave < pRaiz->numeroNodo)

                pRaiz->filhoEsquerda = remover(pRaiz->filhoEsquerda, chave);

            else

                pRaiz->filhoDireita = remover(pRaiz->filhoDireita, chave);

            return pRaiz;
        }
    }
}