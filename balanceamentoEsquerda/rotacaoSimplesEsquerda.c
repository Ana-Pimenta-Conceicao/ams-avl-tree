Nodo *rotacaoSimplesEsquerda(Nodo *nodo)
{
    Nodo *auxiliar = nodo->filhoDireita;
    nodo->filhoDireita = backup->filhoEsquerda;
    backup->filhoEsquerda = nodo;
    return auxiliar;
}