//
// Created by lucas on 08/12/2024.
//

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Elemento
{
    struct Elemento *prox;
    int valor;
} Elemento;

typedef struct Lista
{
    Elemento *pElemento;
} Lista;

// Cria uma lista com tamanho definido
Lista *criaLista();
// Destroi a lista
void destruirLista(Lista *l);
// Retorna o tamanho da lista (numero de elementos inseridos)
int tamanho(Lista *l);

// Buscar um dado pela chave
Elemento *buscaPelaChave(Lista *l, int c);
// Retorna um elemento pela posição
Elemento *buscaPeloIndice(Lista *l, int i);
// Adiciona um item no final da lista
Elemento *adicionaItemNoFinal(Lista *l, int c);
// Adiciona um item no inicio da lista
Elemento *adicionaItemNoInicio(Lista *l, int c);
// Percorre a lista
void imprimeLista(Lista *l);


#endif //LISTA_H_INCLUDED