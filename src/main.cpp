#include <iostream>
#include "segtree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    SegTree segTree(n);

    for (int i = 0; i < q; i++) {
        char operacao;
        std::cin >> operacao;

        if (operacao == 'u') {
            int instante;
            std::cin >> instante;
            int valores[4];
            for (int j = 0; j < 4; j++) {
                std::cin >> valores[j];
            }
            Matriz novaMatriz;
            novaMatriz.Insere(valores);
            segTree.Atualiza(1, instante, novaMatriz, 0, n - 1);
        } else if (operacao == 'q') {
            int t0, td, x, y;
            std::cin >> t0 >> td >> x >> y;
            Matriz resultado = segTree.Consulta(t0, td, 1, 0, n - 1);
            int* coordenadas = resultado.GeraCordenada(x, y);
            std::cout << coordenadas[0]  << " " << coordenadas[1]  << std::endl;
            delete[] coordenadas;
        }
    }

    return 0;
}