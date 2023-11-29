#ifndef MATRIZ_HPP
#define MATRIZ_HPP

class Matriz{

public:

    //Contrutor da classe matriz
    Matriz();

    //Método para multiplicar duas Matrizes
    Matriz MultiplicaMatriz(Matriz A);

    //Método para multiplicar a matriz pela cordenada
    void GeraCordenada(int cord[2]);

private:
    //Matriz 2x2
    int data[2][2];

};


#endif