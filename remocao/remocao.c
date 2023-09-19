
// dev
Nodo *remover(Nodo *ponteiroRaiz, Nodo *ponteiroNodo, int chave)
{

    if (ponteiroNodo == NULL)
    {

        printf("Valor não encontrado\n");

        return ponteiroNodo;
    }
    else
    {

        if (ponteiroNodo->numeroNodo == chave)
        {

            if (ponteiroNodo->grauNodo == 0)
            {
                if ((*ponteiroRaiz) != NULL)
                {
                    (*ponteiroRaiz) = NULL;
                    free(ponteiroNodo);
                }
                else
                    free(ponteiroNodo);

                return NULL;
            }
            //////////////
            else
            {

                if (ponteiroNodo->grauNodo == 2)
                {

                    Nodo *aux = ponteiroNodo->filhoEsquerda;

                    while (aux->filhoDireita != NULL)

                        aux = aux->filhoDireita;

                    Nodo *paiAux = ponteiroNodo->filhoEsquerda;
                    if (ponteiroNodo->filhoEsquerda != aux)
                    {
                        while (paiAux->filhoDireita != aux)

                            paiAux = paiAux->filhoDireita;

                        paiAux->filhoDireita = NULL;
                    }
                    else
                    {
                        ponteiroNodo->filhoEsquerda = aux->filhoEsquerda;
                    }

                    ponteiroNodo->numeroNodo = aux->numeroNodo;

                    aux->numeroNodo = chave;

                    printf("Elemento trocado: %d !\n", chave);

                    free(aux);

                    return ponteiroNodo;
                }

                else
                {

                    Nodo *aux;

                    if (ponteiroNodo->filhoEsquerda != NULL)

                        aux = ponteiroNodo->filhoEsquerda;

                    else

                        aux = ponteiroNodo->filhoDireita;

                    free(ponteiroNodo);

                    printf("Elemento com 1 filho removido %d !\n", chave);

                    return aux;
                }
            }
        }
        else
        {

            if (chave < ponteiroNodo->numeroNodo)

                ponteiroNodo->filhoEsquerda = remover(ponteiroRaiz, ponteiroNodo->filhoEsquerda, chave);

            else

                ponteiroNodo->filhoDireita = remover(ponteiroRaiz, ponteiroNodo->filhoDireita, chave);
        }
    }
}