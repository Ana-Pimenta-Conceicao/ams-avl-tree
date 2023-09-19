Nodo *rotacaoDuplaDireita(Nodo *nodoDesbalanceado) //realiza rotacao a direita
{
    nodoDesbalanceado->filhoEsquerda = rotacaoSimplesEsquerda(nodoDesbalanceado->filhoEsquerda);
    return rotacaoSimplesDireita(nodoDesbalanceado);
}
