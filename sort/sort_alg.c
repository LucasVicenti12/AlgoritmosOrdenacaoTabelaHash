//
// Created by lucas on 08/12/2024.
//

#include "../lista/lista.h"
#include "sort_alg.h"

#include <stdio.h>

void trocaValores(No *a, No *b) {
    int temp = a->chave;
    a->chave = b->chave;
    b->chave = temp;
}

void bubblesort(Lista *l) {
    if (l == NULL || l->pNo->prox == NULL) {
        printf("Lista vazia");
        return;
    }

    No *i = l->pNo;

    while(i != NULL) {
        No *j = l->pNo;
        while(j->prox != NULL) {
            if(j->chave > j->prox->chave) {
                trocaValores(j, j->prox);
            }

            j = j->prox;
        }
        i = i->prox;
    }
}

void selectionsort(Lista *l) {
    if(l == NULL || l->pNo == NULL) {
        printf("Lista vazia");
        return;
    }

    No *i = l->pNo, *j, *min;

    while(i->prox != NULL) {
        min = i;
        j = min->prox;
        while(j != NULL) {
            if(j->chave < min->chave) {
                min = j;
            }

            j = j->prox;
        }
        trocaValores(i, min);

        i = i->prox;
    }
}