#include <iostream>
#include "Matriz.hpp"
#include "Segtree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;

    Matriz* transformacoes = new Matriz[n];
    for (int i = 0; i < n; ++i) {
        transformacoes[i] = Matriz();
    }

    SegTree arvore(n);

    for (int i = 0; i < q; ++i) {
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
            arvore.Atualiza(1, instante, novaMatriz, 0, n - 1);
        }else if (operacao == 'q') {
    int t0, td, x, y;
    std::cin >> t0 >> td >> x >> y;

    Matriz resultado = arvore.Consulta(t0, td, 1, 0, n - 1);

    long long final_x = (resultado.dados[0][0] * x + resultado.dados[0][1] * y) % 100000000;
    long long final_y = (resultado.dados[1][0] * x + resultado.dados[1][1] * y) % 100000000;

    std::cout << final_x << " " << final_y << std::endl;
}


    }

    delete[] transformacoes;

    return 0;
}
