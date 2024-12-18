//
// Created by lucas on 16/12/2024.
//

#include "tabela_hash.h"

#include <stdio.h>
#include <stdlib.h>

#define TAM 11

ListaHash *CriaLista() {
    ListaHash *lista = malloc(sizeof(ListaHash));

    if (lista == NULL) return NULL;

    lista->pNoHash = NULL;
    return lista;
}

ListaHash *CriaTabelaHash() {
    ListaHash *tabelaHash = malloc(TAM * sizeof(ListaHash));

    if (tabelaHash == NULL) return NULL;

    for (int i = 0; i < TAM; i++) {
        tabelaHash[i].pNoHash = NULL;
    }

    return tabelaHash;
}

int BuscarLista(ListaHash *l, int c) {
    if (l == NULL || l->pNoHash == NULL) return -1;

    NoHash *aux = l->pNoHash;
    int valor = -1;

    while (aux != NULL) {
        if (aux->chave == c) {
            valor = aux->chave;
            break;
        }
        aux = aux->prox;
    }

    return valor;
}

int BuscarTabelaHash(ListaHash *l, int c) {
    if (l == NULL || l->pNoHash == NULL) return -1;

    int chave = Hash(c);

    return BuscarLista(&l[chave], c);
}

NoHash *InsereLista(ListaHash *l, int c) {
    if (l == NULL) return;

    NoHash *aux = malloc(sizeof(NoHash));

    if (aux == NULL) return;

    aux->chave = c;
    aux->prox = NULL;

    if (l->pNoHash == NULL) {
        l->pNoHash = aux;
    } else {
        NoHash *aux2 = l->pNoHash;
        while (aux2->prox != NULL) {
            aux2 = aux2->prox;
        }
        aux2->prox = aux;
    }

    return aux;
}
NoHash *InsereTabelaHash(ListaHash *l, int c) {
    if (l == NULL) return;

    int chave = Hash(c);

    return InsereLista(&l[chave], c);
}

void MostrarLista(ListaHash *l) {
    if (l == NULL || l->pNoHash == NULL) return;

    NoHash *aux = l->pNoHash;

    printf("[");
    while (aux->prox != NULL) {
        printf("%d,", aux->chave);
        aux = aux->prox;
    }
    printf("%d]\n", aux->chave);
}
void MostrarTabelaHash(ListaHash *l) {
    if (l == NULL) {
        printf("Tabela hash nao inicializada\n");
        return;
    }

    for (int i = 0; i < TAM; i++) {
        printf("ID -> %d: ", i);
        MostrarLista(&l[i]);
        printf("\n");
    }
}

int Hash(int c) {
    return c % TAM;
}