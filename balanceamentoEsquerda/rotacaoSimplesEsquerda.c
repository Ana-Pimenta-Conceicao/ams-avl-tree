Nodo *rotacaoSimplesEsquerda(Nodo *nodo)
{
    Nodo *auxiliar = nodo->filhoDireita;
    nodo->filhoDireita = auxiliar->filhoEsquerda;
    auxiliar->filhoEsquerda = nodo;
    return auxiliar;
}
