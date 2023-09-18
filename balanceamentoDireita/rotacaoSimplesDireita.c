
Nodo *rotacaoSimplesDireita(Nodo *y) //realiza rotacao a direita
{
    Nodo *backup = y->filhoEsquerda;
    y->filhoEsquerda = backup->filhoDireita;
    backup->filhoDireita = y;
    return backup;
}


