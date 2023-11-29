#ifndef MATRIZ_HPP
#define MATRIZ_HPP

class Matriz{

public:

    //Construtor que inicializa a matriz como a matriz de identidade
    Matriz();

    //Método que insere valores na matriz
    void Insere(int valores[4]);

    //Método para multiplicar duas Matrizes
    Matriz MultiplicaMatriz(Matriz A);

    //Método para multiplicar a matriz pela cordenada
    void GeraCordenada(int cord[2]);

private:
    //Matriz 2x2
    int dados[2][2];

};


#endif