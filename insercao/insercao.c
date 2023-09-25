short inserirNodo(Nodo *novoNodo, Nodo **ponteiroNodo) {
    if (*ponteiroNodo == NULL) {
        *ponteiroNodo = novoNodo;
        return 0;
    }

    if (novoNodo->numeroNodo < (*ponteiroNodo)->numeroNodo) {
        if ((*ponteiroNodo)->filhoEsquerda) {
            return inserirNodo(novoNodo, &((*ponteiroNodo)->filhoEsquerda));
        } else {
            (*ponteiroNodo)->filhoEsquerda = novoNodo;
            return (*ponteiroNodo)->nivelNodo;
        }
    } else {
        if ((*ponteiroNodo)->filhoDireita) {
            return inserirNodo(novoNodo, &((*ponteiroNodo)->filhoDireita));
        } else {
            (*ponteiroNodo)->filhoDireita = novoNodo;
            return (*ponteiroNodo)->nivelNodo;
        }
    }
}
