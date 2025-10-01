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
        return NULL;
    }

    lista->pElemento = NULL;

    return lista;
}

void destruirLista(Lista *l)
{
    Elemento *atual, *removido;
    if (l == NULL)
    {
        printf("Lista == NULL\n");
        return;
    }

    atual = l->pElemento;

    while (atual != NULL)
    {
        removido = atual;
        atual = atual->prox;
        free(removido);
    }

    free(l);
}

int tamanho(Lista *l)
{
    int count = 0;
    Elemento *aux;

    if (l == NULL)
    {
        printf("Lista == NULL\n");
        return 0;
    }

    aux = l->pElemento;

    while (aux != NULL)
    {
        count++;
        aux = aux->prox;
    }

    return count;
}

Elemento *buscaPeloIndice(Lista *l, int i)
{
    Elemento *aux;
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

    aux = l->pElemento;

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

Elemento *buscaPelaChave(Lista *l, int c)
{
    Elemento *aux;

    if (l == NULL)
    {
        printf("List invalida\n");
        return NULL;
    }

    aux = l->pElemento;

    while (aux->prox != NULL)
    {
        if (aux->valor == c)
        {
            break;
        }
        aux = aux->prox;
    }

    if (aux->valor != c)
    {
        return NULL;
    }

    return aux;
}

Elemento *adicionaItemNoFinal(Lista *l, int c)
{
    Elemento *elemento, *aux;

    if (l == NULL)
    {
        printf("List invalida\n");
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    if (elemento == NULL)
    {
        printf("Elemento == NULL\n");
        return NULL;
    }

    elemento->valor = c;
    elemento->prox = NULL;

    if (l->pElemento == NULL)
    {
        l->pElemento = elemento;
    }
    else
    {
        aux = l->pElemento;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = elemento;
    }
    return elemento;
}

Elemento *adicionaItemNoInicio(Lista *l, int c)
{
    Elemento *elemento, *aux;

    if (l == NULL)
    {
        printf("Lista igual a NULL\n");
        return NULL;
    }

    elemento = malloc(sizeof(Elemento));

    elemento->valor = c;
    elemento->prox = NULL;

    if (l->pElemento == NULL)
    {
        l->pElemento = elemento;
    }
    else
    {
        aux = l->pElemento;
        elemento->prox = aux;

        l->pElemento = elemento;
    }

    return elemento;
}

void imprimeLista(Lista *l)
{
    Elemento *aux;
    int count = 0;

    if (l == NULL || l->pElemento == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    aux = l->pElemento;

    int t = tamanho(l);

    printf("[");
    while (aux != NULL)
    {
        printf("%d", aux->valor);
        if(count != t-1) {
            printf(",");
        }
        count++;
        aux = aux->prox;
    }
    printf("]\n");
}