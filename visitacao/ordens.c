void preOrdem (Nodo *endNodo){
if (endNodo != NULL)
{
    printf("%d", endNodo->numeroNodo);
    preOrdem(endNodo->filhoEsquerda);
    preOrdem(endNodo->filhoDireita);
}
}

void emOrdem (Nodo *endNodo){
if (endNodo != NULL)
{
    emOrdem(endNodo->filhoEsquerda);
    printf("%d", endNodo->numeroNodo);
    emOrdem(endNodo->filhoDireita);
}    
}

void posOrdem (Nodo *endNodo){
if (endNodo != NULL)
{
    posOrdem(endNodo->filhoEsquerda);
    posOrdem(endNodo->filhoDireita);
    printf("%d", endNodo->numeroNodo);
}   
}