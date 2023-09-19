
Nodo *rotacaoSimplesDireita(Nodo *nodoDesbalanceado) //realiza rotacao a direita
{
    Nodo *backup = nodoDesbalanceado->filhoEsquerda;
    nodoDesbalanceado->filhoEsquerda = backup->filhoDireita;
    backup->filhoDireita = nodoDesbalanceado;
    return backup;
}


