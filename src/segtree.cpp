#include "segtree.hpp"

SegTree::SegTree(int n){
    tamanho = n;
    matrizes = new Matriz[n];
    arvore = new Matriz[4*n];
}

SegTree::~SegTree(){
    delete arvore;
}

Matriz SegTree::Constroi(int noArvore, int inicial, int final){
    if(inicial==final) {
        return arvore[noArvore] = matrizes[inicial];
    }

    int m = (inicial+final)/2;
    
    Matriz matrizEsquerda = Constroi(2 * noArvore, inicial, m);
    Matriz matrizDireita = Constroi(2 * noArvore + 1, m + 1, final);

    arvore[noArvore] = matrizEsquerda.MultiplicaMatriz(matrizDireita);

    return arvore[noArvore];
}

void SegTree::Atualiza(int noArvore, int posicao, Matriz novaMatriz, int inicial, int final){
        if (posicao < inicial || posicao > final) {
            return;
        }

        
        if (inicial == final) {
            arvore[noArvore] = novaMatriz;
            return;
        }

        int m = (inicial + final) / 2;
        Atualiza(2 * noArvore, posicao, novaMatriz, inicial, m);
        Atualiza(2 * noArvore + 1, posicao, novaMatriz, m + 1, final);

        arvore[noArvore] = arvore[2 * noArvore].MultiplicaMatriz(arvore[2 * noArvore + 1]);
}

Matriz SegTree::Consulta(int a, int b,int noArvore, int inicial, int final){
            if (inicial > b || final < a) {
            return;
        }

        if (inicial >= a && final <= b) {
            return arvore[noArvore];
        }

        
        int m = (inicial + final) / 2;

        Matriz matrizEsquerda = Consulta(2 * noArvore, inicial, m, a, b);
        Matriz matrizDireita = Consulta(2 * noArvore + 1, m + 1, final, a, b);

        return matrizEsquerda.MultiplicaMatriz(matrizDireita);
    }

     
