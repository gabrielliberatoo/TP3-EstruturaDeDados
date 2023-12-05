#include "Segtree.hpp"
#include <iostream>

SegTree::SegTree(int n) {
    tamanho = n;
    matrizes = new Matriz[n];
    arvore = new Matriz[4 * n];

    for (int i = 0; i < n; i++) {
        matrizes[i] = Matriz();  // Inicializar com matriz nula
    }

    // Construir a árvore usando matrizes nulas
    Constroi(1, 0, n - 1);
}

SegTree::~SegTree() {
    delete[] arvore;
}

Matriz SegTree::Constroi(int noArvore, int inicial, int final) {
    if (inicial == final) {
        return arvore[noArvore] = matrizes[inicial];
    }

    int m = (inicial + final) / 2;

    Matriz matrizEsquerda = Constroi(2 * noArvore, inicial, m);
    Matriz matrizDireita = Constroi(2 * noArvore + 1, m + 1, final);

    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);

    return arvore[noArvore];
}

Matriz SegTree::Atualiza(int noArvore, int posicao, Matriz novaMatriz, int inicial, int final) {
    if (posicao < inicial || posicao > final) {
        return arvore[noArvore];
    }

    if (inicial == final) {
        arvore[noArvore] = novaMatriz;
        return arvore[noArvore];
    }

    int m = (inicial + final) / 2;

    Matriz matrizEsquerda = Atualiza(2 * noArvore, posicao, novaMatriz, inicial, m);
    Matriz matrizDireita = Atualiza(2 * noArvore + 1, posicao, novaMatriz, m + 1, final);

    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);

    return arvore[noArvore];
}



Matriz SegTree::Consulta(int a, int b, int noArvore, int inicial, int final) {
    if (inicial > b || final < a) {
        return Matriz();
    }

    if (inicial >= a && final <= b) {
        return arvore[noArvore];
    }

    int m = (inicial + final) / 2;

    Matriz matrizEsquerda = Consulta(a, b, 2 * noArvore, inicial, m);
    Matriz matrizDireita = Consulta(a, b, 2 * noArvore + 1, m + 1, final);

    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);
    return arvore[noArvore];
}

