Nodo *rotacaoDuplaEsquerda(Nodo *nodo)
{
    nodo->filhoDireita = rotacaoSimplesDireita(nodo->filhoDireita);
    return rotacaoSimplesEsquerda(nodo);
}