#include <iostream>
#include <string>

int main() {

    int n_lista; // numero de arrays de caracteres do input
    std::cin >> n_lista;

    // loop para receber a quantidade necessaria de arrays
    for (int i = 0; i < n_lista; i++) {
        std::string s; // variavel da array
        std::cin >> s;
        char pilha [1005]; // pilha com uma margem de seguranca de tamanho
        int cursor = 0; // cursor da pilha
        bool balanceado = true; // flag de verificacao


        for (int j = 0; j < s.length(); j++) {
            char atual = s[j]; // variavel para adicionar ou verificar caracteres da pilha
            // se for de abertura, adicionar na pilha
            if (atual == '(' or atual == '[' or atual == '{') {
                pilha[cursor] = atual;
                cursor++;
            }
            // caso contrario verificar se bate com o ultimo caractere adicionado
            else {
                if (cursor==0) {
                    balanceado = false;
                    break;
                }
                // indice onde esta o caracte de abertura do caracter de fechamento
                char ultimo = pilha[cursor - 1];

                if ((atual == ')' and ultimo == '(') or (atual == ']' and ultimo == '[') or (atual == '}' and ultimo == '{')) {
                    cursor--; // decrementa o cursor caso o par esteja correto
                }
                else {
                    balanceado = false; // se n estiver correto dispara a flag e a string vai ser determinada como desbalanceada
                    break;
                }
            }
        }
        if (balanceado and cursor==0) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
