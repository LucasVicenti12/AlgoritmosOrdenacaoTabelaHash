//
// Created by lucas on 08/12/2024.
//

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct No
{
    struct No *prox;
    int chave;
} No;

typedef struct Lista
{
    No *pNo;
} Lista;

// Cria uma lista com tamanho definido
Lista *criaLista();
// Destroi a lista
void destruirLista(Lista *l);
// Retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista *l);

// Buscar um dado pela chave
No *buscaPelaChave(Lista *l, int c);
// Retorna um elemento pela posição
No *buscaPeloIndice(Lista *l, int i);
// Adiciona um item no final da lista
No *adicionaItemNoFinal(Lista *l, int c);
// Adiciona um item no inicio da lista
No *adicionaItemNoInicio(Lista *l, int c);
// Percorre a lista
void imprimeLista(Lista *l);


#endif //LISTA_H_INCLUDED