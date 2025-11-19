#include <iostream>
#include <string>
using namespace std;

int esquerda [10005];
int direita [10005];

int main() {
    int cases; // numero de casos
    cin >> cases;

    // loop para rodar c vezes
    while (cases--) {

        int tam_balsa, n_carros;
        cin >> tam_balsa >> n_carros;

        tam_balsa = tam_balsa * 100; //conversao para centimetros

        int inicio_esq = 0;
        int inicio_dir = 0;

        int fim_esq = 0;
        int fim_dir = 0;

        // input dos carros
        for (int i = 0; i < n_carros; i++) {
            int tam_carro;
            string lado;
            cin >> tam_carro >> lado;

            // condicional para colocar o tamanho dos carros na fila
            if (lado == "left") {
                esquerda[fim_esq] = tam_carro;
                fim_esq++;
            }
            else if (lado == "right") {
                direita[fim_dir] = tam_carro;
                fim_dir++;
            }
        }

        // funcionamento da balsa

        int travessias = 0;
        int lado_atual = 0; // 0 = esquerda, 1 = direita

        // loop para rodar enquanto tiverem carros na fila
        while (inicio_esq < fim_esq or inicio_dir < fim_dir) {

            int espaco_disponivel = tam_balsa;

            if (lado_atual == 0) {

                // loop para enquanto tiverem carros na esquerda e tiver espaco
                while (inicio_esq < fim_esq and esquerda[inicio_esq] <= espaco_disponivel) {
                    espaco_disponivel -= esquerda[inicio_esq]; // adiciona o tamanho do carro na balsa
                    inicio_esq++; // tira o carro da fila
                }
            }
            else {
                // loop para enquanto tiverem carros na direita e tiver espaco
                while (inicio_dir < fim_dir and direita[inicio_dir] <= espaco_disponivel) {
                    espaco_disponivel -= direita[inicio_dir];
                    inicio_dir++;
                }
            }
            travessias++;

            // troca de lados
            lado_atual = 1 - lado_atual;
        }
        cout << travessias << endl;
    }
    return 0;
}

