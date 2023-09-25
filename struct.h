/* -----------------  Nodo  ------------------- */

typedef struct Nodo
{

    short numeroNodo;

    short nivelNodo;

    short grauNodo;

    short alturaNodo;

    struct Nodo *filhoDireita;

    short alturaDireita;

    struct Nodo *filhoEsquerda;

    short alturaEsquerda;

    short fatorBalanceamento;

} Nodo;

/* -------------------------------------------- */