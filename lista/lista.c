//
// Created by lucas on 08/12/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista *criaLista()
{
    Lista *lista = malloc(sizeof(Lista));

    if (lista == NULL)
    {
        printf("Erro ao cria a lista\n");
    }

    lista->pNo = NULL;

    return lista;
}

void destruirLista(Lista *l)
{
    No *aux, *aux2;
    if (l == NULL)
    {
        printf("Lista == NULL\n");
        return;
    }

    aux = l->pNo;

    while (aux != NULL)
    {
        aux2 = aux;
        aux = aux->prox;
        free(aux2);
    }

    free(l);
}

int tamanho(Lista *l)
{
    int count = 0;
    No *aux;

    if (l == NULL)
    {
        printf("Lista == NULL\n");
        return 0;
    }

    aux = l->pNo;

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }

    return count;
}

No *buscaPeloIndice(Lista *l, int i)
{
    No *aux;
    int count = 0;

    if (l == NULL)
    {
        printf("List invalida\n");
        return NULL;
    }

    if (i < 0)
    {
        printf("Indice invalido\n");
        return NULL;
    }

    aux = l->pNo;

    while (count != i)
    {
        aux = aux->prox;
        count++;

        if (aux->prox == NULL)
        {
            break;
        }
    }

    if (count != i)
    {
        return NULL;
    }

    return aux;
}

No *buscaPelaChave(Lista *l, int c)
{
    No *aux;

    if (l == NULL)
    {
        printf("List invalida\n");
        return NULL;
    }

    aux = l->pNo;

    while (aux->prox != NULL)
    {
        if (aux->chave == c)
        {
            break;
        }
        aux = aux->prox;
    }

    if (aux->chave != c)
    {
        return NULL;
    }

    return aux;
}

No *adicionaItemNoFinal(Lista *l, int c)
{
    No *elemento, *aux;

    if (l == NULL)
    {
        printf("List invalida\n");
        return NULL;
    }

    elemento = malloc(sizeof(No));

    if (elemento == NULL)
    {
        printf("Elemento == NULL\n");
        return NULL;
    }

    elemento->chave = c;
    elemento->prox = NULL;

    if (l->pNo == NULL)
    {
        l->pNo = elemento;
    }
    else
    {
        aux = l->pNo;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = elemento;
    }
    return elemento;
}

No *adicionaItemNoInicio(Lista *l, int c)
{
    No *elemento, *aux;

    if (l == NULL)
    {
        printf("Lista igual a NULL\n");
        return NULL;
    }

    elemento = malloc(sizeof(No));

    elemento->chave = c;
    elemento->prox = NULL;

    if (l->pNo == NULL)
    {
        l->pNo = elemento;
    }
    else
    {
        aux = l->pNo;
        elemento->prox = aux;

        l->pNo = elemento;
    }

    return elemento;
}

void imprimeLista(Lista *l)
{
    No *aux;
    int count = 0;

    if (l == NULL || l->pNo == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    aux = l->pNo;

    int t = tamanho(l);

    printf("[");
    while (aux != NULL)
    {
        printf("%d", aux->chave);
        if(count != t-1) {
            printf(",");
        }
        count++;
        aux = aux->prox;
    }
    printf("]\n");
}