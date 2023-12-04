#include "matriz.hpp"

Matriz::Matriz() {
    dados[0][0] = 1;
    dados[0][1] = 0;
    dados[1][0] = 0;
    dados[1][1] = 1;
}

void Matriz::Insere(int valores[4]) {
    dados[0][0] = valores[0];
    dados[0][1] = valores[1];
    dados[1][0] = valores[2];
    dados[1][1] = valores[3];
}

Matriz Matriz::MultiplicaMatriz(Matriz A) {
    Matriz resultado;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultado.dados[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                resultado.dados[i][j] += dados[i][k] * A.dados[k][j];
            }
        }
    }

    return resultado;
}

int* Matriz::GeraCordenada(int x, int y) {
    int* resultado = new int[2];

    resultado[0] = dados[0][0] * x + dados[0][1] * y;
    resultado[1] = dados[1][0] * x + dados[1][1] * y;

    return resultado;
}
