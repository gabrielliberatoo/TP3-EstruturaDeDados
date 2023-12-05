#include "Matriz.hpp"
#include <iostream>

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

    resultado.dados[0][0] = (dados[0][0] * A.dados[0][0] + dados[0][1] * A.dados[1][0]) % 100000000;
    resultado.dados[0][1] = (dados[0][0] * A.dados[0][1] + dados[0][1] * A.dados[1][1]) % 100000000;
    resultado.dados[1][0] = (dados[1][0] * A.dados[0][0] + dados[1][1] * A.dados[1][0]) % 100000000;
    resultado.dados[1][1] = (dados[1][0] * A.dados[0][1] + dados[1][1] * A.dados[1][1]) % 100000000;

    return resultado;
}
