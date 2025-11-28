#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int testcases;
    cin >> testcases;
    while(testcases--) {
        string arvore;
        cin >> arvore;

        // pilha guarda quantos filhos ainda faltam
        vector<int> pilha;

        // comeca pela raiz
        pilha.push_back(1);

        int profundidade_maxima = 0;

        for (int i = 0; i < arvore.length(); i++) {
            char tipo = arvore[i];

            // o no atual conta como 1 filho processado
            pilha.back()--;

            // profundidade atual e o tamanho da pilha - 1
            int profundidade_atual = pilha.size() - 1;

            // calcula o maximo
            if (profundidade_atual > profundidade_maxima) {
                profundidade_maxima = profundidade_atual;
            }

            // se for n ele abre para os 2 filhos
            if (tipo == 'n') {
                pilha.push_back(2);
            }

            // limpeza, se o topo chegar a 0 e pq n tem mais filhos
            while (!pilha.empty() && pilha.back() == 0) {
                pilha.pop_back();
            }
        }

        cout << profundidade_maxima << endl;
    }

    return 0;
}