#include "segtree.hpp"
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
    std::cout << "Chamada da função Atualiza: noArvore=" << noArvore << ", posicao=" << posicao
         << ", inicial=" << inicial << ", final=" << final << std::endl;

    if (posicao < inicial || posicao > final) {
        std::cout << "Posição fora do intervalo. Retornando a matriz atual do nó " << noArvore << std::endl;
        return arvore[noArvore];
    }

    if (inicial == final) {
        std::cout << "Posição encontrada. Atualizando a matriz do nó " << noArvore << std::endl;
        arvore[noArvore] = novaMatriz;
        return arvore[noArvore];
    }

    int m = (inicial + final) / 2;
    std::cout << "Dividindo intervalo em dois: [" << inicial << ", " << m << "] e [" << m + 1 << ", " << final << "]" << std::endl;

    Matriz matrizEsquerda = Atualiza(2 * noArvore, posicao, novaMatriz, inicial, m);
    Matriz matrizDireita = Atualiza(2 * noArvore + 1, posicao, novaMatriz, m + 1, final);

    std::cout << "Multiplicando as matrizes dos filhos " << 2 * noArvore << " e " << 2 * noArvore + 1 << std::endl;
    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);

    std::cout << "Matriz resultante no nó " << noArvore << ":" << std::endl;
    std::cout << "Matriz resultante no nó " << noArvore << ":" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << arvore[noArvore].dados[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

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

    Matriz matrizEsquerda = Consulta(2 * noArvore, inicial, m, a, b);
    Matriz matrizDireita = Consulta(2 * noArvore + 1, m + 1, final, a, b);
    
    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);
    return arvore[noArvore];
}
