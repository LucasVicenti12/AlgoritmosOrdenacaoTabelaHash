//
// Created by lucas on 20/12/2024.
//

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

Arvore *CriaArvore() {
    Arvore *arvore = malloc(sizeof(Arvore));
    if (arvore == NULL)
        return NULL;

    arvore->raiz = NULL;

    return arvore;
}

NoArv *InserirNo(NoArv *no, int valor) {
    if (no == NULL) {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = valor;
        aux->esq = NULL;
        aux->dir = NULL;
        return aux;
    }
    if (valor < no->valor)
        no->esq = InserirNo(no->esq, valor);
    if (valor > no->valor)
        no->dir = InserirNo(no->dir, valor);

    return no;
}

int BuscarArvore(NoArv *no, int valor) {
    if (no == NULL)
        return -1;
    if (no->valor == valor)
        return no->valor;

    if (valor < no->valor)
        return BuscarArvore(no->esq, valor);
    if (valor > no->valor)
        return BuscarArvore(no->dir, valor);
}

void ImprimeArvore(NoArv *no) {
    if (no == NULL)
        return;
    ImprimeArvore(no->esq);
    printf("%d\t", no->valor);
    ImprimeArvore(no->dir);
}

NoArv *RemoveRaiz(NoArv *no) {
    NoArv *novaRaiz = NULL;

    if(no->esq == NULL) {
        novaRaiz = no->dir;
        free(no);
        return novaRaiz;
    }

    NoArv *pai = no;
    novaRaiz = no->esq;

    while(novaRaiz->dir != NULL) {
        pai = novaRaiz;
        novaRaiz = novaRaiz->dir;
    }

    if(pai != no) {
        pai->dir = novaRaiz->esq;
        novaRaiz->esq = no->esq;
    }

    novaRaiz->dir = no->dir;
    free(no);
    return novaRaiz;
}

NoArv *RemoverNo(NoArv *no, int valor) {
    if (no == NULL)
        return NULL;

    if (valor == no->valor) {
        no = RemoveRaiz(no);
    }else {
        if (valor < no->valor)
            no->esq = RemoverNo(no->esq, valor);
        if (valor > no->valor)
            no->dir = RemoverNo(no->dir, valor);
    }
    return no;
}