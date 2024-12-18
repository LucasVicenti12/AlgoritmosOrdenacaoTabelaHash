//
// Created by lucas on 16/12/2024.
//

#ifndef TABELA_HASH_H
#define TABELA_HASH_H


typedef struct NoHash
{
    struct NoHash *prox;
    int chave;
} NoHash;

typedef struct ListaHash
{
    NoHash *pNoHash;
} ListaHash;

ListaHash *CriaLista();
ListaHash *CriaTabelaHash();

int BuscarLista(ListaHash *l, int c);
int BuscarTabelaHash(ListaHash *l, int c);

NoHash *InsereLista(ListaHash *l, int c);
NoHash *InsereTabelaHash(ListaHash *l, int c);

void MostrarLista(ListaHash *l);
void MostrarTabelaHash(ListaHash *l);

int Hash(int c);

#endif //TABELA_HASH_H
