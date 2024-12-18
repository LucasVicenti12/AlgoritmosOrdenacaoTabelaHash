#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista/lista.h"
#include "sort/sort_alg.h"
#include "tabela_hash/tabela_hash.h"

void preencherListaCrescente(Lista *l, int n) {
    for (int i = 0; i < n; i++) {
        adicionaItemNoFinal(l, i);
    }
}

void preencherListaDecrescente(Lista *l, int n) {
    for (int i = 0; i < n; i++) {
        adicionaItemNoFinal(l, n - i);
    }
}

void preencherListaAleatoria(Lista *l, int n) {
    for (int i = 0; i < n; i++) {
        adicionaItemNoFinal(l, rand() % 10000);
    }
}

double executaTesteTempo(
    void (*preencher(Lista *l, int n)),
    void (*algoritmo(Lista *l)),
    int quantidade
) {
    struct timeval inicio, fim;

    Lista *l = criaLista();

    preencher(l, quantidade);
    mingw_gettimeofday(&inicio, NULL);
    algoritmo(l);
    mingw_gettimeofday(&fim, NULL);

    destruirLista(l);

    return (double) (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
}

void executaTeste(
    char *titulo,
    void (*algoritmo(Lista *l))
) {
    FILE *arquivo = fopen(titulo, "w");
    fprintf(arquivo, "Tamanho da lista; Tempo aleátoria (s); Tempo crescente (s); Tempo decrescente;\n");

    for(int i = 100; i <= 1000; i += 100) {
        double t1 = executaTesteTempo(preencherListaAleatoria, algoritmo, i);
        double t2 = executaTesteTempo(preencherListaCrescente, algoritmo, i);
        double t3 = executaTesteTempo(preencherListaDecrescente, algoritmo, i);

        fprintf(arquivo, "%d;%f;%f;%f;\n", i, t1, t2, t3);
    }

    fclose(arquivo);
}

int main(void) {
    executaTeste("bubblesort.csv", bubblesort);
    executaTeste("selectionsort.csv", selectionsort);

    ListaHash *l = CriaTabelaHash();

    InsereTabelaHash(l, 89);

    MostrarTabelaHash(l);

    printf("Buscar -> %d\n", BuscarTabelaHash(l, 89));
    return 0;
}
