#include <iostream>
#include <vector>

using namespace std;

struct No {
    char dado;
    No* esq;
    No* dir;

    // inicia os ponteiros como vazios
    No(char valor) {
        dado = valor;
        esq = dir = NULL;
    }
};

void inserir(No* &raiz, char valor) {
    if (raiz == NULL) {
        raiz = new No(valor); // cria o no se ele n existir
        return;
    }
    if (valor < raiz->dado) {
        inserir(raiz->esq, valor);
    }
    else {
        inserir(raiz->dir, valor);
    }
}

void imprimir_preorder(No* raiz) {
    if (raiz == NULL) return; // se chegou numa ponta vazia, volta

    cout << raiz->dado;         // imprime a raiz
    imprimir_preorder(raiz->esq); // imprime a esquerda
    imprimir_preorder(raiz->dir);  // imprime a direita
}

void resolver_case(vector<string>& linhas) {
    No* raiz = NULL; // comeca vazio

    // percorre de tras pra frente, o size - 1 serve para isso
    for (int i = linhas.size() - 1; i >= 0; i--) {
        string linha = linhas[i];
        // para cada letra da linha
        for (int j = 0; j < linha.length(); j++) {
            char letra = linha[j];
            inserir(raiz, letra); // manda inserir na arvore
        }
    }

    imprimir_preorder(raiz);
    cout << endl;
}

int main() {

    vector<string> linhas;
    string leitura;

    // le string por string parando quando acabar
    while (cin >> leitura) {
        if (leitura == "$" or leitura == "*") {
            resolver_case(linhas);
            linhas.clear(); // limpa o vetor para o próximo caso

            if (leitura == "$") break; // se for $ acaba
        } else {
            linhas.push_back(leitura);
        }
    }
    if (!linhas.empty()) {
        resolver_case(linhas);
    }

    return 0;
}