//
// Created by lucas on 20/12/2024.
//

#ifndef ARVORE_H
#define ARVORE_H

typedef struct NoArv {
    int valor;
    struct NoArv *esq;
    struct NoArv *dir;
} NoArv;

typedef struct Arvore {
    NoArv *raiz;
} Arvore;

Arvore *CriaArvore();
NoArv *InserirNo(NoArv *no, int valor);
int BuscarArvore(NoArv *no, int valor);
void ImprimeArvore(NoArv *no);
NoArv *RemoverNo(NoArv *no, int valor);
NoArv *RemoveRaiz(NoArv *no);

#endif //ARVORE_H
