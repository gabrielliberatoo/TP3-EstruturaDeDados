#ifndef SEGTREE_HPP
#define SEGTREE_HPP 

#include "Matriz.hpp"


class SegTree{

public:
    //Contrutor que inicializa a árvore apenas com matrizes identidade
    SegTree(int n);

    //Destrutor da clasee
    ~SegTree();

    //Constroi a arvore de forma recursiva
    Matriz Constroi(int noArvore, int inicial, int final);

    //Método para inserir uma matriz na arvore
    Matriz Atualiza(int noArvore, int posicao, Matriz novaMatriz, int inicial, int final);

    //Método que realiza a consulta na matriz
    Matriz Consulta(int a, int b,int noArvore, int inicial, int final);


private:
    //Intervalo de tempo correspondente da arvore
    int tamanho;
    //Array com as matrizes presentes na árvore
    Matriz* matrizes;
    //Array que armazena os nós da árvore
    Matriz* arvore;

};






#endif