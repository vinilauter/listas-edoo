#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hash_func(string chave) {
    int soma = 0;
    for (int i = 0; i < chave.length(); i++) {
        // static cast converte para ASCII e multiplica pela posicao
        soma += static_cast<int>(chave[i]) * (i + 1);
    }
    return (19 * soma) % 101;
}

// passagem por referencia (&) para alterar a tabela original
void func_add (string chave, vector<string> &tabela) {
    int hash_base = hash_func(chave);

    // verifica iguais percorrendo a sequencia de colisoes
    for (int j = 0; j < 20; j++) {
        int pos;
        if (j == 0) pos = hash_base;
        else pos = (hash_base + j*j + 23*j) % 101;

        if (tabela[pos] == chave) return; // ja existe, ignora
    }

    // procura vaga livre
    for (int j = 0; j < 20; j++) { // j comeca em 0 para testar o hash original
        int pos;
        if (j == 0) pos = hash_base;
        else pos = (hash_base + j*j + 23*j) % 101;

        if (tabela[pos] == "") {
            tabela[pos] = chave; // insere na vaga vazia
            return;
        }
    }
}

void func_del (string chave, vector<string> &tabela) {
    int hash_base = hash_func(chave);

    // busca a chave para deletar
    for (int j = 0; j < 20; j++) {
        int pos;
        if (j == 0) pos = hash_base;
        else pos = (hash_base + j*j + 23*j) % 101;

        // so deleta se a chave for exata
        if (tabela[pos] == chave) {
            tabela[pos] = "";
            return;
        }
    }
}

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int n_ops;
        cin >> n_ops;

        // inicia tabela limpa a cada testcase
        vector<string> tabela (101, "");

        for (int i = 0; i < n_ops; i++) {
            string linha;
            cin >> linha;

            // acha os dois pontos e faz o slice
            const int dois_pontos = linha.find(':');
            string comando = linha.substr(0, dois_pontos);
            string chave = linha.substr(dois_pontos + 1);

            // executa comando correspondente
            if (comando == "ADD") {
                func_add(chave, tabela);
            }
            else if (comando == "DEL") {
                func_del(chave, tabela);
            }
        }

        int contador = 0;
        for (int i = 0; i < 101; i++) {
            if (tabela[i] != "") contador++;
        }
        cout << contador << endl;

        for (int i = 0; i < 101; i++) {
            if (tabela[i] != "") {
                cout << i << ":" << tabela[i] << endl;
            }
        }
    }
    return 0;
}