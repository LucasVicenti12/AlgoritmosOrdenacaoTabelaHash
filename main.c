#include "lista/lista.h"

int main(void) {
    Lista *lista = criaLista();

    adicionaItemNoFinal(lista, 12);
    adicionaItemNoFinal(lista, 15);
    adicionaItemNoFinal(lista, 18);

    imprimeLista(lista);

    return 0;
}
