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

    //Método para calcular as cordenadas do ponto final
    int* GeraCordenada(int x, int y);
    
    //Matriz 2x2
    long long dados[2][2];

};


#endif