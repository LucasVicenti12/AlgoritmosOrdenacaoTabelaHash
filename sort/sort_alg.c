//
// Created by lucas on 08/12/2024.
//

#include "../lista/lista.h"
#include "sort_alg.h"

#include <stdio.h>

void trocaValores(Elemento *a, Elemento *b) {
    int temp = a->valor;
    a->valor = b->valor;
    b->valor = temp;
}

void bubblesort(Lista *l) {
    if (l == NULL || l->pElemento->prox == NULL) {
        printf("Lista vazia");
        return;
    }

    Elemento *i = l->pElemento;

    while(i != NULL) {
        Elemento *j = l->pElemento;
        while(j->prox != NULL) {
            if(j->valor > j->prox->valor) {
                trocaValores(j, j->prox);
            }

            j = j->prox;
        }
        i = i->prox;
    }
}

void selectionsort(Lista *l) {
    if(l == NULL || l->pElemento == NULL) {
        printf("Lista vazia");
        return;
    }

    Elemento *i = l->pElemento, *j, *min;

    while(i->prox != NULL) {
        min = i;
        j = min->prox;
        while(j != NULL) {
            if(j->valor < min->valor) {
                min = j;
            }

            j = j->prox;
        }
        trocaValores(i, min);

        i = i->prox;
    }
}